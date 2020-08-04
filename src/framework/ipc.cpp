
/*
 * Nekohook: Free, fast and modular cheat software
 * Copyright (C) 2018 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <algorithm>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/shared_memory_object.hpp>

#include "../util/logging.hpp"  // Logging is good u noob
#include "console.hpp"

#include "ipc.hpp"

// NOTE: we use boost just for the cross platform ipc, message_queue just doesnt
// support authors as well as a way to read messages without deleting them.
// There is just no way to easily do ipc

// TODO: boost::interprocess::shared_memory_object and
// boost::interprocess::mapped_region may need to not be destructed... We use
// them once then grab a pointer but it needs testing to ensure this is true.

namespace ipc {

// The big boi
std::unique_ptr<IpcStream> main_ipc_stream;

// Command handler
IpcCommand::IpcCommand(const char* _name, FuncPtr _callback)
    : name(_name), callback(_callback) {
    List.push_back(this);
}

// Stock ipc commands
static IpcCommand ipc_exec("exec", [](const IpcMessage* message) {
    CallCommand((const char*)message->payload);
});

// Stock CatCommands to handle ipc
static CatCommand exec_all("ipc_exec_all",
                           [](const std::vector<std::string_view>& args) {
                               if (args.empty()) {
                                   debug_log.Puts("Missing args");
                                   return;
                               }
                               if (!main_ipc_stream) {
                                   debug_log.Puts("IPC isnt connected");
                                   return;
                               }
                               // we send size + 1 to include end char, but we
                               // need to convert to string first to ensure we
                               // have that endchar
                               std::string out(args[0]);
                               main_ipc_stream->SendAll("exec", out.c_str(),
                                                        out.size() + 1);
                           });

// Stock CatCommands to handle ipc
static CatCommand connect("ipc_connect",
                          [](const std::vector<std::string_view>& args) {
                              if (main_ipc_stream) {
                                  debug_log.Puts("IPC already connected");
                                  return;
                              }
                              // If no args, use default network
                              std::string tmp;
                              if (args.empty())
                                  tmp = "neko_ipc";
                              else
                                  tmp = args[0];
                              // Connect to ipc
                              main_ipc_stream =
                                  std::make_unique<IpcStream>(tmp.c_str());
                          });

static CatCommand disconnect("ipc_disconnect",
                             [](const std::vector<std::string_view>& args) {
                                 if (!main_ipc_stream) {
                                     debug_log.Puts("IPC isnt connected");
                                     return;
                                 }
                                 // Destruct ipc stream and set to null
                                 main_ipc_stream.reset(nullptr);
                             });

static CatCommand list("ipc_list",
                       [](const std::vector<std::string_view>& args) {
                           if (!main_ipc_stream) {
                               debug_log.Puts("IPC isnt connected");
                               return;
                           }
                           auto tmp = main_ipc_stream->GetMembers();
                           for (const auto& i : tmp)
                               debug_log.Fmt("Found IPC member: %s", i);
                       });

// Constructor responsibilities, constructing the shared memory pool and
// starting the thread if successful
IpcStream::IpcStream(const char* _pool_name) : pool_name(_pool_name) {
    // Boost, I love you <3
    boost::interprocess::shared_memory_object shm_res(
        boost::interprocess::open_or_create, _pool_name,
        boost::interprocess::read_write);
    shm_res.truncate(sizeof(IpcContent));

    boost::interprocess::mapped_region region(shm_res,
                                              boost::interprocess::read_write);
    this->ipc_mem_space = reinterpret_cast<IpcContent*>(region.get_address());

    // Setup a member slot for us
    this->IpcCleanup();  // cleanup to make sure we get unused slots
    this->ipc_pos = GetOpenSlot(this->ipc_mem_space->members, kMaxIpcMembers);
    if (this->ipc_pos != -1) {
        // Set ping so we dont get instantly rejected by peers, then set the
        // state to locked so we can setup
        this->ipc_mem_space->members[this->ipc_pos].time.Reset();
        this->ipc_mem_space->members[this->ipc_pos].state = IpcState::kLocked;
        char new_name[32] = "neko_";
        size_t len = strlen(new_name);
        for (int i = 0; i < kMaxIpcMembers; i++) {
            sprintf(&new_name[len], "%i", i);
            if (!MemberExists(new_name)) {
                strcpy(this->ipc_mem_space->members[this->ipc_pos].name,
                       new_name);
                break;
            }
        }
        if (*this->ipc_mem_space->members[this->ipc_pos].name != '\0') {
            // Allow peers to see us
            this->ipc_mem_space->members[this->ipc_pos].state =
                IpcState::kRecipientLocked;
            debug_log.Fmt("IPC: Found name: %s!",
                          this->ipc_mem_space->members[this->ipc_pos].name);
        } else {
            debug_log.Puts("IPC: Cant find suitible name!");
            return;
        }
    } else {
        debug_log.Puts("IPC: No open slot to register in!");
        return;
    }

    // Start a thread for the ipc
    debug_log.Puts("IPC: Starting Thread");
    this->thread_loop.Start([&]() { this->thread_tick(); });
}

IpcStream::~IpcStream() {
    debug_log.Puts("IPC: IPC shutting down!");
    thread_loop.Stop();
    boost::interprocess::shared_memory_object::remove(pool_name.c_str());
}

void IpcStream::thread_tick() {
    // Ping keeper
    this->ipc_mem_space->members[this->ipc_pos].time.Reset();

    // Find new messages sent to us
    for (auto& i : this->ipc_mem_space->message_pool) {
        if (i.state == IpcState::kRecipientLocked) {
            if (i.recipient == this->ipc_pos) {
                auto find = std::find_if(
                    IpcCommand::List.begin(), IpcCommand::List.end(),
                    [&](auto c) { return !strcmp(c->name, i.command); });
                if (find != IpcCommand::List.end()) {
                    debug_log.Fmt("IPC: Recieved Command: %s!", i.command);
                    // Run the command we found
                    (*find)->callback(&i);
                } else
                    debug_log.Fmt("IPC: Recieved Unknown Command: %s!",
                                  i.command);
                // Reset the message status since we recieved it
                i.state = IpcState::kOpen;
            }
        }
    }

    // Cleanup Crew, we clean every 15 seconds... why, i dont know /shrug
    if (cleanup.ResetAfter(std::chrono::seconds(15))) this->IpcCleanup();
    // Loop sleep
    std::this_thread::sleep_for(std::chrono::milliseconds(75));
}

bool IpcStream::SendMessage(const char* recipient, const char* command,
                            const void* payload, size_t size) {
    if (!strcmp(recipient, "all")) {
        this->SendAll(command, payload, size);
        return true;
    }
    auto tmp = this->FindMember(recipient);
    if (tmp == -1) return false;
    this->SendMessage(tmp, command, payload, size);
    return true;
}
bool IpcStream::SendMessage(int recipient, const char* command,
                            const void* payload, size_t size) {
    auto tmp =
        this->GetOpenSlot(this->ipc_mem_space->message_pool, kMaxIpcMessages);
    if (tmp == -1) return false;
    // Reset ping and lock so we can use without issues
    this->ipc_mem_space->message_pool[tmp].time.Reset();
    this->ipc_mem_space->message_pool[tmp].state = IpcState::kLocked;
    // Address it
    this->ipc_mem_space->message_pool[tmp].author = this->ipc_pos;
    this->ipc_mem_space->message_pool[tmp].recipient = recipient;
    // Copy our payload into the message
    strcpy(this->ipc_mem_space->message_pool[tmp].command, command);
    memcpy(this->ipc_mem_space->message_pool[tmp].payload, payload, size);
    // Allow the recipient to read it
    this->ipc_mem_space->message_pool[tmp].state = IpcState::kRecipientLocked;
    return true;
}
void IpcStream::SendAll(const char* command, const void* payload, size_t size) {
    this->IpcCleanup();  // Cleanup so we only get existing members
    for (int i = 0; i < kMaxIpcMembers; i++) {
        if (i == this->ipc_pos) continue;  // dont send one to yourself dummy
        if (this->ipc_mem_space->members[i].state != IpcState::kRecipientLocked)
            continue;
        this->SendMessage(i, command, payload, size);
    }
}

}  // namespace ipc

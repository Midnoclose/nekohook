
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

#pragma once

#include <atomic>
#include <cstring>
#include <vector>

#include "../util/chrono.hpp"  // for the cat timer, and so we can sleep in thread
#include "../util/functional.hpp"

// Increase as needed, we just need enough space to handle
constexpr int kMaxIpcMembers = 32;
constexpr int kMaxIpcMessages = (kMaxIpcMembers * kMaxIpcMembers / 8);

namespace ipc {

// IPC Memory space

// State of a slot
enum class IpcState {
    kOpen,            // Item is open to the network
    kLocked,          // Item is locked
    kRecipientLocked  // Item is open to recipients
};
// A slot, open, closed, simple as that
struct IpcSlot {
    IpcState state{IpcState::kOpen};
    CatTimer time;
};
// A message, it is the recipients job to recieve it in time and reset it
struct IpcMessage : public IpcSlot {
    int author;  // number in member array
    int recipient;
    char command[64];  // A command that tells the recipient what to do with the
                       // payload
    char payload[1024];  // This could be anything
};
struct IpcMember : public IpcSlot {
    char name[64] = "";
};
// This is what the entire Ipc mapped memory should be
struct IpcContent {
    IpcMember members[kMaxIpcMembers];
    IpcMessage message_pool[kMaxIpcMessages];
};

// IPC command handler
class IpcCommand {
   public:
    using FuncPtr = void (*)(const IpcMessage*);
    IpcCommand(const char* name, FuncPtr _callback);
    const char* name;
    const FuncPtr callback;

   protected:
    friend class IpcStream;  // allow the ipc stream to read the list
    static inline std::vector<IpcCommand*> List;

   private:
};

// IPC Driver

// Ipc stream class
class IpcStream {
    // Constructor/Descructor needed stuff
   private:
    std::string
        pool_name;  // As the input could change, gotta string it to save it oof
    // Ipc stuff
    IpcContent* ipc_mem_space = nullptr;
    int ipc_pos = -1;  // our position in the ipc

    // Setup of shared memory, Destructor, stops thread and unlinks shared
    // memory
   public:
    IpcStream(const char* _pool_name);
    ~IpcStream();

    // Setters/Getters
   public:
    // Used to get a list of members
    inline std::vector<const char*> GetMembers() const {
        std::vector<const char*> ret;
        for (const auto& i : this->ipc_mem_space->members)
            if (i.state == IpcState::kRecipientLocked) ret.push_back(i.name);
        return ret;
    }
    // Returns the name used in ipc
    inline const char* GetIpcName() const {
        if (ipc_pos == -1) return nullptr;
        return this->ipc_mem_space->members[ipc_pos].name;
    }
    // Returns whether member exists
    inline bool MemberExists(const char* test_name) const {
        return FindMember(test_name) != -1;
    }
    // Returns the slot of the member, returns -1 on failure
    inline int FindMember(const char* test_name) const {
        for (int i = 0; i < kMaxIpcMembers; i++)
            if (this->ipc_mem_space->members[i].state ==
                IpcState::kRecipientLocked)  // we only want members that arent
                                             // locked
                if (!strcmp(this->ipc_mem_space->members[i].name, test_name))
                    return i;
        return -1;
    }

   private:
    // Internal cleanup of the ipc space, in the case of a member not being nice
    // >:(
    inline void IpcCleanup() {
        // For the cleanup, we look for anything not open and check the timer on
        // it We clean thing more than 6 seconds of idle
        for (auto& i : this->ipc_mem_space->members)
            if (i.state != IpcState::kOpen &&
                i.time.CheckTime(std::chrono::seconds(6)))
                i.state = IpcState::kOpen;
        for (auto& i : this->ipc_mem_space->message_pool)
            if (i.state != IpcState::kOpen &&
                i.time.CheckTime(std::chrono::seconds(6)))
                i.state = IpcState::kOpen;
    }
    // Internal use for finding open slots, be sure to give it the right size to
    // prevent segfaults
    inline int GetOpenSlot(IpcSlot* slot_array, int size) const {
        for (int i = 0; i < size; i++)
            if (slot_array[i].state == IpcState::kOpen) return i;
        return -1;
    }

    // Threading, TODO: replace with ThreadedLoop
   private:
    cat::ThreadedLoop thread_loop;
    CatTimer cleanup;
    void thread_tick();

   public:
    // Use to send messages through ipc, use member pos or by name, returns true
    // on success
    bool SendMessage(const char* recipient, const char* command,
                     const void* payload, size_t size);
    bool SendMessage(int recipient, const char* command, const void* payload,
                     size_t size);
    void SendAll(const char* command, const void* payload, size_t size);
};

// not garrenteed to not be null, check before using it
extern std::unique_ptr<IpcStream> main_ipc_stream;

}  // namespace ipc

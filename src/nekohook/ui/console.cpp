
#include <algorithm>
#include <fstream>

#include "var.hpp"

#include "console.hpp"

namespace nekohook::ui::console {
    
void Exec(std::ostream& out, std::string_view input) {
    Command::Args args = Command::ProcessLine(input);
    std::string_view name = args[0];
    Exec(out, name, Command::Args(args.begin()++, args.end()));
}

void Exec(std::ostream& out, std::string_view name, Command::Args args) {
    // TODO: Fix command prefix. also TODO: explain more u chud
    {
        const auto& u_list = BaseVar::GetList();
        auto find = std::find_if(u_list.begin(), u_list.end(), [&](auto i) {
            return name == i->command_name;
        });
        if (find != u_list.end())
            return (*find)->Call(out, std::move(args));
    }
    {
        // Try to find command from command list
        const auto& c_list = Command::GetList();
        auto find = std::find_if(c_list.begin(), c_list.end(), [&](auto i) {
            return name == i->name;
        });
        if (find != c_list.end())
            return (*find)->Call(std::move(args));
    }
    out << "Cannot find command: " << name << std::endl;
}

static std::fstream main_log("/tmp/julianacat/nekohook.log", std::ios::out | std::ios::trunc); // TODO: ipc will replay logs to a seperate client during early init.

std::ostream& log = main_log;
std::ostream& err = main_log;

}


#include <algorithm>

#include "settings/var.hpp"

#include "console.hpp"

namespace neko::hook::console {
    
void Exec(std::string_view input) {
    Command::Args args = Command::ProcessLine(input);
    std::string_view name = args[0];
    Exec(name, Command::Args(args.begin()++, args.end()));
}

void Exec(std::string_view name, Command::Args args) {
    {
        const auto& u_list = settings::Var::GetList();
        auto find = std::find_if(u_list.begin(), u_list.end(), [&](auto i) {
            return name == i->command_name;
        });
        if (find != u_list.end()) {
            (*find)->Call(args);
            return;
        }
    }
    {
        // Try to find command from command list
        const auto& c_list = Command::GetList();
        auto find = std::find_if(c_list.begin(), c_list.end(), [&](auto i) {
            return name == i->name;
        });
        if (find != c_list.end()) {
            (*find)->Call(args);
            return;
        }
    }
    console::log << "Cannot find command: " << name << std::endl;
}

}

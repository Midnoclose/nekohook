
#include <algorithm>

#include "var.hpp"

#include "console.hpp"

namespace nekohook::ui::console {
    
void Exec(std::string_view input) {
    Command::Args args = Command::ProcessLine(input);
    std::string_view name = args[0];
    Exec(name, Command::Args(args.begin()++, args.end()));
}

void Exec(std::string_view name, Command::Args args) {
    // TODO: Fix command prefix.
    {
        const auto& u_list = BaseVar::GetList();
        auto find = std::find_if(u_list.begin(), u_list.end(), [&](auto i) {
            return name == i->command_name;
        });
        if (find != u_list.end())
            return (*find)->Call(std::move(args));
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
    console::log << "Cannot find command: " << name << std::endl;
}

}

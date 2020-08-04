

#include "ui/graphical/gui.hpp"
#include "ui/command.hpp"

#include "ui/settings/var.hpp"

namespace nekohook::setting {

static std::string GetCommandName(TreeMap _gui_map, std::string_view name) {
    auto tolower = [](std::string_view in) -> std::string {
        std::string ret(in);
        for (char& i : ret)
            i = ::tolower(i);
        return ret;
    };

    std::string ret(Command::kPrefix);
    for (auto i : _gui_map)
        ret += tolower(i) + '_';

    std::string new_name = tolower(name);
    for (char& i : new_name)
        if (i == ' ')
            i = '_';
    ret += new_name;
    return ret;
}

Var::Var(TreeMap _gui_map, std::string_view name) : command_name(GetCommandName(_gui_map, name)) {
    Var::list.push_back(this);
    gui::Register(_gui_map, this);
}

}

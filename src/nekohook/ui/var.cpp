
//#include "ui/gfx/gfx.hpp"
#include "ui/command.hpp"

#include "ui/var.hpp"

namespace nekohook::ui {

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

BaseVar::BaseVar(Type _type, TreeMap _gui_map, std::string_view name) 
    : command_name(GetCommandName(_gui_map, name)), type(_type) {
    BaseVar::list.push_back(this);
    //gui::Register(_gui_map, this);
}

}


#pragma once

#include "command.hpp"

namespace nekohook::ui::console {

void Exec(std::ostream&, std::string_view line);
void Exec(std::ostream&, std::string_view name, Command::Args);
    
extern std::ostream& log;
extern std::ostream& err;

}

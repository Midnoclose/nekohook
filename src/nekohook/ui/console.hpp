
#pragma once

#include "command.hpp"

namespace nekohook::ui::console {

void Exec(std::string_view);
void Exec(std::string_view name, Command::Args);
extern std::ostream log;

}

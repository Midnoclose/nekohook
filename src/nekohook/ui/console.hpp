
#pragma once

#include "command.hpp"

namespace nekohook::console {

void Exec(std::string_view);
void Exec(std::string_view name, Command::Args);
extern std::ostream log;

}

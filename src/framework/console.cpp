
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

#include "../uservar.hpp"
#include "../util/logging.hpp"
#include "../util/strings.hpp"  // sepstr()

#include "console.hpp"

Command::Command(const char* _name, CallbackType _callback)
    : name(std::string(Command::kPrefix) + _name), callback(_callback) {
    Command::list.push_back(this);
}

void Command::Call(std::string_view input) {
    // Seperate everything in the string to components
    auto args = sepstr(input);
    if (args.empty()) {
        debug_log.Fmt("Command empty!");
        return;
    }

    // Try to find catvar, we do this first as its faster than missing a command
    // every time
    auto find_var = std::find_if(
        uservar::Base::GetList().begin(), uservar::Base::GetList().end(),
        [&](auto i) { return args[0] == i->command_name; });
    if (find_var != uservar::Base::GetList().end()) {
        args.erase(args.begin());
        (*find_var)->Callback(
            args);  // Double deref OOOF, how did i manage this
    } else {
        // Try to find command from command list
        auto find_com =
            std::find_if(Command::GetList().begin(), Command::GetList().end(),
                         [&](auto i) { return args[0] == i->name; });
        if (find_com != Command::GetList().end()) {
            args.erase(args.begin());
            (**find_com)(args);  // ANOTHER DOUBLE DEREFRENCE WTF AHHHHHH
        } else
            debug_log.Fmt("Cannot find command: \"%.*s\"", input.size(),
                          input.data());
    }
}

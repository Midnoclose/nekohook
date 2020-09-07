
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

#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace nekohook::ui {

// A define for commands to use in front of their actual command
class Command {
public:
    using Args = std::vector<std::string_view>;
    using CmdFunc = std::function<void(std::ostream&, Args)>;
    Command(std::string_view _name, CmdFunc _callback) 
        : name(_name), callback(_callback) {
        Command::list.push_back(this);
    }

    static constexpr std::string_view kPrefix = "n";
    const std::string_view name;

    void Call(std::string_view input);
    void Call(Args);
private:
    const CmdFunc callback;
    
    static inline std::vector<Command*> list;
public:
    static const auto& GetList() { return Command::list; }
    static Args ProcessLine(std::string_view);
};

}  // namespace neko

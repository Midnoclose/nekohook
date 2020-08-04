
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

#include <string>
#include <string_view>
#include <vector>

namespace neko {

// A define for commands to use in front of their actual command
class Command {
   public:
    using CallbackType = void (*)(const std::vector<std::string_view>&);
    Command(std::string_view _name, CallbackType);

    inline void operator()(const std::vector<std::string_view>& args) {
        this->callback(args);
    }
    std::string name;

    static constexpr const char kPrefix[] = "n_";

    static const auto& GetList() { return Command::list; }
    static void Call(std::string_view input);

    class Logger {
    public:
        static void Puts(const char*);
        static void Fmt(const char*, ...);
    } log;
   private:
    static inline std::vector<Command*> list;
    CallbackType callback;
};

}

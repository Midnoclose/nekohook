
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

#include <stack>

namespace neko::init {

// Credits to cathook
// I know its kinda shoddy but its clean looking
namespace routine {

// for use in the framework
class Framework {
   public:
    Framework(void (*func)()) { init_stack.push(func); }
    static inline std::stack<void (*)()> init_stack;
    static void Init() {
        while (!init_stack.empty()) {
            init_stack.top()();
            init_stack.pop();
        }
    }
};

// For use within the modules that need to load
class Module {
   public:
    Module(void (*func)()) { init_stack.push(func); }
    static inline std::stack<void (*)()> init_stack;
    static void Init() {
        while (!init_stack.empty()) {
            init_stack.top()();
            init_stack.pop();
        }
    }
};

}  // namespace routine

void Main();

}  // namespace neko::init

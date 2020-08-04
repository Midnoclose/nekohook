
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

#include <neko/color.hpp>

#include "framework/uservar.hpp"  // I would like to use catvars
#include "framework/entity.hpp"

namespace neko::features::esp {

extern uservar::StrEnum esp_menu;

namespace module {
// Should esp draw boxes?
bool ShouldAddBox(Entity*);

// Should esp work at all
bool ShouldEsp(Entity*);

// Add your own strings to the argument
void GetEntityStrings(std::vector<std::pair<const char*, RGBColor>>&, Entity*);
}

}  // namespace features::esp

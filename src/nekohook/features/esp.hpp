
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

#include <NanoCanvas/src/NanoCanvas.h>

#include "nekohook/game/entity.hpp"
#include "nekohook/gfx/color.hpp"
#include "nekohook/ui/var.hpp"  // I would like to use catvars

namespace nekohook::features::esp {

namespace ui {
using namespace nekohook::ui;
extern TreeMap esp_menu;
}

void Draw(NanoCanvas::Canvas&);

namespace module {
bool ShouldDrawBox(Entity*);
bool ShouldEsp(Entity*);
//std::vector<std::pair<const char*, draw::Color>> GetStrings(Entity*);
}  // namespace module

}  // namespace neko::features::esp

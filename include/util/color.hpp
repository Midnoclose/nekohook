
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

#include "framework/entity.hpp"

namespace neko {

// Returns a color based on entity health
inline RGBColor Entity::GetHealth() {
    int health = this->GetHealth(), max_health = this->GetMaxHealth();
    if (health > max_health)  // If health is too much, they must be over their
                              // normal health so we make them blue
        return RGBColor(64, 128);

    // Percentage of health our of max
    float hf = (float)health / (float)max_health;
    // Sick logic
    return RGBAColor::ToRGBA8((hf <= 0.5 ? 1.0 : 1.0 - 2 * (hf - 0.5)),
                              (hf <= 0.5 ? (2 * hf) : 1), 0);
}

}  // namespace neko

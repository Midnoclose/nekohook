
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

#include <math.h>  // fabs() sin()
#include <chrono>  // For time keeping
#include <ratio>   // above

#include "../features/aimbot.hpp"
#include "../features/followbot.hpp"

#include "colors.hpp"

namespace neko {

// Use this to get a color from an entity!
RGBColor Entity::GetColor() {
    // Highlight targets
    if (entity == features::aimbot::highlight_target) return pink;
    if (entity == features::followbot::follow_target) return green;

    // Default color
    RGBColor ent_color = RGBColor::white;

    // Different strokes for different folks
    auto ent_type = this->GetType();
    if (ent_type == Entity::Type::kPlayer ||
        ent_type == Entity::Type::kOtherHostile ||
        ent_type == Entity::Type::kProjectile) {
        switch (GetTeam(entity)) {
            case Entity::Team::kRed:
                ent_color = red;
                break;
            case Entity::Team::kBlue:
                ent_color = blue;
                break;
            case Entity::Team::kGreen:
                ent_color = green;
                break;
            case Entity::Team::kYellow:
                ent_color = yellow;
                break;
            case Entity::Team::kAlly:  // Blue good
                ent_color = blue;
                break;
            case Entity::Team::kEnemy:  // Red bad
                ent_color = red;
        }
    }
    // Pickups
    else if (ent_type == ent::Type::kPickupHealth)
        ent_color = green;
    else if (ent_type == ent::Type::kPickupSheild)
        ent_color = yellow;

    return ent_color;
}

}  // namespace neko

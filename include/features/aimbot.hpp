
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

#include "framework/entity.hpp"  // Contains entity and bone info
#include "framework/uservar.hpp"

namespace neko::features::aimbot {

// Module related
namespace module {

// Auto hitbox function
math::Vector GetAutoHitbox(Entity*);

// For modules to add their target selection stuff, return true if target is
// acceptable
bool TargetSelection(Entity*);

// Should aimbot, well uhh, aimbot?
bool ShouldAim(Entity*);

// Used to tell when an weapon can shoot
bool CanShoot(Entity*);

}

// Use to share same aimbot menu ;)
extern std::initializer_list<std::string_view> aimbot_menu;

// esp colors
extern Entity* highlight_target;

void WorldTick();

// Debug
extern uservar::Int multipoint;
extern uservar::Int multipoint_ratio;

}  // namespace neko::features::aimbot

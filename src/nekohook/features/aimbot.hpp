
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

#include "game/entity.hpp"  // Contains entity and bone info
#include "ui/settings/math.hpp"

namespace nekohook::features::aimbot {

void WorldTick();

extern setting::StrEnum aimbot_menu;
extern Entity* highlight_target;

// Debug
extern setting::Int multipoint;
extern setting::Float multipoint_ratio;

// Module related
namespace module {

math::Vec3 GetAutoHitbox(Entity*);

bool TargetSelection(Entity*);

bool ShouldAim(Entity*);
bool CanShoot(Entity*);

}  // namespace module
}  // namespace neko::features::aimbot

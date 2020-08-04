
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

#include <cassert>

#include "entity.hpp"

namespace neko::trace {

using EndInfo = std::pair<Entity*, math::Vector>;
// Trace line, returns end of trace
math::Vector Terrain(const math::Vector& start, const math::Vector& end);

// Trace a line, returns entity hit or end of trace
EndInfo Shot(const math::Vector& start,
                                      const math::Vector& end,
                                      Entity* ignore = Entity::GetLocalPlayer());


// Check if line hits entity, this is for convienience
inline bool Entity(Entity* entity, const math::Vector& src,
                   const math::Vector& dest,
                   Entity* ignore = Entity::GetLocalPlayer()) {
    assert(entity != ignore);
    EndInfo trace_result = Shot(src, dest, ignore);
    return trace_result.first == entity /*|| trace_result.second.DistTo(dest) < 1*/;
}

// In front of src + angles
inline EndInfo Front(
    const math::Vector& src, math::Angle angles,
    class Entity* ignore = Entity::GetLocalPlayer()) {
    return Shot(src, angles.ExtendLine(src, 8192.0f), ignore);
}

// Whats in front of the player
inline EndInfo Front(
    class Entity* entity, class Entity* ignore = Entity::GetLocalPlayer()) {
    class LocalPlayer* local_ent = Entity::GetLocalPlayer();
    return Front(local_ent->GetCameraPos(), local_ent->GetCameraAngle());
}

}  // namespace neko::trace

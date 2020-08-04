
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

#include "game/entity.hpp"

namespace nekohook::trace {

using EndInfo = std::pair<Entity*, math::Vec3>;

// Trace line, returns end of trace
math::Vec3 Terrain(const math::Vec3& start, const math::Vec3& end);

// Trace a line, returns entity hit or end of trace
EndInfo Shot(const math::Vec3& start, const math::Vec3& end, Entity* ignore = Entity::GetLocalPlayer());

// In front of src + angles
inline EndInfo Front(const math::Vec3& src, const math::Angle& direction, Entity* ignore = Entity::GetLocalPlayer()) {
    return Shot(src, math::DirectionalMove(src, direction, 8192.0f), ignore);
}

// Whats in front of entity
inline EndInfo Front(Entity* entity) {
    return Front(entity->GetCameraPosition(), entity->GetCameraAngle());
}

// Front of player
inline EndInfo Front(LocalPlayer* local_ent) {
    return Front(local_ent->GetCameraPosition(), local_ent->GetCameraAngle(), local_ent);
}
inline EndInfo Front() {
    LocalPlayer* local_ent = Entity::GetLocalPlayer();
    return local_ent ? Front(local_ent) : EndInfo();
}

// Check if line hits entity, this is for convienience
inline bool Entity(Entity* entity, const math::Vec3& src, const math::Vec3& dest,
                   Entity* ignore = Entity::GetLocalPlayer()) {
    assert(entity != ignore);
    return Shot(src, dest, ignore).first == entity;
}

}  // namespace neko::trace

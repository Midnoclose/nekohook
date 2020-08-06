
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


geo::Vec3 Terrain(const geo::Segment3&);

using EndInfo = std::pair<Entity*, geo::Vec3>;
EndInfo Shot(const geo::Segment3&, Entity* ignore = Entity::GetLocalPlayer());

// Check if line hits entity, this is for convienience
bool Entity(Entity* entity, const geo::Segment3& v, Entity* ignore = Entity::GetLocalPlayer()) {
    assert(entity != ignore);
    return Shot(v, ignore).first == entity;
}

}  // namespace neko::trace

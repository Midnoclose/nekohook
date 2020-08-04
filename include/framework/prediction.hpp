
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

#include "entity.hpp"
#include "trace.hpp"

// Used for distance to ground, the following expands on that to make it more
// accurate
inline float DistanceToGround(math::Vector point, int max = 8192) {
    // Get a point far below the "ground" then trace to it, return distance from
    // start to dest
    return point.DistTo(
        trace::Terrain(point, util::ExtendLine(point, math::Vector(89), max)));
}
inline float DistanceToGround(const math::Box& cat_box, int max = 8192) {
    float ret = max;
    // If we can get a collision, we test from the bottom points to the ground
    // to get distance
    auto del = cat_box.max - cat_box.min;
    std::array<math::Vector, 4> points;
    points[0] = cat_box.min;
    points[1] = cat_box.min + CatVector(del.x, 0, 0);
    points[2] = cat_box.min + CatVector(del.x, del.y, 0);
    points[3] = cat_box.min + CatVector(0, del.y, 0);
    // We use the smallest result as collision would "collide" with what it
    // would hit
    for (const auto& i : points) ret = std::min(ret, DistanceToGround(i, ret));
    return ret;
}
inline float DistanceToGround(Entity* entity, int max = 8192) {
    // Collision is prefered to get accurate prediction
    try {
        auto coll = GetCollision(entity);
        return DistanceToGround(coll, max);
    } catch (...) {
        return DistanceToGround(GetOrigin(entity), max);
    }
}

bool OnGround(Entity*);

namespace pred {

// Gives the downward acceleration that a player recieves every worldtick
float GetGravity(Entity*);

// Gives velocity of an object
CatVector GetVelocity(Entity*);

void Init();

}  // namespace pred


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

#include "entity.hpp"

namespace nekohook {

float Entity::GetDistance() const {
    if (LocalPlayer* local_ent = GetLocalPlayer()) {
        std::optional<geo::Vec3> their_loc, our_loc;
        if ((their_loc = this->GetLocation()) && (our_loc = local_ent->GetLocation()))
            return geo::Distance(*their_loc, *our_loc);
    }
    return 0.0f;
}

bool Entity::IsEnemy() const {
    Entity::Team team = this->GetTeam();
    if (team == Team::kAlly) return false;
    if (team == Team::kEnemy) return true;
    if (LocalPlayer* local_ent = Entity::GetLocalPlayer())
        return local_ent->GetTeam() != team;
    return true;
}

std::optional<geo::Vec3> Entity::GetLocation() const {
    if (std::optional<geo::Box3> coll = this->GetCollision())
        return coll.value().GetCenter();
    else if (std::optional<geo::Vec3> origin = this->GetOrigin())
        return origin; 
    return std::nullopt;
}

}

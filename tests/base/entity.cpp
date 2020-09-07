
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

#include <nekohook/game/entity.hpp>

namespace nekohook {
namespace test::EntMgr {
struct AbleState {
    bool dormant, alive;
    int health, max_health;
};
std::vector<AbleState> able_states;
}
using namespace test;

const Entity* TestToEntity(std::size_t ent) {
    return reinterpret_cast<Entity*>(ent);
}

// Basic info
bool Entity::IsDormant() const {
    return EntMgr::able_states.at(this->GetId()).dormant;
}
bool Entity::IsAlive() const {
    return EntMgr::able_states.at(this->GetId()).alive;
}
int Entity::GetHealth() const {
    return EntMgr::able_states.at(this->GetId()).health;
}
int Entity::GetMaxHealth() const {
    return EntMgr::able_states.at(this->GetId()).health;
}
/*Team Entity::GetTeam() const;
Type Entity::GetType() const;
std::string_view Entity::GetName() const;*/
int Entity::GetId() const {
    return reinterpret_cast<uintptr_t>(this);
}

}


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

#include <unordered_map>

#include "nekohook/ui/console.hpp"

#include "entity.hpp"

namespace nekohook::playerstate {
/*
// Playerstates for steamid and name respectivly
static std::unordered_map<uint64_t, State> steam_states;
static std::unordered_map<std::string, State> name_states;

void Remove(Entity& entity) {
    try {
        if (uint64_t id = entity-.GetUserId())
            steam_states.erase(id);
        else
            name_states.erase(std::string(entity->GetName()));
    } catch(...){}
}

State Get(Entity* entity) {
    if (uint64_t id = entity->GetUserId()) {
        auto find = steam_states.find(id);
        if (find != steam_states.end())
            return find->second;
    }
    auto find = name_states.find(std::string(entity->GetName()));
    if (find != name_states.end())
        return find->second;
    return State::kNone;
}

void Set(Entity* entity, State state) {
    if (!state)
        Remove(entity);

    if (uint64_t id = entity->GetUserId())
        steam_states[id] = state;
    else
        name_states[std::string(entity->GetName())] = state;
}

bool IsDefault(Entity* entity) {
    return !Get(entity);
}
bool IsRage(Entity* entity) {
    return Get(entity) > 0;
}
bool IsFriendly(Entity* entity) {
    return Get(entity) < 0;
}

*/
}

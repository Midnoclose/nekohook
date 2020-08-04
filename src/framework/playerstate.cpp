
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

#include "../util/functional.hpp"
#include "../util/logging.hpp"
#include "console.hpp"
#include "entitys.hpp"

#include "playerstate.hpp"

// Playerstates for steamid and name respectivly
static cat::UnorderedFlatMap<int, int>
    player_states_steam;  // Should we use a fastmap for this? I dont know, but
                          // once the size gets really big might be an issue...
static std::unordered_map<std::string, int>
    player_states_name;  // hashing is faster with strings

PlayerState GetPlayerState(CatEntity* entity) {
    // If we can get steam ids, we will use that to deal with playerstates
    /*auto id = GetSteamId(entity);
    if (id) {
      // If we find a playerstate, we return it
      auto find = player_states_steam.find(id);
      if (find != player_states_steam.end())
        return find->second;
    // Without steamids, we can try names instead, more expensive but still
    functional } else { auto find = player_states_name.find(GetName(entity)); if
    (find != player_states_name.end()) return find->second;
    }*/
    return PlayerState::kNone;
}

void SetPlayerState(CatEntity* entity, PlayerState state) {
    /*if (uint32_t id = GetSteamId(entity)) {
      if (!state) {
        player_states_steam.erase(id);
        return;
      }
      auto find = player_states_steam.find(id);
      if (find != player_states_steam.end())
        find->second = state;
      else
        player_states_steam.emplace({id, state});
    } else if (const char* name = GetName(entity)) {
      if (!state) {
        player_states_name.erase(name);
        return;
      }
      auto find = player_states_name.find();
      if (find != player_states_name.end())
        find->second = state;
      else
        player_states_name.emplace({name, state});
    }*/
}

static CatCommand set_state("state_get",
                            [](const std::vector<std::string_view>& args) {
                                /*CatEntity* local_ent = GetLocalPlayer();
                                CatEntity* entity = nullptr;

                                // Resolve with name
                                if (args.size() > 1) {
                                  int ent_count = GetEntityCount();
                                  for (int i = 0; i < ent_count; i++) {
                                    CatEntity* tmp = GetEntity(i);
                                    if (!tmp || tmp == local_ent || GetType(tmp)
                                != ETYPE_PLAYER) continue; if
                                (fuzstrstr(GetName(tmp), args.at(0).c_str())) {
                                      entity = tmp;
                                      break;
                                    }
                                  }
                                // Resolve with sight
                                } else
                                  entity = trace_front(local_ent).first;

                                if (!entity)
                                  debug_log.log("Couldnt resolve player!");
                                else
                                  debug_log.log("State for %s: %i",
                                GetName(entity), GetPlayerState(entity));*/
                            });

// static CatCommand set_state("state_set") {}

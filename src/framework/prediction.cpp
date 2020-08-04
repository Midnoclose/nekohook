
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

#include <boost/circular_buffer.hpp>
#include <chrono>
#include <unordered_map>

#include "../gui/hudstrings/sidestrings.hpp"
#include "drawing.hpp"
#include "game.hpp"

#include "prediction.hpp"

// TODO, this continues to crash! Please fix ;(

namespace pred {

// A CatEntity should have a group of points as well as a "time keeper"
static bool time_keeper;
struct PredictionCache_s {
    boost::circular_buffer<CatVector> origins{3};  // 3 is enough right?
    bool tick = time_keeper;
};

static cat::UnorderedFlatMap<int, PredictionCache_s> origin_cache;

// Update cache for entity
static const PredictionCache_s& GetCache(int entity) {
    PredictionCache_s& cache = origin_cache[entity];
    // Update cache
    if (cache.tick != time_keeper) {
        cache.origins.push_back(GetOrigin(GetEntity(entity)));
        cache.tick = time_keeper;
    }
    return cache;
}

// Cache Cleanup duty
static void AfterWorldTick() {
    /*CatEntity* local_ent = GetLocalPlayer();
    int local_ent_idx = 0;
    if (local_ent && !GetDormant(local_ent) && GetAlive(local_ent)) {
        int ent_count = GetEntityCount();
        for (int i = 0; i < ent_count; i++) {
            if (GetEntity(i) == local_ent) {
                local_ent_idx = i;
                break;
            }
        }
    }*/

    /*for(size_t i = 0; i < origin_cache.size();) {
      local_ent_idx
      auto ii = origin_cache.begin() + i;
      if (ii->second.tick != time_keeper)
        origin_cache.erase(ii);
      else
        i++;
    }*/
    time_keeper = !time_keeper;
}

// Gives the downward acceleration that a player recieves every worldtick, this
// is just GetVelocity
cat::Function<float(int)> GetGravity{[](int entity) -> float {
    const auto& cache = GetCache(entity);
    if (cache.origins.size() < 2) return 0.0f;
    // Generate velocity, NOTE: this is a general velocity, we need something
    // better to account a change over time in the case of airstrafing. This is
    // a maybe though...
    float velocity;
    auto end = cache.origins.end() - 1;
    for (auto i = cache.origins.begin(); i != end; i++) {
        float delta = i->z - (i + 1)->z;
        if (i == cache.origins.begin())  // If its the first time looping, we
                                         // cant average 2 deltas
            velocity = delta;
        else  // meanwhile we average these
            velocity = (delta + velocity) * 0.5f;
    }
    return velocity;
}};

// Gives velocity of an object
CatVector GetVelocity(int entity) {
    const auto& cache = GetCache(entity);
    if (cache.origins.size() < 2) return CatVector();
    // Generate velocity, NOTE: this is a general velocity, we need something
    // better to account a change over time in the case of airstrafing. This is
    // a maybe though...
    CatVector velocity;
    auto end = cache.origins.end() - 1;
    for (auto i = cache.origins.begin(); i != end; i++) {
        CatVector delta = *i - *(i + 1);
        if (i == cache.origins.begin())  // If its the first time looping, we
                                         // cant average 2 deltas
            velocity = delta;
        else  // meanwhile we average these
            velocity = (delta + velocity) * 0.5f;
    }
    return velocity;
}

// A prediction iteration function
// Iter is supposed to be a function to test whether to continue, return true to
// continue. This returns the end origin
CatVector PredIter(int entity_idx,
                   bool (*iter)(CatEntity*, const CatVector&, int)) {
    CatEntity* entity = GetEntity(entity_idx);
    const auto& p_data = GetCache(entity_idx);
    if (p_data.origins.size() <
        2)  // ensure we cached enough to get velocity and gravity
        return GetOrigin(entity);

    // This is the position that we will be iterating with
    CatVector cur_pos = GetOrigin(entity);
    CatVector cur_vel = GetVelocity(entity_idx);
    float grav = cur_vel.z;
    CatBox delta_box = GetCollision(entity) -
                       cur_pos;  // we will use this for collision checking
    for (int tick = 1; iter(entity, cur_pos, tick); tick++) {
        // check if airborne
        if (DistanceToGround(delta_box + cur_pos) < 1)
            cur_vel.z = 0;  // set down velocity to 0 as we are on the ground
        else
            cur_vel.z += grav;  // if we are airborne, we should apply gravity
        // TODO, collision check
        cur_pos + cur_vel;  // add the velocity
        // Stopped check
        if (cur_vel.x < 1 && cur_vel.y < 1 && cur_vel.z < 1) break;
    }
    return cur_pos;
}

void DrawTick() {
    //#ifndef NDEBUG
    CatEntity* local_ent = GetLocalPlayer();
    if (local_ent && !GetDormant(local_ent) && GetAlive(local_ent)) {
        static char buf[32];
        snprintf(buf, sizeof(buf), "On ground: %i", OnGround(local_ent));
        gui::sidestrings::SideStrings.AddString(buf, colors::white);

        int local_ent_idx = 0;
        int ent_count = GetEntityCount();
        for (int i = 0; i < ent_count; i++) {
            if (GetEntity(i) == local_ent) {
                local_ent_idx = i;
                break;
            }
        }
        if (local_ent_idx) {
            CatVector vel = GetVelocity(local_ent_idx);
            static char buf2[64];
            snprintf(buf2, sizeof(buf2), "Velocity: %f, %f, %f", vel.x, vel.y,
                     vel.z);
            gui::sidestrings::SideStrings.AddString(buf2, colors::white);
        }
    }
    //#endif
    /*int ent_count = GetEntityCount();
    for (int i = 0; i < ent_count; i++) {
      CatEntity* entity = GetEntity(i);
      if (!entity || GetDormant(entity) || !GetAlive(entity) || GetType(entity)
    != ETYPE_PLAYER) continue; static CatVector last; last = GetOrigin(entity);
      std::pair<int, int> wts1;
      if (draw::WorldToScreen(last, wts1))
          draw::Rect(wts1.first - 4, wts1.second - 4, 8, 8, colors::white);
      if (draw::WorldToScreen(PredIter(entity, [](CatEntity*, const CatVector&
    cur_pos, int ii) -> bool{ if (ii > 100) return false; std::pair<int, int>
    wts1, wts2; if (draw::WorldToScreen(cur_pos, wts1) &&
    draw::WorldToScreen(cur_pos, wts2)) draw::Line(wts1.first, wts1.second,
    wts2.first - wts1.first, wts2.second - wts1.second, colors::white); last =
    cur_pos; return true;
      }), wts1))
          draw::Rect(wts1.first - 4, wts1.second - 4, 8, 8, colors::white);
    }*/
}

void Init() {
    events::world.Listen(AfterWorldTick, cat::Order::kAfter);
    events::draw.Listen(DrawTick);
}

}  // namespace pred

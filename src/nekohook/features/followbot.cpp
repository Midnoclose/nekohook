
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

#include <deque>

#include "game/trace.hpp"
#include "ui/console.hpp"
#include "ui/settings/bool.hpp"
#include "ui/settings/enum.hpp"
#include "ui/settings/math.hpp"
#include "util/chrono.hpp"

#include "followbot.hpp"

namespace nekohook::features::followbot {

namespace stng {
using namespace setting;
static TreeMap menu({"Followbot"});

static Bool enabled(menu, "Enabled", false);
static Bool roambot(menu, "Roaming", true);
static Bool draw_crumb(menu, "Draw Crumbs", true);
static Int min_distance(menu, "Distance", 175);
static Int min_crumb_distance(menu, "Crumb Distance", 30);
static Int crumb_distance(menu, "No Crumb Distance", 30);
static Int activation_distance(menu, "Activation Distance", 175);
static Int wanted_unique_id(menu, "Follow Id", 0);
}

// TODO, make followbot mooch off of walkbot if no direct path is found to the main target

static std::deque<math::Vec3> breadcrumbs;
Entity* follow_target = nullptr;
static Timer idle_time;

static bool ShouldFollow(LocalPlayer* local_ent, Entity* entity) {
    if (!entity || entity->IsDormant() ||
        entity->GetType() != Entity::Type::kPlayer||
        entity == local_ent || entity->IsAlive() || 
        entity->IsEnemy())
        return false;

    if (stng::activation_distance && entity->GetDistance() > float(stng::activation_distance))
        return false;

    if (std::optional<math::Vec3> loc = entity->GetLocation())
        if (!trace::Entity(entity, local_ent->GetCameraPosition(), *loc, local_ent))
            return false;

    return true;
}

template<class ConditionFn>
static void PruneCrumbs(ConditionFn Condition) {
    for (auto i = breadcrumbs.begin(); i != breadcrumbs.end(); i++) {
        if (Condition(*i)) {
            idle_time.Reset();
            breadcrumbs.erase(breadcrumbs.begin(), i);
        }
    }
}

static void WorldTick() {
    #define ClearRet() ({follow_target = nullptr; return;})

    if (!stng::enabled)
        ClearRet();

    LocalPlayer* local_ent = Entity::GetLocalPlayer();
    if (!local_ent || !local_ent->IsAlive())
        ClearRet();

    #undef ClearRet

    if (follow_target && (follow_target->IsDormant() || !follow_target->IsAlive()))
        follow_target = nullptr;
    
    
    if (!follow_target) {
        breadcrumbs.clear(); 

        if (stng::wanted_unique_id) {
            int ent_count = Entity::GetCount();
            for (int i = 0; i < ent_count; i++) {
                Entity* entity = Entity::Get(i);
                if (!ShouldFollow(local_ent, entity))
                    continue;
                if (stng::wanted_unique_id == entity->GetUserId())
                    { follow_target = entity; break; }
            }
        }
        if (!follow_target && stng::roambot) {
            float closest_distance = stng::activation_distance;
            int ent_count = Entity::GetCount();
            for (int i = 0; i < ent_count; i++) {
                Entity* entity = Entity::Get(i);
                if (!ShouldFollow(local_ent, entity))
                    continue;
                if (closest_distance > entity->GetDistance())
                    continue;
                follow_target = entity;
            }
        }
        if (!follow_target) 
            return;
        idle_time.Reset();
    }

    math::Vec3 target_pos = *follow_target->GetLocation();
    math::Vec3 local_pos = *local_ent->GetLocation();
    float dist_to_target = math::Distance(local_pos, target_pos);
    if (dist_to_target < stng::crumb_distance) {
        breadcrumbs.clear();
        local_ent->WalkTo(target_pos);
        return;
    }

    if (breadcrumbs.empty() || (!follow_target->IsAirborne() && math::Distance(target_pos, breadcrumbs.back()) > stng::min_crumb_distance))
        breadcrumbs.emplace_back(target_pos);
    
    std::optional<Entity::Hitbox> collision = local_ent->GetCollision();
    if (collision)
        PruneCrumbs([&](auto i) -> bool {
            return collision.value().Contains(i);
        });
    else
        PruneCrumbs([&](auto i) -> bool {
            return math::Distance(local_pos, breadcrumbs.front()) > 60.f;
        });

    // Follow the crumbs when too far away, or just starting to follow
    if (dist_to_target > stng::min_distance) {
        if (idle_time.Check(std::chrono::seconds(3)))
            follow_target = nullptr;
        else
            local_ent->WalkTo(breadcrumbs.front());
    } else
        idle_time.Reset();
}

/*static void DrawTick() {
    if (!followbot || !draw_crumb) return;
    if (breadcrumbs.size() < 2) return;
    for (size_t i = 0; i < breadcrumbs.size() - 1; i++) {
        std::pair<int, int> wts1, wts2;
        if (draw::WorldToScreen(breadcrumbs.at(i), wts1) &&
            draw::WorldToScreen(breadcrumbs.at(i + 1), wts2)) {
            draw::Line(wts1.first, wts1.second, wts2.first - wts1.first,
                       wts2.second - wts1.second, colors::white);
        }
    }
    std::pair<int, int> wts;
:w:w    if (!draw::WorldToScreen(breadcrumbs.at(0), wts)) return;
    draw::RectFilled(wts.first - 4, wts.second - 4, 8, 8, colors::white);
    draw::Rect(wts.first - 5, wts.second - 5, 10, 10, colors::black);
}

static CatCommand follow_me("fb_follow_me", [](const std::vector<
                                                std::string_view>&) {
    if (!ipc::main_ipc_stream) {
        debug_log.Puts("IPC isnt connected");
        return;
    }
    CatEntity* local_ent = GetLocalPlayer();
    if (!local_ent) {
        debug_log.Puts("Cant get a local player");
        return;
    }
    auto steam_id = GetSteamId(local_ent);
    if (!steam_id) {
        debug_log.Puts(
            "Cant get steam-id, the game module probably doesnt support it.");
        return;
    }
    // Construct the command
    std::string tmp =
        follow_steam.command_name + " " + std::to_string(steam_id);
    ipc::main_ipc_stream->SendAll("exec", tmp.c_str(), tmp.size() + 1);
});

*/

}  // namespace features::followbot

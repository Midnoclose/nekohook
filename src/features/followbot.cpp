
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

#include "../framework/console.hpp"  // Using console as a wrapper for ipc is even better
#include "../framework/drawing.hpp"  // draw some crumbs
#include "../framework/game.hpp"  // So we can run things in draw and world tick
#include "../framework/ipc.hpp"   // Ipc to control followbots would be nice...
#include "../framework/prediction.hpp"  // DistanceToGround()
#include "../framework/trace.hpp"
#include "../util/catvars.hpp"
#include "../util/chrono.hpp"
#include "../util/logging.hpp"

#include "followbot.hpp"

namespace features::followbot {

static CatEnum followbot_menu({"Autonomy", "Followbot"});
static CatVarBool followbot(followbot_menu, "fb", false, "Followbot Switch",
                            "Set to 1 in followbots' configs");
static CatVarBool roambot(followbot_menu, "fb_roaming", true, "Roambot",
                          "Followbot will roam free, finding targets it can");
static CatVarBool draw_crumb(followbot_menu, "fb_draw", true, "Draw crumbs",
                             "Self explanitory");
static CatVarInt follow_distance(
    followbot_menu, "fb_distance", 175, "Follow Distance",
    "How close the bots should stay to the target");
static CatVarInt follow_activation(followbot_menu, "fb_activation", 175,
                                   "Activation Distance",
                                   "How close a player should be until the "
                                   "followbot will pick them as a target");
static CatVarInt follow_steam(
    followbot_menu, "fb_steam", 0, "Follow Steam Id",
    "Set a steam id to let followbot prioritize players");

// TODO, make followbot mooch off of walkbot if no direct path is found to the
// main target

// TODO, static buffer
static boost::circular_buffer<CatVector> breadcrumbs(64);
CatEntity* follow_target = nullptr;

static void WorldTick() {
    if (!followbot) {
        follow_target = nullptr;
        return;
    }

    auto local_ent = GetLocalPlayer();
    if (!local_ent || !GetAlive((CatEntity*)local_ent)) {
        follow_target = nullptr;
        return;
    }

    if (follow_target) {
        // Overflow protection
        if (breadcrumbs.size() > breadcrumbs.capacity())
            follow_target = nullptr;
        else if (GetDormant(follow_target) || !GetAlive(follow_target))
            follow_target = nullptr;
    }

    // Target Selection
    if (!follow_target) {
        breadcrumbs.clear();  // no target == no path

        if (follow_steam) {
            // Find a target with the steam id, as it is prioritized
            int ent_count = GetEntityCount();
            for (int i = 0; i < ent_count; i++) {
                CatEntity* entity = GetEntity(i);
                if (!entity || GetDormant(entity))  // Exist + dormant
                    continue;
                if (GetType(entity) != ent::Type::kPlayer) continue;
                if (static_cast<int32_t>(follow_steam) !=
                    GetSteamId(entity))  // steamid check
                    continue;
                if (!GetAlive(entity))  // Dont follow dead players
                    continue;
                CatBox coll = GetCollision(entity);
                if (!trace::Entity(entity, GetCamera(local_ent),  // vis check
                                   (coll != CatBox()) ? coll.GetCenter()
                                                      : GetOrigin(entity)))
                    continue;
                follow_target = entity;
                break;
            }
        }
        // If we dont have a follow target from that, we look again for someone
        // else who is suitable
        if (!follow_target && roambot) {
            // Try to get a new target
            int ent_count = GetEntityCount();
            for (int i = 0; i < ent_count; i++) {
                CatEntity* entity = GetEntity(i);
                if (!entity || GetDormant(entity))  // Exist + dormant
                    continue;
                if (GetType(entity) != ent::Type::kPlayer) continue;
                if (entity == local_ent)  // Follow self lol
                    continue;
                if (!GetAlive(entity) ||
                    GetEnemy(entity))  // Dont follow dead players
                    continue;
                if (follow_activation &&
                    GetDistance(entity) > follow_activation)
                    continue;
                auto coll = GetCollision(entity);
                if (!trace::Entity(entity, GetCamera(local_ent),  // vis check
                                   (coll != CatBox()) ? coll.GetCenter()
                                                      : GetOrigin(entity)))
                    continue;
                if (follow_target &&
                    GetDistance(follow_target) >
                        GetDistance(entity))  // favor closer entitys
                    continue;
                // ooooo, a target
                follow_target = entity;
            }
        }
        // last check for entity before we continue
        if (!follow_target) return;
    }

    // If the player is close enough, we dont need to follow the path
    CatVector tar_orig = GetOrigin(follow_target);
    CatVector loc_orig = GetOrigin(local_ent);
    float dist_to_target = loc_orig.DistTo(tar_orig);
    if (dist_to_target < 30) breadcrumbs.clear();

    // Update timer on new target
    static CatTimer idle_time;
    if (breadcrumbs.empty()) idle_time.Reset();

    // New crumbs, we add one if its empty so we have something to follow
    if ((breadcrumbs.empty() ||
         tar_orig.DistTo(breadcrumbs.at(breadcrumbs.size() - 1)) > 40.0F) &&
        DistanceToGround(follow_target) < 30)
        breadcrumbs.push_back(tar_orig);

    // Prune old and close crumbs that we wont need anymore, update idle timer
    // too
    for (auto i = breadcrumbs.begin(); i != breadcrumbs.end(); i++) {
        CatBox coll = GetCollision(local_ent);
        if ((coll != CatBox()) ? coll.Contains(breadcrumbs.at(0))
                               : loc_orig.DistTo(breadcrumbs.at(0)) > 60.f) {
            idle_time.Reset();
            breadcrumbs.erase(breadcrumbs.begin(), i + 1);
        }
    }

    // Follow the crumbs when too far away, or just starting to follow
    if (dist_to_target > follow_distance) {
        if (idle_time.CheckTime(std::chrono::seconds(3)))
            follow_target = nullptr;
        else
            WalkTo(local_ent, breadcrumbs.at(0));
    } else
        idle_time.Reset();
}

static void DrawTick() {
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
    if (!draw::WorldToScreen(breadcrumbs.at(0), wts)) return;
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

void Init() {
    events::world.Listen(WorldTick);
    events::draw.Listen(DrawTick);
}

}  // namespace features::followbot

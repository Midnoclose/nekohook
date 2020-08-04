
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

#include "../framework/game.hpp"
#include "../framework/trace.hpp"
#include "../util/catvars.hpp"
#include "../util/chrono.hpp"
#include "aimbot.hpp"  // We will use the aimbot shoot target checks to make triggerbot simple
#include "antiaim.hpp"  // AA safe ticks

#include "triggerbot.hpp"

namespace features::trigger {

static CatEnum trigger_menu({"TriggerBot"});
static CatVarBool enabled(trigger_menu, "tb", false, "Enable TriggerBot",
                          "Master TriggerBot switch");
static CatVarInt delay(trigger_menu, "tb_delay", 0, "TriggerDelay",
                       "How long to delay triggerbot in ms", 3000);
static CatVarInt accuracy(trigger_menu, "tb_accuracy", 0, "TriggerAccuracy",
                          "How much to shrink the hitboxes and check them",
                          3000);
static CatVarInt teammates(trigger_menu, "tb_team", 0, "TriggerAccuracy",
                           "How much to shrink the hitboxes and check them",
                           3000);

// A second check to determine whether a target is good enough to be aimed at
bool IsTargetGood(CatEntity* entity) {
    if (!entity || GetDormant(entity)) return false;

    // Type
    ent::Type type = GetType(entity);
    if (type != ent::Type::kPlayer && type != ent::Type::kOtherHostile)
        return false;

    // Dead
    if (!GetAlive(entity)) return false;

    // Teammates
    bool team = GetEnemy(entity);
    if (teammates != 2 && ((teammates == 0) ? !team : team)) return false;

    // Do the custom stuff
    if (!aimbot::TargetSelectionModule(entity)) return false;

    // Hey look! Target passed all checks
    return true;
}

static void WorldTick() {
    if (!enabled) return;

    // Check the timer
    static bool delaying = false;
    static CatTimer delay_timer;
    if (delaying && !delay_timer.CheckTime(std::chrono::milliseconds(delay)))
        return;

    auto local_ent = GetLocalPlayer();
    if (!local_ent) {
        delaying = false;
        return;
    }

    // Check if we can shoot in the first place
    if (!aimbot::ShouldAim()) {
        delaying = false;
        return;
    }

    // Get what we see
    CatVector camera_pos = GetCamera(local_ent);
    CatVector dest = util::ExtendLine(camera_pos, GetCameraAngle(local_ent),
                                      8192.0f);  // used for accuracy check
    auto trace_res = trace::Shot(camera_pos, dest, local_ent);

    // Check if shootable
    // TODO, this will not work as it visual checks for us, we need a better
    // solution, c+p from aimbot?
    if (!aimbot::IsTargetGood(trace_res.first).first) {
        delaying = false;
        return;
    }

    // Check accuracy
    if (accuracy) {
        // Check hitboxes, TODO, remove IsTargetGood and add the hitbox thing to
        // it so it isnt static
        CatBox tmp;
        if (GetBone(trace_res.first, ent::Bone::kHead, tmp))
            if (!tmp.LineIntersects(camera_pos, dest)) return;
    }

    // Only set timer if we arent already delaying
    if (!delaying && delay) {
        delaying = true;
        delay_timer.Reset();
        return;
    }

    // Disable antiaim and attack
    antiaim::AddAATicks(3);
    Attack(local_ent);
}

void Init() { events::world.Listen(WorldTick); }

}  // namespace features::trigger

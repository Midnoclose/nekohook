
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

#include "game/trace.hpp"
#include "ui/settings/bool.hpp"
#include "ui/settings/enum.hpp"
#include "ui/settings/math.hpp"
#include "util/chrono.hpp"
#include "antiaim.hpp"  // AA safe ticks

#include "triggerbot.hpp"

namespace nekohook::features::trigger {

/*namespace stng {
using namespace setting;
static TreeMap menu({"TriggerBot"});

static Bool enabled(menu, "Enabled", false);
static Int delay(menu, "Delay", 0, 3000);
static Int accuracy(menu, "Accuracy", 0, 100);
static StrEnum teammates_enum({"Enemy", "Friendly", "Both"});
static Enum teammates(menu, teammates_enum, "Team", 0);
}

bool IsTargetGood(Entity* entity) {
    if (!entity || entity->IsDormant()) return false;

    Entity::Type type = entity->GetType();
    if (type != Entity::Type::kPlayer && type != Entity::Type::kOtherHostile)
        return false;
    
    if (!entity->IsAlive()) return false;
    
    bool team = entity->IsEnemy();
    if (stng::teammates != 2 && ((stng::teammates == 0) ? !team : team)) return false;
    return true;
}

static void WorldTick() {
    if (!stng::enabled) return;

    // Check the timer
    static bool delaying = false;
    static Timer delay_timer;
    if (delaying && !delay_timer.CheckTime(std::chrono::milliseconds(stng::delay)))
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

*/
}  // namespace features::trigger

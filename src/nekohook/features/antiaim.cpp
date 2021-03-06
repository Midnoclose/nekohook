
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

#include <random>

#include "ui/settings/bool.hpp"
#include "ui/settings/enum.hpp"
#include "ui/settings/math.hpp"
#include "game/trace.hpp"

#include "features/antiaim.hpp"

namespace nekohook::features::antiaim {

namespace stng {    
using namespace setting;
static TreeMap menu({"Anti-Aim"});

static Bool enabled(menu, "Enable", false);
static StrEnum aa_pitch_e({
    "OFF", "FIXED", "UP", "DOWN", "FAKEUP", "FAKEDOWN", 
    "FAKECENTER", "RANDOM", "BIGRANDOM", "FLIP", "FAKEFLIP"
});
static Enum aa_pitch(menu, aa_pitch_e, "Pitch", 0);
static StrEnum aa_yaw_e({
    "OFF", "FIXED", "FIXEDOFFSET", "RANDOM",
    "BIGRANDOM", "FLIP", "SPIN", "EDGE"
});
static Enum aa_yaw(menu, aa_yaw_e, "Yaw", 0);
static Float aa_pitch_amt(menu, "Fixed Pitch", 0);
static Float aa_yaw_amt(menu, "Fixed Yaw", 0);
static Float aa_spin_amt(menu, "Spin Speed", 2.5f);
static Bool allow_unclamped(menu, "Unclamp", false);
}
// TODO, antiaims are game specific, the ones we have here wont cut it

// TODO: std::linear_congruential_engine

static float RandFloatRange(float min, float max) {
    return (min + 1) + ((float)rand() / (float)RAND_MAX) * (max - (min + 1));
}

enum class Edge { kNone, kLeft, kRight };
Edge GetEdge(LocalPlayer* local_ent) {
    
    math::Angle camera_ang = local_ent->GetCameraAngle();
    math::Vec3 camera_pos = local_ent->GetCameraPosition();

    // Get some angles facing different directions
    math::Angle look_left(0.0f, camera_ang.y + 90); look_left.Clamp();
    math::Angle look_right(0.0f, camera_ang.y - 90); look_right.Clamp();

    // First we go out to the left and right
    math::Vec3 left = trace::Terrain(camera_pos, math::DirectionalMove(camera_pos, look_left, 128.0f));
    math::Vec3 right = trace::Terrain(camera_pos, math::DirectionalMove(camera_pos, look_right, 128.0f));

    // Check if we hit a wall, if we have, return closer
    float distto_left = math::Distance(camera_pos, left);
    float distto_right = math::Distance(camera_pos, right);
    if (std::abs(distto_left - distto_right) > 2)
        return (distto_left > distto_right) ? Edge::kRight
                                            : Edge::kLeft;

    // Now we go forward and check if we hit something there
    distto_left = math::Distance(camera_pos, trace::Terrain(camera_pos, math::DirectionalMove(left, math::Angle(0.0f, camera_ang.y), 256.0f)));
    distto_right = math::Distance(camera_pos, trace::Terrain(camera_pos, math::DirectionalMove(right, math::Angle(0, camera_ang.y), 256.0f)));
    if (std::abs(distto_left - distto_right) > 4)
        return (distto_left > distto_right) ? Edge::kRight : Edge::kLeft;
    // If we havent hit anything, then we return none
    return Edge::kNone;
}

unsigned int AASafeTicks = 0;

void WorldTick() {

    if (!stng::enabled) return;

    if (AASafeTicks) {
        AASafeTicks--;
        return;
    }

    // Get our local ents angles
    LocalPlayer* local_ent = Entity::GetLocalPlayer();
    if (!local_ent || local_ent->IsDormant() || !local_ent->IsAlive()) return;
    math::Angle angles = local_ent->GetCameraAngle();

    // Check if can aa
    if (!module::ShouldAA()) return;

    // Pitch
    switch (stng::aa_pitch) {
        case 1:  // FIXED
            angles.x = stng::aa_pitch_amt;
            break;
        case 2:  // UP
            angles.x = -89.0f;
            break;
        case 3:  // Down
            angles.x = 89.0f;
            break;
        case 4:  // CENTER
            angles.x = 0.0f;
            break;
        case 5:  // FAKEUP
            angles.x = -271.0f;
            break;
        case 6:  // FAKEDOWN
            angles.x = 271.0f;
            break;
        case 7:  // FAKECENTER
            angles.x = -3256.0f;
            break;
        case 8:  // RANDOM
            angles.x = RandFloatRange(-89.0f, 89.0f);
            break;
        case 9:  // BIGRANDOM
            angles.x = RandFloatRange(-65536.0f, 65536.0f);
            break;
        case 10:  // FLIP
            static bool flip;
            angles.x = flip ? -89 : 89;
            flip = !flip;
            break;
        case 11:  // FAKEFLIP
            angles.x = flip ? -271.0f : 271.0f;
            flip = !flip;
            break;
    }

    // Yaw
    switch (stng::aa_yaw) {
        case 1:  // FIXED
            angles.y = stng::aa_yaw_amt;
            break;
        case 2:  // FIXEDOFFSET
            angles.y += stng::aa_yaw_amt;
            break;
        case 3:  // RANDOM
            angles.y = RandFloatRange(-180.0f, 180.0f);
            break;
        case 4:  // BIGRANDOM
            angles.y = RandFloatRange(-65536.0f, 65536.0f);
            break;
        case 5:  // FLIP
            static bool flip;
            angles.y += flip ? -90 : 90;
            flip = !flip;
            break;
        case 6:  // SPIN
            static float cur_yaw;
            cur_yaw += stng::aa_spin_amt;
            while (cur_yaw > 180)  // Clamping :joy:
                cur_yaw -= 360;
            while (cur_yaw < -180) cur_yaw += 360;
            angles.y = cur_yaw;
            break;
        case 7: {  // EDGE
            Edge edge = GetEdge(local_ent);
            if (edge != Edge::kNone) {
                // Pitch can affect how our head is behind walls, so we fix that
                // here we also clamp so we edge where our real head is
                float pitch = angles.x;
                while (pitch > 89)  // Clamping :joy:
                    pitch -= 180;
                while (pitch < -89) 
                    pitch += 180;
                
                if (pitch < 0) {
                    if (edge == Edge::kLeft)
                        edge = Edge::kRight;
                    else
                        edge = Edge::kLeft;
                }
                // Do the edge dance
                if (edge == Edge::kLeft)
                    angles.y += 90;
                else
                    angles.y -= 90;
            }
        }
    }

    // Clamp Finished angles
    if (!stng::allow_unclamped) angles.Clamp();

    // Send it off to the races
    local_ent->SetSilentCameraAngle(angles);
}

// TODO, snapback/screenshot antiaim using framebuffers. 
// Use a longer time trying to do the anti aim, 
// then a split second to snap back and grab the screen
/*static void DrawTick() {

}*/

}  // namespace neko::features::antiaim

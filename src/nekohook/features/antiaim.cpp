
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

#include "ui/var.hpp"
#include "game/trace.hpp"

#include "features/antiaim.hpp"

namespace nekohook::features::antiaim {

namespace ui {    
using namespace nekohook::ui;
static TreeMap menu({"Anti-Aim"});

static Var<bool> enabled(menu, "Enable", false);
static Var<Enum> aa_pitch(menu, "Pitch", 0, {
    "OFF", "FIXED", "UP", "DOWN", "FAKEUP", "FAKEDOWN", 
    "FAKECENTER", "RANDOM", "BIGRANDOM", "FLIP", "FAKEFLIP"
});
static Var<Enum> aa_yaw(menu, "Yaw", 0, {
    "OFF", "FIXED", "FIXEDOFFSET", "RANDOM",
    "BIGRANDOM", "FLIP", "SPIN", "EDGE"
});
static Var<float> aa_pitch_amt(menu, "Fixed Pitch", 0);
static Var<float> aa_yaw_amt(menu, "Fixed Yaw", 0);
static Var<float> aa_spin_amt(menu, "Spin Speed", 2.5f);
static Var<bool> allow_unclamped(menu, "Unclamp", false);
}
// TODO, antiaims are game specific, the ones we have here wont cut it

// TODO: std::linear_congruential_engine

static float RandFloatRange(float min, float max) {
    return (min + 1) + ((float)rand() / (float)RAND_MAX) * (max - (min + 1));
}

enum class Edge { kNone, kLeft, kRight };
Edge GetEdge(LocalPlayer* local_ent) {
    
    geo::Angle2 camera_ang = local_ent->GetCameraAngle();
    geo::Vec3 camera_pos = local_ent->GetCameraPosition();

    // Get some angles facing different directions
    geo::Angle2 look_left(0.0f, camera_ang.y + 90); look_left.Clamp();
    geo::Angle2 look_right(0.0f, camera_ang.y - 90); look_right.Clamp();

    // First we go out to the left and right
    geo::Vec3 left = trace::Terrain({camera_pos, geo::Ray3(camera_pos, look_left).Cast(128.0f)});
    geo::Vec3 right = trace::Terrain({camera_pos, geo::Ray3(camera_pos, look_right).Cast(128.0f)});

    // Check if we hit a wall, if we have, return closer
    float distto_left = geo::Distance(camera_pos, left);
    float distto_right = geo::Distance(camera_pos, right);
    if (std::abs(distto_left - distto_right) > 2)
        return (distto_left > distto_right) ? Edge::kRight
                                            : Edge::kLeft;

    // Now we go forward and check if we hit something there
    distto_left = geo::Distance(camera_pos, trace::Terrain({camera_pos, geo::Ray3(left, geo::Angle2(0.0f, camera_ang.y)).Cast(256.0f)}));
    distto_right = geo::Distance(camera_pos, trace::Terrain({camera_pos, geo::Ray3(right, geo::Angle2(0, camera_ang.y)).Cast(256.0f)}));
    if (std::abs(distto_left - distto_right) > 4)
        return (distto_left > distto_right) ? Edge::kRight : Edge::kLeft;
    return Edge::kNone;
}

unsigned int AASafeTicks = 0;

void WorldTick() {

    if (!ui::enabled) return;

    if (AASafeTicks) {
        AASafeTicks--;
        return;
    }

    // Get our local ents angles
    LocalPlayer* local_ent = Entity::GetLocalPlayer();
    if (!local_ent || local_ent->IsDormant() || !local_ent->IsAlive()) return;
    geo::Angle2 angles = local_ent->GetCameraAngle();

    // Check if can aa
    if (!module::ShouldAA()) return;

    // Pitch
    switch (ui::aa_pitch) {
        case 1:  // FIXED
            angles.x = ui::aa_pitch_amt;
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
    switch (ui::aa_yaw) {
        case 1:  // FIXED
            angles.y = ui::aa_yaw_amt;
            break;
        case 2:  // FIXEDOFFSET
            angles.y += ui::aa_yaw_amt;
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
            cur_yaw += ui::aa_spin_amt;
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
    if (!ui::allow_unclamped) angles.Clamp();

    // Send it off to the races
    local_ent->SetSilentCameraAngle(angles);
}

// TODO, snapback/screenshot antiaim using framebuffers. 
// Use a longer time trying to do the anti aim, 
// then a split second to snap back and grab the screen
/*static void DrawTick() {

}*/

}  // namespace neko::features::antiaim

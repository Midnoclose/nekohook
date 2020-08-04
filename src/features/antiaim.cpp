
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

#include "framework/game.hpp"
#include "framework/input.hpp"
#include "framework/trace.hpp"
#include "framework/uservar.hpp"

#include "features/antiaim.hpp"

namespace neko::features::antiaim {

static uservar::StrEnum antiaim_menu({"Anti-Aim"});
static uservar::Bool enabled(antiaim_menu, "aa", false, "Enable Anti-Aim",
                          "Master Anti-Aim switch");
static uservar::StrEnum aa_pitch_enum({"OFF", "FIXED", "UP", "DOWN", "FAKEUP",
                              "FAKEDOWN", "FAKECENTER", "RANDOM", "BIGRANDOM",
                              "FLIP", "FAKEFLIP"});
static uservar::Enum aa_pitch(antiaim_menu, aa_pitch_enum, "aa_pitch", 0,
                           "AA Pitch Type",
                           "Type of anti-aim to use for pitch");
static uservar::StrEnum aa_yaw_enum({"OFF", "FIXED", "FIXEDOFFSET", "RANDOM",
                            "BIGRANDOM", "FLIP", "SPIN", "EDGE"});
static uservar::Enum aa_yaw(antiaim_menu, aa_yaw_enum, "aa_yaw", 0, "AA Yaw Type",
                         "Type of anti-aim to use for yaw");
static uservar::Float aa_pitch_amt(antiaim_menu, "aa_pitch_fixed", 0,
                                "AA Pitch Fixed", "Value for fixed anti-aim");
static uservar::Float aa_yaw_amt(antiaim_menu, "aa_yaw_fixed", 0, "AA Yaw Fixed",
                              "Value for fixed anti-aim");
static uservar::Float aa_spin_amt(antiaim_menu, "aa_spin_amt", 2.5f,
                               "AA Spin Speed", "How fast to spin to win");
static uservar::Bool allow_unclamped(
    antiaim_menu, "aa_unclamp", false, "AA UnClamped",
    "Allow UnClamped angles?\nThis is a very dangerous thing to enable if an "
    "anti-cheat is present!");

// TODO, antiaims are game specific, the ones we have here wont cut it

int AASafeTicks = 0;

void WorldTick() {
    if (AASafeTicks) {
        AASafeTicks--;
        return;
    }

    if (!enabled) return;

    // Get our local ents angles
    LocalPlayer* local_ent = Entity::GetLocalPlayer();
    if (!local_ent || local_ent->GetDormant() || !local_ent->GetAlive()) return;
    math::Angle angles = local_ent->GetCameraAngle();

    // Check if can aa
    if (!module::ShouldAA()) return;

    // Pitch
    switch (aa_pitch) {
        case 1:  // FIXED
            angles.x = aa_pitch_amt;
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
            angles.x = math::RandFloatRange(-89.0f, 89.0f);
            break;
        case 9:  // BIGRANDOM
            angles.x = math::RandFloatRange(-65536.0f, 65536.0f);
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
    switch (aa_yaw) {
        case 1:  // FIXED
            angles.y = aa_yaw_amt;
            break;
        case 2:  // FIXEDOFFSET
            angles.y += aa_yaw_amt;
            break;
        case 3:  // RANDOM
            angles.y = math::RandFloatRange(-180.0f, 180.0f);
            break;
        case 4:  // BIGRANDOM
            angles.y = math::RandFloatRange(-65536.0f, 65536.0f);
            break;
        case 5:  // FLIP
            static bool flip;
            angles.y += flip ? -90 : 90;
            flip = !flip;
            break;
        case 6:  // SPIN
            static float cur_yaw;
            cur_yaw += aa_spin_amt;
            while (cur_yaw > 180)  // Clamping :joy:
                cur_yaw -= 360;
            while (cur_yaw < -180) cur_yaw += 360;
            angles.y = cur_yaw;
            break;
        case 7: {  // EDGE
            // TODO, fix the psudo code!
            // With edge, we need to trace until we hit walls basicly
            // Here we use a lambda to make getting the result angle easy!
            enum class EdgeState{ kNone, kLeft, kRight };
            auto edge_angle = [&]() -> auto {
                math::Angle camera_ang = local_ent->GetCameraAngle();
                math::Vector camera_pos = local_ent->GetCameraPos();
                // Get some angles facing different directions
                math::Angle look_left(0, camera_ang.y + 90);
                math::Angle look_right(0, camera_ang.y - 90);
                look_left.Clamp();
                look_right.Clamp();
                // First we go out to the left and right
                math::Vector left = trace::Terrain(camera_pos,
                                      look_left.ExtendLine(camera_pos, 128));
                math::Vector right = trace::Terrain(
                    camera_pos, look_right.ExtendLine(camera_pos, 128));
                // Check if we hit a wall, if we have, return closer
                float distto_left = camera_pos.DistTo(left);
                float distto_right = camera_pos.DistTo(right);
                if (std::abs(distto_left - distto_right) > 2)
                    return (distto_left > distto_right) ? EdgeState::kRight
                                                        : EdgeState::kLeft;
                // Now we go forward and check if we hit something there
                distto_left = camera_pos.DistTo(trace::Terrain(
                    camera_pos,
                    math::Angle(0, camera_ang.y).ExtendLine(left, 256)));
                distto_right = camera_pos.DistTo(trace::Terrain(
                    camera_pos,
                    math::Angle(0, camera_ang.y).ExtendLine(right, 256)));
                if (std::abs(distto_left - distto_right) > 4)
                    return (distto_left > distto_right) ? EdgeState::kRight
                                                        : EdgeState::kLeft;
                // If we havent hit anything, then we return none
                return EdgeState::kNone;
            }
            ();
            if (edge_angle != EdgeState::kNone) {
                // Pitch can affect how our head is behind walls, so we fix that
                // here we also clamp so we edge where our real head is
                float pitch = angles.x;
                while (pitch > 89)  // Clamping :joy:
                    pitch -= 180;
                while (pitch < -89) pitch += 180;
                if (pitch < 0) {
                    if (edge_angle == EdgeState::kLeft)
                        edge_angle = EdgeState::kRight;
                    else
                        edge_angle = EdgeState::kLeft;
                }
                // Do the edge dance
                if (edge_angle == EdgeState::kLeft)
                    angles.y += 90;
                else
                    angles.y -= 90;
            }
        }
    }

    // Clamp Finished angles
    if (!allow_unclamped) angles.Clamp();

    // Send it off to the races
    local_ent->SetSilentCameraAngle(angles);
}

// TODO, snapback/screenshot antiaim
// Take screenshot using original angles, then snap to the fake or whatever, and
// display the screenshot after about .5-1.5 seconds snap back and continue.
// USECASE: when you dont have actual silent

/*static void DrawTick() {

}*/

}  // namespace features::antiaim

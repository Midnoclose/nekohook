
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

#include <neko/chrono.hpp>

#include "framework/trace.hpp"  // so we can vis check

#include "features/aimbot.hpp"

namespace neko::features::aimbot {

// TODO, shove everything into lambdas to save cycles?

std::initializer_list<std::string_view> aimbot_menu(
    {"Aimbot"});  // Menu locator for esp settings
static uservar::Bool enabled(aimbot_menu, "ab", true, "Enable Aimbot",
                             "Main aimbot switch");
// Target Selection
static std::initializer_list<std::string_view> priority_mode_enum(
    {"SMART", "FOV", "DISTANCE", "HEALTH"});
static uservar::Enum priority_mode(
    aimbot_menu, priority_mode_enum, "ab_prioritymode", 1, "Priority mode",
    "Priority mode.\nSMART: Basically Auto-Threat.\nFOV, DISTANCE, HEALTH are "
    "self-explainable.\nHEALTH picks the weakest enemy");
static uservar::Float fov(aimbot_menu, "ab_fov", 0, "Aimbot FOV",
                          "FOV range for aimbot to lock targets.", 180.0f);
static std::initializer_list<std::string_view> teammates_enum({"ENEMY ONLY",
                                                               "TEAMMATE ONLY",
                                                               "BOTH"});
static uservar::Enum teammates(aimbot_menu, teammates_enum, "ab_teammates", 0,
                               "Teammates",
                               "Use to choose which team/s to target");
static uservar::Bool target_lock(
    aimbot_menu, "ab_targetlock", false, "Target lock",
    "Once aimbot finds a target, it will continue to use that target untill "
    "that target is no longer valid");
// Aiming
static uservar::Key aimkey(
    aimbot_menu, "ab_aimkey", input::Key::kE, "Aimkey",
    "If an aimkey is set, aimbot only works while key is depressed.");
static uservar::Bool autoshoot(aimbot_menu, "ab_autoshoot", true, "Auto-shoot",
                               "Automaticly shoots when it can");
static uservar::Enum hitbox_mode_enum();
static uservar::Enum hitbox_mode(
    aimbot_menu, {"AUTO", "AUTO-HEAD", "AUTO-CLOSEST",
                  "HEAD", "CENTER"}, "ab_hitbox_mode", 0, "Hitbox Mode",
    "Hitbox selection mode\n"
    "AUTO: Automaticly chooses best hitbox\n"
    "AUTO-HEAD: Head is first priority, but will aim anywhere else if not "
    "possible\n"
    "AUTO-CLOSEST: Aims to the closest hitbox to your crosshair\n"
    "HEAD: Head only\n"
    "CENTER: Aims directly in the center of the entity");
static uservar::Int smooth_aim(aimbot_menu, "ab_smooth", 0, "Smooth Aim",
                               "Smooths the aimbot");
static std::initializer_list<std::string_view> silent_aim_enum({"OFF",
                                                                "SNAPBACK",
                                                                "MODULE"});
static uservar::Enum silent_aim(
    aimbot_menu, silent_aim_enum, "ab_silent", 0, "Silent aimbot",
    "SNAPBACK: Snaps the aimbot back after aiming\n"
    "MODULE: Uses the modules own version of silent, if any");
static uservar::Int silent_snaptime(
    aimbot_menu, "ab_silent_snaptime", 100, "Silent snaptime",
    "Amount of time in milliseconds to hold the snap", 1000);
uservar::Int multipoint(aimbot_menu, "ab_multipoint", 0, "Multipoint",
                        "Amount of boxes to check, 0 = off\n NOTE: THIS IS "
                        "EXTREMELY INTENSIVE, USE ONLY WHAT YOU NEED!",
                        5);
uservar::Int multipoint_ratio(
    aimbot_menu, "ab_multipoint_ratio", 86, "Multipoint Ratio",
    "Some games might have crappier lag comp than others, this shrinks the "
    "hitbox to correct for that.",
    100);
static uservar::Bool can_shoot(
    aimbot_menu, "ab_canshoot", true, "Can Shoot check",
    "Aimbot will only aim when the weapon can shoot\nDoesnt work well with "
    "legit configs if using weapons that shoot rappidly\nNEEDS MODULE SUPPORT");

// Hitbox selection

// Somewhere to store the auto-hitbox function
//math::Vector GetAutoHitbox(Entity*) { return RetrieveAimpoint(entity, 3); };

// Cache
LocalPlayer* local_ent = nullptr;

// A function to find a place to aim for on the target
static math::Vector RetrieveAimpoint(Entity* entity, int mode = hitbox_mode) {

    // A simple multi-point function, call it when you get bone center to get a
    // point that hits. This does tracing for you. First in pair is if it could
    // get bone, second is if it could find a point set trace to true if you
    // want it tracing first point if multipoint is disabled
    // TODO: find a better way to impliment other than using as a drop-in for
    // GetBone
    auto GetMultiBone = [&](Entity::BonePos bone_id, math::Vector& out,
                            math::Vector camera_pos = local_ent->GetCameraPos(),
                            bool trace = false) -> std::pair<bool, bool> {

        // Normal bone stuff
        Entity::Hitbox tmp_bone;
        if (!entity->GetHitbox(bone_id, tmp_bone))
            return {false, false};

        // If we arent using multi-point and we arent tracing first, we can just
        // return it
        math::Vector center = tmp_bone.GetCenter();
        if ((!multipoint && !trace) || trace::Entity(entity, camera_pos, center, local_ent)) {
            out = center;
            return {true, true};
        }

        // First we shrink the box to try to avoid latency issues, we do this
        // once to save the little cycles we have then we devide that by how
        // many times we will recurse to get the ratio
        // TODO, use a double?
        math::Box ratio =
            (tmp_bone * ((float)multipoint_ratio * 0.01)) / multipoint;
        for (int i = 1; i <= multipoint; i++) {
            // then we multiply it using the ratio to expand the point back to
            // the size we want to check
            math::Box expanded = ratio * i;
            // Try to find a point that fits
            for (const math::Vector ii : expanded.GetPoints()) {
                if (trace::Entity(entity, camera_pos, ii, local_ent)) {
                    out = ii;
                    return {true, true};
                }
            }
        }

        // We didnt get any points ;( but we can still return the first, which
        // is already set, and return trace as false
        return {true, false};
    };

    // Get our best bone
    switch (mode) {
        case 0: {  // AUTO
            return module::GetAutoHitbox(entity);
        }
        case 1: {  // AUTO-HEAD
            // Head is first bone, should be fine to iterate through them
            math::Vector camera_pos = local_ent->GetCameraPos();
            for (int i = 0; i < static_cast<int>(Entity::BonePos::kCount);
                 i++) {
                // Get our bone
                math::Vector tmp;
                if (GetMultiBone(static_cast<Entity::BonePos>(i), tmp,
                                 camera_pos, true).second)
                    return tmp;
            }
            break;
        }
        case 2: {  // AUTO-CLOSEST
            // We need this for fov checks
            math::Angle camera_ang = local_ent->GetCameraAngle();
            math::Vector camera_pos = local_ent->GetCameraPos();
            // Book-keepers for the best one we have found
            math::Vector closest;
            float closest_fov = 361;
            for (int i = 0; i < static_cast<int>(Entity::BonePos::kCount); i++) {
                // Get our bone
                math::Vector tmp;
                if (!GetMultiBone(static_cast<Entity::BonePos>(i), tmp, camera_pos).first)
                    continue;
                // Get FOV
                float fov = math::Angle::GetFov(camera_ang, camera_pos, tmp);
                // Check if fov is lower than our current best
                if (fov > closest_fov) continue;
                // Vis check
                if (!trace::Entity(entity, camera_pos, tmp, local_ent)) continue;
                // Set the new current best
                closest = tmp;
                closest_fov = fov;
            }
            // Check if we have anything set, then return if true
            if (closest_fov != 361) return closest;
            break;
        }
        case 3: {  // HEAD
            math::Vector tmp;
            if (GetMultiBone(Entity::BonePos::kHead, tmp).first)
                return tmp;  // if we couldnt get a bone, we let collision take
                             // over
            break;
        }
    }

    // Center fallback, uses center of collision bo
    math::Box coll;
    if (entity->GetCollision(coll))
        return coll.GetCenter();

    // Without anything else, all we can use is the origin
    math::Vector origin;
    return entity->GetOrigin(origin) ? origin : math::Vector();
}

// Target Selection

// For modules to add their target selection stuff
//bool(CatEntity*) > TargetSelection{[](auto) { return true; }};

// A second check to determine whether a target is good enough to be aimed at
// passes true if good, and the aimpoint to prevent retrieving it again
static std::pair<bool, math::Vector> IsTargetGood(Entity* entity) {

    std::pair<bool, math::Vector> ret = {false, math::Vector()};
    if (!entity || entity->GetDormant()) return ret;

    // Local player check
    if (local_ent == entity) return ret;

    // Type
    Entity::Type type = entity->GetType();
    if (type != Entity::Type::kPlayer && type != Entity::Type::kOtherHostile)
        return ret;

    // Dead
    if (!entity->GetAlive()) return ret;

    // Teammates
    bool team = entity->GetEnemy();
    if (teammates != 2 && ((teammates == 0) ? !team : team)) return ret;

    // Do the custom stuff
    if (!module::TargetSelection(entity)) return ret;

    // Get our best Aimpoint
    math::Vector aimpoint = RetrieveAimpoint(entity);

    // Fov check
    math::Vector camera_pos = local_ent->GetCameraPos();
    if (fov > 0.0f &&
        math::Angle::GetFov(local_ent->GetCameraAngle(), camera_pos, aimpoint) > fov)
        return ret;

    // Vis check
    if (!trace::Entity(entity, camera_pos, aimpoint, local_ent)) return ret;

    // Hey look! Target passed all checks
    return {true, aimpoint};
}

static Entity* last_target = nullptr;  // for target lock
// Function to find a suitable target
static std::pair<Entity*, math::Vector> RetrieveBestTarget() {

    // If target lock is enabled, check last entity.
    if (target_lock && last_target) {
        auto tmp = IsTargetGood(last_target);
        if (tmp.first) return {last_target, tmp.second};
    }

    // Book keepers for highest target
    std::pair<Entity*, math::Vector> ret;
    float highest_score = 0;

    math::Vector camera_pos = local_ent->GetCameraPos();
    math::Angle camera_ang = local_ent->GetCameraAngle();

    // Loop through all entitys
    int ent_count = Entity::GetCount();
    for (int i = 0; i < ent_count; i++) {
        Entity* entity = Entity::Get(i);
        auto tmp = IsTargetGood(entity);
        if (!tmp.first) continue;

        // Get score based on priority mode
        float score = 0;
        switch (priority_mode) {
            case 0:  // SMART Priority
                     // score = 0; break; // TODO, fix
            case 1:  // Fov Priority
                score = 180.0f - math::Angle::GetFov(camera_ang, camera_pos, tmp.second);
                break;
            case 2:  // Distance priority
                score = 4096.0f - entity->GetDistance();
                break;
            case 3:  // Health Priority
                score = 1024.0f - entity->GetHealth();
        }

        // Compare the top score to our current ents score
        if (score > highest_score) {
            ret = {entity, tmp.second};
            highest_score = score;
        }
    }

    return ret;
}

//cat::Function<bool(CatEntity*)> ShouldAimModule{[](auto) { return true; }};

// A check to determine whether the local player should aimbot
static bool ShouldAim() {

    // Alive check
    if (!local_ent->GetAlive()) return false;
    // Aimkey
    if (!aimkey.Depressed()) return false;

    if (!module::ShouldAim(local_ent)) return false;

    return true;
}

// Externed entity to highlight color
Entity* highlight_target = nullptr;

// Snapback Silent Info
enum SbState { kIdle, kInSnap, kTimeout };
SbState sb_state;
static math::Angle sb_delta;
static Timer sb_time;

// The main "loop" of the aimbot.
void WorldTick() {
    // Main enabled check
    if (!enabled) {
        last_target = nullptr;
        highlight_target = nullptr;
        return;
    }

    // Get local ent for use below
    local_ent = Entity::GetLocalPlayer();
    if (!local_ent || local_ent->GetDormant()) {
        last_target = nullptr;
        highlight_target = nullptr;
        return;
    }


    // Return for snapback
    auto preRet = [&]() {
        if (silent_aim == 1) {
            if (sb_state == SbState::kInSnap) {
                math::Angle old_angle =
                    local_ent->GetCameraAngle() + sb_delta;
                local_ent->SetCameraAngle(old_angle.Clamp());
            }
            sb_state = SbState::kIdle;
        }
        last_target = nullptr;
    };

    // Attempt to get a target and test if it exist
    auto target = RetrieveBestTarget();
    highlight_target = target.first;
    if (!target.first) {
        preRet();
        return;
    }

    // Check if our local player is ready to aimbot
    if (!ShouldAim()) {
        preRet();
        return;
    }

    // Get camera so we wont need to again
    const math::Angle camera_ang = local_ent->GetCameraAngle();

    // Snapback Time Reset
    if (silent_aim == 1 && sb_state) {
        if (sb_state == SbState::kInSnap &&
            sb_time.ResetAfter(
                std::chrono::milliseconds(silent_snaptime))) {
            math::Angle old_angle = camera_ang + sb_delta;
            local_ent->SetCameraAngle(old_angle.Clamp());
            sb_state = SbState::kIdle;
        }
        return;
    }

    // Set our last target
    last_target = target.first;

    // Do smoothaim
    if (smooth_aim > 0) {
        // TODO, Smooth is only somewhat fixed, it still needs a change to fix
        // the crossing of the y axis (-180, 180)

        math::Vector camera_pos = local_ent->GetCameraPos();
        math::Angle angles = math::Angle::VectorAngles(camera_pos, target.second);
        math::Angle delta = camera_ang.GetDiff(angles);

        // Pitch, If our camera pitch is more than our target pitch, we should
        // add to lower that value, and vise versa for camera being lower
        float p_move_ammt = delta.x / pow(smooth_aim, 1.5);
        angles.x = (camera_ang.x > angles.x) ? (camera_ang.x - p_move_ammt)
                                             : (camera_ang.x + p_move_ammt);

        // Yaw, same as above but If we go across -180 to 180, we do some
        // changes
        float y_move_ammt = delta.y / pow(smooth_aim, 1.5);
        angles.y =
            (camera_ang.y > angles.y || (camera_ang.y < -90 && angles.y > 90))
                ? (camera_ang.y - y_move_ammt)
                : (camera_ang.y + y_move_ammt);

        // Aim here as silent wont work with smooth
        local_ent->SetCameraAngle(angles.Clamp());

        // Slowaim Autoshoot, basicly we recreate an extremly simple triggerbot
        // here
        if (autoshoot) {
            // The further the terget gets from us, we want to make the allowed
            // fov lower
            if (math::Angle::GetFov(camera_ang, camera_pos, target.second) -
                    camera_pos.DistTo(target.second) / 32 <
                5)
                local_ent->Attack();
        }
    } else {
        // Autoshoot
        if (autoshoot) local_ent->Attack();
        // Check weapon time, we only want to aim when the weapon can shoot
        if (!module::CanShoot(local_ent)) return;
        // Get angles and Aim at player
        math::Angle aim_angles =
            math::Angle::VectorAngles(local_ent->GetCameraPos(), target.second);
        switch (silent_aim) {
            case 0:  // OFF
                local_ent->SetCameraAngle(aim_angles);
                break;
            case 1: {  // SNAPBACK
                // Setup the snap
                if (sb_state == SbState::kIdle) {
                    sb_state = SbState::kInSnap;
                    sb_delta =
                        camera_ang - aim_angles;  // we use a delta in case
                                                  // player looks around
                    sb_time.Reset();
                }
                // Set angles
                local_ent->SetCameraAngle(aim_angles);
                break;
            }
            case 2:  // MODULE
                local_ent->SetSilentCameraAngle(aim_angles);
                break;
        }
    }
}

}  // namespace neko::features::aimbot

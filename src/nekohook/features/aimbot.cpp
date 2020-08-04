
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

#include "util/chrono.hpp"
#include "ui/settings/bool.hpp"
#include "ui/settings/enum.hpp"
#include "ui/settings/math.hpp"
#include "game/trace.hpp"  // so we can vis check

#include "features/aimbot.hpp"

namespace nekohook::features::aimbot {

namespace stng {
using namespace setting;
TreeMap menu({"Aimbot"});

static Bool enabled(menu, "Enabled", false);
static StrEnum priority_mode_e({"SMART", "FOV", "DISTANCE", "HEALTH"});
static Enum priority_mode(menu, priority_mode_e, "Priority Mode", 1);
static Float fov(menu, "FOV", 180.0f);
static Enum teammates(menu, {"ENEMY ONLY", "TEAMMATE ONLY", "BOTH"}, "ab_teammates", 0);
static Bool target_lock(menu, "Target lock", false);
//static Key aimkey(menu, "Aimkey", input::Key::kE);
static Bool autoshoot(menu, "Auto shoot", true);
static StrEnum hitbox_mode_e({"AUTO", "AUTO-HEAD", "AUTO-CLOSEST", "HEAD", "CENTER"});
static Enum hitbox_mode(menu, hitbox_mode_e, "Hitbox Mode", 0);
static Int smooth_aim(menu, "Smooth", 0);
static StrEnum silent_aim_e({"OFF", "SNAPBACK", "MODULE"});
static Enum silent_aim(menu, silent_aim_e, "Silent", 0);
static Int silent_snaptime(menu, "Silent snaptime", 100, 1000);
Int multipoint(menu, "Multipoint", 0, 5);
Float multipoint_ratio(menu, "Multipoint Ratio", 86, 1, 100);
static Bool can_shoot(menu, "Can Shoot", true);
}

static std::vector<Entity::Hitbox> GetMultiBoxes(const Entity::Hitbox& hitbox) {
    math::Box<math::DVec3> ratio = {hitbox.min, hitbox.max};
    ratio /= multipoint_ratio;

    std::vector<Entity::Hitbox> ret;
    ret.reserve(multipoint);
    for (int i = 1; i <= multipoint; i++) // should we use <= or <
        ret.emplace_back(ratio * i);
    return ret;
}

static std::vector<math::Vec3> GetMultiPoints(const Entity::Hitbox& hitbox) {
    std::vector<Entity::Hitbox> boxes = GetMultiBoxes(hitbox);

    std::vector<math::Vec3> ret;
    ret.reserve(boxes.size() * 8);
    for (const auto& i : boxes) // should we use <= or <
        for (auto ii : i.GetPoints())
            ret.emplace_back(ii);
    return ret;
}

static std::vector<math::Vec3> GetVisibleMultipoints(LocalPlayer* local_ent,
        Entity* entity, const math::Vec3& start_pos,
        const Entity::Hitbox& hitbox) {
    std::vector<math::Vec3> points = GetMultiPoints(hitbox);

    std::vector<math::Vec3> visible;
    visible.reserve(points.size() + 1);
    math::Vec3 center = hitbox.GetCenter();
    if (trace::Entity(entity, start_pos, center, local_ent))
        visible.emplace_back(center);

    for (const math::Vec3& i : points)
        if (trace::Entity(entity, start_pos, i, local_ent))
            visible.emplace_back(i);
    return visible;
}

static std::vector<math::Vec3> GetVisibleMultipoints(LocalPlayer* local_ent,
        Entity* entity, const math::Vec3& start_pos, Entity::BonePos pos) {
    std::optional<Entity::Hitbox> hitbox;
    if ((hitbox = entity->GetHitbox(pos)))
        return GetVisibleMultipoints(local_ent, entity, start_pos, *hitbox);
    return {};
}

static std::optional<math::Vec3> GetVisible(LocalPlayer* local_ent,
        Entity* entity, const math::Vec3& start_pos, const Entity::Hitbox& hitbox) {
    if (multipoint) {
        std::vector<math::Vec3> points = GetVisibleMultipoints(
                local_ent, entity, start_pos, hitbox);
        if (!points.empty())
            return points[0];
    } else {
        math::Vec3 center = hitbox.GetCenter();
        if (trace::Entity(entity, start_pos, center, local_ent))
            return center;
    }

    return std::nullopt;
}

static std::optional<math::Vec3> GetVisible(LocalPlayer* local_ent,
        Entity* entity, const math::Vec3& start_pos, Entity::BonePos pos) {
    std::optional<Entity::Hitbox> hitbox;
    if ((hitbox = entity->GetHitbox(pos)))
        return GetVisible(local_ent, entity, start_pos, *hitbox);
    return std::nullopt;
}

// A function to find a place to aim for on the target
static std::optional<math::Vec3> RetrieveAimpoint(LocalPlayer* local_ent,
        Entity* entity, const math::Vec3& camera_pos,
        const math::Angle& camera_ang) {

    // Get our best bone
    switch (stng::hitbox_mode) {
        case 0: {  // AUTO
            return module::GetAutoHitbox(entity);
        }
        case 1: {  // AUTO-HEAD
            // Head is first bone, should be fine to iterate through them
            std::optional<math::Vec3> bone;
            for (int i = 0; i < Entity::BonePos::kCount; i++)
                if ((bone = GetVisible(local_ent, entity, camera_pos, Entity::BonePos(i))))
                    return bone;
            break;
        }
        case 2: {  // AUTO-CLOSEST
            math::Vec3 closest;
            float closest_fov = 361;
            if (!multipoint) {
                for (int i = 0; i < Entity::BonePos::kCount; i++) {
                    std::optional<math::Vec3> bone;
                    if ((bone = GetVisible(local_ent, entity, camera_pos, Entity::BonePos(i))))
                        continue;

                    float fov = camera_ang.GetFov(camera_pos, *bone);
                    if (fov > closest_fov) continue;

                    closest = *bone;
                    closest_fov = fov;
                }
            } else {
                for (int i = 0; i < Entity::BonePos::kCount; i++) {
                    for (const math::Vec3& ii: GetVisibleMultipoints(local_ent,
                            entity, camera_pos, Entity::BonePos(i))) {
                        float fov = camera_ang.GetFov(camera_pos, ii);
                        if (fov > closest_fov) continue;

                        closest = ii;
                        closest_fov = fov;
                    }
                }
            }
            if (closest_fov != 361)
                return closest;
            break;
        }
        case 3: {  // HEAD
            std::optional<math::Vec3> head;
            if ((head = GetVisible(local_ent, entity, camera_pos, Entity::BonePos::kHead)))
                return head;
            break;
        }
    }

    // TODO: multi-point this? add ui option?
    if (std::optional<Entity::Hitbox> coll = entity->GetCollision()) {
        math::Vec3 center = coll.value().GetCenter();
        if (trace::Entity(entity, camera_pos, center, local_ent))
            return center;
    } else if (std::optional<math::Vec3> origin = entity->GetOrigin())
        if (trace::Entity(entity, camera_pos, *origin, local_ent))
            return origin;

    return std::nullopt;
}

static Entity* last_target = nullptr;
static std::pair<Entity*, math::Vec3> RetrieveBestTarget(LocalPlayer* local_ent,
            const math::Vec3& camera_pos, const math::Angle& camera_ang) {

    auto IsTargetable = [&](Entity* entity) -> std::optional<math::Vec3> {

        if (!entity || entity->IsDormant()) return std::nullopt;
        if (local_ent == entity) return std::nullopt;

        Entity::Type type = entity->GetType();
        if (type != Entity::Type::kPlayer && type != Entity::Type::kOtherHostile) return std::nullopt;
        if (!entity->IsAlive()) return std::nullopt;

        bool team = entity->IsEnemy();
        if (stng::teammates != 2 && ((stng::teammates == 0) ? !team : team)) return std::nullopt;
        if (!module::TargetSelection(entity)) return std::nullopt;

        std::optional<math::Vec3> aimpoint;
        if (!(aimpoint = RetrieveAimpoint(local_ent, entity, camera_pos, camera_ang)))
            return std::nullopt;

        if (stng::fov && camera_ang.GetFov(camera_pos, *aimpoint) > stng::fov)
            return std::nullopt;

        if (trace::Entity(entity, camera_pos, *aimpoint, local_ent))
            return aimpoint;
        return std::nullopt;
    };

    if (stng::target_lock && last_target) {
        std::optional<math::Vec3> aimpoint = IsTargetable(last_target);
        if (aimpoint)
            return {last_target, *aimpoint};
    }

    // Book keepers for highest target
    std::pair<Entity*, math::Vec3> highest_ent = {nullptr, {}};
    float highest_score = 0;

    int ent_count = Entity::GetCount();
    for (int i = 0; i < ent_count; i++) {
        Entity* entity = Entity::Get(i);
        std::optional<math::Vec3> aimpoint = IsTargetable(entity);
        if (!aimpoint) continue;

        // Get score based on priority mode
        float score = 0;
        switch (stng::priority_mode) {
            case 0:  // SMART Priority
                     // score = 0; break; // TODO
            case 1:  // Fov Priority
                score = 180.0f - camera_ang.GetFov(camera_pos, *aimpoint);
                break;
            case 2:  // Distance priority
                score = 4096.0f - entity->GetDistance();
                break;
            case 3:  // Health Priority
                score = 1024.0f - entity->GetHealth();
        }

        // Compare the top score to our current ents score
        if (score > highest_score) {
            highest_ent = {entity, *aimpoint};
            highest_score = score;
        }
    }

    return highest_ent;
}

// Externed entity to highlight color
Entity* highlight_target = nullptr;

// Snapback Silent System
class Snapback {
    enum class State {
        kIdle, // Nothing going on
        kAiming, // Aimbot activated
        kTimeout // Aimed for long enough, snapped back and waiting.
    };
    static inline State state;
    static inline math::Angle delta;
    static inline Timer<> time;
    static void GetDelta(const math::Angle& cur_ang, const math::Angle& wanted_ang) {
        assert(state != State::kAiming);
        delta = cur_ang - wanted_ang;
    }
    static void ReturnDelta(LocalPlayer* local_ent,
            const math::Angle& camera_ang) {
        assert(state == State::kAiming);
        math::Angle old_angle = local_ent->GetCameraAngle() + delta;
        local_ent->SetCameraAngle(old_angle.Clamp());
    }
public:
    static void Reset(LocalPlayer* local_ent, const math::Angle& camera_ang) {
        if (state == State::kAiming)
            ReturnDelta(local_ent, camera_ang);
        state = State::kIdle;
    }
    static bool Timeout(LocalPlayer* local_ent, const math::Angle& camera_ang) {
        switch (state) {
        case State::kAiming:
            if (time.ResetCheck(std::chrono::milliseconds(stng::silent_snaptime))) {
                ReturnDelta(local_ent, camera_ang);
                state = State::kIdle;
            }
        case State::kTimeout:
            return true;
        case State::kIdle:
            return false; 
        default:
            assert(false);
            return false;
        }
    }
    static void SetupSnap(LocalPlayer* local_ent, const math::Angle& camera_ang,
            const math::Angle& aim_ang) {
        if (state == State::kIdle) {
            GetDelta(camera_ang, aim_ang);
            time.Reset();
        }
        local_ent->SetCameraAngle(aim_ang);
        state = State::kAiming;
    }
};


// The main "loop" of the aimbot.
void WorldTick() {

    auto PreRet1 = [&]() {
        last_target = nullptr;
        highlight_target = nullptr;
    };
    #define ClearRet() ({PreRet1(); return;})

    if (!stng::enabled)
        ClearRet();

    LocalPlayer* local_ent = Entity::GetLocalPlayer();
    if (!local_ent || local_ent->IsDormant() || !local_ent->IsAlive())
        ClearRet();
    
    const math::Vec3 camera_pos = local_ent->GetCameraPosition();
    const math::Angle camera_ang = local_ent->GetCameraAngle();
    
    auto PreRet2 = [&]() {
        if (stng::silent_aim == 1) // Redundant?
            Snapback::Reset(local_ent, camera_ang);
        last_target = nullptr;
    };
    #undef ClearRet
    #define ClearRet() ({PreRet2(); return;})

    auto [target, aimpoint] = RetrieveBestTarget(local_ent, camera_pos, camera_ang);
    if (!target)
        ClearRet();

    highlight_target = target;

    if (/*!aimkey.Depressed() ||*/ !module::ShouldAim(local_ent))
        ClearRet();

    #undef ClearRet
    if (stng::silent_aim == 1 && Snapback::Timeout(local_ent, camera_ang))
        return;

    last_target = target;

    // Do smoothaim
    if (stng::smooth_aim > 0) {
        // TODO, Smooth is only somewhat fixed, it still needs a change to fix
        // the crossing of the y axis (-180, 180)

        math::Angle angles = math::Angle::PointTo(camera_pos, aimpoint);
        math::Angle delta = camera_ang.GetDelta(angles);

        // Pitch, If our camera pitch is more than our target pitch, we should
        // add to lower that value, and vise versa for camera being lower
        float p_move_ammt = delta.x / pow(stng::smooth_aim, 1.5);
        angles.x = (camera_ang.x > angles.x) ? (camera_ang.x - p_move_ammt)
                                             : (camera_ang.x + p_move_ammt);

        // Yaw, same as above but If we go across -180 to 180, we do some
        // changes
        float y_move_ammt = delta.y / pow(stng::smooth_aim, 1.5);
        angles.y =
            (camera_ang.y > angles.y || (camera_ang.y < -90 && angles.y > 90))
                ? (camera_ang.y - y_move_ammt)
                : (camera_ang.y + y_move_ammt);

        // Aim here as silent wont work with smooth
        local_ent->SetCameraAngle(angles.Clamp());

        // Slowaim Autoshoot, basicly we recreate an extremly simple triggerbot
        // here
        // FIXME
        if (stng::autoshoot) {
            // The further the terget gets from us, we want to make the allowed
            // fov lower
            if (camera_ang.GetFov(camera_pos, aimpoint) -
                    math::Distance(camera_pos, aimpoint) / 32 < 5)
                local_ent->Attack();
        }
    } else {
        // Autoshoot
        if (stng::autoshoot) local_ent->Attack();
        // Check weapon time, we only want to aim when the weapon can shoot
        if (!module::CanShoot(local_ent)) return;
        // Get angles and Aim at player
        math::Angle aim_angles = math::Angle::PointTo(camera_pos, aimpoint);
        switch (stng::silent_aim) {
            case 0:  // OFF
                local_ent->SetCameraAngle(aim_angles);
                break;
            case 1: {  // SNAPBACK
                // Setup the snap
                Snapback::SetupSnap(local_ent, camera_ang, aim_angles);
                break;
            }
            case 2:  // MODULE
                local_ent->SetSilentCameraAngle(aim_angles);
                break;
        }
    }
}

}  // namespace neko::features::aimbot

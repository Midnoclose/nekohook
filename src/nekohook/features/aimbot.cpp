
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

#include "nekohook/util/chrono.hpp"
#include "nekohook/ui/var.hpp"
#include "nekohook/game/trace.hpp"  // so we can vis check

#include "aimbot.hpp"

namespace nekohook::features::aimbot {
namespace ui {
using namespace nekohook::ui;
TreeMap menu({"Aimbot"});

static Var<bool> enabled(menu, "Enabled", false);
static Var<Enum> priority_mode(menu, "Priority Mode", 1, {
    "SMART", "FOV", "DISTANCE", "HEALTH"});
static Var<float> fov(menu, "FOV", 180.0f, 360.0f);
static Var<float> max_distance(menu, "Max Distance", 8192.0f);
static Var<Enum> teammates(menu, "ab_teammates", 0, {
    "ENEMY ONLY", "TEAMMATE ONLY", "BOTH"});
static Var<bool> target_lock(menu, "Target lock", false);
//static Key aimkey(menu, "Aimkey", input::Key::kE);
static Var<bool> autoshoot(menu, "Auto shoot", true);
static Enum hitbox_mode_e();
static Var<Enum> hitbox_mode(menu, "Hitbox Mode", 0, {
    "AUTO", "AUTO-HEAD", "AUTO-CLOSEST", "HEAD", "CENTER"});
static Var<int> smooth_aim(menu, "Smooth", 0);
static Var<Enum> silent_aim(menu, "Silent", 0, {"OFF", "SNAPBACK", "MODULE"});
static Var<int> silent_snaptime(menu, "Silent snaptime", 100, 1000);
Var<int> multipoint(menu, "Multipoint", 0, 5);
Var<float> multipoint_ratio(menu, "Multipoint Ratio", 86, 1, 100);
static Var<bool> can_shoot(menu, "Can Shoot", true);
}

// TODO: create seperate aimbot machines to push more optimizations using priority. big think

static std::vector<Entity::Hitbox> ScaleBox(const Box auto& hitbox, std::floating_point auto amt) {
    geo::Box auto ratio = hitbox /= ui::multipoint_ratio;
    
    std::vector<decltype(ratio)> scaled(ui::multipoint);
    for (auto& i : scaled) // should we use <= or <
        ret[i] = ratio * i;
    return ret;
}

static std::vector<geo::Vec3> GetMultiPoints(const Entity::Hitbox& hitbox) {
    std::vector<Entity::Hitbox> boxes = GetMultiBoxes(hitbox);

    std::vector<geo::Vec3> ret;
    ret.reserve(boxes.size() * 8);
    for (const auto& i : boxes) // should we use <= or <
        for (auto ii : i.GetPoints())
            ret.emplace_back(ii);
    return ret;
}

static std::vector<geo::Vec3> GetVisibleMultipoints(LocalPlayer* local_ent,
        Entity* entity, const geo::Vec3& start_pos,
        const Entity::Hitbox& hitbox) {
    std::vector<geo::Vec3> points = GetMultiPoints(hitbox);

    std::vector<geo::Vec3> visible;
    visible.reserve(points.size() + 1);
    Entity::Bone center = hitbox.GetCenter();
    if (trace::Entity(entity, {start_pos, center}, local_ent))
        visible.emplace_back(center);

    for (const geo::Vec3& i : points)
        if (trace::Entity(entity, {start_pos, i}, local_ent))
            visible.emplace_back(i);
    return visible;
}

static std::vector<geo::Vec3> GetVisibleMultipoints(LocalPlayer* local_ent,
        Entity* entity, const geo::Vec3& start_pos, Entity::BonePos pos) {
    std::optional<Entity::Hitbox> hitbox;
    if ((hitbox = entity->GetHitbox(pos)))
        return GetVisibleMultipoints(local_ent, entity, start_pos, *hitbox);
    return {};
}

static std::optional<geo::Vec3> GetVisible(LocalPlayer* local_ent,
        Entity* entity, const geo::Vec3& start_pos, const Entity::Hitbox& hitbox) {
    if (ui::multipoint) {
        std::vector<geo::Vec3> points = GetVisibleMultipoints(
                local_ent, entity, start_pos, hitbox);
        if (!points.empty())
            return points[0];
    } else {
        geo::Vec3 center = hitbox.GetCenter();
        if (trace::Entity(entity, {start_pos, center}, local_ent))
            return center;
    }

    return std::nullopt;
}

static std::optional<geo::Vec3> GetVisible(LocalPlayer* local_ent,
        Entity* entity, const geo::Vec3& start_pos, Entity::BonePos pos) {
    std::optional<Entity::Hitbox> hitbox;
    if ((hitbox = entity->GetHitbox(pos)))
        return GetVisible(local_ent, entity, start_pos, *hitbox);
    return std::nullopt;
}

// A function to find a place to aim for on the target
static std::optional<geo::Vec3> RetrieveAimpoint(LocalPlayer* local_ent,
        Entity* entity, const geo::Vec3& camera_pos,
        const geo::Angle2& camera_ang) {

    // Get our best bone
    switch (ui::hitbox_mode) {
        case 0: {  // AUTO
            return module::GetAutoHitbox(entity);
        }
        case 1: {  // AUTO-HEAD
            // Head is first bone, should be fine to iterate through them
            std::optional<geo::Vec3> bone;
            for (int i = 0; i < Entity::BonePos::kCount; i++)
                if ((bone = GetVisible(local_ent, entity, camera_pos, Entity::BonePos(i))))
                    return bone;
            break;
        }
        case 2: {  // AUTO-CLOSEST
            geo::Vec3 closest;
            float closest_fov = 361;
            if (!ui::multipoint) {
                for (int i = 0; i < Entity::BonePos::kCount; i++) {
                    std::optional<geo::Vec3> bone;
                    if ((bone = GetVisible(local_ent, entity, camera_pos, Entity::BonePos(i))))
                        continue;

                    float fov = camera_ang.GetFov(camera_pos, *bone);
                    if (fov > closest_fov) continue;

                    closest = *bone;
                    closest_fov = fov;
                }
            } else {
                for (int i = 0; i < Entity::BonePos::kCount; i++) {
                    for (const geo::Vec3& ii: GetVisibleMultipoints(local_ent,
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
            std::optional<geo::Vec3> head;
            if ((head = GetVisible(local_ent, entity, camera_pos, Entity::BonePos::kHead)))
                return head;
            break;
        }
    }

    // TODO: multi-point this? add ui option?
    if (std::optional<Entity::Hitbox> coll = entity->GetCollision()) {
        geo::Vec3 center = coll.value().GetCenter();
        if (trace::Entity(entity, {camera_pos, center}, local_ent))
            return center;
    } else if (std::optional<geo::Vec3> origin = entity->GetOrigin())
        if (trace::Entity(entity, {camera_pos, *origin}, local_ent))
            return origin;

    return std::nullopt;
}

auto RankTarget(const std::input_iterator auto entity) {
    <entity> hostile;
    distance

    if constexpr (game::entity::Networked<entity>>) {
        if (entity->IsDormant())
            return std::nullopt;

    if constexpr (game::) 
    bool team = entity->IsEnemy();
    if ((ui::teammates != 2 && ((ui::teammates == 0) ? !team : team)) 
        || entity->GetDistance(local_ent) > ui::max_distance
        || !module::TargetSelection(entity))
        return std::nullopt;

        std::optional<geo::Vec3> aimpoint;
        if (!(aimpoint = RetrieveAimpoint(local_ent, entity, camera_pos, camera_ang)) 
            || (ui::fov && camera_ang.GetFov(camera_pos, *aimpoint) > ui::fov) 
            || (trace::Entity(entity, {camera_pos, *aimpoint}, local_ent)))
            return aimpoint;
        return std::nullopt;
    };

static Entity* last_target = nullptr;
static std::pair<Entity*, geo::Vec3> FindBestTarget(Player* local_ent, const geo::Vec3& camera_pos, const geo::Angle2& camera_ang) {
    
    if (ui::target_lock && last_target) {
        std::optional<geo::Vec3> aimpoint = IsTargetable(last_target);
        if (aimpoint)
            return {last_target, *aimpoint};
    }

    // Book keepers for highest target
    std::pair<Entity*, geo::Vec3> highest_ent = {nullptr, {}};
    float highest_score = 0;

    int ent_count = Entity::GetCount();
    for (int i = 0; i < ent_count; i++) {
        Entity* entity = Entity::Get(i);
        std::optional<geo::Vec3> aimpoint = IsTargetable(entity);
        if (!aimpoint) continue;

        // Get score based on priority mode
        float score = 0;
        switch (ui::priority_mode) {
            case 0:  // SMART Priority
                     // score = 0; break; // TODO
            case 1:  // Fov Priority
                score = 180.0f - camera_ang.GetFov(camera_pos, *aimpoint);
                break;
            case 2:  // Distance priority
                score = 4096.0f - entity->GetDistance(local_ent);
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
    static inline geo::Angle2 delta;
    static inline Timer<> time;
    static void GetDelta(const geo::Angle2& cur_ang, const geo::Angle2& wanted_ang) {
        assert(state != State::kAiming);
        delta = cur_ang - wanted_ang;
    }
    static void ReturnDelta(LocalPlayer* local_ent,
            const geo::Angle2& camera_ang) {
        assert(state == State::kAiming);
        geo::Angle2 old_angle = local_ent->GetCameraAngle() + delta;
        local_ent->SetCameraAngle(old_angle.Clamp());
    }
public:
    static void Reset(LocalPlayer* local_ent, const geo::Angle2& camera_ang) {
        if (state == State::kAiming)
            ReturnDelta(local_ent, camera_ang);
        state = State::kIdle;
    }
    static bool Timeout(LocalPlayer* local_ent, const geo::Angle2& camera_ang) {
        switch (state) {
        case State::kAiming:
            if (time.ResetCheck(std::chrono::milliseconds(ui::silent_snaptime))) {
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
    static void SetupSnap(LocalPlayer* local_ent, const geo::Angle2& camera_ang,
            const geo::Angle2& aim_ang) {
        if (state == State::kIdle) {
            GetDelta(camera_ang, aim_ang);
            time.Reset();
        }
        local_ent->SetCameraAngle(aim_ang);
        state = State::kAiming;
    }
};

template<std::ranges::forward_range EnemyEnts>
auto GetBestTarget(EnemyEnts ent_mgr) {
    auto i = ent_mgr.begin();
    for(
}

template<typename ControlledEntity, std::ranges::forward_range KillableTargets>
bool PointAt(Entity src_ent, const std::ranges::range auto ) {
    
    auto PreRet1 = [&]() {
        last_target = nullptr;
        highlight_target = nullptr;
    };
    #define ClearRet() ({PreRet1(); return;})

    if (!ui::enabled)
        ClearRet();

    LocalPlayer* local_ent = Entity::GetLocalPlayer();
    if (!local_ent || local_ent->IsDormant() || !local_ent->IsAlive())
        ClearRet();
    
    const geo::Vec3 camera_pos = local_ent->GetCameraPosition();
    const geo::Angle2 camera_ang = local_ent->GetCameraAngle();
    
    auto PreRet2 = [&]() {
        if (ui::silent_aim == 1) // Redundant?
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
    if (ui::silent_aim == 1 && Snapback::Timeout(local_ent, camera_ang))
        return;

    last_target = target;

    // Do smoothaim
    /*if (ui::smooth_aim > 0) {
        // TODO, Smooth is only somewhat fixed, it still needs a change to fix
        // the crossing of the y axis (-180, 180)

        geo::Angle2 angles = geo::Angle2::PointTo(camera_pos, aimpoint);
        geo::Angle2 delta = camera_ang.GetDelta(angles);

        // Pitch, If our camera pitch is more than our target pitch, we should
        // add to lower that value, and vise versa for camera being lower
        float p_move_ammt = delta.x / pow(ui::smooth_aim, 1.5);
        angles.x = (camera_ang.x > angles.x) ? (camera_ang.x - p_move_ammt)
                                             : (camera_ang.x + p_move_ammt);

        // Yaw, same as above but If we go across -180 to 180, we do some
        // changes
        float y_move_ammt = delta.y / pow(ui::smooth_aim, 1.5);
        angles.y =
            (camera_ang.y > angles.y || (camera_ang.y < -90 && angles.y > 90))
                ? (camera_ang.y - y_move_ammt)
                : (camera_ang.y + y_move_ammt);

        // Aim here as silent wont work with smooth
        local_ent->SetCameraAngle(angles.Clamp());

        // Slowaim Autoshoot, basicly we recreate an extremly simple triggerbot
        // here
        // FIXME
        if (ui::autoshoot) {
            // The further the terget gets from us, we want to make the allowed
            // fov lower
            if (camera_ang.GetFov(camera_pos, aimpoint) -
                    geo::Distance(camera_pos, aimpoint) / 32 < 5)
                local_ent->Attack();
        }
    } else {*/
        // Autoshoot
        if (ui::autoshoot) local_ent->Attack();
        // Check weapon time, we only want to aim when the weapon can shoot
        if (!module::CanShoot(local_ent)) return;
        // Get angles and Aim at player
        geo::Angle2 aim_angles = geo::Angle2::PointTo(camera_pos, aimpoint);
        switch (ui::silent_aim) {
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
    //}
}

}  // namespace neko::features::aimbot

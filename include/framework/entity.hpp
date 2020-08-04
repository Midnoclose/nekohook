
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

#pragma once

#include <neko/color.hpp>

#include "util/math.hpp"

namespace neko {

class LocalPlayer;
class Entity {
   private:
    // No constructors allowed
    Entity() = delete;
    Entity(Entity&) = delete;

   public:
    enum class Team { kUnknown, kEnemy, kAlly, kRed, kBlue, kYellow, kGreen };
    enum class Type {  // Entity Type
        kPlayer,
        kOtherHostile,  // Not player but still hostile, TODO find better name
                        // for this
        kProjectile,    // Bullet projectiles count
        kPickupHealth,
        kPickupSheild,
        kPickupAmmo,
        kGeneric
    };

    // TODO, is pos needed
    enum class BonePos { // Bone position enum, Add bones as needed, position
                         // shouldnt matter if everything is made right...
        kHead,       // Middle section
        kSpineTop,
        kSpineUpper,
        kSpineMiddle,
        kSpineLower,
        kSpineBottom,
        kLUpperArm,  // Upper limbs
        kRUpperArm,
        kLMiddleArm,
        kRMiddleArm,
        kLLowerArm,
        kRLowerArm,
        kLUpperLeg,  // Lower limbs
        kRUpperLeg,
        kLMiddleLeg,
        kRMiddleLeg,
        kLLowerLeg,
        kRLowerLeg,
        kCount
    };
    static constexpr auto BoneCount = static_cast<int>(BonePos::kCount);

    // main functions to get info out of entities
    bool GetDormant();
    bool GetAlive();
    int GetHealth();
    int GetMaxHealth();
    Team GetTeam();
    Type GetType();
    std::string_view GetName();
    int32_t GetUserId();  // stuff like steamid etc... just a unique identifier

    bool GetOrigin(math::Vector&);
    bool GetCollision(math::Box&);
    using Bone = math::Vector;
    using Hitbox = math::Box;
    bool GetBone(BonePos, Bone&);
    bool GetHitbox(BonePos, Hitbox&);
    math::Vector GetCameraPos();
    math::Angle GetCameraAngle();

    // Util functions that dont need to be defined
    inline float GetDistance();
    inline bool GetEnemy();

    // Colors, defined in ../util/colors.cpp
    RGBColor GetColor();
    inline RGBColor GetHealthColor();

    // Entity manager stuff
    static int GetCount();
    static Entity* Get(int i);
    static LocalPlayer* GetLocalPlayer();
};

// This is our char that we control
class LocalPlayer : public Entity {
public:
    // Local player specific, some can be used on entitys but avoid using it on
    // entitys other than GetLocalPlayer()
    void Attack();
    void Jump();
    void WalkTo(const math::Vector&);  // specific to followbot and walkbot
    bool InThirdperson();

    void SetCameraAngle(const math::Angle&);
    void SetSilentCameraAngle(
        const math::Angle&);  // Silent doesnt move our perspective but moves it
                              // ingame anyways
};

inline float Entity::GetDistance() {
    LocalPlayer* local_ent = GetLocalPlayer();
    if (local_ent == nullptr) return 0;
    math::Vector this_origin, our_origin;
    if (!this->GetOrigin(this_origin) || !local_ent->GetOrigin(our_origin))
        return 0;
    return this_origin.DistTo(our_origin);
}

inline bool Entity::GetEnemy() {
    Entity::Team team = this->GetTeam();
    if (team == Entity::Team::kAlly) return false;
    if (team == Entity::Team::kEnemy) return true;
    LocalPlayer* local_ent = Entity::GetLocalPlayer();
    if (local_ent) return local_ent->GetTeam() != team;
    return true;
}

}  // namespace neko

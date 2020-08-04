
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

#include "util/geometry.hpp"
#include "ui/gfx/gfx.hpp"

namespace nekohook {

class LocalPlayer;
class Entity {
   private:
    // No constructors allowed
    Entity() = delete;
    Entity(const Entity&) = delete;
    Entity(Entity&&) = delete;

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

    enum BonePos {  // Bone position enum, Add bones as needed, position
                          // shouldnt matter if everything is positioned in the right places

        kHead,            // Middle section
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

    // Basic info
    bool IsDormant() const;
    bool IsAlive() const;
    int GetHealth() const;
    int GetMaxHealth() const;
    Team GetTeam() const;
    Type GetType() const;
    std::string_view GetName() const;
    int GetId() const; // Entity id in the game system
    std::optional<int32_t> GetUserId() const;  // stuff like steamid etc... just a unique identifier

    // Positional
    std::optional<geo::Vec3> GetOrigin() const;
    using Bone = geo::Vec3;
    using Hitbox = geo::Box<Bone>;
    std::optional<Hitbox> GetCollision() const;
    std::optional<Bone> GetBone(BonePos) const;
    std::optional<Hitbox> GetHitbox(BonePos) const;
    geo::Vec3 GetCameraPosition() const; // FIXME: Optionals???
    geo::Angle GetCameraAngle() const;
    bool IsAirborne() const;
    float DistanceFromGround() const;

    // Util functions
    float GetDistance() const;
    bool IsEnemy() const;
    std::optional<geo::Vec3> GetLocation() const;
    gfx::Color GetColor();
    gfx::Color GetHealthColor();
    
    // Playerstate
    enum State { kFriendly = -1, kNone = 0, kRage = 1 };
    void SetPState(State);
    State GetPState() const;
    bool GetHasNoState() const { return !GetPState(); }
    bool IsRage() const { return this->GetPState() > 0; }
    bool IsFriendly() const { return this->GetPState() < 0; }

        
    // Entity manager stuff
    static int GetCount();
    static Entity* Get(int id);
    static LocalPlayer* GetLocalPlayer();
};

static_assert(!std::is_default_constructible<Entity>::value);
static_assert(!std::is_copy_constructible<Entity>::value);

// TODO: rename LocalPlayer to something like, OurPlayer, Player etc...
// This is our char that we control
class LocalPlayer : public Entity {
   public:
    void Attack();
    void Jump();
    void WalkTo(const geo::Vec3&);
    bool IsThirdperson();

    geo::Vec3 GetCameraPosition();
    geo::Angle GetCameraAngle();
    void SetCameraAngle(const geo::Angle&);
    void SetSilentCameraAngle(
        const geo::Angle&);  // Silent doesnt move our perspective but moves it
                              // ingame anyways
};

}  // namespace neko

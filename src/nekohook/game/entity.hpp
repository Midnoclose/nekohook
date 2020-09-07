
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

#include <ranges>

#include "../util/geometry.hpp"
#include "../gfx/gfx.hpp"

namespace nekohook::game {

namespace internal {

/*class LocalPlayer;
class Entity {
public:
    enum class Type {  // Entity Type
        kPlayer,
        kOtherHostile,  // Not player but still hostile, TODO find better name for this
        kProjectile,    // Bullet projectiles count
        kPickupHealth,
        kPickupSheild,
        kPickupAmmo,
        kGeneric
    };

    enum BonePos {       
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

    // Basic info
    std::string_view GetName() const;

    // Util functions
    float GetDistance() const;
    float GetDistance(LocalPlayer*) const;
    bool IsEnemy() const;
    std::optional<geo::Vec3> GetLocation() const;
    NanoCanvas::Color GetColor() const;
    NanoCanvas::Color GetHealthColor() const;

    // Entity manager stuff
    static int GetCount();
    static Entity* Get(int id);
    static LocalPlayer* GetLocalPlayer();
};*/
}

}  // namespace neko

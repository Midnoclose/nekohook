
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

#include <cstdlib>  // rand()

#include "math.hpp"

// Math utilities

namespace nekohook::math {

Angle& Angle::Clamp() {
    
    while (this->x > 89) this->x -= 180;
    while (this->x < -89) this->x += 180;
   
    while (this->y > 180) this->y -= 360;
    while (this->y < -180) this->y += 360;

    return *this;
}

// Returns angles to a point in space
Angle Angle::PointTo(const Vec3& src_point, const Vec3& dest_point) {
    Vec3 aim_point = dest_point - src_point;
    // Get angles
    Angle out;
    out.y = atan2(aim_point.y, aim_point.x) * 180 / F_PI;
    out.x = atan2(-aim_point.z, sqrt(aim_point.x * aim_point.x + aim_point.y * aim_point.y)) * 180 / F_PI;

    // Clamp and return
    return out.Clamp();
}

// A function to get the difference from angles, Please make sure inputs are
// clamped
Angle Angle::GetDelta(const Angle& dest_angles) const {
    // Our output difference
    Angle diff;

    // Yaw
    if (this->y != dest_angles.y) {
        // Check if yaw is on opposing poles
        if (this->y < -90 && dest_angles.y > 90)
            diff.y = this->y + 360 - dest_angles.y;
        else if (this->y > 90 && dest_angles.y < -90)
            diff.y = dest_angles.y + 360 - this->y;
        else
            diff.y = std::abs(this->y - dest_angles.y);
    }
    // Pitch
    if (this->x != dest_angles.x) diff.x = std::abs(this->x - dest_angles.x);

    return diff;
}
// Use input angles and our eye position to get fov to a destination point
float Angle::GetFov(const Vec3& src, const Vec3& dest) {    
    return this->GetFov(PointTo(src, dest));
}
float Angle::GetFov(const Angle& pointed_angle) {
    Angle delta = this->GetDelta(pointed_angle);
    return std::max<float>(delta.x, delta.y);
}


Vec3 DirectionalMove(const Vec3& src, const Angle& dir, float amt) {
    // Math I dont understand
    float sp = sinf(dir.x * F_PI / 180.f);
    float cp = cosf(dir.x * F_PI / 180.f);
    float sy = sinf(dir.y * F_PI / 180.f);
    float cy = cosf(dir.y * F_PI / 180.f);

    return Vec3(cp * cy, cp * sy, -sp) * amt + src;
}

}  // namespace neko::math

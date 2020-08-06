
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

#include "geometry.hpp"

// Math utilities

namespace nekohook::geo {

Angle2& Angle2::Clamp() {
    
    while (this->x > 89.0f) this->x -= 180.0f;
    while (this->x < -89.0f) this->x += 180.0f;
   
    while (this->y > 180.0f) this->y -= 360.0f;
    while (this->y < -180.0f) this->y += 360.0f;

    return *this;
}

// Returns angles to a point in space
AngleBase<2> AngleBase<2>::PointTo(const Vec3& src_point, const Vec3& dest_point) {
    Vec3 aim_point = dest_point - src_point;
    
    Angle2 out;
    out.y = atan2(aim_point.y, aim_point.x) * 180.0f / F_PI;
    out.x = atan2(0, sqrt(aim_point.x * aim_point.x + aim_point.y * aim_point.y)) * 180.0f / F_PI;

    return out.Clamp();
}

// A function to get the difference from angles, Please make sure inputs are
// clamped
AngleBase<2> AngleBase<2>::GetDelta(const AngleBase<2>& dest_angles) const {
    // Our output difference
    Angle2 diff;

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
float AngleBase<2>::GetFov(const Vec3& src, const Vec3& dest) const {    
    return this->GetFov(PointTo(src, dest));
}
float AngleBase<2>::GetFov(const AngleBase<2>& pointed_angle) const {
    Angle2 delta = this->GetDelta(pointed_angle);
    return std::max<float>(delta.x, delta.y);
}

Vec3 DirectionalMove(const Vec3& src, const AngleBase<2>& dir, float amt) {
    // Math I dont understand
    float sp = sinf(dir.x * F_PI / 180.f);
    float cp = cosf(dir.x * F_PI / 180.f);
    float sy = sinf(dir.y * F_PI / 180.f);
    float cy = cosf(dir.y * F_PI / 180.f);

    return Vec3(cp * cy, cp * sy, -sp) * amt + src;
}

}  // namespace neko::math

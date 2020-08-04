
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

#include "framework/entitys.hpp"  // For fov, local players angles

#include "math.hpp"

// Math utilities

namespace neko::math {

// Returns angles to a point in space
Angle Angle::VectorAngles(const Vector& src_point, const Vector& dest_point) {
    Vector aim_point = dest_point - src_point;
    // Get angles
    Angle out;
    out.y = atan2(aim_point.y, aim_point.x) * 180 / M_PI;
    out.x = atan2(-aim_point.z,
                  sqrt(aim_point.x * aim_point.x + aim_point.y * aim_point.y)) *
            180 / M_PI;

    // Clamp and return
    return out.Clamp();
}

// A function to get the difference from angles, Please make sure inputs are
// clamped
Angle Angle::GetDiff(const Angle& dest_angles) {
    // Our output difference
    Angle diff = Angle();

    // Yaw
    if (cur_angles.y != dest_angles.y) {
        // Check if yaw is on opposing poles, if so, we do an alternative
        // process
        if (this->y < -90 && dest_angles.y > 90)
            diff.y = this->y + 360 - dest_angles.y;
        else if (cur_angles.y > 90 && dest_angles.y < -90)
            diff.y = dest_angles.y + 360 - this->y;
        else
            diff.y = std::abs(this->y - dest_angles.y);
    }
    // Pitch
    if (this->x != dest_angles.x) diff.x = std::abs(this->x - dest_angles.x);

    return diff;
}
// Use input angles and our eye position to get fov to a destination point
float Angle::GetFov(const Angle& orig_angle, const Vector& eye_position,
                    const Vector& dest_point) {
    // Get the aimbots angles
    Angle aim_angles = VectorAngles(eye_position, dest_point);
    // Get the delta from the current and aimbots angles
    Angle delta = GetDifference(orig_angle, aim_angles);
    // Return our fov
    return std::max<float>(delta.x, delta.y);
}

// Give it a starting position, the direction to go in and how far!
Vector Angle::ExtendLine(const Vector& src_pos, float extend_amt) {
    // Math I dont understand
    float sp = sinf(this->x * M_PI / 180.f);
    float cp = cosf(this->x * M_PI / 180.f);
    float sy = sinf(this->y * M_PI / 180.f);
    float cy = cosf(this->y * M_PI / 180.f);

    Vector ret(cp * cy, cp * sy, -sp);
    return ret * extend_amt + src_pos;
}

// Paste from cathhok
float RandFloatRange(float min, float max) {
    return (min + 1) + ((float)rand() / (float)RAND_MAX) * (max - (min + 1));
}

}  // namespace neko::math

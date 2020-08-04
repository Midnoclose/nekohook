
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

#include <array>       // std::array<>
#include <cmath>       // This is a mathlib, did you think we didnt need math?
#if defined(_MSC_VER)  // these defines mess with our CatBox
#if defined(min)
#undef min
#endif
#if defined(max)
#undef max
#endif
#endif

namespace neko::math {

// Pi stuff
constexpr double kRadPi = 57.295779513082f;

// Struct for point in 3d space
class Vector {
   public:
    inline Vector(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f)
        : x(_x), y(_y), z(_z) {}
    float x, y, z;
    // So we can do math with our catvectors easily
    inline Vector operator+(const Vector& value) const {
        return Vector(this->x + value.x, this->y + value.y, this->z + value.z);
    }
    inline Vector operator-(const Vector& value) const {
        return Vector(this->x - value.x, this->y - value.y, this->z - value.z);
    }
    inline Vector operator*(const Vector& value) const {
        return Vector(this->x * value.x, this->y * value.y, this->z * value.z);
    }
    inline Vector operator/(const Vector& value) const {
        return Vector(x / value.x, this->y / value.y, this->z / value.z);
    }
    inline Vector operator*(float value) const {
        return Vector(this->x * value, this->y * value, this->z * value);
    }
    inline Vector operator/(float value) const {
        return Vector(this->x / value, this->y / value, this->z / value);
    }
    inline Vector& operator/=(float value) {
        this->x /= value;
        y /= value;
        this->z /= value;
        return *this;
    }
    inline bool operator==(const Vector& value) const {
        return value.x == this->x && value.y == this->y && value.z == this->z;
    }
    inline bool operator!=(const Vector& value) const {
        return value.x != this->x || value.y != this->y || value.z != this->z;
    }
    // Used to get the distance between 2 vectors
    inline float DistTo(const Vector& end) const {
        return sqrt(pow(this->x - end.x, 2) + pow(this->y - end.y, 2) +
                    pow(this->z - end.z, 2));
    }
};

// Used to store points in a box
class Box {
   public:
    inline Box(const Vector& _min = Vector(), const Vector& _max = Vector())
        : min(_min), max(_max) {}
    Vector min, max;

    // TODO, have this give refrences instead of copying through the use of
    // iterators lel
    inline auto GetPoints()
        const {  // Used to get out all 8 points from our box, Be sure to pass
                 // an array with at least 8 values
        // Expand into 8 points for box
        std::array<Vector, 8> points;
        points[0] = this->min;
        points[1] = Vector(this->max.x, this->min.y, this->min.z);
        points[2] = Vector(this->max.x, this->max.y, this->min.z);
        points[3] = Vector(this->min.x, this->max.y, this->max.z);
        points[4] = Vector(this->min.x, this->min.y, this->max.z);
        points[5] = Vector(this->max.x, this->min.y, this->max.z);
        points[6] = Vector(this->min.x, this->max.y, this->min.z);
        points[7] = this->max;
        return points;
    }
    inline bool Contains(const Vector& in) const {
        if (in.x < this->min.x || in.y < this->min.y || in.z < this->min.z)
            return false;
        if (in.x > this->max.x || in.y > this->max.y || in.z > this->max.z)
            return false;
        return true;
    }
    // Credits to cathook
    inline bool LineIntersects(const Vector& src, const Vector& dst) const {
        if (dst.x < this->min.x && src.x < this->min.x) return false;
        if (dst.y < this->min.y && src.y < this->min.y) return false;
        if (dst.z < this->min.z && src.z < this->min.z) return false;
        if (dst.x > this->max.x && src.x > this->max.x) return false;
        if (dst.y > this->max.y && src.y > this->max.y) return false;
        if (dst.z > this->max.z && src.z > this->max.z) return false;
        return true;
    }
    inline Vector GetCenter() const { return (this->min + this->max) * 0.5; }
    inline Vector GetDelta() const { return this->max - this->min; }
    inline bool operator==(const Box& value) const {
        return value.min == this->min && value.max == this->max;
    }
    inline bool operator!=(const Box& value) const {
        return value.min != this->min || value.max != this->max;
    }
    inline Box operator+(const Vector& value) const {
        return Box(this->min + value, this->max + value);
    }
    inline Box operator-(const Vector& value) const {
        return Box(this->min - value, this->max - value);
    }
    inline Box operator*(
        float value) const {  // for expanding relative to center
        // Take the center so we can operate on the delta later
        Vector center = this->GetCenter();
        // Take the delta and do the operation on our box, devide by 2 after so
        // we can add to center
        Vector delta = (this->GetDelta() * value) * 0.5;
        // Recreate the box with the new delta and return
        return Box(center - delta, center + delta);
    }
    inline Box operator/(
        float value) const {  // for shrinking relative to center
        // Take the center so we can operate on the delta later
        Vector center = this->GetCenter();
        // Take the delta and do the operation on our box, devide by 2 after so
        // we can add to center
        Vector delta = (this->GetDelta() / value) * 0.5;
        // Recreate the box with the new delta and return
        return Box(center - delta, center + delta);
    }
};

class Angle {
public:
    inline Angle(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f)
        : x(_x), y(_y), z(_z) {}
    float x, y, z;
    // So we can do math with our catvectors easily
    inline Angle operator+(const Angle& value) const {
        return Angle(this->x + value.x, this->y + value.y, this->z + value.z);
    }
    inline Angle operator-(const Angle& value) const {
        return Angle(this->x - value.x, this->y - value.y, this->z - value.z);
    }
    inline bool operator==(const Angle& value) const {
        return value.x == this->x && value.y == this->y && value.z == this->z;
    }
    inline bool operator!=(const Angle& value) const {
        return value.x != this->x || value.y != this->y || value.z != this->z;
    }
    // Clamps angles to prevent them from going out of bounds, this is simple
    // and should be inlined
    inline Angle& Clamp() {
        // Pitch
        while (this->x > 89) this->x -= 180;
        while (this->x < -89) this->x += 180;
        // Yaw
        while (this->y > 180) this->y -= 360;
        while (this->y < -180) this->y += 360;
        // Roll
        this->z = 0;
        return *this;
    }
    // Give it a position, angles to go in, and how far to extend, then it
    // returns a vector in that direction
    Vector ExtendLine(const Vector& src_pos, float extend_amt);
    // Input 2 angles to get the delta of difference
    Angle GetDiff(const Angle& other_angles) const;
    // Input the angles of your player, the vector position of your camera, and
    // the destination point and it returns fov value
    static float GetFov(const Angle& orig_angle, const Vector& eye_position,
                        const Vector& dest_point);
    // Returns angles used to aim at an object from a point, to another
    static Angle VectorAngles(const Vector& src_point,
                              const Vector& dest_point);
};

// Paste from cathhok
float RandFloatRange(float min, float max);

// Todo, phase out with std::uniform_real_distribution
/*// Class to satisfy UniformRandomBitGenerator using rand()
class RandEngine {
public:
    using result_type = size_t;
    static constexpr result_type min() { return 0; }
    static constexpr result_type max() { return RAND_MAX; }
    result_type operator()() { return static_cast<result_type>(std::rand()); }
};*/

}  // namespace neko::math

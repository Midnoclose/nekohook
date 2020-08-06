
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

#include <array>
#include <algorithm>
#include <stdexcept>

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/geometric.hpp>

namespace nekohook::geo {

namespace internal {

#if NEKOHOOK_GFX == opengl
    using Vec2 = glm::vec2;
    using Vec3 = glm::vec3;
    using DVec3 = glm::dvec3;
    using IVec2 = glm::ivec2;

    constexpr float F_PI = glm::pi<float>();
    
    template<class... T>
    auto Distance(T... in) { return glm::distance(in...); }
#endif

}
using namespace internal;

template<typename T, int _length>
class BoxBase;

template<typename T>
class BoxBase <T, 2> {
    static_assert(T::length() == 2);
protected:
    BoxBase() {}
    BoxBase(T _first, T _second) 
        : first(_first),  second(_second) {}
public:
    
    // TODO, rotation around origin?

    // Data
    union { T first, origin; };
    union { T second, size; };    

    T GetMax() const { return this->origin + this->size; }
    T GetSize() const { return this->size; }
    
    T GetPoint(int idx) const {
        switch (idx) {
        case 0: return this->origin;
        case 1: return {this->origin.x + this->size.x, this->origin.y};
        case 2: return {this->origin.x, this->origin.y + this->size.y};
        case 3: return this->origin + this->size;
        default:
            throw std::logic_error("Unknown point idx: " + std::to_string(idx));
        }
    }
    std::array<T, 4> GetPoints() const {
        T max = this->GetMax();
        return {
            this->origin,
            {max.x, this->origin.y},
            {this->origin.x, this->max.y},
            this->max
        };
    }

    bool Contains(T in) const {
        if (in.x > this->origin.x && in.y > this->origin.y) {
            T max = this->GetMax();
            return (in.x < max.x && in.x < max.y);
        }
        return false;
     }
    
    bool SegmentIntersects(T src, T dest) const {
        if ((dest.x > this->min.x && src.x > this->min.x) &&
            (dest.y > this->min.y && src.y > this->min.y)) {
            T max = this->GetMax();
            return (dest.x < max.x && src.x < max.x) || 
                   (dest.y < max.y && src.y < max.y);
        }
        return false;
    }
    enum class Direction {
        kUp,
        kDown,
        kLeft,
        kRight,
        kPosX = kRight,
        kPosY = kDown,
        kNegX = kLeft,
        kNegY = kUp
    };
    void Expand(Direction dir, int amt) { // TODO: Bitmongering(nopey)
        switch(dir) {
        case Direction::kUp:
            this->origin.y -= amt;
        case Direction::kDown:
            this->size.y += amt;
            break;
        case Direction::kLeft:
            this->origin.x -= amt;
        case Direction::kRight:
            this->size.x += amt;
            break;
        default:
            assert(false);
        }
    }
    void ExpandTo(T v) {
        if (this->origin.x > v.x)
            this->Expand(Direction::kNegX, this->origin.x - v.x);
        if (this->origin.y > v.y)
            this->Expand(Direction::kNegY, this->origin.y - v.y);
        T t_max = this->GetMax();
        if (t_max.x < v.x)
            this->Expand(Direction::kPosX, v.x - this->origin.x);
        if (t_max.y < v.y)
            this->Expand(Direction::kPosY, v.y - this->origin.y);
    }
    // TODO: Center around
};

template<typename T>
class BoxBase <T, 3> {
    static_assert(T::length() == 3);
protected:
    BoxBase() {}
    BoxBase(T _first, T _second) 
        : first(_first),  second(_second) {}
public:
    
    // Data
    union { T first, min; };
    union { T second, max; };
    
    auto operator[](const int idx) const {
        return this->data.at(idx);
    }

    // Utility functions
    T GetSize() const { return this->max - this->min; }
    T& GetMax() const { return this->max; }

    T GetPoint(int idx) const {
        switch (idx) {
        case 0: return this->min;
        case 1: return {this->max.x, this->min.y, this->min.z};
        case 2: return {this->max.x, this->max.y, this->min.z};
        case 3: return {this->min.x, this->max.y, this->max.z};
        case 4: return {this->min.x, this->min.y, this->max.z};
        case 5: return {this->max.x, this->min.y, this->max.z};
        case 6: return {this->min.x, this->max.y, this->min.z};
        case 7: return this->max;
        default: 
            throw std::logic_error("GetPoint() is only available for 2 and 3 axis vectors");
        }
    }
    std::array<T, 8> GetPoints() const {
        return {
            this->min,
            {this->max.x, this->min.y, this->min.z},
            {this->max.x, this->max.y, this->min.z},
            {this->min.x, this->max.y, this->max.z},
            {this->min.x, this->min.y, this->max.z},
            {this->max.x, this->min.y, this->max.z},
            {this->min.x, this->max.y, this->min.z},
             this->max
        };
    }

    bool Contains(T i) const {
        if (i.x > this->min.x || i.y > this->min.y || i.z > this->min.z)
        if (i.x < this->max.x || i.y < this->max.y || i.z < this->max.z)
            return false;
        return true;
    }

    // Credits to cathook
    bool LineIntersects(T src, T dst) const {
        if (dst.x < this->min.x && src.x < this->min.x) return false;
        if (dst.y < this->min.y && src.y < this->min.y) return false;
        if (dst.z < this->min.z && src.z < this->min.z) return false;
        if (dst.x > this->max.x && src.x > this->max.x) return false;
        if (dst.y > this->max.y && src.y > this->max.y) return false;
        if (dst.z > this->max.z && src.z > this->max.z) return false;
        return true;
    }

    enum Direction {
        kUp,
        kDown,
        kLeft,
        kRight,
        kForward,
        kBackward,
        kPosX = kUp,
        kPosY = kLeft,
        kPosZ = kForward,
        kNegX = kDown,
        kNegY = kRight,
        kNegZ = kBackward
    };
    void Expand(Direction dir, int amt) {
        switch(dir) {
        case Direction::kUp:
            this->max.y += amt; break;
        case Direction::kDown:
            this->min.y -= amt; break;
        case Direction::kLeft:
            this->min.x += amt; break;
        case Direction::kRight:
            this->min.x -= amt; break;
        case Direction::kForward:
            this->min.z += amt; break;
        case Direction::kBackward:
            this->max.z -= amt; break;
        default:
            assert(false);
        }
    }
};

template<typename T>
class Box : public BoxBase<T, T::length()> {
    using Parent = BoxBase<T, T::length()>;
public:
    using Direction = typename Parent::Direction;

    Box() {}
    Box(T _first, T _second) : Parent(_first, _second) {} 
    Box(std::pair<T, T> v) : Box(v.first, v.second) {}
    template<typename TT>
    Box(TT v) : Box(v.first, v.second) {
        static_assert(!std::is_same_v<std::pair<T, T>, TT>);
    }

    template<typename TT>
    Box<T>& operator=(TT v) { *this = Box<T>(v.first, v.second); }
    
    // Unary arithmetic operators
    bool operator==(T v) const {
        return this->first == v.first && this->second == v.second;
    }
    bool operator!=(T v) const {
        return !(*this == v);
    }
    Box<T> operator+(T v) const {
        return {this->min + v, this->max + v};
    }
    Box<T> operator-(T v) const {
        return {this->min - v, this->max - v};
    }

    Box<T> operator*(typename T::value_type v) const {
        T center = this->GetCenter();
        T size = (this->GetSize() * v) / typename T::value_type(2);
        return {center - size, center + size};
    }
    Box<T> operator/(typename T::value_type v) const {
        T center = this->GetCenter();
        T delta = (this->GetSize() / v) / typename T::value_type(2);

        return {center - delta, center + delta};
    }
    Box<T>& operator/=(typename T::value_type v) {
        return *this = *this / v;
    }
    

    // Utility functions
    T GetCenter() const { return (this->first + this->second) / typename T::value_type(2); }
    void Expand(std::initializer_list<Direction> dirs, int amt) {
        auto end = dirs.end();
        for (auto i = dirs.begin(); i != end; i++)
            this->Expand(*i, amt);
    }
    void Shrink(Direction dir, int amt) { this->Expand(dir, -amt); }

    Box<T> GetReal() {
        return *this;
    }
};

template<typename T_Parent, typename T_This = T_Parent>
class ChildBox : Box<T_This> {
    const T_Parent& parent;
public:
    template<typename... TT> 
    ChildBox(T_Parent _parent, TT... args) : Box<T_This>(args...), parent(_parent) {}
    T_Parent GetReal() {
        T_Parent real = parent->GetReal();
        assert(this->size <= real.size - this->origin);
        return {real.origin + this->origin, this->size};
    }
};

using Box2 = Box<IVec2>;
using Box3 = Box<Vec3>;

template<int T_length>
class AngleBase;

template<>
class AngleBase<1> {
    float data;
protected:
    template<typename... T>
    AngleBase(T... args) : data(args...) {}
public:
    operator float() const {
        return this->data;
    }
    operator float&() {
        return this->data;
    }
};

template<>
class AngleBase<2> : public Vec2 {
    using Vec2::Vec2;
    using Parent = Vec2;
protected:
    template<typename... T>
    AngleBase(T... args) : Vec2(args...) {
        static_assert(!(std::is_same_v<Vec2, T> || ...));
    }
public:
    using Vec2::operator=;
    template<class T>
    AngleBase operator-(T in) { return *this - Vec2(in); }
    template<class T>
    AngleBase operator+(T in) { return *this + Vec2(in); }

    AngleBase<2>& Clamp();
    AngleBase<2> Clamp() const;
    AngleBase<2> GetDelta(const AngleBase<2>& other_angles) const;
    float GetFov(const Vec3& view_src, const Vec3& dest_point) const;
    float GetFov(const AngleBase<2>& pointed_angle) const;
    static AngleBase<2> PointTo(const Vec3& src_point, const Vec3& dest_point);
};

template<int T_Length>
using Angle = AngleBase<T_Length>;
using Angle1 = Angle<1>;
using Angle2 = Angle<2>;

template<typename T_Origin, typename T_Angle>
class Ray;

template<typename T>
class Segment : public std::pair<T, T> {
public:
    using Parent = std::pair<T, T>;
    using Parent::Parent;
    using Parent::operator=;
    template<typename TT>
    Segment(Ray<T, TT> r, float dist = 8192.0f) : Parent(r.Cast(dist)){}
};
using Segment2 = Segment<IVec2>;
using Segment3 = Segment<Vec3>;

template<typename T_Origin, typename T_Angle>
class Ray : public std::pair<T_Origin, T_Angle> {
public:
    using Parent = std::pair<T_Origin, T_Angle>;
    using Parent::Parent;
    using Parent::operator=;
    T_Origin Cast(float dist = 8192.0f);
};
using Ray2 = Ray<IVec2, Angle1>;
using Ray3 = Ray<Vec3, Angle2>;

template<typename T_Origin, typename T_Distance = float>
using Sphereoid = std::pair<T_Origin, T_Distance>;

}  // namespace neko::math

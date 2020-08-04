
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

#include <cstdint>
#include <filesystem>

#include <nanovg.h>

#include <util/geometry.hpp>

namespace nekohook {

namespace events {
    void Draw();
} 

namespace gfx {

class Point : public geo::IVec2 {
public:
    static std::tuple<bool, Point> FromWorld(geo::Vec3); 
};

class Segment : public geo::Segment<geo::IVec2> {
public:
    void Draw();
};

class Ray : public geo::Ray<geo::IVec2, geo::Angle<1>> {
public:
    void Draw();
};

using Box = geo::Box<Point>;
using Circle = geo::Sphereoid<Point, float>;

class Color : NVGcolor {
    using Base = NVGcolor;
    using Base::Base;
public:
    static Color FromRGB(uint8_t _r, uint8_t _g, uint8_t _b);
    static Color FromRGBA(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a = 255);
    static Color FromHSL(float h, float s, float l);
    static Color FromHSLA(float h, float s, float l, uint8_t _a = 255);

    enum class Warp {
        kNone,
        kRainbow
    };
    static Color FromWarp(Warp, float speed = 1);
    
    bool operator ==(const Color& i) const { return *this == i; }
    Color Interp(const Color& c1, float u);

    static const Color white;
    static const Color black;
    static const Color pink;
    static const Color red;
    static const Color blue;
    static const Color yellow;
    static const Color orange;
    static const Color green;
    static const Color gray;
    static const Color lightgray;
    static const Color darkgray;
    static const Color empty;
};

void Line(const Point& src, const Point& dest, Color);
void RectFilled(const Box&, Color);
void RectOutline(const Box&, Color);
void CircleFilled(const Circle&, int steps, Color);
void CircleOutline(const Circle&, int steps, Color);
Point GetScreenSize();

namespace fs = std::filesystem;
class Font {
    int handle = -1;
public:
    void Draw(std::string_view src, const Point& dest, Color);
    void Length(std::string_view);

    static Font& GetDefault();
    static Font FontByName(std::string_view);
    static Font FontByPath(fs::path);
private:
    static Font _default;
};


}} // namespace nekohook::draw

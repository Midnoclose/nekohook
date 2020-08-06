
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

#include <nanovg.h>

namespace nekohook::gfx {

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
    
    bool operator ==(Color i) const { return *this == i; }
    Color Interp(Color c1, float u);

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

}


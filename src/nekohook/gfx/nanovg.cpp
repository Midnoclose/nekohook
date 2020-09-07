
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

#include <cassert>
#include <cmath>
#include <chrono>

#include "nanovg.hpp"

namespace nekohook::gfx::nanovg {

Color Color::FromRGB(uint8_t _r, uint8_t _g, uint8_t _b) { return nvgRGB(_r, _g, _b); }
Color Color::FromRGBA(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) { return nvgRGBA(_r, _g, _b, _a); }
Color Color::FromHSL(float h, float s, float l) { return nvgHSL(h, s, l); }
Color Color::FromHSLA(float h, float s, float l, uint8_t _a) { return nvgHSLA(h, s, l, _a); }

static auto start_time = std::chrono::steady_clock::now();
Color Color::FromWarp(Warp w, float speed) {
    switch(w) {
    case Warp::kRainbow: {
        std::chrono::duration<float, std::deca> curtime = std::chrono::steady_clock::now() - start_time;
        return Color::FromHSL(fabs(sin(curtime.count() * speed)) * 360.0f, 0.85f, 0.9f);
    }
    case Warp::kNone:
        return Color::empty;
    default:
        assert(false);
    }
}
    
Color Color::Interp(Color c1, float amt) const {
    return nvgLerpRGBA(*this, c1, amt);
}

const Color Color::white = Color::FromRGB(67, 70, 75);
const Color Color::black = Color::FromRGB(16, 17, 20);
const Color Color::pink = Color::FromRGB(255, 105, 180);
const Color Color::red = Color::FromRGB(90, 42, 46);
const Color Color::magenta = Color::FromRGB(78, 47, 87);
const Color Color::blue = Color::FromRGB(38, 69, 94);
const Color Color::yellow = Color::FromRGB(82, 60, 40);
const Color Color::orange = Color::FromRGB(255, 120, 0);
const Color Color::green = Color::FromRGB(60, 77, 48);
const Color Color::darkgray = Color::black.Interp(Color::white, 0.25);
const Color Color::gray = Color::darkgray.Interp(Color::white, 0.25);
const Color Color::lightgray = Color::gray.Interp(Color::white, 0.25);
const Color Color::empty = Color::FromRGBA(0, 0, 0, 0); 

ContextPtr::ContextPtr(NVGcontext* _ctx) : ctx(_ctx) {}
void ContextPtr::StartDraw() {
    nvgBeginFrame(this->ctx, window_width, window_height, 1);
}
void ContextPtr::SetColor(const Color&) {
    
}
void ContextPtr::DrawPoint(const Point&);
void ContextPtr::DrawLine(const Segment&, int thickness);
void ContextPtr::DrawOutline(const Box&, int thickness);
void ContextPtr::DrawFilled(const Box&);
void ContextPtr::DrawOutline(const Circle&, int thickness);
void ContextPtr::DrawFilled(const Circle&);
void ContextPtr::EndDraw();
const Point& ContextPtr::GetSize();
};

}

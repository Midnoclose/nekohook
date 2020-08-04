
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

#include "color.hpp"
#include "geometry.hpp"

namespace nekohook::gfx {

class Canvas {
public:
    virtual void StartDraw() = 0;
    virtual void SetColor(const Color&) = 0;
    virtual void DrawLine(const Point& src, const Point& dest, int thickness) = 0;
    virtual void DrawOutline(const Box&, int thickness) = 0;
    virtual void DrawFilled(const Box&) = 0;
    virtual void DrawOutline(const Circle&, int thickness) = 0;
    virtual void DrawFilled(const Circle&) = 0;
    virtual void EndDraw() = 0;
    virtual const Point& GetSize() = 0;
    Box GetBox() { return {{0, 0}, this->GetSize()}; }
};

}

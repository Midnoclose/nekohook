
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

//#include "color.hpp"
//#include "canvas.hpp"

namespace nekohook::gfx {

// Texture needs to be created at EndDraw()
/*class TextureCanvas : Canvas {
public:
    TextureCanvas(Canvas& _parent, const Point& _size) : size(_size), parent(_parent) {}
    Canvas& StartDraw() final {
        assert([this]() -> bool {
            const Point& p_size = this->parent.GetSize();
            Point rela_size = p_size - this->size;
            return 
        }());
        raw_data = std::vector<Color>(size.x * size.y, Color::empty);
    }
    Canvas& SetColor(const Color&) final;
    Canvas& DrawLine(const Segment&, int thickness) final;
    Canvas& DrawOutline(const Box&, int thickness) final;
    Canvas& DrawFilled(const Box&) final;
    Canvas& DrawOutline(const Circle&, int thickness) final;
    Canvas& DrawFilled(const Circle&) final;
    void EndDraw() final {
        this->parent.
    }
    const Point& GetSize() final { return this->size; }
    Point size;
private:
    const Canvas& parent;
    std::vector<Color> raw_data;
};*/

}

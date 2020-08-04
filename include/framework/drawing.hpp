
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

#include <neko/color.hpp>
#include <utility>  // std::pair()

#include "framework/uservar.hpp"
#include "util/math.hpp"

namespace neko::draw {

void Line(std::pair<int, int> pnt, std::pair<int, int> size, RGBColor);
void RectOutline(std::pair<int, int> pnt, std::pair<int, int> size, RGBColor);
void RectFilled(std::pair<int, int> pnt, std::pair<int, int> size, RGBColor);
void Circle(std::pair<int, int> center, float size, int steps, RGBColor);
void CircleFilled(std::pair<int, int> center, float size, int steps, RGBColor);

/*class FontHandle;
class Font {
   public:
    enum class Face { kOpensans, kVerasans, kUnispace };
    Font(Face _face, size_t _size) : face(_face), size(_size) {
        this->handle = CreateHandle(this->face, this->size);
    }
    ~Font() { DestroyHandle(this->handle); }
    inline bool operator==(const Font& in_value) const {
        return this->face == in_value.face && this->size == in_value.size;
    }

   private:
    const Face face;
    const size_t size;
    FontHandle* handle;

   private:
    std::string_view GetName() { return Font::fonts[this->face].first; }
    std::string_view GetPath() {
        return Font::fonts[this->face].second.GetPath();
    }
    static FontHandle* CreateHandle(Face _face, size_t size);
    static void DestroyHandle(FontHandle*);
    static std::array<std::pair<std::string_view, PackedFile>, Face::kCount>
        fonts;
};*/

// Draw string and get length, returns length of widthxheight
using Font = bool;
void String(std::string_view str, std::pair<int, int> pnt, const Font& = 0,
            RGBColor = RGBColor::white);
std::pair<int, int> GetStringSize(std::string_view str, const Font& = 0);

bool WorldToScreen(math::Vector, std::pair<int, int>&);

}  // namespace neko::draw

namespace neko::uservar {

/*class Font : public Base {
   public:
    Font(std::initializer_list<std::string_view> _gui_map,
         std::string_view _com_name, draw::Font::Face _defaults,
         std::string_view _gui_name, std::string_view _desc = "unknown")
        : Base(_gui_map, _com_name, _gui_name, _desc, Base::Type::kFont),
          defaults(_defaults),
          value(_defaults),
          min(_min),
          max(_max) {}

    inline operator const draw::Font&() const { return value; }
    inline bool operator==(const draw::Font& in_value) const {
        return value == in_value;
    }

    const int defaults;
    draw::Font value;
    const int min;
    const int max;

    void operator=(Font);
    virtual void Callback(const std::vector<std::string_view>&);
    virtual std::string GetValue();
};*/

}  // namespace neko::uservar

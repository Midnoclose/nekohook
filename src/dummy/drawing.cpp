
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

// TODO, add texture func with texture load with drawline
/*#include <cmath>
#include <cstring>  // strlen

#include "util/math.hpp"  // Contains pi defines

#include "drawing.hpp"

namespace draw {

// Line
void Line(int, int, int, int, CatColor);

// Outline rect
void Rect(int x, int y, int w, int h, CatColor color) {
    // Make outline rect with draw line
    Line(x, y, w, 0, color);              // Top
    Line(x, y + 1, 0, h, color);          // Left
    Line(x + 1, y + h, w - 1, 0, color);  // Botton
    Line(x + w, y + 1, 0, h - 1, color);  // Right
}

// Filled Rect
void RectFilled(int x, int y, int w, int h, CatColor color) {
    // Make filled rect with lines
    for (int i = 0; i < w; i++) {
        Line(x + i, y, 0, h, color);
    }
}

// Outline circle
void Circle(int x, int y, float radius, int steps, CatColor color) {
    if (radius < 0 || steps <= 3)
        return;  // cant draw a cirle without specific parameters
    float px = 0;
    float py = 0;
    for (int i = 0; i < steps; i++) {
        float ang = 2 * M_PI * (float(i) / steps);
        float dx = x + radius * cos(ang);
        float dy = y + radius * sin(ang);
        if (!i) {
            ang = 2 * M_PI * (float(steps - 1) / steps);
            px = x + radius * cos(ang);
            py = y + radius * sin(ang);
        }
        Line(px, py, dx - px, dy - py, color);
        px = dx;
        py = dy;
    }
}

// Filled circle
void CircleFilled(int x, int y, float radius, int steps, CatColor color) {
    if (radius < 0) return;  // cant draw a cirle without specific parameters
    // Interate Left and right
    for (int i = 0; i < radius; i++) {
        // Up and down
        for (int ii = radius; ii >= 0; ii--) {
            // Check if our distance is within the radius
            if (sqrt(pow(i, 2) + pow(ii, 2)) > radius) continue;
            Line(x - i, y - ii, 0, ii * 2, color);  // Left line
            Line(x + i, y - ii, 0, ii * 2, color);  // Right line
            break;
        }
    }
}

// String
void String(const char* text, int x, int y, int font, int size,
            CatColor color) {}

// String length in pixels
std::pair<int, int> GetStringLength(
    const char* string, int font,
    int size);  // a psudo string len, so spacings dont get ruined

// The main world to screen function used by most of the cheats esp features
// New breakthrough, we can potentially make our own wts function to utilize
// view matrixes, I didnt know this is used across many games.
// TODO, impliment that ^
bool WorldToScreen(math::Vector, std::pair<int, int>&) { return false }

const char* Fonts[] = {"Open Sans", "Bitstream Vera Sans Mono", "Unispace"};
static std::initializer_list<std::string_view> gui_menu({"GUI"});
uservar::Enum default_font(gui_menu, {Fonts[0], Fonts[1], Fonts[2]}, "gui_font",
                           0, "Gui font", "The main font setting");
uservar::Int default_font_size(gui_menu, "gui_font_size", 6, "Gui font size",
                               "The main font size");

} */ // namespace draw

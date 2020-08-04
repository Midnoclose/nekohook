
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

#include "input.hpp"

namespace input {

cat::Function<std::pair<int, int>(void)> GetBounds;
cat::Event<std::pair<int, int>> bounds_event;
cat::Function<std::pair<int, int>(void)> GetMouse;
cat::Event<std::pair<int, int>> mouse_event;
cat::Function<bool(CatKey)> GetKey;
cat::Event<CatKey, bool> key_event;

// Holds our cat keys as strings
const char* key_names[static_cast<int>(CatKey::kCount)] = {

    "NONE",        "0",
    "1",           "2",
    "3",           "4",
    "5",           "6",
    "7",           "8",
    "9",           "A",
    "B",           "C",
    "D",           "E",
    "F",           "G",
    "H",           "I",
    "J",           "K",
    "L",           "M",
    "N",           "O",
    "P",           "Q",
    "R",           "S",
    "T",           "U",
    "V",           "W",
    "X",           "Y",
    "Z",

    "ESCAPE",      "LBRACKET",
    "RBRACKET",    "SEMICOLON",
    "APOSTROPHE",  "BACKQUOTE",
    "COMMA",       "PERIOD",
    "SLASH",       "BACKSLASH",
    "MINUS",       "EQUAL",
    "ENTER",       "SPACE",
    "BACKSPACE",   "TAB",
    "CAPSLOCK",

    "INSERT",      "DELETE",
    "HOME",        "END",
    "PAGEUP",      "PAGEDOWN",

    "LSHIFT",      "RSHIFT",
    "LALT",        "RALT",
    "LCONTROL",    "RCONTROL",

    "PAD_0",       "PAD_1",
    "PAD_2",       "PAD_3",
    "PAD_4",       "PAD_5",
    "PAD_6",       "PAD_7",
    "PAD_8",       "PAD_9",

    "PAD_DIVIDE",  "PAD_MULTIPLY",
    "PAD_MINUS",   "PAD_PLUS",
    "PAD_ENTER",   "PAD_DECIMAL",

    "UP",          "LEFT",
    "DOWN",        "RIGHT",

    "F1",          "F2",
    "F3",          "F4",
    "F5",          "F6",
    "F7",          "F8",
    "F9",          "F10",
    "F11",         "F12",

    "MOUSE_1",     "MOUSE_2",
    "MOUSE_3",     "MOUSE_4",
    "MOUSE_5",     "M_WHEEL_UP",
    "M_WHEEL_DOWN"};

}  // namespace input


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

#include <neko/event.hpp>

namespace neko::input {

// The namings are completely fucked, but its related to user input so its more
// readable NOTE: I tried to remove the k from in front for readability, but
// numbers arent allowed so deal with it
enum class Key {
    kNone,
    k0,
    k1,
    k2,
    k3,
    k4,
    k5,
    k6,
    k7,
    k8,
    k9,
    kA,
    kB,
    kC,
    kD,
    kE,
    kF,
    kG,
    kH,
    kI,
    kJ,
    kK,
    kL,
    kM,
    kN,
    kO,
    kP,
    kQ,
    kR,
    kS,
    kT,
    kU,
    kV,
    kW,
    kX,
    kY,
    kZ,

    kEscape,
    kLBracket,
    kRBracket,
    kSemicolon,
    kApostrophe,
    kBackquote,
    kComma,
    kPeriod,
    kSlash,
    kBackslash,
    kHyphen,
    kEqual,
    kEnter,
    kSpace,
    kBackspace,
    kTab,
    kCapslock,

    kInsert,
    kDelete,  // cant use delete lol
    kHome,
    kEnd,
    kPageUp,
    kPageDown,

    kLShift,
    kRShift,
    kLAlt,
    kRAlt,
    kLControl,
    kRControl,

    kPad0,
    kPad1,
    kPad2,
    kPad3,
    kPad4,
    kPad5,
    kPad6,
    kPad7,
    kPad8,
    kPad9,

    kPadDivide,
    kPadMultiply,
    kPadMinus,
    kPadPlus,
    kPadEnter,
    kPadPeriod,

    kUp,
    kLeft,
    kDown,
    kRight,

    kF1,
    kF2,
    kF3,
    kF4,
    kF5,
    kF6,
    kF7,
    kF8,
    kF9,
    kF10,
    kF11,
    kF12,

    kMouse1,
    kMouse2,
    kMouse3,
    kMouse4,
    kMouse5,
    kMWheelUp,
    kMWheelDown,
    kCount
};
extern std::string_view key_names[static_cast<int>(Key::kCount)];

std::pair<int, int> GetBounds();
extern FastEvent<std::pair<int, int>> bounds_event;
std::pair<int, int> GetMouse();
extern FastEvent<std::pair<int, int>> mouse_event;
bool GetKey(Key);
extern FastEvent<Key, bool> key_event;

}  // namespace input

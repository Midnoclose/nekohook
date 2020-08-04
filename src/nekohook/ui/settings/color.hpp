
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

#include "ui/graphical/draw.hpp"
#include "var.hpp"

namespace nekohook::setting {

class Color : public Var {
public:
    Color(TreeMap, std::string name, const draw::Color& _defaults);
    Type GetType() override;
    std::string GetString() override;
    void SetString(std::string_view) override;
    void Call(Command::Args) override;

    operator draw::Color() const { return this->value; }
    bool operator==(const draw::Color& in_value) const { return this->value == in_value; }
public:
    draw::Color value;
    const draw::Color defaults;
};

}

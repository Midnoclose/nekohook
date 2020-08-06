
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

#include <filesystem>
#include <optional>
#include <string_view>

namespace nekohook::gfx {

class Canvas;
class Font {
    friend Canvas;
    using Handle = int;
    Font() {}
    std::optional<Handle> handle;
public:
    Font(Font&& v) {
        std::optional<Handle> tmp = std::move(v.handle);
        v.handle = std::nullopt;
        this->handle = std::move(tmp);
    }
    static Font& GetDefault();
    static Font FontByName(std::string_view);
    static Font FontByPath(const std::filesystem::path&);
private:
    static Font _default;
};

}

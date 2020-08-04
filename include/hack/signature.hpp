
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

#include "memory.hpp"

#include "sharedobj.hpp"

namespace neko {

void* FindPattern(std::pair<uintptr_t, uintptr_t> range, const char* pattern);

template <typename T>
T GetSignature(const SharedObject& shared_obj, const char* pattern,
               std::ptrdiff_t offset = 0) {
    void* find = FindPattern(shared_obj.GetRange(), pattern);
    return mem::Offset<T>(find, offset);
}

}  // namespace neko

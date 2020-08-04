
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

#if defined(__linux__)
#include <link.h>  // link maps
using SOHandle = link_map*;
#elif defined(_WIN32)
#include <windows.h>  // loadlibrary
using SOHandle = HMODULE;
#endif

#include <neko/filesystem.hpp>

namespace neko {

// Create a shared object with the name of the shared object, then it attempts
// to find its path and allows access to the linkmap
class SharedObject {
   public:
    SharedObject(){};
    SharedObject(const char* file_info) { Init(file_info); }
    void Init(const char* file_info);

    // Getters
    std::string GetFileName() const { return path.filename().generic_string(); }
    const fs::path& GetPath() const { return path; }
    SOHandle GetLmap() const { return lmap; }
    const std::pair<uintptr_t, uintptr_t>& GetRange() const { return range; }

#if defined(__linux__)
    inline auto GetSym(const char* name) { return dlsym(GetLmap(), name); }
#elif defined(_WIN32)
    inline auto GetSym(LPCSTR name) { return GetProcAddress(GetLmap(), name); }
#endif

   private:
    fs::path path;  // The full path of the shared library we are looking for

    SOHandle lmap = nullptr;                // Link map returned from dllopen
    std::pair<uintptr_t, uintptr_t> range;  // start and end of the range
};

}  // namespace neko

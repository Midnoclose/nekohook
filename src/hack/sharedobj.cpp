
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

#if defined(__linux__)
#include <dlfcn.h>  // dlopen, libary stuffs
#include <fstream>
#elif defined(__WIN32)
#include <windows.h>
#endif

#include "../util/logging.hpp"  // Logging
#include "../util/platform.hpp"

#include "sharedobj.hpp"

namespace neko {

void SharedObject::Init(const char* _file_info) {
    this->path = _file_info;

    // Ensure filename is a valid filename
    if (this->GetFileName().find('.') ==
        std::string::npos)  // TODO: fix this when im not high
        path += Platform(".so", ".dll", ".dylib");

#if defined(__linux__)
    std::ifstream proc_maps(
        "/proc/self/maps");  // this contains shared library locations and names
    while (!proc_maps.eof()) {
        std::string line_read;
        std::getline(proc_maps, line_read);

        if (line_read.find("/" + this->GetFileName()) == std::string::npos)
            continue;

        // Proc maps ex: 7fbfe002d000-7fbfe0095000 r-xp 00000000 fe:01 5118287
        // /usr/lib/libncursesw.so.6.1
        unsigned int begin, end;
        char tmp_path[1024];
        if (int ret = sscanf(line_read.c_str(), "%x-%x %*s %*s %*s %*s %[^\t]",
                             &begin, &end, tmp_path) != 3) {
            debug_log.Fmt("Scanned: %s\n Got: %i", tmp_path, ret);
            continue;
        } else
            this->range = {begin, end};

        path = tmp_path;
        break;
    }
    if (proc_maps.eof())
        debug_log.Fmt("Couldnt find library \"%s\" in /proc/maps!",
                      this->GetFileName().c_str());
    proc_maps.close();
    // Try to grab a handle, but do not load or increse refcount
    this->lmap = static_cast<SOHandle>(
        dlopen(path.c_str(), RTLD_NOLOAD | RTLD_NOW | RTLD_LOCAL));
    if (const char* error = dlerror())
        debug_log.Fmt("DLERROR: %s from %s", error,
                      this->GetFileName().c_str());

#elif defined(_WIN32)
    this->lmap = GetModuleHandle(this->GetFileName().c_str());
    if (auto error = GetLastError())
        debug_log.Fmt("DLERROR: %i from %s", error,
                      this->GetFileName().c_str());

    wchar_t buffer[MAX_PATH];
    auto result = GetModuleFileNameW(this->lmap, buffer, MAX_PATH);
    if (!result || result != wcslen(buffer))
        debug_log.Fmt("Couldnt find library path for \"%s\"!",
                      this->GetFileName().c_str());

    this->path = buffer;
#else
#pragma message("warning: Shared object cannot get library info")
#endif

    debug_log.Fmt("SO Handle: %#x, Range: %#x -> %#x, Path: \"%s\"", this->lmap,
                  this->range.first, this->range.second,
                  this->path.generic_string().c_str());
}

}  // namespace neko

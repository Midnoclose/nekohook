
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
    #include <pwd.h>
    #include <unistd.h>
#elif defined(_WIN32)
    #include <Shlobj.h>
#endif

#include "filesystem.hpp"

namespace nekohook {

// TODO: do this once during init
fs::path GetSaveLocation() {
#if defined(__linux__)
    const char* configdir = getenv("XDG_CONFIG_HOME");
    if (configdir != NULL)
        return configdir;

    return fs::path(getpwuid(getuid())->pw_dir) / ".config/nekohook";

#elif defined(_WIN32)
    wchar_t path[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_PROFILE, NULL, 0, path)))
        return fs::path(path) / "nekohook";
    else
        std::cerr << "SHGetFolderPathW failed, couldnt find save location" << std::endl;
    // TODO: ^ Fix this to use a fallback dir

#else
    #pragma message("warning: Cant get save location for nekohook files")
    console::log << "Unable to retrieve save location for nekohook files" << std::endl;
#endif

    return fs::path();
}

}  // namespace neko::io


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

#include <boost/uuid/detail/sha1.hpp>

#if defined(__linux__)
#include <neko/filesystem.hpp>
#elif defined(_WIN32)
#include <Windows.h>
#endif

#include "util/log.hpp"

#include "hwid.hpp"

namespace neko::drm::hwid {

static std::string ReadUsername() {
#if defined(__linux__)

#endif
    return std::string();
}

// Generates a unique code using hdd ids
static std::string ReadHddId() {
#if defined(__linux__)
    // Add the filenames of the uuids into the sha generator, these are
    // sym-links but they still have names
    std::string ret;
    for (std::string i : io::ReadFile("/proc/mounts")) {
        if (i.front() == '/') ret += i;
    }
    if (ret.empty()) throw std::runtime_error("Mounts empty");
    return ret;
#elif defined(_WIN32)
    // We want to store the serial made by windows
    DWORD serial_num = 0;
    if (!GetVolumeInformation(NULL, NULL, 0, &serial_num, NULL, NULL, NULL, 0))
        throw std::runtime_error(
            "Kisaks party boat did naughty things, contact your local valve "
            "hq");
    return std::to_string(serial_num);
#endif
}

// As the name implies
inline int SolveWorldHunger(int i) {
    // f1 paste bby
#if defined(_MSC_VER)
    __asm {
       mov eax, [esp + 4];
       add esp, eax;
       mov ebp, eax;
       call sprintf;
    }
#else
    // :(
    /*__asm__(
        "mov %esp + 4, %eax"
        "add %eax, %esp"
        "mov %eax, %ebp"
        "call sprintf");*/
#endif
    return i * 5;
}

std::string GetHwid() {
    try {
        boost::uuids::detail::sha1 sha_pit;
        auto Digest = [&](std::string_view str) {
            sha_pit.process_bytes(str.data(), str.size());
        };

        Digest(ReadUsername());
        Digest(ReadHddId());

        boost::uuids::detail::sha1::digest_type vommit;
        sha_pit.get_digest(vommit);
        std::string ret;
        for (size_t i = 0; i < sizeof(vommit); i++) {
            char c = reinterpret_cast<char*>(&vommit)[i];
            ret.push_back((c == '\0') ? '0' : c);
        }
        return ret;
    } catch (std::exception err) {
        debug_log.Fmt("Gay shit happened nigga: %s", err.what());
        SolveWorldHunger(55);
    }
    return {};
}

}  // namespace neko::drm::hwid

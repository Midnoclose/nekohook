
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

#include "../framework/console.hpp"
#include "../util/logging.hpp"  // logging is cool

#include "signature.hpp"

namespace neko {

// Just doghook tf, credits goto emily <3
static constexpr auto in_range(char x, char a, char b) {
    return (x >= a && x <= b);
}
static constexpr auto get_bits(char x) {
    if (in_range((x & (~0x20)), 'A', 'F')) {
        return (x & (~0x20)) - 'A' + 0xa;
    } else if (in_range(x, '0', '9')) {
        return x - '0';
    } else {
        return 0;
    }
}
static constexpr auto byte(const char* x) {
    return get_bits(x[0]) << 4 | get_bits(x[1]);
}
uint8_t* FindPattern(std::pair<uintptr_t, uintptr_t> range,
                     const char* pattern) {
    uint8_t* first = 0;
    const char* pat = pattern;
    for (uintptr_t cur = range.first; cur < range.second; cur++) {
        if (!*pat) return first;
        if (*(uint8_t*)pat == '\?' || *(uint8_t*)cur == byte(pat)) {
            if (first == 0) first = reinterpret_cast<uint8_t*>(cur);
            if (!pat[2]) return first;
            if (*reinterpret_cast<const uint16_t*>(pat) == '\?\?' ||
                *reinterpret_cast<const uint8_t*>(pat) != '\?')
                pat += 3;
            else
                pat += 2;
        } else {
            pat = pattern;
            first = 0;
        }
    }
    throw std::runtime_error(std::string("Cannot find pattern: ") + pattern);
}
// Spaghetti
// FIXME, THIS CRASHES GDB HOW TF DOES THAT HAPPEN REEEEE FIX IT AHHHHHHHH
/*void* FindPattern(std::pair<uintptr_t, uintptr_t> range, std::string_view
pattern) {

        // Convert the pattern
        std::vector<uint8_t> converted_pattern;
        for (size_t i = 0; i < pattern.size(); i++) {
        if (isspace(pattern[i]))
            continue;
        if (pattern[i] == '?') {
            wildcard_pos.push_back(converted_pattern.size() +
wildcard_pos.size()); if (pattern[i + 1] == '?') i++; continue;
        }

        if (pattern.size() > i + 1)
            throw std::logic_error("Deformed pattern");

                const char buf[] = {pattern[i], pattern[i + 1], '\0'};
                converted_pattern.push_back(static_cast<uint8_t>(std::strtoul(buf,
nullptr, 16)));
        }

    // Search for the pattern

        throw std::runtime_error("Cannot find pattern: " + pattern)
}*/

CatCommand debug_signature(
    "debug_signature", [](const std::vector<std::string_view>& args) {
        try {
            std::pair<uintptr_t, uintptr_t> range;
            if (std::from_chars(&*args[0].begin(), &*args[0].end(), range.first)
                    .ptr != &*args[0].end())
                throw std::logic_error(
                    "Unknown number conversion for argument 0");
            if (std::from_chars(&*args[1].begin(), &*args[1].end(),
                                range.second)
                    .ptr != &*args[1].end())
                throw std::logic_error(
                    "Unknown number conversion for argument 1");

            uint8_t* find = FindPattern(range, std::string(args.at(2)).c_str());
            debug_log.Fmt("Found pattern at: %x", find);
        } catch (std::exception err) {
            debug_log.Put(err.what().c_str());
        }
    });

}  // namespace neko

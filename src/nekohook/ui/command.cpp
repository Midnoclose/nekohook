
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

#include "command.hpp"

namespace nekohook::ui {

// Seperates args like how "argc, args" works
Command::Args Command::ProcessLine(std::string_view input) {
    std::vector<std::string_view> ret;
    while (!input.empty()) {
        // Discard whitespace
        std::size_t non_white_start = input.find_first_not_of(' ');
        if (non_white_start == std::string_view::npos) break;
        input.remove_prefix(non_white_start);

        // Find delim
        std::size_t first_delim = input.find_first_of(" \"\'");
        if (first_delim == std::string_view::npos) break;
        std::size_t size = first_delim;

        // act on delim
        if (input[first_delim] == ' ') {
            ret.push_back(input.substr(0, first_delim - 1));
            input.remove_prefix(first_delim);
        } else {
            // Pushback existing
            if (first_delim != 0) ret.push_back(input.substr(0, size));
            // Find end
            char found_delim = input[first_delim];
            input.remove_prefix(first_delim);
            std::size_t end = input.find_first_of(input);
            if (end == std::string_view::npos) break;
            ret.push_back(input.substr(0, end - 1));
            input.remove_prefix(end);
        }
    }
    if (!input.empty()) ret.push_back(input);
    return ret;
}

void Command::Call(std::string_view args) {
    this->Call(ProcessLine(args));
}

}  // namespace neko

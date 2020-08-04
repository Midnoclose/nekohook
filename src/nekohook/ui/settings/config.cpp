
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

#include <fstream>

#include "ui/command.hpp"
#include "ui/console.hpp"
#include "ui/settings/var.hpp"
#include "util/filesystem.hpp"

namespace nekohook::configs {

static fs::path save_location = GetSaveLocation() / "cfg";

void Load(const fs::path& cfg_path) {
    // Call all of the lines as commands
    std::ifstream file(save_location / cfg_path);
    while (file) {
        std::string buf;
        std::getline(file, buf);
        if (!buf.empty()) console::Exec(buf);
    }
}
void Load(std::string_view cfg_name) { Load(fs::path(std::string(cfg_name))); }

void Save(const fs::path& cfg_path) {
    
    std::fstream file(save_location / cfg_path);
    for (const auto& catvar : setting::Var::GetList()) {
        file << catvar->command_name;
        std::string value = catvar->GetString();
        if (value.find(' ') != std::string::npos)
            file << " \"" << value << '"';
        else
            file << ' ' << value << '\n';
    }
}
void Save(std::string_view cfg_name) { Save(fs::path(std::string(cfg_name))); }

std::vector<std::string> ListConfigs() {
    std::vector<std::string> ret;
    for (auto i : fs::directory_iterator(save_location))
        ret.push_back(i.path().generic_string());
    return ret;
}

static Command LoadConfig("load", [](const Command::Args& args) {
    if (args.empty()) {
        console::log << "Missing input argument" << std::endl;
        return;
    }
    try {
        Load(args[0]);
        console::log << "Loaded \"" << args[0] << "\"successfully!" << std::endl;
    } catch (...) {
        console::log << "Failed to load config: \"" << args[0] << "\"" << std::endl;
    }
});

static Command SaveConfig("save", [](const Command::Args& args) {
    if (args.empty()) {
        console::log << "Missing input argument" << std::endl;
        return;
    }

    try {
        Save(args[0]);
        console::log << "Saved \"" << args[0]
        << "\" successfully!\n";
    } catch (...) {
        console::log << "Failed to save config: \"" << args[0] << "\"" << std::endl;
    }
});

static Command ListConfig("list_configs", [](const Command::Args& args) {
    console::log << "List of configs:";
    for (auto i : ListConfigs())
        console::log << "\n\t" << i;
    console::log << std::endl;
});

}  // namespace neko::configs


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

#include "../init.hpp"
#include "../util/iohelper.hpp"
#include "../util/log.hpp"
#include "console.hpp"
#include "game.hpp"  // to get ingame state

#include "config.hpp"

namespace neko::configs {

static fs::path cfg_save_location = io::GetSaveLocation() / "cfg/";

static fs::path GetConfigFile(std::string cfg_name) {
    // Ensure we have .cfg to make saving file easy
    if (cfg_name.find(".cfg") == std::string::npos) cfg_name += ".cfg";

    // Make it a path to file
    return cfg_save_location / ("cat-" + cfg_name);
}

void Load(const fs::path& cfg_path) {
    auto file_lines = io::ReadFile(cfg_path);
    if (file_lines.empty())  // if empty, something probs happened and we wont
                             // be able to load the config
        return;

    // Call all of the lines as commands
    for (const std::string& i : file_lines) CallCommand(i);
}
void Load(std::string_view cfg_name) { Load(GetConfigFile(cfg_name)); }

void Save(const fs::path& cfg_path) {
    // Generate a list of commands from catvars
    std::vector<std::string> cfg_lines;
    for (const auto& catvar : CatVar::GetList()) {
        std::string value = catvar->GetValue();
        if (value.find(' ') !=
            std::string::npos)  // add quotes if value contains a space so the
                                // command executer doesnt have problems
            cfg_lines.push_back(catvar->command_name + " \"" + value + '"');
        else
            cfg_lines.push_back(catvar->command_name + ' ' + value);
    }

    io::WriteFile(cfg_path, cfg_lines);
}
void Save(std::string_view cfg_name) { Save(GetConfigFile(cfg_name)); }

std::vector<std::string> ListConfigs() {
    std::vector<std::string> ret;
    for (auto i : fs::directory_iterator(cfg_save_location))
        ret.push_back(i.generic_string());
    return {};
}

CatCommand LoadConfig("load", [](const std::vector<std::string_view>& args) {
    if (args.empty()) {
        debug_log.Fmt("Missing input argument");
        return;
    }

    fs::path cfg_path = GetConfigFile(args[0]);
    try {
        Load(cfg_path);
        debug_log.Fmt("Loaded %s successfully!", cfg_path.c_str());
    } catch (...) {
        debug_log.Fmt("Failed to load config: %s", cfg_path.c_str());
    }
});

CatCommand SaveConfig("save", [](const std::vector<std::string_view>& args) {
    if (args.empty()) {
        debug_log.Puts("Missing input argument");
        return;
    }

    fs::path cfg_path = GetConfigFile(args[0]);
    try {
        Save(cfg_path);
        debug_log.Fmt("Saved %s successfully!", cfg_path.c_str());
    } catch (...) {
        debug_log.Fmt("Failed to load config: %s", cfg_path.c_str());
    }
});

static CatCommand ListConfig("list_configs",
                             [](const std::vector<std::string_view>& args) {
                                 std::string print_str;
                                 for (std::string i : ListConfigs())
                                     print_str += "/n/t" + i;
                                 debug_log.Fmt("List of configs: %s");
                             });

init::routine::Framework([]() { Load("autoexec"); });

}  // namespace neko::configs

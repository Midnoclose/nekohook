
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
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>

#include "nekohook/ui/command.hpp"
#include "nekohook/ui/console.hpp"
#include "nekohook/ui/var.hpp"
#include "nekohook/util/filesystem.hpp"

namespace nekohook::ui::cfg {
namespace rj = rapidjson;

static const fs::path save_location = GetSaveLocation() / "cfg";

void Load(const fs::path& path) {
    std::ostream& err = console::err;

    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    file.open(path);

    rapidjson::Document doc;
    rj::IStreamWrapper file_w(file);
    doc.ParseStream(file_w);
    if (!doc.IsObject()) 
        throw std::runtime_error("Config file's json doenst start with object");

    rj::Document::ConstMemberIterator f = doc.FindMember("cfg");
    if (f == doc.MemberEnd())
        throw std::runtime_error("Config file's json doesnt contain cfg member");

    const rj::Value& c = f->value;
    if (!c.IsObject())
        throw std::runtime_error("Config file's json cfg member isnt an object");
    
    const auto& var_list = ui::BaseVar::GetList();
    for (const auto& i : c.GetObject()) {
        if (!i.value.IsString()) {
            err << "Config file's json value for \""
            << i.name.GetString() << "\" is not a string" << std::endl;
            continue;
        }

        auto find2 = std::find_if(var_list.begin(), var_list.end(), [&](BaseVar* ii){
            return ii->command_name == std::string_view(i.name.GetString(), i.name.GetStringLength()); 
        });
        if (find2 == var_list.end()) {
            err << "Config files variable \"" << i.name.GetString() << "Not found!" << std::endl;
            continue;
        }
        (*find2)->SetString(i.value.GetString());
    }
}
void Load(std::string_view cfg_name) { 
    Load(save_location / cfg_name); 
}

void Save(const fs::path& path) {
    std::fstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    file.open(path);  

    rj::OStreamWrapper file_w(file);
    rj::PrettyWriter<rj::OStreamWrapper> write(file_w);
    
    write.StartObject();

    write.Key("cfg");
    write.StartObject();
    for (BaseVar* var : BaseVar::GetList()) {
        write.Key(var->command_name.c_str(), var->command_name.size());
        std::string val = var->GetString();
        write.String(val.c_str(), val.size());
    }
    write.EndObject();

    write.EndObject();
}
void Save(std::string_view cfg_name) { 
    Save(save_location / cfg_name); 
}

std::vector<std::string> ListConfigs() {
    std::vector<std::string> ret;
    for (auto i : fs::directory_iterator(save_location))
        ret.push_back(i.path().filename());
    return ret;
}

static Command LoadConfig("cfg_load", [](std::ostream& out, Command::Args args) {
    if (args.empty()) {
        out << "Usage: cfg_load <name>" << std::endl; return; }

    Load(args[0]);
    out << "Loaded \"" << args[0] << "\"successfully!" << std::endl;
});

static Command SaveConfig("cfg_save", [](std::ostream& out, Command::Args args) {
    if (args.empty()) {
        out << "Usage: cfg_save <name>" << std::endl; return; }

    Save(args[0]);
    out << "Saved config \"" << args[0] << "\" successfully!" << std::endl;
});

static Command ListConfig("cfg_list", [](std::ostream& out, Command::Args args) {
    out << "List of configs--";
    std::vector<std::string> cfgs(ListConfigs());
    for (std::string& i : cfgs)
        out << "\n\t" << i;
    out << std::endl;
});

}  // namespace nekohook::ui::cfg

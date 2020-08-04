
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

#include <algorithm>
#include <charconv>
#include <exception>

#include "logging.hpp"
#include "strings.hpp"

#include "uservar.hpp"

namespace neko::uservar {

// General catvar constructor
Base::Base(std::initializer_list<std::string_view> _gui_map,
           std::string_view _com_name, std::string_view _gui_name,
           std::string_view _desc)
    : gui_map(_gui_map),
      command_name(std::string(kCommandPrefix) + _com_name),
      gui_name(_gui_name),
      desc(_desc) {
    Base::list.push_back(this);
    MenuTree::Expand(this);
}

// Adding menutrees with catvars
void MenuTree::Expand(CatVar* cat_var) {
    // Add any trees needed and get out ending tree
    MenuTree& cur_tree = MenuTree::root;
    for (auto i : cat_var->gui_map) {
        auto find =
            std::find_if(cur_tree.branches.begin(), cur_tree.branches.end(),
                         [&](const auto& ii) { return ii.name == i; });
        if (find == cur_tree.branches.end()) {
            cur_tree.branches.push_back(i);
            cur_tree = cur_tree.branches.back();
        } else
            cur_tree = *find;
    }
    // Add the catvar to the end tree
    cur_tree.cat_children.push_back(cat_var);
}

// Setters, we need to make sure we call the callback if we do change!
// This is important for menu sizing and keeping us in sync with games and such!
// Note: Even the source engine does this, it is really useful
void Bool::operator=(bool i) {
    if (i == this->value) return;

    this->value = i;
    Base::change_event.Emit(this);
}
void Int::operator=(int i) {
    if (i == this->value) return;

    this->value = std::clamp(i, this->min, this->max);
    Base::change_event.Emit(this);
}
void Key::operator=(CatKey i) {
    if (i == this->value) return;

    this->value = i;
    Base::change_event.Emit(this);
}
void Float::operator=(float i) {
    if (i == this->value) return;

    this->value = std::clamp(i, this->min, this->max);
    Base::change_event.Emit(this);
}
void String::operator=(std::string_view i) {
    if (i == this->value) return;

    this->value = i;
    Base::change_event.Emit(this);
}
void Color::operator=(CatColor i) {
    if (i == this->value) return;

    this->value = i;
    Base::change_event.Emit(this);
}
void Color::SetRainbow(bool i) {
    if (i == this->rainbow) return;

    this->rainbow = i;
    Base::change_event.Emit(this);
}

// Command Callbacks
// Self explanitory, take in arguments and set urself, if none print ur values
void Bool::Callback(const std::vector<std::string_view>& args) {
    // Empty args
    if (args.empty()) {
        debug_log.Fmt("%s: %s", this->command_name.c_str(),
                      this->GetValue().c_str());
        return;
    }
    // Number
    int result;
    if (std::from_chars(&*args[0].begin(), &*args[0].end(), result).ptr ==
        &*args[0].end())
        *this = result;
    // String
    else if (fuz::strcmp(args[0], "true"))
        *this = true;
    else if (fuz::strcmp(args[0], "false"))
        *this = false;
    else
        debug_log.Fmt("CatVarBool: Unknown conversion for \"%.*s\"",
                      args[0].size(), args[0].data());
}

void Int::Callback(const std::vector<std::string_view>& args) {
    if (args.empty()) {
        debug_log.Fmt("%s: %i", this->command_name.c_str(), this->value);
        return;
    }

    int result;
    if (std::from_chars(&*args[0].begin(), &*args[0].end(), result).ptr ==
        &*args[0].end())
        *this = result;
    else
        debug_log.Puts("CatVarInt: Unknown conversion for \"%.*s\"");
}

void Enum::Callback(const std::vector<std::string_view>& args) {
    if (args.empty()) {
        debug_log.Fmt("%s: %f", this->command_name.c_str(), this->value);
        return;
    }
    // Text
    for (size_t i = 0; i < cat_enum.size(); i++) {
        if (!fuz::strcmp(args[0], cat_enum[i])) continue;
        *this = static_cast<int>(i);
        return;
    }
    // int input
    int result;
    if (std::from_chars(&*args[0].begin(), &*args[0].end(), result).ptr ==
        &*args[0].end())
        *this = result;
    else
        debug_log.Fmt("CatVarEnum: No value in \"%s\" found for \"%.*s\"",
                      this->command_name.c_str(), args[0].size(),
                      args[0].data());
}

void Key::Callback(const std::vector<std::string_view>& args) {
    if (args.empty()) {
        debug_log.Fmt("%s: %s", this->command_name.c_str(),
                      this->GetValue().c_str());
        return;
    }

    // Text input
    for (int i = 0; i < static_cast<int>(CatKey::kCount); i++) {
        if (fuz::strcmp(args[0], input::key_names[i]) ||
            fuz::strcmp(args[0],
                        std::string("CATKEY_") + input::key_names[i])) {
            *this = static_cast<CatKey>(i);
            return;
        }
    }
    // int input
    int result;
    if (std::from_chars(&*args[0].begin(), &*args[0].end(), result).ptr ==
        &*args[0].end())
        *this = static_cast<CatKey>(result);
    else
        debug_log.Fmt("CatVarKey: No value in \"%s\" found for \"%.*s\"",
                      this->command_name.c_str(), args[0].size(),
                      args[0].data());
}

void Float::Callback(const std::vector<std::string_view>& args) {
    if (args.empty()) {
        debug_log.Fmt("%s: %f", this->command_name.c_str(), value);
        return;
    }

    // Sadly this isnt working with gcc for some reason...
    /*float result;
        auto chars_conv = std::from_chars(args[0].data(), nullptr, result);
        if (chars_conv.ptr == args[0].end())
        *this = result;
        else
        debug_log.Puts("CatVarFloat: Unknown Exception!");*/
    try {
        *this = std::stof(std::string(args[0]));
    } catch (...) {
    }
}

void String::Callback(const std::vector<std::string_view>& args) {
    if (args.empty())
        debug_log.Fmt("%s: %s", this->command_name.c_str(), value.c_str());
    else
        *this = args[0];
}

void Color::Callback(const std::vector<std::string_view>& args) {
    if (args.empty()) {
        debug_log.Fmt("%s: R:%i, G:%i, B:%i, A:%i", this->command_name.c_str(),
                      this->value.r, this->value.g, this->value.b,
                      this->value.a);
        return;
    }
    // Note, this is messy, but its optimised
    CatColor set = *this;
    try {
        int result;
        // Red
        std::string_view i = args.at(0);
        if (std::from_chars(&*i.begin(), &*i.end(), result).ptr == &*i.end()) {
            set.r = result;
            // Green
            i = args.at(1);
            if (std::from_chars(&*i.begin(), &*i.end(), result).ptr ==
                &*i.end()) {
                set.g = result;
                // Blue
                i = args.at(2);
                if (std::from_chars(&*i.begin(), &*i.end(), result).ptr ==
                    &*i.end()) {
                    set.b = result;
                    // Alpha
                    i = args.at(3);
                    if (std::from_chars(&*i.begin(), &*i.end(), result).ptr ==
                        &*i.end())
                        set.a = result;
                }
            }
        }
    } catch (const std::out_of_range&) {
    }
    *this = set;
}

// GetValues, return something that the class itself could turn back into a
// value that can be callbacked
std::string Bool::GetValue() { return this->value ? "true" : "false"; }

std::string Int::GetValue() { return std::to_string(this->value); }

std::string Key::GetValue() {
    return std::string("CATKEY_") +
           input::key_names[static_cast<int>(this->value)];
}

std::string Enum::GetValue() { return std::string(cat_enum[this->value]); }

std::string Float::GetValue() { return std::to_string(value); }

std::string String::GetValue() { return value; }

std::string Color::GetValue() {
    return std::to_string(value.r) + ' ' + std::to_string(value.g) + ' ' +
           std::to_string(value.b) + ' ' + std::to_string(value.a);
}

// CatCommands Related to catvars
CatCommand list_vars("list", [](const std::vector<std::string_view>& args) {
    auto print_var = [](CatVar* i) {
        // if we are writing an enum, we should display the enums with it
        if (i->GetType() == CatVar::Type::kEnum) {
            CatVarEnum* cvar_enum = reinterpret_cast<CatVarEnum*>(i);

            // generate the enum string
            std::string enum_str;
            for (const auto& tmp : cvar_enum->cat_enum)
                enum_str += enum_str.empty() ? tmp : ", " + std::string(tmp);
            debug_log.Fmt("Command: \"%s\", \"%s\"\n\t\t\"%s\"\n\t\tEnums: %s",
                          cvar_enum->command_name.c_str(), cvar_enum->gui_name,
                          cvar_enum->desc, enum_str.c_str());
        } else
            debug_log.Fmt("Command: \"%s\", \"%s\"\n\t\t\"%s\"",
                          i->command_name.c_str(), i->gui_name, i->desc);
    };
    // Single var list
    if (!args.empty()) {
        auto find =
            std::find_if(CatVar::GetList().begin(), CatVar::GetList().end(),
                         [&](auto i) { return i->command_name == args[0]; });
        if (find == CatVar::GetList().end())
            debug_log.Fmt("Unknown catvar: \"%.*s\"", args[0].size(),
                          args[0].data());
        else
            print_var(*find);
        // Entire var list
    } else {
        debug_log.Puts("Current list of CatVars--");
        for (const auto& i : CatVar::GetList()) print_var(i);
        debug_log.Puts("End of list--");
    }
});

}  // namespace neko::uservar

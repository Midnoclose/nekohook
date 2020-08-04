
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

#include "../framework/entitys.hpp"
#include "../util/catvars.hpp"

#include "misc.hpp"

namespace features::misc {

static CatEnum misc_menu({"Misc"});
static CatEnum namesteal_enum({"OFF", "PASSIVE", "ACTIVE"});
static CatVarEnum namesteal(misc_menu, namesteal_enum, "namesteal", 0,
                            "Name-Stealer");
static CatEnum namesteal_method_enum({"NONE", "\\n", "\\x0F", "wierd comma"});
static CatVarEnum namesteal_method(
    misc_menu, namesteal_method_enum, "namesteal_method", 0,
    "Name-Steal Method",
    "Change untill something works, this is for multi-game purposes");

std::string NameSteal() {
    if (!namesteal) return std::string();

    // TODO, add more methods
    auto ApplyMethod = [](std::string in_str) {
        switch (namesteal_method) {
            case 1:
                in_str = '\n' + in_str;
                break;
            case 2:
                in_str += '\x0F';
                break;
            case 3:
                in_str += " ุ ";
                break;
        }
        return in_str;
    };

    CatEntity* local_ent =
        GetLocalPlayer();  // We probs dont need to check for null or anything
    static std::string last_name;
    std::vector<std::string> potential_names;
    int ent_count = GetEntityCount();
    for (int i = 0; i < ent_count; i++) {
        auto entity = GetEntity(i);

        if (!entity) continue;
        if (entity == (CatEntity*)local_ent) continue;
        if (GetType(entity) != ent::Type::kPlayer) continue;
        if (GetEnemy(entity)) continue;

        std::string ent_name = GetName(entity);
        if (ent_name.empty()) continue;
        if (ent_name ==
            last_name) {  // If we found the entity we stole the name from, we
                          // might want to reuse or avoid
            if (namesteal == 1)  // PASSIVE
                return ApplyMethod(last_name);
            else  // ACTIVE
                continue;
        }

        // Add our entity to the list
        potential_names.push_back(ent_name);
    }

    // We need names to steal >_>
    if (potential_names.empty()) return std::string();

    // Get a random name and return it
    last_name = potential_names.at(rand() % potential_names.size());
    return ApplyMethod(last_name);
}

}  // namespace features::misc

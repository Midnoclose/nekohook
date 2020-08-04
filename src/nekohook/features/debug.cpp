
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

/*
#include <fstream>

#include "framework/drawing.hpp"
#include "framework/entity.hpp"
#include "framework/game.hpp"
#include "framework/uservar.hpp"
#include "features/aimbot.hpp"

#include "features/debug.hpp"

// TODO, draw multipoint

namespace neko::features::debug {

static uservar::StrEnum debug_menu({"debug"});

Command debug_ent_dump(
    "debug_entity_dump", [](const std::vector<std::string_view>&) {
        try {
            std::fstream tmp_log("/tmp/entdump.tmp", std::fstream::out | std::fstream::trunc);
            tmp_log << "Start Entity Info Dump---";
            // General ent info
            auto ent_count = Entity::GetCount();
            tmp_log << "Entity Count: " << ent_count;
            // local
            auto local_ent = Entity::GetLocalPlayer();
            if (!local_ent)
                tmp_log << "\nLocal Entity: Null\n";
            else
                tmp_log << "\nLocal Entity:\n\tThirdperson: " << local_ent->InThirdperson()
                << "\n\tCamera: "
                << std::boolalpha << (local_ent->GetCameraPos() != math::Vector())
                << "\n\tCamera Angles: \n"
                << std::boolalpha << (local_ent->GetCameraAngle() != math::Angle());
            // other
            for (int i = 0; i < ent_count; i++) {

                auto ent = Entity::Get(i);
                tmp_log << "Entity " << i << ": ";
                if (!ent)
                    tmp_log << " Null\n";
                else if (!ent->GetDormant())
                    tmp_log << "Dormant: 0\n";
                else if (!ent->GetAlive())
                    tmp_log << "\n\tDormant: 1\n\tAlive: 0";
                else {
                    math::Vector tmp_vec;
                    math::Box tmp_box;
                    tmp_log << "\n\tDormant: 1\n\tAlive: 1\n\t"
                        "Health: " << ent->GetHealth() << "\n\t"
                        "MaxHealth: " << ent->GetMaxHealth() << "\n\t"
                        "Team: " << static_cast<int>(ent->GetTeam()) << "\n\t"
                        "Type: " << static_cast<int>(ent->GetType()) << "\n\t"
                        "Name: " << ent->GetName() << "\n\t"
                        "Origin: " << std::boolalpha << ent->GetOrigin(tmp_vec) << "\n\t"
                        "Collision: " << std::boolalpha << ent->GetCollision(tmp_box) << "\n\t"
                        "SteamId: " << ent->GetUserId() << "\n";
                }
            }
            tmp_log << "End Entity Info Dump---";
            tmp_log.flush();
        } catch(std::exception err) {
            std::cerr << "Debug Dump Encountered an error: " << err.what() << std::endl;
        } catch(...) {}
    });

uservar::Bool multi_debug(debug_menu, "debug_multipoint", false, "Multipoint");

void DrawTick() {
    // Multipoint shit, its pasted from aimbot so if u change that code, this
    // will need to be remade to fix the math
    if (multi_debug) {
        auto ent_count = Entity::GetCount();
        for (int i = 0; i < ent_count; i++) {
            auto entity = Entity::Get(i);
            if (!entity || entity->GetDormant() || !entity->GetAlive() ||
                entity->GetType() != Entity::Type::kPlayer)
                continue;

            math::Box tmp_bone;
            if (!entity->GetHitbox(Entity::BonePos::kHead, tmp_bone)) continue;

            // So i dont need to do this everywhere :/
            auto draw_pt = [](const math::Vector& in, const RGBColor& color) {
                std::pair<int, int> wts;
                if (!draw::WorldToScreen(in, wts)) return;
                draw::RectFilled({wts.first - 3, wts.second - 3}, {6, 6}, color);
                draw::RectOutline({wts.first - 4, wts.second - 4}, {8, 8}, RGBColor::black);
            };

            // Draw multipoints
            auto ratio = (tmp_bone * ((float)aimbot::multipoint_ratio * 0.01)) /
                         aimbot::multipoint;
            for (int i = 1; i <= aimbot::multipoint; i++)
                for (const auto ii : (ratio * i).GetPoints())
                    draw_pt(ii, RGBColor::white);

            // Draw center, and sides
            draw_pt(tmp_bone.GetCenter(), RGBColor::red);
            draw_pt(tmp_bone.min, RGBColor::red);
            draw_pt(tmp_bone.max, RGBColor::red);
        }
    }
}

}  // namespace features::debug*/

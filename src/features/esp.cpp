
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

#include <string.h>   // strcpy()
#include <algorithm>  // min()

#include "framework/drawing.hpp"
#include "framework/game.hpp"
#include "framework/input.hpp" // Screen size

#include "features/esp.hpp"

namespace neko::features::esp {

uservar::StrEnum esp_menu({"Visuals", "Esp"});  // Menu locator for esp settings
static uservar::Bool esp_enabled(esp_menu, "esp", true, "ESP",
                              "Master esp switch");
// Target selection
static uservar::Bool esp_players(esp_menu, "esp_players", true, "ESP Players",
                              "Whether to esp with players");
static uservar::Bool esp_other_hostile(
    esp_menu, "esp_other_hostile", true, "ESP Other Hostile",
    "Whether to esp with other hostile entitys\nThis is anything not a player "
    "but still hostile to you");
static uservar::StrEnum esp_team_enum({"Enemy", "Friendly", "Both"});
static uservar::Enum esp_team(esp_menu, esp_team_enum, "esp_team", 2, "Team",
                           "Select which team to show esp on.");
// Box esp + Options
static uservar::StrEnum box_esp_enum({"None", "Normal", "Corners"});
static uservar::Enum box_esp(esp_menu, box_esp_enum, "esp_box", 1, "Box",
                          "Draw a 2D box");
static uservar::Int box_corner_size(esp_menu, "esp_box_corner_size", 10,
                                 "Corner Size", "Controls corner box size");
// Strings
static uservar::StrEnum esp_text_position_enum({"TOP RIGHT", "BOTTOM RIGHT", "ABOVE",
                                       "BELOW", "CENTER"});
static uservar::Enum esp_text_position(esp_menu, esp_text_position_enum,
                                    "esp_text_position", 0, "Text position",
                                    "Defines text position");
// Health Esp
static uservar::StrEnum show_health_enum({"None", "Text", "Healthbar", "Both"});
static uservar::Enum show_health(esp_menu, show_health_enum, "esp_health", 3,
                              "Health ESP", "Show health");
static uservar::StrEnum health_bar_pos_enum({"Left", "Right", "Top", "Bottom"});
static uservar::Enum health_bar_pos(esp_menu, health_bar_pos_enum,
                                 "esp_health_bar_pos", 0, "Health Bar Position",
                                 "Where to put the health bar");

// Other strings
static uservar::Bool show_name(esp_menu, "esp_name", true, "Name ESP",
                            "Shows the entity names of entitys");
static uservar::Bool show_distance(esp_menu, "esp_distance", false, "Distance ESP",
                                "Shows distance on entitys");
// Bone esp
static uservar::Bool esp_bone(esp_menu, "esp_bones", true, "Bone ESP",
                           "Shows cached bones");
static uservar::Bool esp_bone_debug(esp_menu, "esp_bones_debug", false,
                                 "Bone ESP debug",
                                 "Shows debug info about bones");
// Tracers
static uservar::StrEnum tracers_enum({"OFF", "CENTER", "BOTTOM"});
static uservar::Enum tracers(
    esp_menu, tracers_enum, "esp_tracers", 2, "Tracers",
    "Draws a line from the player to a position on your screen");
// Other
static uservar::StrEnum box_mode_enum({"Collision", "Bone", "Hitbox"});
static uservar::Enum box_mode(esp_menu, box_mode_enum, "esp_box_mode", 0,
                           "Box mode", "What method to use to get the esp box");
// Pickups
static uservar::Bool show_pickup_health(esp_menu, "esp_pickup_health", false,
                                     "Show health pickups");
static uservar::Bool show_pickup_ammo(esp_menu, "esp_pickup_ammo", false,
                                   "Show ammo pickups");
static uservar::Bool show_pickup_sheild(esp_menu, "esp_pickup_sheild", false,
                                     "Show sheild pickups");

// TODO, draw strings as we get them instead of generating a cache

// Externed, add you functions to get strings onto entities
/*cat::Function<bool(CatEntity*)> ShouldAddBox{[](CatEntity* entity) -> bool {
    auto type = GetType(entity);
    return (esp_players && type == ent::Type::kPlayer) ||
           (esp_other_hostile && type == ent::Type::kOtherHostile);
}};*/

//cat::Function<bool(CatEntity*)> ShouldEsp{[](auto) { return true; }};

//cat::Function<void(std::vector<std::pair<const char*, CatColor>>&, CatEntity*)>
    //GetEntityStrings;

void Draw() {
    /*
    if (!esp_enabled || !game::GetInGame()) return;

    Entity* local_ent = Entity::GetLocalPlayer();
    int ent_count = Entity::GetCount();
    for (int i = 0; i < ent_count; i++) {
        Entity* entity = Entity::Get(i);
        if (!entity || entity->GetDormant()) continue;

        if (local_ent && !local_ent->InThirdperson() && local_ent == entity)
            continue;  // Determine whether to apply esp to local player
        Entity::Type type = entity->GetType();
        if ((type == Entity::Type::kPlayer || type == Entity::Type::kOtherHostile) &&
            !entity->GetAlive())
            continue;  // Dont esp dead players
        if (!entity->ShouldEsp()) continue;
        bool enemy = entity->GetEnemy();
        if (esp_team != 2 && (esp_team == 0 ? !enemy : enemy)) continue;

        enum class State { kEmpty, kOffscreen, kOnscreen };
        State sbox_state = State::kEmpty;
        draw::Point sbox_min = {65536, 65536};
        draw::Point sbox_max = {-65536, -65536};

        // Call this to tell if you're allowed to use the entity box
        // This is lambdad so that we can reuse the local player variables and
        // other things like type, we can also put the sboxes in the stack
        auto HasBox = [&]() -> bool {
            if (sbox_state != State::kEmpty)
                return sbox_state == State::kOnscreen;
            sbox_state = State::kOffscreen;
            auto ExpandWithPoint = [&](const Point& pnt) {
                if (pnt.x > sbox_max.x) sbox_max.x = pnt.x;
                if (pnt.y > sbox_max.y) sbox_max.y = pnt.y;
                if (pnt.x < sbox_min.x) sbox_min.x = pnt.x;
                if (pnt.y < sbox_min.y) sbox_min.y = pnt.y;
            };
            Point wts;
            if (box_mode >= 1) {
                // Collect our bones
                std::vector<math::Box> cur_bones;
                cur_bones.reserve(Entity::BoneCount);
                for (int ii = 0; ii < Entity::BoneCount; ii++) {
                    Entity::Bone tmp;
                    if (entity->GetBone(static_cast<Entity::BonePos>(ii), tmp))
                        cur_bones.push_back(tmp);
                }
                // Recurse and update sbox with bones
                if (!cur_bones.empty()) {
                    for (auto& tmp : cur_bones) {
                        if (box_mode == 1) {  // Bone
                            if (!draw::WorldToScreen(tmp.GetCenter(), wts))
                                return false;
                            ExpandWithPoint(wts);
                        } else {  // Hitbox
                            for (auto pt : tmp.GetPoints()) {
                                if (!draw::WorldToScreen(pt, wts)) return false;
                                ExpandWithPoint(wts);
                            }
                        }
                    }
                    sbox_state = State::kOnscreen;
                    return true;
                }
            }
            // Collision box
            auto points = entity->GetCollision().GetPoints();
            for (auto& pt : points) {
                if (!draw::WorldToScreen(pt, wts)) return false;
                ExpandWithPoint(wts);
            }

            sbox_state = State::kOnscreen;
            return true;
        };

        auto ent_color = colors::EntityColor(entity);

        // Check if main esp features should apply
        if ((esp_players && type == Entity::Type::kPlayer) ||
            (esp_other_hostile && type == Entity::Type::kOtherHostile)) {
            if (tracers) {
                draw::Point scn;
                if (draw::WorldToScreen(entity->GetOrigin(), scn)) {
                    auto bounds = input::GetBounds();
                    draw::Line(scn, bounds.first / 2 - scn.first,
                        ((tracers == 2) ? bounds.second : bounds.second / 2) -
                            scn.second,
                        ent_color);
                }
            }

            // Bone esp
            if (esp_bone) {
                static const std::initializer_list<Entity::BonePos> bonesets[] = {
                    {ent::Bone::kHead, ent::Bone::kSpineTop,
                     ent::Bone::kSpineUpper, ent::Bone::kSpineMiddle,
                     ent::Bone::kSpineLower,
                     ent::Bone::kSpineBottom},  // Center
                    {ent::Bone::kLLowerArm, ent::Bone::kLMiddleArm,
                     ent::Bone::kLUpperArm, ent::Bone::kSpineTop,
                     ent::Bone::kRUpperArm, ent::Bone::kRMiddleArm,
                     ent::Bone::kRLowerArm},  // Upper limbs
                    {ent::Bone::kLLowerLeg, ent::Bone::kLMiddleLeg,
                     ent::Bone::kLUpperLeg, ent::Bone::kSpineBottom,
                     ent::Bone::kRUpperLeg, ent::Bone::kRMiddleLeg,
                     ent::Bone::kRLowerLeg}  // Lower limbs
                };
                for (const auto& current_set : bonesets) {

                    // Setup our last bone
                    Entity::Bone last_bone;

                    auto ii = current_set.begin();
                    auto end = current_set.end();
                    for (;ii != end; ii++)
                        if (entity->GetBone(*ii, last_bone))
                            break;

                    // Finish rest of the bones
                    if (ii != end) {
                        for (;ii != end; ii++) {
                            Entity::Bone cur_bone;
                            if (entity->GetBone(*ii, cur_bone)) {
                                draw::Point wts1, wts2;
                                bool pass1 = draw::WorldToScreen(cur_bone, wts1);
                                bool pass2 = draw::WorldToScreen(last_bone, wts2);
                                if (pass1 || pass2) {
                                    draw::Line(wts1, wts2 - wts1, ent_color);
                                    last_bone = cur_bone;
                                }
                            }
                        }
                    }
                }

                // Debug for bone esp, prints strings on screen of what bone is
                // being represented
                // TODO, put in debug.cpp
                if (esp_bone_debug) {
                    for (int ii = 0; ii < Entity::BoneCount; ii++) {
                        Entity::Bone tmp;
                        if (!GetBoneCenter(entity, static_cast<ent::Bone>(ii), tmp))
                            continue;
                        std::pair<int, int> wts;
                        if (!draw::WorldToScreen(tmp, wts))
                            continue;
                        std::string buf = "B:" + std::to_string(ii);
                        draw::String(buf, wts, colors::white);
                    }
                }
            }

            if (box_esp) {
                if (HasBox()) {
                    draw::RectOutline(sbox_min + 1, sbox_max - sbox_min - 2, ent_color);
                    draw::RectOutline(sbox_min, sbox_max - sbox_min, colors::black);
                    draw::RectOutline(sbox_min + 2, sbox_max - sbox_min - 4, colors::black);
                }
            }

            // Health bars
            if ((int)show_health >= 2) {
                if (GetEntityBox()) {
                    // TODO, add right, top, and bottom health bars
                    // Get in bar height
                    int hbh = (sbox_max.y - sbox_min.y - 2) *
                              std::min(static_cast<float>(entity->GetHealth()) /
                                           static_cast<float>(entity->GetMaxHealth()),
                                       1.0f);

                    draw::RectOutline(sbox_min.x - 7, sbox_min.y, 7,
                               sbox_max.y - sbox_min.y,
                               colors::black);
                    draw::RectFilled(sbox_min.x - 6,
                                     sbox_max.y - hbh - 1, 5, hbh,
                                     colors::Health(entity));
//                    					// Get in bar fill
//                       percentage float fill = std::min((float)GetHealth(entity)
//                       / (float)GetMaxHealth(entity), 1.0f);
//
//                                                            switch(health_bar_pos_enum)
//                       { case 0: // left
//                                                                    // Draw the
//                       infill draw::RectFilled(sbox_min.first - 6,
//                       sbox_max.second - hbh - 1, 5, hbh,
//                       colors::Health(entity));
//                                                                    // Draw
//                       outline draw::Rect(sbox_min.first - 7, sbox_min.second,
//                       7, sbox_max.second - sbox_min.second, colors::black);

//                                                            }
                }
            }
        }

        // Strings

        // Get our strings
        std::vector<std::pair<std::string_view, RGBColor>> str_cache;
        switch (type) {
            case Entity::Type::kPlayer:
            case Entity::Type::kOtherHostile:
                if (show_name)
                    str_cache.push_back({entity->GetName(), ent_color});
                if (show_health == 1 || show_health == 3) {
                    static std::string buf;
                    buf = std::to_string(entity->GetHealth()) + "/" +
                                         std::to_string(entity->GetMaxHealth()) +
                                         "HP";
                    str_cache.push_back({buf, colors::Health(entity)});
                }
                if (show_distance) {
                    static std::string buf;
                    buf = std::to_string((int)GetDistance(entity)) + "m";
                    str_cache.push_back({buf, colors::white});
                }
                break;
            case ent::Type::kPickupHealth:
                if (show_pickup_health)
                    str_cache.push_back({"[Health]", colors::green});
                break;
            case ent::Type::kPickupAmmo:
                if (show_pickup_ammo)
                    str_cache.push_back({"[Ammo]", colors::lightgray});
                break;
            case ent::Type::kPickupSheild:
                if (show_pickup_sheild)
                    str_cache.push_back({"[Sheild]", colors::yellow});
                break;
        }

        // Get module to write strings
        module::GetEntityStrings(str_cache, entity);

        // TODO, find reason why strings are spaced too far apart
        // Check if there is strings to draw
        if (!str_cache.empty()) {
            // Get world to screen
            draw::Point draw_point;
            if (draw::WorldToScreen(entity->GetOrigin(), draw_point)) {
                // Change draw point if needed & determine wheter we center the
                // strings
                bool center_strings = true;
                if (sbox_state == State::kOnscreen &&
                    esp_text_position < 4) {  // Check if we have an entity box
                    center_strings = false;   // Dont center strings

                    switch (esp_text_position) {
                        case 0:  // TOP RIGHT
                            draw_point = {sbox_max.x + 2, sbox_min.y};
                            break;
                        case 3:  // BELOW
                            center_strings = true;
                            draw_point = {sbox_min.x, sbox_max.y};
                            break;
                        case 2:  // ABOVE
                            center_strings = true;
                        case 1: {  // BOTTOM RIGHT
                            // Get our height
                            int total_height = 0;
                            for (const auto& str : str_cache)
                                total_height +=
                                    draw::GetStringLength(
                                        str.first, draw::default_font,
                                        draw::default_font_size)
                                        .second;

                            if (esp_text_position == 1)  // BOTTOM RIGHT
                                draw_point = {sbox_min.x,
                                              sbox_min.y - total_height};
                            else  // ABOVE
                                draw_point = {sbox_max.x + 2,
                                              sbox_max.y - total_height};
                        }
                    }
                }

                // Draw our stringsDraw
                // Loop through strings
                for (const auto& str : str_cache) {
                    // Get string sizes
                    auto size = draw::GetStringLength(
                        str.first, draw::default_font, draw::default_font_size);

                    if (center_strings)  // Centered strings
                        draw::String(str.first,
                                     {draw_point.x - size.first / 2,
                                     draw_point.y}, draw::default_font,
                                     draw::default_font_size, str.second);
                    else  // Not centered
                        draw::String(str.first, draw_point, draw::default_font,
                                     draw::default_font_size, str.second);

                    // Lower draw point for recursions
                    draw_point.second += size.second;
                }
            }
        }
    }*/
}

}  // namespace features::esp

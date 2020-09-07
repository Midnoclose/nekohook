
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

#include <string.h>
#include <algorithm> 

#include "nekohook/ui/var.hpp"
#include "nekohook/gfx/geometry.hpp"

#include "esp.hpp"

namespace nekohook::features::esp {

namespace ui {
using namespace nekohook::ui;
TreeMap menu({"Visuals", "Esp"});

static Var<bool> enabled(menu, "Enabled", true);
// Target selection
static Var<bool> do_players(menu, "Players", true);
static Var<bool> do_other_hostile(menu, "Other Hostile", true);
static Var<Enum> do_team(menu, "Team", 2, {"Enemy", "Friendly", "Both"});
// Box esp + Options
static Var<Enum> show_box(menu, "Box", 1, {"None", "Normal", "Corners"});
static Var<int> corner_size(menu, "Box Corner Size", 10);
// Strings
static Enum side_pos_enum({"Top", "Bottom", "Left", "Right"});
static Enum align_enum();
static Var<Enum> text_side(menu, "Text Side", 2, side_pos_enum);
static Var<Enum> text_align(menu, "Text alignment", 0, {"Left", "Right", "Center"});
static Var<bool> text_align_force(menu, "Text alignment force", false);
static Var<Enum> text_box_align(menu, "Text box alignment", 0, {"Top", "Bottom"});
// Health Esp
static Var<Enum> show_health(menu, "Health", 3, {"None", "Text", "Healthbar", "Both"});
static Var<Enum> health_bar_pos(menu, "Health Bar Position", 0, side_pos_enum);

// Other strings
static Var<bool> show_name(menu, "Name", true);
static Var<bool> show_distance(menu, "Distance", false);
// Bone esp
static Var<bool> show_bone(menu, "Bones", true);
static Var<bool> show_bone_debug(menu, "Bones Debug", false);
// Tracers
static Enum tracers_enum();
static Var<Enum> show_tracers(menu, "Tracers", 2, {"OFF", "CENTER", "BOTTOM"});
// Other
static Var<Enum> box_method(menu, "Box Method", 0, {"Collision", "Bone", "Hitbox"});
static Var<bool> box_fallthrough(menu, "Box Method Fallthrough", false); 
// Pickups
static Var<bool> show_pickup_health(menu, "Health Pickups", false);
static Var<bool> show_pickup_ammo(menu, "Ammo Pickups", false);
static Var<bool> show_pickup_sheild(menu, "Sheild", false);
}

// TODO: better esp "types" using an enum and switch
// FIXME: other healthbar options

// Externed, add you functions to get strings onto entities
/*cat::Function<bool(CatEntity*)> ShouldAddBox{[](CatEntity* entity) -> bool {
    auto type = GetType(entity);
    return (esp_players && type == ent::Type::kPlayer) ||
           (esp_other_hostile && type == ent::Type::kOtherHostile);
}};*/

//cat::Function<bool(CatEntity*)> ShouldEsp{[](auto) { return true; }};

//cat::Function<void(std::vector<std::pair<const char*, CatColor>>&, CatEntity*)>
    //GetEntityStrings;

// WTS Box generator
class BoxData {
    enum class State { kUnchecked, kUnuseable, kUseable };
    State state = State::kUnchecked;
    gfx::Box box = {{65536, 65536}, {0, 0}};
    static std::vector<Entity::Bone> GetBones(Entity* entity) {
        std::vector<Entity::Bone> bones;
        bones.reserve(Entity::BonePos::kCount);

        for (int i = 0; i < Entity::BonePos::kCount; i++) {
            std::optional<Entity::Bone> bone;
            if ((bone = entity->GetBone(Entity::BonePos(i))))
                bones.push_back(*bone);
        }
        return bones;
    }
    static std::vector<Entity::Hitbox> GetBoxes(Entity* entity) {
        std::vector<Entity::Hitbox> boxes;
        boxes.reserve(Entity::BonePos::kCount);

        for (int i = 0; i < Entity::BonePos::kCount; i++) {
            std::optional<Entity::Hitbox> box;
            if ((box = entity->GetHitbox(Entity::BonePos(i))))
                boxes.push_back(*box);
        }
        return boxes;
    }
public:
    bool MakeUseable(Entity* entity) { 
        if (this->state != State::kUnchecked)
            return this->state == State::kUseable;
        this->state = State::kUnuseable;
        
        gfx::WTS wts_res;
        switch(ui::box_method) {
        case 2: { // Hitbox
            const auto hitboxes = GetBoxes(entity);
            if (!hitboxes.empty()) {
                for (const auto i : hitboxes) {
                    for (const auto ii : i.GetPoints()) {
                        if (!std::get<bool>(wts_res = gfx::FromWorld(ii)))
                             return false;
                        this->box.ExpandTo(std::get<gfx::Point>((wts_res)));
                    }
                }
                this->state = State::kUseable;
                if (!ui::box_fallthrough)
                    break; 
            }
        } 
        case 1: { // Bones
            const auto bones = GetBones(entity);
            if (!bones.empty()) {
                for (const auto i : bones) {
                    if (!std::get<bool>(wts_res = gfx::FromWorld(i)))
                        return false;
                    this->box.ExpandTo(std::get<gfx::Point>(wts_res));
                }
                this->state = State::kUseable;
                if (!ui::box_fallthrough)
                    break; 
            }
        }
        case 0: {
            std::optional<Entity::Hitbox> collision;
            if ((collision = entity->GetCollision())) {
                auto points = collision.value().GetPoints();
                for (auto& i : points) {
                    if (!std::get<bool>(wts_res = gfx::FromWorld(i))) 
                        return false;
                    this->box.ExpandTo(std::get<gfx::Point>(wts_res));
                }
                this->state = State::kUseable;
            }
            break;
        }
        default:
            assert(false);
        }        
        return this->state == State::kUseable;
    }
    bool IsUseable() const { return this->state == State::kUseable; }
    const geo::Box<gfx::Point>& GetBox() const { 
        assert(this->IsUseable());
        return this->box;
    }
};
/*
void DrawTracer(Entity* entity, const gfx::Color& clr);
void DrawTracer(Entity* entity, const BoxData&, const gfx::Color& clr) {
    // TODO, draw to bottom of box
    DrawTracer(entity, clr);
}
void DrawTracer(Entity* entity, const gfx::Color& clr) {
    
    if (std::optional<geo::Vec3> origin = entity->GetOrigin()) {
        gfx::Point bounds = gfx::GetScreenSize();
        gfx::Point center = {bounds.x / 2, bounds.y};
        if (ui::show_tracers == 2)
            center.y /= 2;
        gfx::Line(center, *gfx::WTS(*origin), clr);
    }
}

static const std::initializer_list<Entity::BonePos> bonemap[] = {
    {Entity::BonePos::kHead, Entity::BonePos::kSpineTop,
     Entity::BonePos::kSpineUpper, Entity::BonePos::kSpineMiddle,
     Entity::BonePos::kSpineLower,
     Entity::BonePos::kSpineBottom},  // Center
    {Entity::BonePos::kLLowerArm, Entity::BonePos::kLMiddleArm,
     Entity::BonePos::kLUpperArm, Entity::BonePos::kSpineTop,
     Entity::BonePos::kRUpperArm, Entity::BonePos::kRMiddleArm,
     Entity::BonePos::kRLowerArm},  // Upper limbs
    {Entity::BonePos::kLLowerLeg, Entity::BonePos::kLMiddleLeg,
     Entity::BonePos::kLUpperLeg, Entity::BonePos::kSpineBottom,
     Entity::BonePos::kRUpperLeg, Entity::BonePos::kRMiddleLeg,
     Entity::BonePos::kRLowerLeg}  // Lower limbs
};

void DrawBones(Entity* entity, const gfx::Color& clr) {
    for (const auto& i : bonemap) {
        auto ii = i.begin();
        auto end = i.end();

        Entity::Bone cur_bone;
        for (; ii != end; ii++) {
            if (auto bone = entity->GetBone(*ii)) {
                cur_bone = *bone;
                break;
            }
        }
        if (ii != end)
            ii++;

        gfx::WTS cur_wts = gfx::WTS(cur_bone);
        for (;ii != end; ii++) {
            if (auto swap_bone = entity->GetBone(*ii)) {
                gfx::WTS swap_wts = *swap_bone;
                if (cur_wts || swap_wts)
                    gfx::Line(*cur_wts, *swap_wts - *cur_wts, clr);
                cur_bone = *swap_bone;
                cur_wts = swap_wts;
            }
        }
    }

    if (ui::show_bone_debug) {
        for (int ii = 0; ii < Entity::BonePos::kCount; ii++) {
            std::optional<Entity::Bone> bone;
            if ((bone = entity->GetBone(Entity::BonePos(ii))))
                if (gfx::WTS wts_result = *bone) 
                    gfx::Font::GetDefault().Draw("B:" + std::to_string(ii), *wts_result, gfx::Color::white);
        }
    }
}

static void DrawBox(Entity* entity, BoxData& box_data, gfx::Color& clr) {
    auto box = box_data.GetBox();
    gfx::RectOutline(box.min - 1, box.max + 2, gfx::Color::black);
    gfx::RectOutline(box.min + 1, box.max - 2, gfx::Color::black);
    gfx::RectOutline(box.min,     box.max,     clr);
}
static void DrawHealthBar(Entity* entity, BoxData& box_data, gfx::Color& clr) {
    auto box = box_data.GetBox();
    
    constexpr int bar_spacing = 7;
    constexpr int girth = 6;
    float health_percentage = std::min(static_cast<float>(entity->GetHealth()) / static_cast<float>(entity->GetMaxHealth()), 1.0f);
    
    geo::Box<gfx::Point> bar_box;
    geo::Box<gfx::Point> health_box;
    switch(int(ui::health_bar_pos)) {
    case 0: { // Left
         bar_box = {
            {box.min.x - (bar_spacing + girth), // shift right 
                box.min.y + 3}, // reduce top spacing
            {girth, 
                box.max.y - 3} // reduce bottom spacing
        };
        health_box = bar_box;
        int shift = health_box.max.y - (health_box.max.y * health_percentage length);
        health_box.min.y += shift; // shift top down // TODO: shrink
        health_box.max.y -= shift; // shift bottom back up
        box_data.Expand(BoxData::Direction::kLeft, bar_spacing + girth);
        break;
    }
    case 1: { // Right
        bar_box = {
            {box.min.x + box.max.x + bar_spacing, // shift right 
                box.min.y + 3}, // reduce top spacing
            {girth, 
                box.max.y - 3} // reduce bottom spacing
        };
        health_box = bar_box;
        int shift = health_box.max.y - (health_box.max.y * health_percentagelength*);
        health_box.min.y += shift; // shift top down
        health_box.max.y -= shift; // shift bottom back up
        box_data.Expand(BoxData::Direction::kRight, bar_spacing + girth);
        break;
    }
    case 2: { // Top 
        bar_box = {
            {box.min.x + 3, // reduce left spacing
                box.min.y - bar_spacing + girth}, // shift up
            {, 
                girth} // reduce bottom spacing
        };
        health_box = bar_box;
        int shift = health_box.max.y - (health_box.max.y * health_percentagelength);
        health_box.min.y += shift; // shift top down
        health_box.max.y -= shift; // shift bottom back up
        box_data.Expand(BoxData::Direction::kUp, bar_spacing + girth);
        break;
    }
    case 3: { // Bottom

        break;
    }
    default:
        assert(false);
    };
    gfx::RectOutline(bar_box.min - 1, bar_box.max + 1, gfx::Color::black);
    gfx::RectFilled(health_box.min, health_box.max, entity->GetHealthColor());
}

class StringDrawer {
    enum class Pos {
        kTop,
        kBottom,
        kLeft,
        kRight,
    } pos;
    enum class Align {
        kLeft,
        kRight,
        kCenter
    } align;
    int cur_y = 0;
public:
   
    StringDrawer(Entity&, const BoxData& box, const gfx::Color& clr) {
        if (box.IsUseable()) {
            switch(text_side) {
            case 0: // Top
            case 1: // Bottom
                this->align = Align::kCenter; break;
            case 2: // Left
                this->align = Align::kRight; break;
            case 3: // Right
                this->align = Align::kLeft; break;
            }
        } else {
            this->align = Align((int)text_align);
        
        // Get String starting pos
        switch () {
        case 0:
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
                    gfx::GetStringLength(
                        str.first, gfx::default_font,
                        gfx::default_font_size)
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

    }
    Draw();
    Finish();
};

void Draw() {
    if (!ui::enabled || !game::GetInGame()) return;

    LocalPlayer* local_ent = Entity::GetLocalPlayer();
    const bool is_thirdperson = local_ent->IsThirdperson();

    int ent_count = Entity::GetCount();
    for (int i = 0; i < ent_count; i++) {
        Entity* entity = Entity::Get(i);
        
        {
            if (!entity || entity->IsDormant()) continue;
            if (local_ent && !is_thirdperson && local_ent == entity) continue;
            if (!module::ShouldEsp(entity)) continue;
            bool enemy = entity->IsEnemy();
            if (ui::do_team != 2 && (ui::do_team == 0 ? !enemy : enemy)) continue;
        }
        // TODO: cache entitys, rank by furthest distance first, and draw on them from furthest to closest. use reserve!!!
        
        auto clr = entity->GetColor();
        Entity::Type type = entity->GetType();
        if ((ui::do_players && type == Entity::Type::kPlayer) ||
            (ui::do_other_hostile && type == Entity::Type::kOtherHostile)) {
            if (!entity->IsAlive()) 
                continue;

            BoxData box;
            box.MakeUseable(entity);

            if (ui::show_tracers) 
                DrawTracer(entity, box, clr);

            if (ui::show_bone)
                DrawBones(entity, clr);

            if (ui::show_box)
                DrawBox(entity, box, clr);
            
            if (ui::show_health >= 2) 
                DrawHealthBar(entity, box, clr);
                
        }

        // Strings
        StartDrawSrrings();
        
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
            gfx::Point draw_point;
            if (gfx::WorldToScreen(entity->GetOrigin(), draw_point)) {
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
                                    gfx::GetStringLength(
                                        str.first, gfx::default_font,
                                        gfx::default_font_size)
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
                    auto size = gfx::GetStringLength(
                        str.first, gfx::default_font, gfx::default_font_size);

                    if (center_strings)  // Centered strings
                        gfx::String(str.first,
                                     {draw_point.x - size.first / 2,
                                     draw_point.y}, gfx::default_font,
                                     gfx::default_font_size, str.second);
                    else  // Not centered
                        gfx::String(str.first, draw_point, gfx::default_font,
                                     gfx::default_font_size, str.second);

                    // Lower draw point for recursions
                    draw_point.second += size.second;
                }
            }
        }
    }
}
*/
}  // namespace features::esp

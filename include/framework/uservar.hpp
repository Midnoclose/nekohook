
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

#pragma once

#include <string>
#include <vector>

#include <neko/color.hpp>

#include "framework/console.hpp"
#include "framework/input.hpp"  // CatVarKey uses it to look for catkeys as well as its Depressed Function

namespace neko::uservar {

using StrEnum = std::initializer_list<std::string_view>;

class Base {
   protected:
    enum class Type {
        kBool,
        kInt,
        kKey,
        kEnum,
        kFloat,
        kString,
        kColor,
        kFont
    } type;
    Base(StrEnum _gui_map,
         std::string_view _com_name, std::string_view _gui_name,
         std::string_view _desc, Type);

   public:
    const std::vector<std::string_view> gui_map;
    const std::string command_name;
    const std::string_view gui_name;
    const std::string_view desc;

    // Getters
    inline Type GetType() { return this->type; }
    virtual std::string GetValue() = 0;  // Used by cfg mgr and gui
    static inline const auto& GetList() { return list; }

    virtual void Callback(
        const std::vector<std::string_view>&) = 0;  // for command line
    static inline FastEvent<Base*> change_event;

   private:
    // :b:ig peen
    static inline std::vector<Base*> list;
};

// CatVar varients
class Bool : public Base {
   public:
    Bool(StrEnum _gui_map,
         std::string_view _com_name, bool _defaults, std::string_view _gui_name,
         std::string_view _desc = "Unknown")
        : Base(_gui_map, _com_name, _gui_name, _desc, Base::Type::kBool),
          defaults(_defaults),
          value(_defaults) {}

    inline operator bool() const { return value; }
    inline bool operator==(bool in_value) const { return value == in_value; }

    const bool defaults;
    bool value;

    void operator=(bool);
    virtual void Callback(const std::vector<std::string_view>&);
    virtual std::string GetValue();
};
class Int : public Base {
   public:
    Int(StrEnum _gui_map,
        std::string_view _com_name, int _defaults, std::string_view _gui_name,
        std::string_view _desc, int _min, int _max)
        : Base(_gui_map, _com_name, _gui_name, _desc, Base::Type::kInt),
          defaults(_defaults),
          value(_defaults),
          min(_min),
          max(_max) {}
    Int(StrEnum _gui_map,
        std::string_view _com_name, int _defaults, std::string_view _gui_name,
        std::string_view _desc = "Unknown", int _max = 100)
        : Int(_gui_map, _com_name, _defaults, _gui_name, _desc, 0, _max) {}

    inline operator int() const { return value; }
    inline bool operator==(int in_value) const { return value == in_value; }

    const int defaults;
    int value;
    const int min;
    const int max;

    void operator=(int);
    virtual void Callback(const std::vector<std::string_view>&);
    virtual std::string GetValue();
};
class Key : public Base {
   public:
    Key(StrEnum _gui_map,
        std::string_view _com_name, input::Key _defaults,
        std::string_view _gui_name, std::string_view _desc = "Unknown")
        : Base(_gui_map, _com_name, _gui_name, _desc, Base::Type::kKey),
          value(_defaults),
          defaults(_defaults) {}

    inline operator input::Key() const { return value; }
    inline bool operator==(input::Key in_value) const { return value == in_value; }
    inline bool Depressed() const {
        return this->value != input::Key::kNone ? input::GetKey(this->value) : true;
    }

    const input::Key defaults;
    input::Key value;

    void operator=(input::Key);
    virtual void Callback(const std::vector<std::string_view>&);
    virtual std::string GetValue();
};
class Enum : public Int {
   public:
    Enum(StrEnum _gui_map,
         StrEnum _cat_enum,
         std::string_view _com_name, int _defaults, std::string_view _gui_name,
         std::string_view _desc = "Unknown")
        : Int(_gui_map, _com_name, _defaults, _gui_name, _desc, 0,
              _cat_enum.size()),
          cat_enum(_cat_enum) {
        type = Base::Type::kEnum;
    }
    const std::vector<std::string_view> cat_enum;

    inline void operator=(int i) { this->Int::operator=(i); }
    virtual void Callback(const std::vector<std::string_view>&);
    virtual std::string GetValue();
};
class Float : public Base {
   public:
    Float(StrEnum _gui_map,
          std::string_view _com_name, float _defaults,
          std::string_view _gui_name, std::string_view _desc, float _min,
          float _max)
        : Base(_gui_map, _com_name, _gui_name, _desc, Base::Type::kFloat),
          defaults(_defaults),
          value(_defaults),
          min(_min),
          max(_max) {}
    Float(StrEnum _gui_map,
          std::string_view _com_name, float _defaults,
          std::string_view _gui_name, std::string_view _desc = "Unknown",
          float _max = 100)
        : Float(_gui_map, _com_name, _defaults, _gui_name, _desc, 0, _max) {}

    inline operator float() const { return value; }
    inline bool operator==(float in_value) const { return value == in_value; }

    const float defaults;
    float value;
    const float min;
    const float max;

    void operator=(float);
    virtual void Callback(const std::vector<std::string_view>&);
    virtual std::string GetValue();
};
class String : public Base {
   public:
    String(StrEnum _gui_map,
           std::string_view _com_name, std::string_view _defaults,
           std::string_view _gui_name, std::string_view _desc)
        : Base(_gui_map, _com_name, _gui_name, _desc, Base::Type::kString),
          defaults(_defaults),
          value(_defaults) {}

    inline operator std::string() const { return value; }
    inline bool operator==(std::string_view in_value) const {
        return value == in_value;
    }

    const std::string_view defaults;
    std::string
        value;  // std::string is perfectly acceptible due to the fact that its
                // mostly static and its extra features are nice

    void operator=(std::string_view);
    virtual void Callback(const std::vector<std::string_view>&);
    virtual std::string GetValue();
};
class Color : public Base {
   public:
    Color(StrEnum _gui_map,
          std::string_view _com_name, RGBColor _defaults,
          std::string_view _gui_name, std::string_view _desc)
        : Base(_gui_map, _com_name, _gui_name, _desc, Base::Type::kColor),
          defaults(_defaults),
          value(_defaults) {}

    inline operator RGBColor() const {
        return rainbow ? RGBColor::Rainbow() : value;
    }
    inline bool operator==(const RGBColor& in_value) const {
        return value == in_value;
    }

    const RGBColor defaults;
    RGBColor value;

    void SetRainbow(bool);
    void operator=(const RGBColor&);
    virtual void Callback(const std::vector<std::string_view>&);
    virtual std::string GetValue();

   private:
    bool rainbow = false;  // Change to set color to rainbow
};

// Class to store how the menu is layed out
class MenuTree {
   private:
    MenuTree(std::string_view _name) : name(_name) {}
    static void Expand(Base*);
    friend Base;
    static MenuTree root;
   public:
    const MenuTree& GetMenuMap() { return root; }
    const std::string_view name;
    std::vector<MenuTree> branches;
    std::vector<Base*> cat_children;  // Nyaa~ :3
};
inline MenuTree MenuTree::root("root");

}

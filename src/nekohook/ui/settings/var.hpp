
#include <variant>

#include "ui/command.hpp"

#pragma once

namespace nekohook::setting {

template<typename T>
class Var;

using StrEnum = std::initializer_list<std::string_view>;
using TreeMap = StrEnum;

class BaseVar {
public:
    BaseVar(TreeMap _tree_map, std::string_view gui_name);
    enum class Type {
        kBool,
        kInt,
        kKey,
        kEnum,
        kFloat,
        kString,
        kColor,
        kFont
    };

    const std::string command_name;
    const std::string_view gui_name;

    virtual Type GetType() = 0;
    virtual void Call(Command::Args) = 0;
    virtual std::string GetString() = 0;  // Used by cfg mgr and gui
    virtual void SetString(std::string_view) = 0;
private:
    static inline std::vector<std::variant<Var<bool>*, Var<int>*, Var<float>*, >> list;
public:
    static inline const auto& GetList() { return list; }
};

template<typename T>
class Var {
public:
    Var(TreeMap, std::string_view _gui_name, T _defaults);
    
};

}

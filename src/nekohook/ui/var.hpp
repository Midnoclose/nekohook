
#include <variant>

#include "ui/command.hpp"

#pragma once

namespace nekohook::ui {

template<typename T>
class Var;

using Enum = std::initializer_list<std::string_view>;
using TreeMap = std::initializer_list<std::string_view>;

class BaseVar {
public:
    enum class Type {
        kBool,
        kInt,
        kFloat,
        kKey,
        kEnum,
        kString,
        kColor,
        kFont
    };
    const Type type;
    BaseVar(Type, TreeMap, std::string_view _gui_name);

    const std::string command_name;
    const std::string_view gui_name;

    virtual void Call(Command::Args) = 0;
    virtual std::string GetString() = 0;  // Used by cfg mgr and gui
    virtual void SetString(std::string_view) = 0;
private:
    static inline std::vector<BaseVar*> list;
public:
    static inline const auto& GetList() { return list; }
};

template<typename T>
class Var : public BaseVar {
public:
    Var(TreeMap, std::string_view _gui_name, T _defaults);
    
    std::string GetString() override;
    void SetString(std::string_view) override;
    void Call(Command::Args) override;

    operator T() const { return this->value; }
    bool operator==(T v) const { return this->value == v; }
private:
    T value;
public:
    const T defaults;
};

template<typename T>
class MathVar : public BaseVar {
public:
    MathVar(TreeMap, std::string name, T _defaults, T min, T max);
    MathVar(TreeMap, std::string name, T _defaults, T max = 100);
    std::string GetString() override;
    void SetString(std::string_view) override;
    void Call(Command::Args) override;

    inline operator T() const { return this->value; }
    inline bool operator==(T v) const { return this->value == v; }
private:
    T value;
public:
    const T defaults, min , max;
};

template<>
class Var<int> : public MathVar<int> {
using MathVar<int>::MathVar;
};
template<>
class Var<float> : public MathVar<float> {
using MathVar<float>::MathVar;
};

template<>
class Var<Enum> : public Var<int> {
public:
    Var<Enum>(TreeMap, std::string_view name, int _defaults, Enum _enum);
    std::string GetString() override;
    void SetString(std::string_view) override;
    void Call(Command::Args) override;
public:
};

}

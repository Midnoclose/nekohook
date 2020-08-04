
#pragma once

#include "var.hpp"

namespace nekohook::setting {

template<typename T>
class MathVar : public Var {
public:
    MathVar(TreeMap _tree_map, std::string name, T _defaults, T min, T max);
    MathVar(TreeMap _tree_map, std::string name, T _defaults, T max = 100);
    Type GetType() override;
    std::string GetString() override;
    void SetString(std::string_view) override;
    void Call(Command::Args) override;

    inline operator T() const { return this->value; }
    inline bool operator==(T in_value) const { return this->value == in_value; }
private:
    T value;
    const T min , max;
};

using Int = MathVar<int>;
using Float = MathVar<float>;

}

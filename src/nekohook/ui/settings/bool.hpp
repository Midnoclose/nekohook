
#pragma once

#include "var.hpp"

namespace nekohook::setting {

class Bool : public Var {
public:
    Bool(TreeMap, std::string name, bool _defaults);
    Type GetType() override;
    std::string GetString() override;
    void SetString(std::string_view) override;
    void Call(Command::Args) override;

    inline operator bool() const { return this->value; }
    inline bool operator==(bool in_value) const { return this->value == in_value; }
public:
    bool value;
    const bool defaults;
};

}

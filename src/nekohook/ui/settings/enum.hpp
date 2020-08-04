

#pragma once

#include "math.hpp"

namespace nekohook::setting {

class Enum : public Int {
public:
    Enum(StrEnum gui, StrEnum _enum, std::string name, int _defaults);
    Type GetType() override;
    std::string GetString() override;
    void SetString(std::string_view) override;
    void Call(Command::Args) override;

    //bool operator bool();
    //bool operator =(bool i);

public:
    bool value;
    const bool defaults;
};


// Magic enum/boost???
/*template<class T...>
class Enum {
public:
    constexpr Enum(std::initializer_list<std::string_view>) {

    }
};
#define MAKE_ENUM_CONVERT(arg1, args...) ({##arg1, args...
MAKE_ENUM(_name, args...) (Enum _name
*/

}


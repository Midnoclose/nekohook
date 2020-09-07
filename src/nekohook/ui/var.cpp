
#include <cmath>

//#include "ui/gfx/gfx.hpp"
#include "nekohook/ui/command.hpp"

#include "var.hpp"

namespace nekohook::ui {

static std::string GetCommandName(const TreeMap& _gui_map, std::string_view name) {
    auto ToLower = [](std::string_view str) -> std::string {
        std::string ret(str);
        for (char& i : ret)
            i = tolower(i);
        return ret;
    };

    std::string ret = ToLower(Command::kPrefix); assert(ret.back() != '_');
    for (std::string_view i : _gui_map) { assert((i.find_first_of(" _") == std::string_view::npos));
        ret += '_' + ToLower(i);
    }
    
    std::string new_name = ToLower(name);
    for (char& i : new_name)
        if (i == ' ')
            i = '_';

    return ret + new_name;
}

BaseVar::BaseVar(Type _type, TreeMap _gui_map, std::string_view _gui_name) 
    : command_name(GetCommandName(_gui_map, _gui_name)), type(_type) {
    BaseVar::list.push_back(this);
    //gui::Register(std::move(_gui_map), this);
}

Var<bool>::Var(TreeMap _gui_map, std::string_view _gui_name, bool _defaults)
    : BaseVar(BaseVar::Type::kBool, std::move(_gui_map), _gui_name), defaults(_defaults) {}
std::string Var<bool>::GetString() { return this->value ? "true" : "false"; }
void Var<bool>::SetString(std::string_view i) {
    if (i == "true")
        *this = true;
    else if(i == "false")
        *this = false;
    else 
        *this = std::stoi(static_cast<std::string>(i));
}
void Var<bool>::Call(std::ostream& out, Command::Args a) {
    if (a.empty())
        out << "Set Variable Usage: " << this->command_name << "<boolean>" << std::endl;
    else
        this->SetString(a.at(0));
}
void Var<bool>::SetDefault() { *this = this->defaults; }
Var<bool>& Var<bool>::operator=(bool v) {
    if (v != this->value) {
        if (this->Callback)
            this->Callback(v);
        this->value = v;
    }
    return *this; 
}

Var<int>::Var(TreeMap _gui_map, std::string_view _gui_name, int _defaults, int _min, int _max) 
    : BaseVar(BaseVar::Type::kInt, std::move(_gui_map), _gui_name), defaults(_defaults), min(_min), max(_max) {}
Var<int>::Var(TreeMap _gui_map, std::string_view _gui_name, int _defaults, int _max) 
    : Var(std::move(_gui_map), _gui_name, _defaults, 0, _max) {}
std::string Var<int>::GetString() { return std::to_string(this->value); }
void Var<int>::SetString(std::string_view i) {
    *this = std::stoi(static_cast<std::string>(i)); }
void Var<int>::Call(std::ostream& out, Command::Args a) {
    if (a.empty())
        out << "Set Variable Usage: " << this->command_name << " <integer>" << std::endl;
    else
        this->SetString(a.front());
}
void Var<int>::SetDefault() { *this = this->defaults; }
Var<int>& Var<int>::operator=(int v) {
    v = std::max(v, this->min);
    v = std::min(v, this->max);
    if (v != this->value) {
        if (this->Callback)
            this->Callback(v);
        this->value = v;
    }
    return *this; 
}

Var<float>::Var(TreeMap _gui_map, std::string_view _gui_name, float _defaults, float _min, float _max) 
    : BaseVar(BaseVar::Type::kFloat, std::move(_gui_map), _gui_name), defaults(_defaults), min(_min), max(_max) {}
Var<float>::Var(TreeMap _gui_map, std::string_view _gui_name, float _defaults, float _max)
    : Var(std::move(_gui_map), _gui_name, _defaults, nanf(""), _max) {}
Var<float>::Var(TreeMap _gui_map, std::string_view _gui_name, float _defaults)
    : Var(std::move(_gui_map), _gui_name, _defaults, nanf("")) {}
std::string Var<float>::GetString() { return std::to_string(this->value); }
void Var<float>::SetString(std::string_view i) {
    *this = std::stoi(static_cast<std::string>(i)); }
void Var<float>::Call(std::ostream& out, Command::Args a) {
    if (a.empty())
        out << "Set Variable Usage: " << this->command_name << " <float>" << std::endl;
    else
        this->SetString(a.front());
}
void Var<float>::SetDefault() { *this = this->defaults; }
Var<float>& Var<float>::operator=(float v) {
    if (!std::isnan(this->min))
        v = std::max(v, this->min);
    if (!std::isnan(this->max))
        v = std::min(v, this->max);
    if (v != this->value) {
        if (this->Callback)
            this->Callback(v);
        this->value = v;
    }
    return *this; 
}


Var<Enum>::Var(TreeMap _gui_map, std::string_view _gui_name, int _defaults, Enum _enum) 
    : Var<int>(std::move(_gui_map), _gui_name, _defaults, 0, _enum.size() - 1), internal_enum(std::move(_enum)) { assert(!this->internal_enum.empty()); }
std::string Var<Enum>::GetString() { return std::string(this->internal_enum[this->value]); }
void Var<Enum>::SetString(std::string_view str) {
    for (std::size_t i = 0; i < internal_enum.size(); i++) {
        if (internal_enum[i] == str) {
            *this = i;
            return;
        }
    }
    this->Var<int>::SetString(str);
}
void Var<Enum>::Call(std::ostream& out, Command::Args a) {
    if (a.empty())
        out << "Set Variable Usage: " << this->command_name << " <string/integer>" << std::endl;
    else
        this->SetString(a.front());
}

}

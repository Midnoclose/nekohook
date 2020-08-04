
/*
 *
 * An implimentation to prevent the framework from using its own console, and to
 * use sources console instead.
 *
 */

#include "../../../util/catvars.hpp"
#include "../../../util/logging.hpp"
#include "../../../util/strings.hpp"
#include "../hacks/interfaces.hpp"

#include "console.hpp"

namespace modules::source::framework::console {

class CatConVar : public ConVar {
   public:
    CatConVar(CatVar* _cat_var)
        : cat_var(_cat_var),
          ConVar(_cat_var->name.c_str(), _cat_var->GetValue().c_str(), 0,
                 _cat_var->desc_long.c_str()) {}
    CatVar* cat_var;
    virtual void SetValue(const char* value) {
        cat_var->callback(sepstr(value));
        ConVar::SetValue(value);
    }
    virtual void SetValue(float value) {
        cat_var->callback({std::to_string(value)});
        ConVar::SetValue(value);
    }
    virtual void SetValue(int value) {
        cat_var->callback({std::to_string(value)});
        ConVar::SetValue(value);
    }
};
static void ConCommandCallback(const CCommand& args) {}
class CatConCommand : public ConCommand {
   public:
    CatConCommand(CatCommand* _cat_com)
        : ConCommand(_cat_com->name.c_str(), [](const CCommand& con_args) {
              CallCommand(con_args.GetCommandString());
          }) {}
};

void Init() {
    // Register Commands and vars
    for (auto& tmp : CatVarMap)
        g_ICvar->RegisterConCommand(new CatConVar(tmp.second));
    for (auto& tmp : CatCommandMap)
        g_ICvar->RegisterConCommand(new CatConCommand(tmp.second));
    // Logging into console ;)
    debug_log.console_tap = [](const char* in) { g_ICvar->ConsolePrintf(in); };
    debug_log.log("Now using game console!");
}

}  // namespace modules::source::framework::console

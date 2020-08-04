
/*
 *
 *	Classes
 *
 *
 */

#include "../../../framework/game.hpp"  // So we can get ingame state
#include "../../../framework/gameticks.hpp"
#include "../../../util/logging.hpp"  // Logging is cool
#include "../hacks/interfaces.hpp"    // for g_IBaseClient and sdk

#include "classes.hpp"

namespace modules {
namespace csgo {
namespace classes {

// used for magic
static int GetClassNum(const char* input) {
    // We want to find a class with the name input here
    ClientClass* cc = g_IBaseClient->GetAllClasses();
    while (cc) {
        if (!strcmp(cc->m_pNetworkName,
                    input)) {  // Cast to string to make equals work... Its bad
                               // I know... Deal with it!
            debug_log.log("ClassGen: found %s at %i", input, cc->m_ClassID);
            return cc->m_ClassID;  // We found our class, return
        }
        cc = cc->m_pNext;
    }
    debug_log.log("ClassGen: Couldnt find %s", input);
    return -1;
}

// Players
int CPlayer = -1;
int CPlayerResource = -1;

void Init() {
    // Init needs to be done while ingame, not at the menu!
    if (!g_IEngine->IsInGame()) return;
    wtickmgr.before_event.remove(Init);

    // Players
    CPlayer = GetClassNum("CCSPlayer");
    CPlayerResource = GetClassNum("CCSPlayerResource");
}

}  // namespace classes
}  // namespace csgo
}  // namespace modules

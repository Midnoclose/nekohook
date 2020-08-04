
/*
 *
 *	The source engine modules file for interfacting with the game and its
 *values
 *
 */

#include <sstream>

#include "../../../hacks/signature.hpp"
#include "../../../util/logging.hpp"  // So we can log errors
#include "sharedobj.hpp"  // We get our interfaces from inside these objects

#include "interfaces.hpp"

namespace modules::source {

// Essential
IBaseClientDLL* g_IBaseClient =
    nullptr;  // Getting g_IClientMode + controling attack and movement,
              // classes, netvars, and many more!
IClientEntityList* g_IEntityList =
    nullptr;  // Entity Information, pretty much needed
IVEngineClient013* g_IEngine = nullptr;  // Currently used for player names and
                                         // a few smaller essential things
IVModelInfoClient* g_IModelInfo = nullptr;  // Aimboat
IEngineTrace* g_ITrace = nullptr;           // Vischecks
ICvar* g_ICvar = nullptr;                   // Source engines cvar system
CGlobalVars* g_GlobalVars = nullptr;        // Curtime... Thats it... Welp...
IClientMode* g_IClientMode = nullptr;       // wts + Create move hook
// Visual
IPanel* g_IPanel = nullptr;  // Our paint traverse hook and everything to do
                             // with drawing and panels
IEngineTool* g_IEngineTool = nullptr;  // wts
#if defined(CATHOOK_GFX_SURFACE)
ISurface* g_ISurface = nullptr;  // Used for surface drawing
#endif

namespace hacks {

template <typename T>
static T* BruteforceInterface(const std::string& name, SourceSo& object,
                              int start = 0) {
    for (auto i = start; i < 100; i++) {
        // Bookmark
        auto tmp = name;

        // Add displacment zeros
        if (i < 100) tmp += "0";
        if (i < 10) tmp += "0";
        // Add number
        tmp += std::to_string(i);

        // Try to get interface
        auto result = reinterpret_cast<T*>(object.CreateInterface(tmp.c_str()));
        if (result) return result;
    }
    debug_log.log("RIP Software: can't create interface %s!", name.c_str());
    return nullptr;
}

void CreateInterfaces() {
    g_IBaseClient =
        BruteforceInterface<IBaseClientDLL>("VClient", sharedobj::client);
    g_IEntityList = BruteforceInterface<IClientEntityList>("VClientEntityList",
                                                           sharedobj::client);
    g_IEngine = BruteforceInterface<IVEngineClient013>("VEngineClient",
                                                       sharedobj::engine);
    g_IModelInfo = BruteforceInterface<IVModelInfoClient>("VModelInfoClient",
                                                          sharedobj::engine);
    g_ITrace = BruteforceInterface<IEngineTrace>("EngineTraceClient",
                                                 sharedobj::engine);
    g_ICvar = BruteforceInterface<ICvar>("VEngineCvar", sharedobj::vstdlib);
    g_IEngineTool =
        BruteforceInterface<IEngineTool>("VENGINETOOL", sharedobj::engine);
    auto g_IPlayerInfoManager = BruteforceInterface<IPlayerInfoManager>(
        "PlayerInfoManager", sharedobj::server, 2);
    g_GlobalVars = g_IPlayerInfoManager->GetGlobalVars();

    uintptr_t* tmp;
    while (!(
        tmp = **(uintptr_t***)((uintptr_t)((*(void***)g_IBaseClient)[10]) + 1)))
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    g_IClientMode = (IClientMode*)tmp;

    g_IPanel = BruteforceInterface<IPanel>("VGUI_Panel", sharedobj::vgui2);
#if defined(CATHOOK_GFX_SURFACE)
    g_ISurface = BruteforceInterface<ISurface>("VGUI_Surface",
                                               sharedobj::vguimatsurface);
#endif
}

}  // namespace hacks
}  // namespace modules::source

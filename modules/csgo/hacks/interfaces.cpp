/*
 *
 * Interfaces for csgo
 *
 */

#include <sstream>

#include "../../../util/logging.hpp"  // So we can log errors
#include "sharedobj.hpp"  // We get our interfaces from inside these objects

#include "interfaces.hpp"

namespace modules {
namespace csgo {

// Essential
IBaseClientDLL* g_IBaseClient =
    nullptr;  // Create move hook + controling attack and movement, as well as
              // classes and netvars
IClientEntityList* g_IEntityList =
    nullptr;  // Allows us to use and get information about the games entitys
IEngineClient* g_IEngine =
    nullptr;  // Currently used for player names and world to screen
IVModelInfo* g_IModelInfo = nullptr;  // Aimboat
IEngineTrace* g_ITrace = nullptr;
IVDebugOverlay* g_IDebugOverlay = nullptr;  // World to screen

// Visual
IEngineVGui* g_IEngineVGui = nullptr;
// IVPanel* g_IPanel = nullptr;			// Our paint traverse hook
ISurface* g_ISurface = nullptr;  // Used for surface drawing

namespace hacks {

// Remake this
template <typename T>
T* BruteforceInterface(std::string name, SourceSo& object, int start = 0) {
    T* result = nullptr;
    std::stringstream stream;
    for (int i = start; i < 100; i++) {
        stream.str("");
        stream << name;
        int zeros = 0;
        if (i < 10)
            zeros = 2;
        else if (i < 100)
            zeros = 1;
        for (int j = 0; j < zeros; j++) stream << '0';
        stream << i;
        result =
            reinterpret_cast<T*>(object.CreateInterface(stream.str().c_str()));
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
    g_IEngine =
        BruteforceInterface<IEngineClient>("VEngineClient", sharedobj::engine);
    g_IModelInfo =
        BruteforceInterface<IVModelInfo>("VModelInfoClient", sharedobj::engine);
    g_ITrace = BruteforceInterface<IEngineTrace>("EngineTraceClient",
                                                 sharedobj::engine);
    g_IDebugOverlay =
        BruteforceInterface<IVDebugOverlay>("VDebugOverlay", sharedobj::engine);

    g_IEngineVGui =
        BruteforceInterface<IEngineVGui>("VEngineVGui", sharedobj::engine);
    // g_IPanel = BruteforceInterface<IVPanel>("VGUI_Panel", sharedobj::vgui2);
    g_ISurface = BruteforceInterface<ISurface>("VGUI_Surface",
                                               sharedobj::vguimatsurface);
}

}  // namespace hacks
}  // namespace csgo
}  // namespace modules

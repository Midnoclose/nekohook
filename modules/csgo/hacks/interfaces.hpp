
/*
 *
 *
 *
 */

#pragma once

#include "../sdk/sdk.h"
#include "sharedobj.hpp"

namespace modules {
namespace csgo {

// Interfaces themselves
// Essentials
extern IBaseClientDLL* g_IBaseClient;
extern IClientEntityList* g_IEntityList;
extern IEngineClient* g_IEngine;
extern IVModelInfo* g_IModelInfo;
extern IEngineTrace* g_ITrace;
extern IVDebugOverlay* g_IDebugOverlay;

// Visuals
extern IEngineVGui* g_IEngineVGui;
// extern IVPanel* g_IPanel;
extern ISurface* g_ISurface;

namespace hacks {

void CreateInterfaces();

}
}  // namespace csgo
}  // namespace modules

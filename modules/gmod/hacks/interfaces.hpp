
/*
 *
 *	Header file for giving our interfaces to the module.
 *
 */

#pragma once

#include "../sdk/sdk.hpp"
#include "sharedobj.hpp"

namespace modules::source {

// Interfaces themselves
// Essentials
extern IBaseClientDLL* g_IBaseClient;
extern IClientEntityList* g_IEntityList;
extern IVEngineClient013* g_IEngine;
extern IVModelInfoClient* g_IModelInfo;
extern IEngineTrace* g_ITrace;
extern ICvar* g_ICvar;
extern CGlobalVars* g_GlobalVars;
extern IClientMode* g_IClientMode;
// Visuals
extern IPanel* g_IPanel;
extern IEngineTool* g_IEngineTool;
#if defined(CATHOOK_GFX_SURFACE)
extern ISurface* g_ISurface;
#endif

namespace hacks {

void CreateInterfaces();

}
}  // namespace modules::source

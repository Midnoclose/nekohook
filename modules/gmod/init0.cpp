
/*
 *	Init file for the source engine module
 *	Please keep everything in the module in its own namespace!
 *
 */

#include "../../util/logging.hpp"  // So we can log
#include "util/debug.hpp"          //Uncomment for dev use
// Internal module stuff
#include "features/features.hpp"
#include "framework/framework.hpp"
#include "hacks/hacks.hpp"  // So we can init the hack
#include "util/util.hpp"
// Potentially loadable modules for source
#include "../xlib/input.hpp"
#include "util/surface.hpp"

#include "init.hpp"

namespace modules::source {

// The startup function for the module
void Init() {
    debug_log.log("Begin Source engine module init...");

    debug_log.log("Begin Hacking...");
    hacks::Init();

    debug_log.log("Loading Framework Interfaces...");
    framework::Init();

    debug_log.log("Loading Modular Cheats...");
    features::Init();

    debug_log.log("Loading Util...");
    util::Init();

    // Put possible graphics modules here.
    debug_log.log("Loading graphics module...");
#if defined(CATHOOK_GFX_SURFACE)
    valvesurface::Init();
#endif

    // Input modules
    debug_log.log("Loading input module...");
#if defined(CATHOOK_INP_XLIB)
    xlib::InitInput();
#endif

    debug_log.log("Source engine module init!");
}

}  // namespace modules::source

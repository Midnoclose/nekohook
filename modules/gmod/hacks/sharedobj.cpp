
/*
 *
 *	l4d2's shared objects
 *
 */

#include <libgen.h>  // basename()

#include "../../../util/logging.hpp"  // So we can log errors

#include "sharedobj.hpp"

SourceSo::SourceSo(const char* _file_name) : SharedObject(_file_name) {}
void* SourceSo::CreateInterface(const char* interface) {
    // Check for the fptr, if not we must find it
    if (fptr == nullptr) {
        while (!fptr) {
            fptr = reinterpret_cast<fn_CreateInterface_t>(
                dlsym(lmap, "CreateInterface"));
            if (!fptr)
                debug_log.log("Failed to create interface factory for %s",
                              basename(lmap->l_name));
        }
        debug_log.log("Found interface factory at 0x%x for %s", fptr,
                      basename(lmap->l_name));
    }
    // We have it now so use it
    return (void*)(fptr(interface, nullptr));
}

namespace modules::source::hacks::sharedobj {

// Create move hook + controling attack and movement
SourceSo client("client.so");

SourceSo server("server.so");
// For player names
SourceSo engine("engine.so");
// Used for surface drawing
SourceSo vgui2("vgui2.so");
// CVARS
SourceSo vstdlib("libvstdlib.so");

// Used for our paint traverse hook
#if defined(CATHOOK_GFX_SURFACE)
SourceSo vguimatsurface("vguimatsurface.so");
#endif

}  // namespace modules::source::hacks::sharedobj

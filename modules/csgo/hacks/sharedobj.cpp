
/*
 *
 * Shared objects for csgo
 *
 */

#include <libgen.h>  // basename()

#include "../../../util/logging.hpp"  // So we can log errors

#include "sharedobj.hpp"

// Stolen from 2013, update as needed :^)
SourceSo::SourceSo(const char* _file_name) : SharedObject(_file_name) {}
void* SourceSo::CreateInterface(const char* interface) {
    // Check for the fptr, if not we must find it
    if (fptr == nullptr) {
        while (!fptr) {
            fptr = reinterpret_cast<fn_CreateInterface_t>(
                dlsym(GetLmap(), "CreateInterface"));
            if (!fptr)
                debug_log.log("Failed to create interface factory for %s",
                              basename(GetLmap()->l_name));
        }
        debug_log.log("Found interface factory at 0x%x for %s", fptr,
                      basename(GetLmap()->l_name));
    }
    // We have it now so use it
    return (void*)(fptr(interface, nullptr));
}

namespace modules {
namespace csgo {
namespace hacks {
namespace sharedobj {

// Create move hook + controlling attack and movement
SourceSo client("client_client.so");
// For player names
SourceSo engine("engine_client.so");
// Used for surface drawing
SourceSo vgui2("vgui2_client.so");
// Used for our paint traverse hook
SourceSo vguimatsurface("vguimatsurface_client.so");

}  // namespace sharedobj
}  // namespace hacks
}  // namespace csgo
}  // namespace modules


/*
 *
 *  We use the cpp file for conditions that need to be cached for a reason
 *
 *
 */

#if defined(CATHOOK_TF2)

#include <chrono>  // For time keeping
#include <ratio>   // Transforming time incriments

#include "../../../framework/gameticks.hpp"  // Stuff to init with
#include "../hacks/interfaces.hpp"

#include "conditions.hpp"

namespace modules::source {
namespace conditions {

// Time when the local player started zooming
static std::chrono::steady_clock::time_point zoom_begin;

static void WorldTick() {
    auto local_ent =
        g_IEntityList->GetClientEntity(g_IEngine->GetLocalPlayer());
    if (!HasCondition((CatEntity*)local_ent, TFCond_Zoomed))
        zoom_begin = std::chrono::steady_clock::now();
}

void Init() { wtickmgr.REventBefore(WorldTick); }

}  // namespace conditions

bool CanHeadshot() {
    // Get local ent
    auto local_ent =
        g_IEntityList->GetClientEntity(g_IEngine->GetLocalPlayer());
    if (!local_ent || local_ent->IsDormant()) return false;
    // Check if currently zoomed
    if (!HasCondition((CatEntity*)local_ent, TFCond_Zoomed)) return false;
    // Check if zoomed long enough
    auto time_zoomed =
        std::chrono::steady_clock::now() - conditions::zoom_begin;
    return time_zoomed > std::chrono::milliseconds(200);
}

}  // namespace modules::source

#endif

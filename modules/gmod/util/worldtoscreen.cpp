
/*
 *
 *	Source engines world to screen framework interface
 *
 *
 */

#include "../../../framework/drawing.hpp"  // So we can put our world to screen into the framework
#include "../../../framework/gameticks.hpp"  // So we can reset the wts cache
#include "../../../framework/input.hpp"      // For window bounds

#include "../hacks/interfaces.hpp"  // For g_IEngine + sdk
#include "../util/mathlib.hpp"      // To convert between vector types

#include "worldtoscreen.hpp"

namespace modules::source::wts {

// externed so overridehook can set it
CViewSetup* wts_viewsetup;

// Our world to screen function
static bool WorldToScreen(CatVector world, CatVector& screen) {
    if (!wts_viewsetup) return false;
    VMatrix wts;
    g_IEngineTool->GetWorldToScreenMatrixForView(*wts_viewsetup, &wts);
    // Sick P@sted math from original cathook
    float w = wts[3][0] * world.x + wts[3][1] * world.y + wts[3][2] * world.z +
              wts[3][3];
    if (w > 0.001) {
        float odw = 1.0f / w;
        screen.x = (input::bounds.first / 2) +
                   (0.5 *
                        ((wts[0][0] * world.x + wts[0][1] * world.y +
                          wts[0][2] * world.z + wts[0][3]) *
                         odw) *
                        input::bounds.first +
                    0.5);
        screen.y = (input::bounds.second / 2) -
                   (0.5 *
                        ((wts[1][0] * world.x + wts[1][1] * world.y +
                          wts[1][2] * world.z + wts[1][3]) *
                         odw) *
                        input::bounds.second +
                    0.5);
        return true;
    }
    return false;
}

// We run this to make the framework use our world to screen
void Init() { draw::WorldToScreen = WorldToScreen; }

}  // namespace modules::source::wts

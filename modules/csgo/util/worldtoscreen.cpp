
/*
 *
 *	Source engines world to screen framework interface
 *
 *
 */

#include "../../../framework/input.hpp"  // For window bounds
#include "../hacks/interfaces.hpp"       // For g_IEngine + sdk
#include "../util/mathlib.hpp"           // To convert between vector types

// Stuff to init with
#include "../../../framework/drawing.hpp"  // So we can put our world to screen into the framework
#include "../../../framework/gameticks.hpp"  // So we can reset the wts cache

#include "worldtoscreen.hpp"

namespace modules {
namespace csgo {
namespace wts {

// Our world to screen function
static bool WorldToScreen(CatVector world, std::pair<int, int>& screen) {
    // Sick P@sted math from aimtux fuzion
    Vector tmp;
    bool uhhh = g_IDebugOverlay->ScreenPosition(ToVector(world), tmp);
    screen = {tmp.x, tmp.y};
    return !uhhh;
}

// We run this to make the framework use our world to screen
void Init() {
    // Pass the wts function to the framework
    draw::WorldToScreen = WorldToScreen;
}

}  // namespace wts
}  // namespace csgo
}  // namespace modules


/*
 *
 *	The cheats file that manages the additional cheat features added by this
 *module
 *
 *
 */

#include "../../../framework/gameticks.hpp"  // Stuff to init with
#include "esp.hpp"                           // Stuff to init

#include "features.hpp"

namespace modules {
namespace csgo {
namespace features {

void Init() { wtickmgr.REventDuring(cheats::esp::WorldTick); }

}  // namespace features
}  // namespace csgo
}  // namespace modules

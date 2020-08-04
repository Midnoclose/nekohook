
/*
 *
 * Airstuck for source engine
 *
 */

//#include<bits/stdc++.h> // INT_MAX
#include "../../../framework/gameticks.hpp"
#include "../../../framework/input.hpp"
#include "../../../util/catvars.hpp"
#include "../hacks/hooks.hpp"
#include "../hacks/interfaces.hpp"

#include "airstuck.hpp"

namespace modules::source::features::airstuck {

static CatEnum airstuck_menu({"Misc"});
static CatVarKey airstuck(airstuck_menu, "airstuck", CATKEY_F, "Airstuck");

void Init() {
    /*wtickmgr.REventDuring([](){
      if (airstuck != CATKEY_NONE && input::pressed_buttons[airstuck]) {
        hacks::hooks::g_UserCmd->tick_count = INT_MAX;
      }
    });*/
}

}  // namespace modules::source::features::airstuck

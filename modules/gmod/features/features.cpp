
/*
 *
 *	The cheats file that manages the additional cheat features added by this
 *module
 *
 *
 */

#include "../../../framework/gameticks.hpp"  // Stuff to init with
#include "aimbot.hpp"
#include "airstuck.hpp"
#include "esp.hpp"  // Stuff to init
#include "spam.hpp"

#include "features.hpp"

namespace modules::source::features {

void Init() {
    // aimbot
    aimbot::Init();

    esp::Init();

    airstuck::Init();

    spam::Init();
}

}  // namespace modules::source::features

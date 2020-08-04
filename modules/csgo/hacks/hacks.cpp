
/*
 *
 *	Init stuff for the hacks section of the tf2 module.
 *
 */

// Stuff we have to init
#include "hooks.hpp"
#include "interfaces.hpp"

#include "hacks.hpp"

namespace modules {
namespace csgo {
namespace hacks {

void Init() {
    // Load our interfaces
    CreateInterfaces();

    // Load our hooks
    hooks::Init();
}

}  // namespace hacks
}  // namespace csgo
}  // namespace modules

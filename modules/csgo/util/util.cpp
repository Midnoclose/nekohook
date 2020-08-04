
/*
 *
 *  Util init file
 *
 *
 */

#include "../../../framework/gameticks.hpp"
#include "classes.hpp"
#include "netvars.hpp"
#include "worldtoscreen.hpp"

#include "util.hpp"

namespace modules {
namespace csgo {
namespace util {

void Init() {
    wtickmgr.REventBefore(classes::Init);

    netvars::Init();

    wts::Init();
}

}  // namespace util
}  // namespace csgo
}  // namespace modules

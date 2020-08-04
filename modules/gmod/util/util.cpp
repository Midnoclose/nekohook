
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
#if defined(CATHOOK_TF2)
#include "conditions.hpp"
#endif
#include "util.hpp"

namespace modules::source::util {

void Init() {
    wtickmgr.REventBefore(classes::Init);

    netvars::Init();

    wts::Init();

#if defined(CATHOOK_TF2)
    conditions::Init();
#endif
}

}  // namespace modules::source::util

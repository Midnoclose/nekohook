
/*
 *
 * Borderlands Init
 *
 */

#include "../../util/logging.hpp"  // So we can log

#include "hacks/hooks.hpp"

namespace modules::borderlands {

void Init() {
    debug_log.Puts("Doing the do");

    hooks::Init();
}

}  // namespace modules::borderlands

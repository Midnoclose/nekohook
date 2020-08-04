
/*
 *
 *	Init the below to Hook stuff
 *
 */

#pragma once

#include "../sdk/sdk.hpp"

namespace modules::source::hacks::hooks {

// Used to mess with user commands
extern CUserCmd* g_UserCmd;
extern bool UsingSilent;  // dont touch, only for use by the
                          // SetSilentCameraAngle function

void Init();

}  // namespace modules::source::hacks::hooks


/*
 *
 *	Init the below to Hook stuff
 *
 */

#pragma once

#include "../sdk/sdk.h"

namespace modules {
namespace source {
namespace hacks {
namespace hooks {

// Used to mess with user commands
extern CUserCmd* g_UserCmd;

void Init();

}  // namespace hooks
}  // namespace hacks
}  // namespace source
}  // namespace modules
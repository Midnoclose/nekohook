
/*
 *
 *	We do hooking here!
 *	Eventually you will be able to pass your function into here to do stuff
 *with the hooked functions
 *
 *
 */

#include <stdlib.h>  // Needed to get client mode
#include <unistd.h>  // sleep()

// Stuff we use to hook with
#include "../../../hacks/hooking.hpp"  // What we use to hook with
#include "../../../util/logging.hpp"
#include "interfaces.hpp"  // We use offsets from interfaces to hook things
// So we can run the framework from the hooks
#include "../../../framework/entitys.hpp"
#include "../../../framework/game.hpp"       // We set ingame state here
#include "../../../framework/gameticks.hpp"  // We run the main cheat loops
// platform specific offsets
#include "../../../util/platform.hpp"

#include "hooks.hpp"

// Contains offsets to vfuncs that we hook
namespace offsets {
const auto CreateMove = Platform<short>(25, -1, -1);
// const auto PaintTraverse = Platform<short>(42, -1, -1);
const auto Paint = 15;
const auto OverrideView = Platform<short>(17, -1, -1);
const auto FrameStageNotify = Platform<short>(35, -1, -1);
}  // namespace offsets

namespace modules {
namespace csgo {
namespace hacks {
namespace hooks {

// Here we store our main hooks
static VMTHook clientmode;
// static VMTHook panel;
static VMTHook enginevgui;

// Here we have our hooked functions.
CUserCmd* g_UserCmd = nullptr;
bool UsingSilent = false;
QAngle LastAngles;  // We save angles from CreateMove to use down in
                    // FrameStageNotify
static bool CreateMove_hook(void* thisptr, float inputSample, CUserCmd* cmd) {
    typedef bool (*CreateMove_t)(
        void*, float, CUserCmd*);  // Type defs like these allow us to contain
                                   // the original function
    const CreateMove_t original =
        clientmode.GetMethod<CreateMove_t>(offsets::CreateMove);
    if (!cmd)
        return original(thisptr, inputSample,
                        cmd);  // Cant do anything without cmd
    g_UserCmd = cmd;           // Update the cmd
                               // marc was heree ;)
    // Update ingame
    if (!g_IEngine->IsInGame()) return original(thisptr, inputSample, cmd);

    // Run the frameworks worldtick
    wtickmgr();

    // Run the original to get result
    bool ret = original(thisptr, inputSample, cmd);

    // Save this so we can use it in FrameStageNotify to show angles in
    // thirdperson
    LastAngles = cmd->viewangles;

    // If we are using silent aim, we return false
    if (UsingSilent) {
        // To use silent, we just dont return true, but we need to still correct
        // movement so we do that too
        auto local_ent =
            g_IEntityList->GetClientEntity(g_IEngine->GetLocalPlayer());
        if (local_ent) {
            auto ang = [](CatVector forward)
                -> CatVector {  // Lambdas lmao :joy:, I had to rip this from
                                // cathook... Sad face...
                CatVector ret;
                if (forward.y == 0 && forward.x == 0) {
                    if (forward.z > 0)
                        ret.x = 270;
                    else
                        ret.x = 90;
                } else {
                    ret.y = atan2(forward.y, forward.x) * 180 / PI;
                    if (ret.y < 0) ret.y += 360;
                    ret.x = atan2(-forward.z, sqrt(forward.x * forward.x +
                                                   forward.y * forward.y)) *
                            180 / PI;
                    if (ret.x < 0) ret.x += 360;
                }
                return ret;
            }(CatVector(g_UserCmd->forwardmove, g_UserCmd->sidemove,
                        g_UserCmd->upmove));
            auto yaw = DEG2RAD(ang.y - GetCameraAngle((CatEntity*)local_ent).y +
                               g_UserCmd->viewangles.y);
            auto speed = sqrt(g_UserCmd->forwardmove * g_UserCmd->forwardmove +
                              g_UserCmd->sidemove * g_UserCmd->sidemove);
            g_UserCmd->forwardmove = cos(yaw) * speed;
            g_UserCmd->sidemove = sin(yaw) * speed;
        }
        UsingSilent = false;
        return false;
    }
    return ret;
}

static void Paint_hook(void* _this, PaintMode_t mode) {
    typedef void (*Paint_t)(void*, PaintMode_t);
    const Paint_t original = enginevgui.GetMethod<Paint_t>(offsets::Paint);
    original(_this, mode);

    // if (!mode)
    // return;
    // if (!g_IEngine->IsInGame())
    // return;

    drawmgr();  // Call the managers draw tick
}

// Pastes from aimtux
inline const void** getvtable(const void* inst, size_t offset = 0) {
    return *reinterpret_cast<const void***>((size_t)inst + offset);
}
inline uintptr_t GetAbsoluteAddress(uintptr_t instruction_ptr, int offset,
                                    int size) {
    return instruction_ptr +
           *reinterpret_cast<uint32_t*>(instruction_ptr + offset) + size;
}
typedef IClientMode* (*GetClientModeFn)(void);

// Use this to init our hooks
void Init() {
    uintptr_t hudprocessinput =
        reinterpret_cast<uintptr_t>(getvtable(g_IBaseClient)[10]);
    GetClientModeFn GetClientMode = reinterpret_cast<GetClientModeFn>(
        GetAbsoluteAddress(hudprocessinput + 11, 1, 5));
    IClientMode* clientMode = GetClientMode();
    clientmode.Set(clientMode);
    clientmode.HookMethod((void*)CreateMove_hook,
                          offsets::CreateMove);  // World Tick
    clientmode.Apply();

    // enginevgui
    enginevgui.Set(g_IEngineVGui);
    enginevgui.HookMethod((void*)Paint_hook, offsets::Paint);
    enginevgui.Apply();

    // Panel
    /*panel.Set(g_IPanel);
    panel.HookMethod((void*)Paint_hook, offsets::Paint); // Draw Tick
    panel.Apply();*/
}

}  // namespace hooks
}  // namespace hacks
}  // namespace csgo
}  // namespace modules

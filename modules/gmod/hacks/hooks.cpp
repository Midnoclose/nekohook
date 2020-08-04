
/*
 *
 *	We do hooking here!
 *	Eventually you will be able to pass your function into here to do stuff
 *with the hooked functions
 *
 *
 */

#include <stdlib.h>  // Needed to get client mode
#include <chrono>    // Sleep in thread
#include <thread>

// Stuff we use to hook with
#include "../../../hacks/hooking.hpp"  // What we use to hook with
#include "interfaces.hpp"  // We use offsets from interfaces to hook things
// So we can run the framework from the hooks
#include "../../../framework/game.hpp"       // We set ingame state here
#include "../../../framework/gameticks.hpp"  // We run the main cheat loops
// Stuff to do with features
#include "../../../util/catvars.hpp"
#include "../../../util/logging.hpp"
#include "../util/netvars.hpp"
#include "../util/worldtoscreen.hpp"
#if defined(CATHOOK_TF2)
#include "../util/conditions.hpp"
#endif
// platform specific offsets
#include "../../../util/platform.hpp"

#include "hooks.hpp"

// Contains offsets to vfuncs that we hook
namespace offsets {
const auto CreateMove = Platform<short>(22);
const auto PaintTraverse = Platform<short>(42);
const auto OverrideView = Platform<short>(17);
const auto FrameStageNotify = Platform<short>(35);
}  // namespace offsets

namespace modules::source::hacks::hooks {

// Here we store our main hooks
static VMTHook clientmode;
static VMTHook client;
static VMTHook panel;

// Here we have our hooked functions
CUserCmd* g_UserCmd = nullptr;  // UserInput
bool UsingSilent = false;
Vector LastAngles;  // We save angles from CreateMove to use down in
                    // FrameStageNotify
static bool CreateMove_hook(void* thisptr, float inputSample, CUserCmd* cmd) {
    typedef bool (*CreateMove_t)(
        void*, float, CUserCmd*);  // Type defs like these allow us to contain
                                   // the original function
    const CreateMove_t original = clientmode.GetMethod<CreateMove_t>(
        offsets::CreateMove);  // We call this on return so that we can process
                               // our stuff before create move
    if (!cmd)
        return original(thisptr, inputSample,
                        cmd);  // Cant do anything without cmd
    g_UserCmd = cmd;           // Update the cmd

    // Update ingame
    if (!game::GetInGame()) return original(thisptr, inputSample, cmd);

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
            auto yaw =
                DEG2RAD(ang.y - GetCameraAngle((CatLocalPlayer*)local_ent).y +
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

#if defined(CATHOOK_TF2)
static CatVarBool no_zoom({"Visuals", "Misc"}, "no_zoom", false, "No Zoom",
                          "Disables scope overlay and zoom");
#endif
static void PaintTraverse_hook(void* _this, unsigned int vp, bool fr, bool ar) {
    typedef void (*PaintTraverse_t)(void*, unsigned int, bool, bool);
    const PaintTraverse_t original =
        panel.GetMethod<PaintTraverse_t>(offsets::PaintTraverse);

    static unsigned long panel_top = 0;
    if (!panel_top && !strcmp("MatSystemTopPanel", g_IPanel->GetName(vp)))
        panel_top = vp;

    static unsigned long panel_focus = 0;
    if (!panel_focus && !strcmp("FocusOverlayPanel", g_IPanel->GetName(vp)))
        panel_focus = vp;

// No Zoom
#if defined(CATHOOK_TF2)
    static unsigned long panel_scope = 0;
    if (!panel_scope && !strcmp("HudScope", g_IPanel->GetName(vp)))
        panel_scope = vp;
    if (no_zoom && vp == panel_scope) return;
#endif

    original(_this, vp, fr, ar);  // Call the original function before we draw

    // Logic to determine whether we should draw, no idea how it works
    static bool draw_flag = false;
    if (vp == panel_top) draw_flag = true;
    if (vp != panel_focus) return;
    g_IPanel->SetTopmostPopup(panel_focus, true);
    if (!draw_flag) return;
    draw_flag = false;

    drawmgr();  // Call the managers draw tick
}

static CatVarInt fov_override({"Visuals", "Misc"}, "fov", 0, "Fov Override",
                              "Change fov");
static void OverrideView_hook(void* _this, CViewSetup* setup) {
    typedef void (*OverrideView_t)(void*, CViewSetup*);
    const OverrideView_t original =
        clientmode.GetMethod<OverrideView_t>(offsets::OverrideView);
    original(_this, setup);

    // Set this for wts
    wts::wts_viewsetup = setup;

    // No-Zoom
#if defined(CATHOOK_TF2)
    static ConVar* fov_desired = g_ICvar->FindVar("fov_desired");
    auto local_ent =
        g_IEntityList->GetClientEntity(g_IEngine->GetLocalPlayer());
    if (no_zoom && local_ent && !local_ent->IsDormant() &&
        HasCondition((CatEntity*)local_ent, TFCond_Zoomed)) {
        if (fov_override)
            setup->fov = fov_override;
        else
            setup->fov = fov_desired->GetFloat();  //
    } else
#endif
        if (fov_override)
        setup->fov = fov_override;
}

static CatVarBool force_thirdperson(
    {"Visuals", "Misc"}, "thirdperson", false, "Force Thirdperson",
    "Forces thirdperson mode 99.9% of the time");
static void FrameStageNotify_hook(void* _this, int stage) {
    typedef void (*FrameStageNotify_t)(void*, int);
    const FrameStageNotify_t original =
        client.GetMethod<FrameStageNotify_t>(offsets::FrameStageNotify);

    if (stage == FRAME_RENDER_START) {
        auto local_ent =
            g_IEntityList->GetClientEntity(g_IEngine->GetLocalPlayer());
        if (local_ent && !GetDormant((CatEntity*)local_ent) &&
            GetAlive((CatEntity*)local_ent)) {
#if defined(CATHOOK_TF2)
            // Force Thirdperson
            NET_VAR(local_ent, netvars::m_nForceTauntCam, int) =
                force_thirdperson;
#endif
            // To show antiaim in thirdperson
            if (force_thirdperson &&
                stage == 5) {  //&& g_IInput && g_IInput->CAM_IsThirdPerson()) {
                NET_VAR(local_ent, netvars::deadflag + 4, float) = LastAngles.x;
                NET_VAR(local_ent, netvars::deadflag + 8, float) = LastAngles.y;
            }
        }
    }
    original(_this, stage);
}
// Use this to init our hooks
void Init() {
    // Client mode
    clientmode.Set(g_IClientMode);
    clientmode.HookMethod((void*)CreateMove_hook,
                          offsets::CreateMove);  // World Tick
    clientmode.HookMethod((void*)OverrideView_hook,
                          offsets::OverrideView);  // Override View
    clientmode.Apply();

    // Panel
    panel.Set(g_IPanel);
    panel.HookMethod((void*)PaintTraverse_hook,
                     offsets::PaintTraverse);  // Draw Tick
    panel.Apply();

    // Client
    client.Set(g_IBaseClient);
    client.HookMethod((void*)FrameStageNotify_hook, offsets::FrameStageNotify);
    client.Apply();
}

}  // namespace modules::source::hacks::hooks

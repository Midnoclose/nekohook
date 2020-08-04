
/*
 *
 *	This is a interface for the entity manager to the tf2 module.
 *
 *
 */

#include "../../../framework/entitys.hpp"  // Our entity manager we want to fill
#include "../../../framework/game.hpp"     // Our entity manager we want to fill
#include "../../../util/logging.hpp"
#include "../hacks/hooks.hpp"       // Has interfaces to the game that we need
#include "../hacks/interfaces.hpp"  // Has interfaces to the game that we need
#include "../util/classes.hpp"      // Enables us to use class num gen
#include "../util/mathlib.hpp"  // To convert between catvectors and source vectors
#include "../util/netvars.hpp"         // Contains definition for use of netvars
#include "../util/playerresource.hpp"  // To retrive player information

#include "entitys.hpp"

namespace modules::source::framework::entitys {

bool GetDormant(CatEntity* this_ptr) {
    return ((IClientEntity*)this_ptr)->IsDormant();
}
bool GetAlive(CatEntity* this_ptr) {
    return !NET_VAR(this_ptr, netvars::m_lifeState, unsigned char);
}
int GetHealth(CatEntity* this_ptr) {
    auto type = GetType(this_ptr);
    if (type == ETYPE_PLAYER) return NET_VAR(this_ptr, netvars::m_iHealth, int);
#if defined(CATHOOK_TF2)
    if (type == ETYPE_OTHERHOSTILE)
        return NET_VAR(this_ptr, netvars::m_iBuildingHealth, int);
#endif
    return 100;
}
int GetMaxHealth(CatEntity* this_ptr) {
#if defined(CATHOOK_TF2)
    auto type = GetType(this_ptr);
    if (type == ETYPE_PLAYER) return PRGetMaxHealth(this_ptr);

    if (type == ETYPE_OTHERHOSTILE)
        return NET_VAR(this_ptr, netvars::m_iBuildingMaxHealth, int);
#endif
    return 100;
}
int GetTeam(CatEntity* this_ptr) {
    // Get team info
    switch (NET_VAR(this_ptr, netvars::m_iTeamNum, int)) {
#if defined(CATHOOK_FOF)
        case 0:  // Probs deathmatch, everyone is enemys
            return ETEAM_ENEMY;
        case 2:  // Blue
            return ETEAM_BLUE;
        case 3:  // Red
            return ETEAM_RED;
        case 4:  // Yellow
            return ETEAM_YELLOW;
        case 5:  // Green
            return ETEAM_GREEN;
#else  // Generic class
        case 0:  // None
            return ETEAM_NONE;
        case 1:  // Unknown
            return ETEAM_UNKNOWN;
        case 2:  // Red
            return ETEAM_RED;
        case 3:  // Blue
            return ETEAM_BLUE;
#endif
    }
    return ETEAM_ENEMY;
}
int GetType(CatEntity* this_ptr) {
    // Players
    auto cl = ((IClientEntity*)this_ptr)->GetClientClass()->m_ClassID;
    if (cl == classes::CPlayer) return ETYPE_PLAYER;
#if defined(CATHOOK_TF2)
    // Buildings
    else if (cl == classes::CObjectTeleporter ||
             cl == classes::CObjectSentrygun || cl == classes::CObjectDispenser)
        return ETYPE_OTHERHOSTILE;
    // Projectiles
    else if (cl == classes::CTFProjectile_Arrow ||
             cl == classes::CTFProjectile_EnergyBall ||
             cl == classes::CTFProjectile_EnergyRing ||
             cl == classes::CTFProjectile_GrapplingHook ||
             cl == classes::CTFProjectile_HealingBolt ||
             cl == classes::CTFProjectile_Rocket ||
             cl == classes::CTFProjectile_SentryRocket ||
             cl == classes::CTFProjectile_Flare ||
             cl == classes::CTFGrenadePipebombProjectile ||
             cl == classes::CTFProjectile_Cleaver ||
             cl == classes::CTFProjectile_Jar ||
             cl == classes::CTFProjectile_JarMilk)
        return ETYPE_PROJECTILE;
#endif
    // Unknown
    return ETYPE_GENERIC;
}
const char* GetName(CatEntity* this_ptr) {
    auto type = GetType(this_ptr);
    if (type == ETYPE_PLAYER) {
        static player_info_s info;
        if (g_IEngine->GetPlayerInfo(((IClientEntity*)this_ptr)->entindex(),
                                     &info)) {
            return info.name;
        }
    }
#if defined(CATHOOK_TF2)
    if (type == ETYPE_OTHERHOSTILE) {
        auto cl = ((IClientEntity*)this_ptr)->GetClientClass()->m_ClassID;
        if (cl == classes::CObjectSentrygun)
            return "Sentrygun";
        else if (cl == classes::CObjectDispenser)
            return "Dispenser";
        else if (cl == classes::CObjectTeleporter)
            return "Teleporter";
    }
#endif
    return "unknown";
}
CatVector GetOrigin(CatEntity* this_ptr) {
    return ToCatVector(((IClientEntity*)this_ptr)->GetAbsOrigin());
}
CatBox GetCollision(CatEntity* this_ptr) {
    auto collidable = ((IClientEntity*)this_ptr)->GetCollideable();
    auto collision_origin = collidable->GetCollisionOrigin();
    return CatBox(ToCatVector(collidable->OBBMins() + collision_origin),
                  ToCatVector(collidable->OBBMaxs() + collision_origin));
};

bool GetBone(CatEntity* this_ptr, int bone, CatBox& input) {
#if defined(CATHOOK_FOF)
    // we can always use force setup bones
    return false;
#endif

    // Test type
    if (GetType(this_ptr) != ETYPE_PLAYER) return false;

    // Map used to map source bones to. Position in array is source bone and
    // value is bone it is to the framework
    enum hitbox_t {
        head,
        pelvis,
        spine_0,
        spine_1,
        spine_2,
        spine_3,
        upperArm_L,
        lowerArm_L,
        hand_L,
        upperArm_R,
        lowerArm_R,
        hand_R,
        hip_L,
        knee_L,
        foot_L,
        hip_R,
        knee_R,
        foot_R
    };
    const static CatFastMap<int, int> bone_map{
        // Generic maps for most games
        {EBone_head, hitbox_t::head},
        {EBone_pelvis, hitbox_t::pelvis},
        {EBone_bottom_spine, hitbox_t::spine_0},
        {EBone_middle_spine, hitbox_t::spine_1},
        {EBone_upper_spine, hitbox_t::spine_2},
        {EBone_top_spine, hitbox_t::spine_3},  // Center
        {EBone_upper_arm_l, hitbox_t::upperArm_L},
        {EBone_middle_arm_l, hitbox_t::lowerArm_L},
        {EBone_lower_arm_l, hitbox_t::hand_L},
        {EBone_upper_arm_r, hitbox_t::upperArm_R},
        {EBone_middle_arm_r, hitbox_t::lowerArm_R},
        {EBone_lower_arm_r, hitbox_t::hand_R},
        {EBone_upper_leg_l, hitbox_t::hip_L},
        {EBone_middle_leg_l, hitbox_t::knee_L},
        {EBone_lower_leg_l, hitbox_t::foot_L},
        {EBone_upper_leg_r, hitbox_t::hip_R},
        {EBone_middle_leg_r, hitbox_t::knee_R},
        {EBone_lower_leg_r, hitbox_t::foot_R}};
    // Get a bone
    const auto use_bone = bone_map.find(bone);
    if (use_bone == bone_map.end()) return false;

    // Try to get a model
    model_t* model = (model_t*)((IClientEntity*)this_ptr)->GetModel();
    if (!model) return false;

    // Use the model to get a studio model
    studiohdr_t* shdr = g_IModelInfo->GetStudiomodel(model);
    if (!shdr) return false;

    // Use the studio model to get a hitbox set
    mstudiohitboxset_t* hitbox_set =
        shdr->pHitboxSet(NET_VAR(this_ptr, netvars::m_nHitboxSet, int));
    if (!hitbox_set) return false;

    // Create a storage vector for bones and setup them
    matrix3x4_t bones[128];
    // TODO, curtime
    //#if defined(CATHOOK_FOF)
    //  if (!((IClientEntity*)this_ptr)->ForceSetupBonesAtTime(bones,
    //  NET_VAR(this_ptr, netvars::m_flSimulationTime, float))) return false;
    //  #else
    if (!((IClientEntity*)this_ptr)
             ->SetupBones(
                 bones, 128, 0x100,
                 NET_VAR(this_ptr, netvars::m_flSimulationTime, float)))
        return false;
    //#endif

    // Get our hitbox
    mstudiobbox_t* bbox = hitbox_set->pHitbox(use_bone->second);
    if (!bbox) return false;

    auto HitBoxTransform = [](Vector in1, matrix3x4_t in2) -> auto {
        return CatVector(
            (in1.x * in2[0][0] + in1.y * in2[0][1] + in1.z * in2[0][2]) +
                in2[0][3],
            (in1.x * in2[1][0] + in1.y * in2[1][1] + in1.z * in2[1][2]) +
                in2[1][3],
            (in1.x * in2[2][0] + in1.y * in2[2][1] + in1.z * in2[2][2]) +
                in2[2][3]);
    };
    // Get and return hitbox
    input = CatBox(HitBoxTransform(bbox->bbmin, bones[bbox->bone]),
                   HitBoxTransform(bbox->bbmax, bones[bbox->bone]));

    return true;
}

CatVector GetCamera(CatLocalPlayer* this_ptr) {
    if (((IClientEntity*)this_ptr)->IsDormant()) return CatVector();
    return GetOrigin((CatEntity*)this_ptr) +
           ToCatVector(NET_VAR(this_ptr, netvars::m_vecViewOffset, Vector));
}
CatVector GetCameraAngle(CatLocalPlayer* this_ptr) {
    Vector angle;
    g_IEngine->GetViewAngles(angle);
    return ToCatVector(angle);
}
void SetCameraAngle(CatLocalPlayer* this_ptr, CatVector in) {
    using namespace hacks::hooks;  // Fuck these namespaces lmao
    if (!g_UserCmd) return;
    *(CatVector*)&g_UserCmd->viewangles = in;
    g_IEngine->SetViewAngles(g_UserCmd->viewangles);
    UsingSilent = false;
}
void SetSilentCameraAngle(CatLocalPlayer* this_ptr, CatVector in) {
    using namespace hacks::hooks;  // Fuck these namespaces lmao
    if (!g_UserCmd) return;
    *(CatVector*)&g_UserCmd->viewangles = in;
    UsingSilent = true;
}
void Attack(CatLocalPlayer* this_ptr) {
    if (!hacks::hooks::g_UserCmd) return;
    hacks::hooks::g_UserCmd->buttons |= IN_ATTACK;
}

CatEntity* GetEntity(int idx) {
    return (CatEntity*)g_IEntityList->GetClientEntity(idx);
}
CatLocalPlayer* GetLocalPlayer() {
    return (CatLocalPlayer*)g_IEntityList->GetClientEntity(
        g_IEngine->GetLocalPlayer());
}
int GetEntityCount() { return g_IEntityList->GetHighestEntityIndex(); }

void Init() {
    ::GetDormant = GetDormant;
    ::GetAlive = GetAlive;
    ::GetHealth = GetHealth;
    ::GetTeam = GetTeam;
    ::GetType = GetType;
    ::GetName = GetName;
    ::GetOrigin = GetOrigin;
    ::GetCollision = GetCollision;
    ::GetBone = GetBone;
    // Local ent
    ::GetCamera = GetCamera;
    ::GetCameraAngle = GetCameraAngle;
    ::SetCameraAngle = SetCameraAngle;
    ::SetSilentCameraAngle = SetSilentCameraAngle;
    ::Attack = Attack;
    // Major ent stuff
    ::GetEntity = GetEntity;
    ::GetLocalPlayer = GetLocalPlayer;
    ::GetEntityCount = GetEntityCount;
    game::GetInGame = []() { return g_IEngine->IsInGame(); };
}

}  // namespace modules::source::framework::entitys

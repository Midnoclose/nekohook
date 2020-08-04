
/*
 *
 *	This is a interface for the entity manager to the tf2 module.
 *
 *
 */

#include "../../../framework/entitys.hpp"  // Our entity manager we want to fill
#include "../../../framework/gameticks.hpp"  // We run stuff on gameticks
#include "../hacks/hooks.hpp"
#include "../hacks/interfaces.hpp"  // Has interfaces to the game that we need
#include "../util/classes.hpp"      // Enables us to use class num gen
#include "../util/mathlib.hpp"  // To convert between catvectors and source vectors
#include "../util/netvars.hpp"         // Contains definition for use of netvars
#include "../util/playerresource.hpp"  // To retrive player information

#include "entitys.hpp"

namespace modules {
namespace csgo {
namespace framework {
namespace entitys {

bool GetDormant(CatEntity* this_ptr) {
    return ((IClientEntity*)this_ptr)->GetDormant();
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
int GetTeam(CatEntity* this_ptr) {
    auto team = NET_VAR(this_ptr, netvars::m_iTeamNum, int);
    if (team == 2) return ETEAM_RED;
    if (team == 3) return ETEAM_BLUE;
    return ETEAM_NONE;
}
int GetType(CatEntity* this_ptr) {
    // Players
    auto cl = ((IClientEntity*)this_ptr)->GetClientClass()->m_ClassID;
    if (cl == classes::CPlayer) return ETYPE_PLAYER;
    // Unknown
    return ETYPE_GENERIC;
}
const char* GetName(CatEntity* this_ptr) {
    auto type = GetType(this_ptr);
    if (type == ETYPE_PLAYER) {
        static IEngineClient::player_info_t info;
        if (g_IEngine->GetPlayerInfo(((C_BasePlayer*)this_ptr)->GetIndex(),
                                     &info))
            return info.name;
    }
    return "unknown";
}
CatVector GetOrigin(CatEntity* this_ptr) {
    return ToCatVector(NET_VAR(this_ptr, netvars::m_vecOrigin, Vector));
}
CatBox GetCollision(CatEntity* this_ptr) {
    ICollideable& collidable =
        NET_VAR(this_ptr, netvars::m_Collision, ICollideable);
    auto collision_origin = GetOrigin(this_ptr);
    return CatBox(ToCatVector(collidable.OBBMins()) + collision_origin,
                  ToCatVector(collidable.OBBMaxs()) + collision_origin);
};

// CSGO :b:ones
enum hitbox_t {
    head = 0,
    evenHigherSpine = 1,
    higherSpine = 2,
    highSpine = 7,
    upperSpine = 6,
    midSpine = 5,
    lowerSpine = 4,
    arm_l = 16,
    arm_r = 17,
    hand_l = 14,
    hand_r = 15,
    hip = 3,
    upperLeg_l = 8,
    lowerLeg_l = 10,
    foot_l = 12,
    upperLeg_r = 9,
    lowerLeg_r = 11,
    foot_r = 13
};

bool GetBone(CatEntity* this_ptr, int bone, CatBox& input) {
    // Test type
    if (GetType(this_ptr) != ETYPE_PLAYER) return false;

    const static CatFastMap<int, int> bone_map{
        {EBone_head, hitbox_t::head},
        {EBone_pelvis, hitbox_t::hip},
        {EBone_bottom_spine, hitbox_t::lowerSpine},
        {EBone_middle_spine, hitbox_t::midSpine},
        {EBone_upper_spine, hitbox_t::upperSpine},
        {EBone_top_spine, hitbox_t::highSpine},  // Center
        {EBone_middle_arm_l, hitbox_t::arm_l},
        {EBone_lower_arm_l, hitbox_t::hand_l},
        {EBone_middle_arm_r, hitbox_t::arm_r},
        {EBone_lower_arm_r, hitbox_t::hand_r},
        {EBone_upper_leg_l, hitbox_t::upperLeg_l},
        {EBone_middle_leg_l, hitbox_t::lowerLeg_l},
        {EBone_lower_leg_l, hitbox_t::foot_l},
        {EBone_upper_leg_r, hitbox_t::upperLeg_r},
        {EBone_middle_leg_r, hitbox_t::lowerLeg_r},
        {EBone_lower_leg_r, hitbox_t::foot_r}};
    // Get a bone
    const auto use_bone = bone_map.find(bone);
    if (use_bone == bone_map.end()) return false;

    // Try to get a model
    auto* model = ((IClientEntity*)this_ptr)->GetModel();
    if (!model) return false;

    // Use the model to get a studio model
    studiohdr_t* shdr = g_IModelInfo->GetStudioModel(model);
    if (!shdr) return false;

    // Use the studio model to get a hitbox set
    mstudiohitboxset_t* hitbox_set =
        shdr->pHitboxSet(NET_VAR(this_ptr, netvars::m_nHitboxSet, int));
    if (!hitbox_set) return false;

    // Create a storage vector for bones and setup them
    matrix3x4_t bones[128];
    // TODO, curtime
    if (!((IClientEntity*)this_ptr)
             ->SetupBones(
                 bones, 128, 0x100,
                 NET_VAR(this_ptr, netvars::m_flSimulationTime, float)))
        return false;

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

CatVector GetCamera(CatEntity* this_ptr) {
    if (((C_BaseEntity*)this_ptr)->GetDormant()) return CatVector();
    return GetOrigin((CatEntity*)this_ptr) +
           ToCatVector(NET_VAR(this_ptr, netvars::m_vecViewOffset, Vector));
}
CatVector GetCameraAngle(CatEntity* this_ptr) {
    QAngle angle;
    g_IEngine->GetViewAngles(angle);
    return ToCatVector(angle);
}
void SetCameraAngle(CatEntity* this_ptr, const CatVector& in) {
    if (!hacks::hooks::g_UserCmd) return;
    hacks::hooks::g_UserCmd->viewangles = ToQAngle(in);
}
void Attack(CatEntity* this_ptr) {
    if (!hacks::hooks::g_UserCmd) return;
    hacks::hooks::g_UserCmd->buttons |= IN_ATTACK;
}

CatEntity* GetEntity(int idx) {
    return (CatEntity*)g_IEntityList->GetClientEntity(idx);
}
CatEntity* GetLocalPlayer() {
    return (CatEntity*)g_IEntityList->GetClientEntity(
        g_IEngine->GetLocalPlayer());
}
int GetEntityCount() { return g_IEntityList->GetHighestEntityIndex(); }

void Init() {
    ::GetDormant = GetDormant;
    ::GetAlive = GetAlive;
    ::GetHealth = GetHealth;
    ::GetMaxHealth = GetMaxHealth;
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
    ::Attack = Attack;
    // Major ent stuff
    ::GetEntity = GetEntity;
    ::GetLocalPlayer = GetLocalPlayer;
    ::GetEntityCount = GetEntityCount;
}

}  // namespace entitys
}  // namespace framework
}  // namespace csgo
}  // namespace modules

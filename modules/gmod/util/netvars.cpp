
/*
 *
 *	This is the netvar machine for the tf2 module
 *
 *
 */

#include "../../../util/logging.hpp"
#include "../hacks/interfaces.hpp"

#include "netvars.hpp"

namespace modules::source::netvars {

// This is for the last recursion
static int GetNetvarOffsetRecursive(RecvTable* pTable, int cur_offset,
                                    const char* name) {
    // Recurse into all of the children of our current table
    for (int i = 0; i < pTable->GetNumProps(); i++) {
        RecvProp* pProp = pTable->GetProp(i);
        if (pProp == nullptr) continue;

        if (isdigit(pProp->GetName()[0])) continue;

        if (!strcmp(pProp->GetName(), name))
            return cur_offset + pProp->GetOffset();
    }
    debug_log.log("Netvar: Couldnt find last \"%s\"", name);
    return -1;
}
// Middle recursion
template <typename... args_t>
static int GetNetvarOffsetRecursive(RecvTable* pTable, int cur_offset,
                                    const char* name, args_t... args) {
    // Recurse into all of the children of our current table
    for (int i = 0; i < pTable->GetNumProps(); i++) {
        RecvProp* pProp = pTable->GetProp(i);
        if (pProp == nullptr) continue;

        if (isdigit(pProp->GetName()[0])) continue;

        if (!strcmp(pProp->GetName(), name)) {
            int tmp = GetNetvarOffsetRecursive(pProp->GetDataTable(),
                                               cur_offset + pProp->GetOffset(),
                                               args...);
            // Sanity checks boi
            if (tmp != -1) return tmp;
        }
    }
    debug_log.log("Netvar: Couldnt find sub \"%s\"", name);
    return -1;
}
// starter recursion, call this to get netvars
template <typename... args_t>
static int GetNetvarOffset(const char* name, args_t... args) {
    // Loop through the whole table and look for our first name
    ClientClass* pList = g_IBaseClient->GetAllClasses();
    while (pList != nullptr) {
        // If the name of the table is the name that we are looking for, recurse
        // into it
        if (!strcmp(pList->m_pRecvTable->GetName(), name)) {
            int tmp = GetNetvarOffsetRecursive(pList->m_pRecvTable, 0, args...);
            // Sanity checks boi
            if (tmp != -1) return tmp;
        }
        pList = pList->m_pNext;
    }
    debug_log.log("Netvar: Couldnt find root \"%s\"", name);
    return -1;
}
// TODO, use std::ptrdiff_t
// Storage of netvar offsets
// Generic
int m_iTeamNum = 0;
int m_iHealth = 0;
int m_lifeState = 0;
int m_vecViewOffset = 0;
// Aimbot related
int m_nHitboxSet = 0;
int m_flSimulationTime = 0;  // Bones
int m_hActiveWeapon = 0;
int m_iFOV = 0;
int m_nTickBase = 0;
int deadflag = 0;
// Team fortress specific
#if defined(CATHOOK_TF2)
int m_iBuildingHealth = 0;
int m_iBuildingMaxHealth = 0;
int m_iUpgradeLevel = 0;
int m_iClass = 0;
int res_iMaxHealth = 0;
int res_iPlayerClass = 0;
int m_nPlayerCond = 0;
int _condition_bits = 0;
int m_flChargedDamage = 0;
int m_iItemDefinitionIndex = 0;
int m_flLastFireTime = 0;
int m_nForceTauntCam = 0;
#endif

void Init() {
    // Generic
    m_iTeamNum = GetNetvarOffset("DT_BaseEntity", "m_iTeamNum");
    m_iHealth = GetNetvarOffset("DT_BasePlayer", "m_iHealth");
    m_lifeState = GetNetvarOffset("DT_BasePlayer", "m_lifeState");
    m_vecViewOffset =
        GetNetvarOffset("DT_BasePlayer", "localdata", "m_vecViewOffset[0]");
    // Aimbot related
    m_nHitboxSet = GetNetvarOffset("DT_BaseAnimating", "m_nHitboxSet");
    m_flSimulationTime = GetNetvarOffset("DT_BaseEntity", "m_flSimulationTime");
    m_hActiveWeapon =
        GetNetvarOffset("DT_BaseCombatCharacter", "m_hActiveWeapon");
    m_iFOV = GetNetvarOffset("DT_BasePlayer", "m_iFOV");
    m_nTickBase = GetNetvarOffset("DT_BasePlayer", "localdata", "m_nTickBase");
    deadflag = GetNetvarOffset("DT_BasePlayer", "pl", "deadflag");
    // Team fortress specific
#if defined(CATHOOK_TF2)
    m_iBuildingHealth = GetNetvarOffset("DT_BaseObject", "m_iHealth");
    m_iBuildingMaxHealth = GetNetvarOffset("DT_BaseObject", "m_iMaxHealth");
    m_iUpgradeLevel = GetNetvarOffset("DT_BaseObject", "m_iUpgradeLevel");
    m_iClass = GetNetvarOffset("DT_TFPlayer", "m_PlayerClass", "m_iClass");
    res_iMaxHealth = GetNetvarOffset("DT_TFPlayerResource", "m_iMaxHealth");
    res_iPlayerClass = GetNetvarOffset("DT_TFPlayerResource", "m_iPlayerClass");
    m_nPlayerCond = GetNetvarOffset("DT_TFPlayer", "m_Shared", "m_nPlayerCond");
    _condition_bits = GetNetvarOffset("DT_TFPlayer", "m_Shared",
                                      "m_ConditionList", "_condition_bits");
    m_flChargedDamage = GetNetvarOffset(
        "DT_TFSniperRifle", "SniperRifleLocalData", "m_flChargedDamage");
    m_iItemDefinitionIndex =
        GetNetvarOffset("DT_EconEntity", "m_AttributeManager", "m_Item",
                        "m_iItemDefinitionIndex");
    m_flLastFireTime = GetNetvarOffset(
        "DT_TFWeaponBase", "LocalActiveTFWeaponData", "m_flLastFireTime");
    m_nForceTauntCam = GetNetvarOffset("DT_TFPlayer", "m_nForceTauntCam");
#endif
}

}  // namespace modules::source::netvars

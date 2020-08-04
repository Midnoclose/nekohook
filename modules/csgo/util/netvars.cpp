
/*
 *
 *	This is the netvar machine for the tf2 module
 *
 *
 */

#include "../../../util/logging.hpp"
#include "../hacks/interfaces.hpp"

#include "netvars.hpp"

namespace modules {
namespace csgo {
namespace netvars {

// This is for the last recursion
static int GetNetvarOffsetRecursive(RecvTable* pTable, int cur_offset,
                                    const char* name) {
    // Recurse into all of the children of our current table
    for (int i = 0; i < pTable->m_nProps; i++) {
        RecvProp* pProp = &pTable->m_pProps[i];
        if (pProp == nullptr) continue;

        if (isdigit(pProp->m_pVarName[0])) continue;

        if (!strcmp(pProp->m_pVarName, name))
            return cur_offset + pProp->m_Offset;
    }
    debug_log.log("Netvar: Couldnt find last \"%s\"", name);
    return -1;
}
// Middle recursion
template <typename... args_t>
static int GetNetvarOffsetRecursive(RecvTable* pTable, int cur_offset,
                                    const char* name, args_t... args) {
    // Recurse into all of the children of our current table
    for (int i = 0; i < pTable->m_nProps; i++) {
        RecvProp* pProp = &pTable->m_pProps[i];
        if (pProp == nullptr) continue;

        if (isdigit(pProp->m_pVarName[0])) continue;

        if (!strcmp(pProp->m_pVarName, name)) {
            int tmp = GetNetvarOffsetRecursive(
                pProp->m_pDataTable, cur_offset + pProp->m_Offset, args...);
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
        if (!strcmp(pList->m_pRecvTable->m_pNetTableName, name)) {
            int tmp = GetNetvarOffsetRecursive(pList->m_pRecvTable, 0, args...);
            // Sanity checks boi
            if (tmp != -1) return tmp;
        }
        pList = pList->m_pNext;
    }
    debug_log.log("Netvar: Couldnt find root \"%s\"", name);
    return -1;
}

// Storage of netvar offsets
// Generic
int m_vecOrigin = 0;
int m_Collision = 0;
int m_iTeamNum = 0;
int m_iHealth = 0;
int m_lifeState = 0;
int m_vecViewOffset = 0;
// Aimbot related
int m_nHitboxSet = 0;
int m_flSimulationTime = 0;  // Bones

void Init() {
    // Generic
    m_vecOrigin = GetNetvarOffset("DT_BaseEntity", "m_vecOrigin");
    m_Collision = GetNetvarOffset("DT_BaseEntity", "m_Collision");
    m_iTeamNum = GetNetvarOffset("DT_BaseEntity", "m_iTeamNum");
    m_iHealth = GetNetvarOffset("DT_BasePlayer", "m_iHealth");
    m_lifeState = GetNetvarOffset("DT_BasePlayer", "m_lifeState");
    m_vecViewOffset =
        GetNetvarOffset("DT_BasePlayer", "localdata", "m_vecViewOffset[0]");
    // Aimbot related
    m_nHitboxSet = GetNetvarOffset("DT_BaseAnimating", "m_nHitboxSet");
    m_flSimulationTime = GetNetvarOffset("DT_BaseEntity", "m_flSimulationTime");
}

}  // namespace netvars
}  // namespace csgo
}  // namespace modules

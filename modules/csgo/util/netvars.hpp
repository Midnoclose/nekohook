
/*
 *
 *	Header file for netvars. Be sure to extern every netvar you put in the
 *main cpp file
 *
 */

#pragma once

#define NET_VAR(entity, offset, type) \
    (*(reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(entity) + (offset))))

namespace modules {
namespace csgo {
namespace netvars {

// Generic stuff
extern int m_vecOrigin;
extern int m_Collision;
extern int m_iTeamNum;
extern int m_iHealth;
extern int m_lifeState;
extern int m_vecViewOffset;
// Aimbot
extern int m_nHitboxSet;
extern int m_flSimulationTime;

void Init();

}  // namespace netvars
}  // namespace csgo
}  // namespace modules

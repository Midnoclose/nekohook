
/*
 *
 *	Header file for netvars. Be sure to extern every netvar you put in the
 *main cpp file
 *
 */

#pragma once

#define NET_VAR(entity, offset, type) \
    (*(reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(entity) + (offset))))

namespace modules::source::netvars {

// Generic stuff
extern int m_iTeamNum;
extern int m_iHealth;
extern int m_lifeState;
extern int m_vecViewOffset;
// Aimbot
extern int m_nHitboxSet;
extern int m_flSimulationTime;
extern int m_hActiveWeapon;
extern int m_iFOV;
extern int m_nTickBase;
extern int m_flLastFireTime;
extern int deadflag;
// Team fortress 2
#if defined(CATHOOK_TF2)
extern int m_iBuildingHealth;
extern int m_iBuildingMaxHealth;
extern int m_iUpgradeLevel;
extern int m_iClass;
extern int res_iMaxHealth;
extern int res_iPlayerClass;
extern int m_nPlayerCond;
extern int _condition_bits;
extern int m_flChargedDamage;
extern int m_iItemDefinitionIndex;
extern int m_nForceTauntCam;
#endif

void Init();

}  // namespace modules::source::netvars

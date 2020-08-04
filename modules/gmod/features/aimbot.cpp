
/*
 *
 * Aimbot stuff
 *
 *
 */

#if defined(CATHOOK_TF2)
#include "../util/conditions.hpp"
#endif
#include "../../../features/aimbot.hpp"
#include "../../../framework/gameticks.hpp"
#include "../../../util/catvars.hpp"
#include "../hacks/interfaces.hpp"
#include "../util/classes.hpp"
#include "../util/netvars.hpp"

#include "aimbot.hpp"

namespace modules::source::features::aimbot {

CatVector AutoHitbox(CatEntity* entity) {
// Team fortress 2check
#if defined(CATHOOK_TF2)
    // Get our active weapon
    auto local_ent =
        g_IEntityList->GetClientEntity(g_IEngine->GetLocalPlayer());
    if (!local_ent || local_ent->IsDormant())
        return ::features::aimbot::RetrieveAimpoint(entity, 4);
    auto weapon_idx = NET_VAR(local_ent, netvars::m_hActiveWeapon, int) & 0xFFF;
    if (!weapon_idx) return ::features::aimbot::RetrieveAimpoint(entity, 4);
    auto weapon = g_IEntityList->GetClientEntity(weapon_idx);
    if (!weapon || weapon->IsDormant())
        return ::features::aimbot::RetrieveAimpoint(entity, 4);
    auto wep_id = weapon->GetClientClass()->m_ClassID;

    // Sniper rifle
    if (wep_id == classes::CTFSniperRifle ||
        wep_id == classes::CTFSniperRifleDecap) {
        // Check if can headshot
        if (HasCondition((CatEntity*)local_ent, TFCond_Zoomed) &&
            CanHeadshot()) {
            // Bodyshot handler
            auto cdmg = NET_VAR(weapon, netvars::m_flChargedDamage, float);
            auto bdmg = 50;
            // Vaccinator damage correction, protects against 75% of damage
            if (HasCondition(entity, TFCond_UberBulletResist)) {
                bdmg -= bdmg / 75;
                cdmg -= cdmg * 0.25f;
            }
            // Passive bullet resist protects against 10% of damage
            else if (HasCondition(entity, TFCond_SmallBulletResist)) {
                bdmg -= bdmg / 10;
                cdmg -= cdmg * 0.90f;
            }
            // Invis damage correction, Invis spies get protection from 10% of
            // damage
            if (HasCondition(entity, TFCond_Cloaked)) {
                bdmg -= bdmg / 10;
                cdmg -= cdmg * 0.90f;
            }
            // Check if we cant bodyshot
            auto health = GetHealth(entity);
            if (!(health <= 150 &&
                  (bdmg >= health || cdmg >= health ||
                   HasConditionMask((CatEntity*)local_ent, KCritBoostMask)))) {
                // We cant kill with bodyshot, use head
                return ::features::aimbot::RetrieveAimpoint(entity, 3);
            }
        }
        return ::features::aimbot::RetrieveAimpoint(entity, 4);
    }
    // Hunstman
    if (wep_id == classes::CTFCompoundBow)
        return ::features::aimbot::RetrieveAimpoint(entity, 3);
    // Ambassador
    auto wep_IDI = NET_VAR(weapon, netvars::m_iItemDefinitionIndex, int);
    if (wep_IDI == 61 || wep_IDI == 1006) {
        if (GetHealth(entity) <= 18 ||
            HasConditionMask((CatEntity*)local_ent, KCritBoostMask) ||
            g_GlobalVars->curtime -
                    NET_VAR(weapon, netvars::m_flLastFireTime, float) <=
                1.0) {
            return ::features::aimbot::RetrieveAimpoint(entity, 4);
        }
        return ::features::aimbot::RetrieveAimpoint(entity, 3);
    }
#elif defined(CATHOOK_FOF)
    // Head
    ::features::aimbot::RetrieveAimpoint(entity, 3);
#endif
    // Nothing to do, return center
    return ::features::aimbot::RetrieveAimpoint(entity, 4);
}

void Init() { ::features::aimbot::GetAutoHitbox = AutoHitbox; }

}  // namespace modules::source::features::aimbot

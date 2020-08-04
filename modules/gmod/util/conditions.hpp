
/*
 *
 * Used to get conditions of entitys
 *
 */

#include <cstdint>

#include "../../../framework/entitys.hpp"
#include "../util/netvars.hpp"

namespace modules::source {

struct condition_data_s {
    uint32_t conds[4];
};

enum : unsigned {
    TFCond_Slowed = 0,
    TFCond_Zoomed,
    TFCond_Disguising,
    TFCond_Disguised,
    TFCond_Cloaked,
    TFCond_Ubercharged,
    TFCond_TeleportedGlow,
    TFCond_Taunting,
    TFCond_UberchargeFading,
    TFCond_Unknown1,  // 9
    TFCond_CloakFlicker = 9,
    TFCond_Teleporting,
    TFCond_Kritzkrieged,
    TFCond_Unknown2,  // 12
    TFCond_TmpDamageBonus = 12,
    TFCond_DeadRingered,
    TFCond_Bonked,
    TFCond_Dazed,
    TFCond_Buffed,
    TFCond_Charging,
    TFCond_DemoBuff,
    TFCond_CritCola,
    TFCond_InHealRadius,
    TFCond_Healing,
    TFCond_OnFire,
    TFCond_Overhealed,
    TFCond_Jarated,
    TFCond_Bleeding,
    TFCond_DefenseBuffed,
    TFCond_Milked,
    TFCond_MegaHeal,
    TFCond_RegenBuffed,
    TFCond_MarkedForDeath,
    TFCond_NoHealingDamageBuff,
    TFCond_SpeedBuffAlly,  // 32
    TFCond_HalloweenCritCandy,
    TFCond_CritCanteen,
    TFCond_CritDemoCharge,
    TFCond_CritHype,
    TFCond_CritOnFirstBlood,
    TFCond_CritOnWin,
    TFCond_CritOnFlagCapture,
    TFCond_CritOnKill,
    TFCond_RestrictToMelee,
    TFCond_DefenseBuffNoCritBlock,
    TFCond_Reprogrammed,
    TFCond_CritMmmph,
    TFCond_DefenseBuffMmmph,
    TFCond_FocusBuff,
    TFCond_DisguiseRemoved,
    TFCond_MarkedForDeathSilent,
    TFCond_DisguisedAsDispenser,
    TFCond_Sapped,
    TFCond_UberchargedHidden,
    TFCond_UberchargedCanteen,
    TFCond_HalloweenBombHead,
    TFCond_HalloweenThriller,
    TFCond_RadiusHealOnDamage,
    TFCond_CritOnDamage,
    TFCond_UberchargedOnTakeDamage,
    TFCond_UberBulletResist,
    TFCond_UberBlastResist,
    TFCond_UberFireResist,
    TFCond_SmallBulletResist,
    TFCond_SmallBlastResist,
    TFCond_SmallFireResist,
    TFCond_Stealthed,  // 64
    TFCond_MedigunDebuff,
    TFCond_StealthedUserBuffFade,
    TFCond_BulletImmune,
    TFCond_BlastImmune,
    TFCond_FireImmune,
    TFCond_PreventDeath,
    TFCond_MVMBotRadiowave,
    TFCond_HalloweenSpeedBoost,
    TFCond_HalloweenQuickHeal,
    TFCond_HalloweenGiant,
    TFCond_HalloweenTiny,
    TFCond_HalloweenInHell,
    TFCond_HalloweenGhostMode,
    TFCond_MiniCritOnKill,
    TFCond_DodgeChance,  // 79
    TFCond_ObscuredSmoke = 79,
    TFCond_Parachute,
    TFCond_BlastJumping,
    TFCond_HalloweenKart,
    TFCond_HalloweenKartDash,
    TFCond_BalloonHead,
    TFCond_MeleeOnly,
    TFCond_SwimmingCurse,
    TFCond_HalloweenKartNoTurn,  // 87
    TFCond_FreezeInput = 87,
    TFCond_HalloweenKartCage,
    TFCond_HasRune,
    TFCond_RuneStrength,
    TFCond_RuneHaste,
    TFCond_RuneRegen,
    TFCond_RuneResist,
    TFCond_RuneVampire,
    TFCond_RuneWarlock,
    TFCond_RunePrecision,  // 96
    TFCond_RuneAgility,
    TFCond_GrapplingHook,
    TFCond_GrapplingHookSafeFall,
    TFCond_GrapplingHookLatched,
    TFCond_GrapplingHookBleeding,
    TFCond_AfterburnImmune,
    TFCond_RuneKnockout,
    TFCond_RuneImbalance,
    TFCond_CritRuneTemp,
    TFCond_PasstimeInterception,
    TFCond_SwimmingNoEffects,
    TFCond_EyeaductUnderworld,
    TFCond_KingRune,
    TFCond_PlagueRune,
    TFCond_SupernovaRune,
    TFCond_Plague,
    TFCond_KingAura,
    TFCond_SpawnOutline,  // 114
    TFCond_KnockedIntoAir,
    TFCond_CompetitiveWinner,
    TFCond_CompetitiveLoser,
    TFCond_NoTaunting
};

// Combines multiple masks together, Compiles out
template <typename... ConditionList>
constexpr condition_data_s CreateConditionMask(ConditionList... conds) {
    condition_data_s ret = {0, 0, 0, 0};
    for (const auto& cond : {conds...}) {
        if (cond >= 32 * 3) ret.conds[3] |= (1u << (cond % 32));
        if (cond >= 32 * 2) ret.conds[2] |= (1u << (cond % 32));
        if (cond >= 32 * 1)
            ret.conds[1] |= (1u << (cond % 32));
        else
            ret.conds[0] |= (1u << (cond));
    }
    return ret;
}

// Checking for conditions

// Checks a mask to another to see if something matches
inline bool CondMaskCheck(condition_data_s ent_data,
                          condition_data_s mask_data) {
    return (mask_data.conds[0] & ent_data.conds[0]) ||
           (mask_data.conds[1] & ent_data.conds[1]) ||
           (mask_data.conds[2] & ent_data.conds[2]) ||
           (mask_data.conds[3] & ent_data.conds[3]);
}
// Check an entity for a condition mask
inline bool HasConditionMask(CatEntity* entity, condition_data_s data) {
    return CondMaskCheck(
               NET_VAR(entity, netvars::_condition_bits, condition_data_s),
               data) ||
           CondMaskCheck(
               NET_VAR(entity, netvars::m_nPlayerCond, condition_data_s), data);
}

// Preset masks
constexpr condition_data_s KInvulnerabilityMask = CreateConditionMask(
    TFCond_Ubercharged, TFCond_UberchargedCanteen, TFCond_UberchargedHidden,
    TFCond_UberchargedOnTakeDamage, TFCond_Bonked, TFCond_DefenseBuffMmmph);
constexpr condition_data_s KCritBoostMask = CreateConditionMask(
    TFCond_Kritzkrieged, TFCond_CritRuneTemp, TFCond_CritCanteen,
    TFCond_CritMmmph, TFCond_CritOnKill, TFCond_CritOnDamage,
    TFCond_CritOnFirstBlood, TFCond_CritOnWin, TFCond_CritRuneTemp,
    TFCond_HalloweenCritCandy);

// Adding and removing conditions

// Use to set data with a cond mask.
inline void CondBitSet(condition_data_s& ent_data, unsigned cond_mask,
                       bool state) {
    if (state) {
        if (cond_mask > 32 * 3)
            ent_data.conds[3] |= (1 << (cond_mask % 32));
        else if (cond_mask > 32 * 2)
            ent_data.conds[2] |= (1 << (cond_mask % 32));
        else if (cond_mask > 32 * 1)
            ent_data.conds[1] |= (1 << (cond_mask % 32));
        else
            ent_data.conds[0] |= (1 << (cond_mask));
    } else {
        if (cond_mask > 32 * 3)
            ent_data.conds[3] &= ~(1u << (cond_mask % 32));
        else if (cond_mask > 32 * 2)
            ent_data.conds[2] &= ~(1u << (cond_mask % 32));
        else if (cond_mask > 32 * 1)
            ent_data.conds[1] &= ~(1u << (cond_mask % 32));
        else
            ent_data.conds[0] &= ~(1u << (cond_mask));
    }
}

// Adds and removes conditions from entitys
inline void AddCondition(CatEntity* entity, unsigned cond_mask) {
    CondBitSet(NET_VAR(entity, netvars::_condition_bits, condition_data_s),
               cond_mask, true);
    CondBitSet(NET_VAR(entity, netvars::m_nPlayerCond, condition_data_s),
               cond_mask, true);
}
inline void RemoveCondition(CatEntity* entity, unsigned cond_mask) {
    CondBitSet(NET_VAR(entity, netvars::_condition_bits, condition_data_s),
               cond_mask, false);
    CondBitSet(NET_VAR(entity, netvars::m_nPlayerCond, condition_data_s),
               cond_mask, false);
}
inline bool CondBitCheck(unsigned cond, condition_data_s data) {
    if (cond >= 32 * 3) return data.conds[3] & (1u << (cond % 32));
    if (cond >= 32 * 2) return data.conds[2] & (1u << (cond % 32));
    if (cond >= 32 * 1) return data.conds[1] & (1u << (cond % 32));
    if (cond < 32) return data.conds[0] & (1u << (cond));
    return false;
}
// Checks for single bits
inline bool HasCondition(CatEntity* entity, unsigned cond_mask) {
    if (cond_mask < 96) {
        if (CondBitCheck(cond_mask, NET_VAR(entity, netvars::_condition_bits,
                                            condition_data_s)))
            return true;
    }
    return CondBitCheck(
        cond_mask, NET_VAR(entity, netvars::m_nPlayerCond, condition_data_s));
}

// Conditions not set in bits

bool CanHeadshot();

namespace conditions {

void Init();

}

}  // namespace modules::source

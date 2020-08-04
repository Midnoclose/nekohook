
/*
 *
 *	Classes
 *
 *
 */

#include "../../../framework/game.hpp"  // So we can get ingame state
#include "../../../framework/gameticks.hpp"
#include "../../../util/logging.hpp"  // Logging is cool
#include "../hacks/interfaces.hpp"    // for g_IBaseClient and sdk

#include "classes.hpp"

namespace modules::source::classes {

// used for magic
static int GetClassNum(const char* input) {
    // We want to find a class with the name input here
    ClientClass* cc = g_IBaseClient->GetAllClasses();
    while (cc) {
        if (!strcmp(cc->GetName(),
                    input))  // Cast to string to make equals work... Its bad I
                             // know... Deal with it!
            return cc->m_ClassID;  // We found our class, return
        cc = cc->m_pNext;
    }
    debug_log.log("ClassGen: Couldnt find %s", input);
    return -1;
}

// Players
int CPlayer = -1;
int CPlayerResource = -1;

#if defined(CATHOOK_TF2)
// Buildings
int CObjectSentrygun = -1;
int CObjectDispenser = -1;
int CObjectTeleporter = -1;
// Projectiles
int CTFProjectile_Arrow = -1;
int CTFProjectile_EnergyBall = -1;
int CTFProjectile_EnergyRing = -1;
int CTFProjectile_GrapplingHook = -1;
int CTFProjectile_HealingBolt = -1;
int CTFProjectile_Rocket = -1;
int CTFProjectile_SentryRocket = -1;
int CTFProjectile_Flare = -1;
int CTFGrenadePipebombProjectile = -1;
int CTFProjectile_Cleaver = -1;
int CTFProjectile_Jar = -1;
int CTFProjectile_JarMilk = -1;
int CTFSniperRifle = -1;
int CTFSniperRifleDecap = -1;
int CTFCompoundBow = -1;
#endif

void Init() {
    //  This needs to be done ingame
    if (!g_IEngine->IsInGame()) return;
    wtickmgr.before_event.remove(Init);

    // Players
#if defined(CATHOOK_TF2)
    CPlayer = GetClassNum("CTFPlayer");
    CPlayerResource = GetClassNum("CTFPlayerResource");
    // Buildings
    CObjectSentrygun = GetClassNum("CObjectSentrygun");
    CObjectDispenser = GetClassNum("CObjectDispenser");
    CObjectTeleporter = GetClassNum("CObjectTeleporter");
    // Projectiles
    CTFProjectile_Arrow = GetClassNum("CTFProjectile_Arrow");
    CTFProjectile_EnergyBall = GetClassNum("CTFProjectile_EnergyBall");
    CTFProjectile_EnergyRing = GetClassNum("CTFProjectile_EnergyRing");
    CTFProjectile_GrapplingHook = GetClassNum("CTFProjectile_GrapplingHook");
    CTFProjectile_HealingBolt = GetClassNum("CTFProjectile_HealingBolt");
    CTFProjectile_Rocket = GetClassNum("CTFProjectile_Rocket");
    CTFProjectile_SentryRocket = GetClassNum("CTFProjectile_SentryRocket");
    CTFProjectile_Flare = GetClassNum("CTFProjectile_Flare");
    CTFGrenadePipebombProjectile = GetClassNum("CTFGrenadePipebombProjectile");
    CTFProjectile_Cleaver = GetClassNum("CTFProjectile_Cleaver");
    CTFProjectile_Jar = GetClassNum("CTFProjectile_Jar");
    CTFProjectile_JarMilk = GetClassNum("CTFProjectile_JarMilk");
    // Weapons
    CTFSniperRifle = GetClassNum("CTFSniperRifle");
    CTFSniperRifleDecap = GetClassNum("CTFSniperRifleDecap");
    CTFCompoundBow = GetClassNum("CTFCompoundBow");
#elif defined(CATHOOK_FOF)
    CPlayer = GetClassNum("CFoF_Player");
#endif
}

}  // namespace modules::source::classes

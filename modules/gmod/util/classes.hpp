
/*
 *
 *	Classes header file. Remembet to extern class numbers that you need!
 *
 *
 */

namespace modules::source::classes {

// Players
extern int CPlayer;
extern int CPlayerResource;

#if defined(CATHOOK_TF2)
// Buildings
extern int CObjectSentrygun;
extern int CObjectDispenser;
extern int CObjectTeleporter;
// Projectiles
extern int CTFProjectile_Arrow;
extern int CTFProjectile_EnergyBall;
extern int CTFProjectile_EnergyRing;
extern int CTFProjectile_GrapplingHook;
extern int CTFProjectile_HealingBolt;
extern int CTFProjectile_Rocket;
extern int CTFProjectile_SentryRocket;
extern int CTFProjectile_Flare;
extern int CTFGrenadePipebombProjectile;
extern int CTFProjectile_Cleaver;
extern int CTFProjectile_Jar;
extern int CTFProjectile_JarMilk;
// Weapons
extern int CTFSniperRifle;
extern int CTFSniperRifleDecap;
extern int CTFCompoundBow;
#endif

void Init();

}  // namespace modules::source::classes

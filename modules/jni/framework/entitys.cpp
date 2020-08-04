
/*
 *
 * The file for communicating with entitys in the game.
 *
 * Since we cant give direct entity pointers to the framework,
 * Instead we will give the framework a "handle" which we can break down later
 * and resolve it into a proper entity.
 *
 * This is on your side, the java side.
 *
 */

#include "../../../framework/entitys.hpp"

namespace modules::jni {

void Init() {
    // main functions to get info out of entities
    GetDormant = [](CatEntity* in) -> bool {
        // These are static as they shouldnt change, so they would be fast to do
        // once and forget
        static auto entity_class =
            FindClass(g_Enviroment, "neko/framework/entitys");
        static auto dormant_method =
            GetStaticMethodID(g_Enviroment, entity_class, "GetDormant", "")
    };
    GetAlive = [](CatEntity* in) -> bool {

    };
    extern CMFunction<int(CatEntity*)> GetHealth;
    extern CMFunction<int(CatEntity*)> GetMaxHealth;
    extern CMFunction<int(CatEntity*)> GetTeam;
    extern CMFunction<int(CatEntity*)> GetType;
    extern CMFunction<const char*(CatEntity*)> GetName;
    extern CMFunction<CatVector(CatEntity*)> GetOrigin;
    extern CMFunction<CatBox(CatEntity*)> GetCollision;
    extern CMFunction<int(CatEntity*)> GetSteamId;
    extern CMFunction<bool(CatEntity*, int, CatBox&)> GetBone;

    // Local player specific
    extern CMFunction<void(CatLocalPlayer*)> Attack;
    extern CMFunction<void(CatLocalPlayer*)> Jump;
    extern CMFunction<void(CatLocalPlayer*, CatVector)> WalkTo;
    extern CMFunction<bool(CatLocalPlayer*)> InThirdperson;
    extern CMFunction<CatVector(CatLocalPlayer*)> GetCamera;
    extern CMFunction<CatVector(CatLocalPlayer*)> GetCameraAngle;
    extern CMFunction<void(CatLocalPlayer*, CatVector)> SetCameraAngle;
    extern CMFunction<void(CatLocalPlayer*, CatVector)> SetSilentCameraAngle;
    // Entity manager stuff
    extern CMFunction<int()> GetEntityCount;
    extern CMFunction<CatEntity*(int)> GetEntity;
    extern CMFunction<CatLocalPlayer*()> GetLocalPlayer;
}

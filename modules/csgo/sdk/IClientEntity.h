#pragma once

#include "ai_activity.h"
#include "vector.h"

#define MAX_SHOOT_SOUNDS 16
#define MAX_WEAPON_STRING 80
#define MAX_WEAPON_PREFIX 16
#define MAX_WEAPON_AMMO_NAME 32

enum WeaponSound_t {
    EMPTY,
    SINGLE,
    SINGLE_NPC,
    WPN_DOUBLE,  // Can't be "DOUBLE" because windows.h uses it.
    DOUBLE_NPC,
    BURST,
    RELOAD,
    RELOAD_NPC,
    MELEE_MISS,
    MELEE_HIT,
    MELEE_HIT_WORLD,
    SPECIAL1,
    SPECIAL2,
    SPECIAL3,
    TAUNT,
    FAST_RELOAD,

    // Add new shoot sound types here
    REVERSE_THE_NEW_SOUND,

    NUM_SHOOT_SOUND_TYPES,
};

enum MoveType_t {
    MOVETYPE_NONE = 0,
    MOVETYPE_ISOMETRIC,
    MOVETYPE_WALK,
    MOVETYPE_STEP,
    MOVETYPE_FLY,
    MOVETYPE_FLYGRAVITY,
    MOVETYPE_VPHYSICS,
    MOVETYPE_PUSH,
    MOVETYPE_NOCLIP,
    MOVETYPE_LADDER,
    MOVETYPE_OBSERVER,
    MOVETYPE_CUSTOM,
    MOVETYPE_LAST = MOVETYPE_CUSTOM,
    MOVETYPE_MAX_BITS = 4
};

enum DataUpdateType_t {
    DATA_UPDATE_CREATED = 0,
    DATA_UPDATE_DATATABLE_CHANGED,
};

class ICollideable {
   public:
    ICollideable() {}
    virtual void pad0();

    virtual const Vector& OBBMins() const;

    virtual const Vector& OBBMaxs() const;
};

class IHandleEntity {
   public:
    virtual ~IHandleEntity(){};
};

class IClientUnknown : public IHandleEntity {};

class IClientRenderable {
   public:
    virtual ~IClientRenderable(){};

    model_t* GetModel() {
        typedef model_t* (*oGetModel)(void*);
        return getvfunc<oGetModel>(this, 8)(this);
    }

    bool SetupBones(matrix3x4_t* pBoneMatrix, int nMaxBones, int nBoneMask,
                    float flCurTime = 0) {
        typedef bool (*oSetupBones)(void*, matrix3x4_t*, int, int, float);
        return getvfunc<oSetupBones>(this, 13)(this, pBoneMatrix, nMaxBones,
                                               nBoneMask, flCurTime);
    }
};

class IClientNetworkable {
   public:
    virtual ~IClientNetworkable(){};

    void Release() {
        typedef void (*oRelease)(void*);
        return getvfunc<oRelease>(this, 1)(this);
    }

    ClientClass* GetClientClass() {
        typedef ClientClass* (*oGetClientClass)(void*);
        return getvfunc<oGetClientClass>(this, 2)(this);
    }

    void PreDataUpdate(DataUpdateType_t updateType) {
        typedef void (*oPreDataUpdate)(void*, DataUpdateType_t);
        return getvfunc<oPreDataUpdate>(this, 6)(this, updateType);
    }

    bool GetDormant() {
        typedef bool (*oGetDormant)(void*);
        return getvfunc<oGetDormant>(this, 9)(this);
    }

    int GetIndex() {
        typedef int (*oGetIndex)(void*);
        return getvfunc<oGetIndex>(this, 10)(this);
    }

    void SetDestroyedOnRecreateEntities() {
        typedef void (*oSetDestroyedOnRecreateEntities)(void*);
        return getvfunc<oSetDestroyedOnRecreateEntities>(this, 13)(this);
    }
};

class IClientThinkable {
   public:
    virtual ~IClientThinkable(){};
};

class IClientEntity : public IClientUnknown,
                      public IClientRenderable,
                      public IClientNetworkable,
                      public IClientThinkable {
   public:
    virtual ~IClientEntity(){};
};

class C_BaseEntity : public IClientEntity {
   public:
    IClientNetworkable* GetNetworkable() {
        return (IClientNetworkable*)((uintptr_t)this + 0x10);
    }

    void SetModelIndex(int index) {
        typedef void (*oSetModelIndex)(void*, int);
        return getvfunc<oSetModelIndex>(this, 111)(this, index);
    }
};

/* generic game classes */
class C_BasePlayer : public C_BaseEntity {
   public:
    /*inline Vector GetBonePosition( int boneIndex ) {
        matrix3x4_t BoneMatrix[MAXSTUDIOBONES];

        if ( !this->SetupBones( BoneMatrix, MAXSTUDIOBONES, BONE_USED_BY_HITBOX,
    0 ) ) return this->GetVecOrigin();

        matrix3x4_t hitbox = BoneMatrix[boneIndex];

        return Vector( hitbox[0][3], hitbox[1][3], hitbox[2][3] );
    }*/
};

class CHudTexture;

class FileWeaponInfo_t {
   public:
    FileWeaponInfo_t();

    // Each game can override this to get whatever values it wants from the
    // script.
    virtual void Parse(KeyValues* pKeyValuesData, const char* szWeaponName);

    bool bParsedScript;
    bool bLoadedHudElements;

    char szClassName[MAX_WEAPON_STRING];
    char szPrintName[MAX_WEAPON_STRING];

    char szViewModel[MAX_WEAPON_STRING];
    char szWorldModel[MAX_WEAPON_STRING];
    char szAmmo1[MAX_WEAPON_AMMO_NAME];
    char szWorldDroppedModel[MAX_WEAPON_STRING];
    char szAnimationPrefix[MAX_WEAPON_PREFIX];
    int iSlot;
    int iPosition;
    int iMaxClip1;
    int iMaxClip2;
    int iDefaultClip1;
    int iDefaultClip2;
    int iWeight;
    int iRumbleEffect;
    bool bAutoSwitchTo;
    bool bAutoSwitchFrom;
    int iFlags;
    char szAmmo2[MAX_WEAPON_AMMO_NAME];
    char szAIAddOn[MAX_WEAPON_STRING];

    // Sound blocks
    char aShootSounds[NUM_SHOOT_SOUND_TYPES][MAX_WEAPON_STRING];

    int iAmmoType;
    int iAmmo2Type;
    bool m_bMeleeWeapon;

    // This tells if the weapon was built right-handed (defaults to true).
    // This helps cl_righthand make the decision about whether to flip the model
    // or not.
    bool m_bBuiltRightHanded;
    bool m_bAllowFlipping;

    // Sprite data, read from the data file
    int iSpriteCount;
    CHudTexture* iconActive;
    CHudTexture* iconInactive;
    CHudTexture* iconAmmo;
    CHudTexture* iconAmmo2;
    CHudTexture* iconCrosshair;
    CHudTexture* iconAutoaim;
    CHudTexture* iconZoomedCrosshair;
    CHudTexture* iconZoomedAutoaim;
    CHudTexture* iconSmall;
};

class CCSWeaponInfo : public FileWeaponInfo_t {
   public:
    char* GetConsoleName() { return *(char**)((uintptr_t)this + 0x8); }

    int GetClipSize() { return *(int*)((uintptr_t)this + 0x20); }

    CSWeaponType GetWeaponType() {
        return *(CSWeaponType*)((uintptr_t)this + 0x140);
    }

    int GetDamage() { return *(int*)((uintptr_t)this + 0x16C); }

    float GetWeaponArmorRatio() { return *(float*)((uintptr_t)this + 0x170); }

    float GetPenetration() { return *(float*)((uintptr_t)this + 0x178); }

    float GetRange() { return *(float*)((uintptr_t)this + 0x184); }

    float GetRangeModifier() { return *(float*)((uintptr_t)this + 0x188); }

    float GetMaxPlayerSpeed() { return *(float*)((uintptr_t)this + 0x1B0); }

    float* GetMaxPlayerSpeedPtr() { return (float*)((uintptr_t)this + 0x1B0); }

    int GetZoomLevels() { return *(int*)((uintptr_t)this + 0x240); }

    char* GetTracerEffect() { return *(char**)((uintptr_t)this + 0x278); }

    int* GetTracerFrequency() { return (int*)((uintptr_t)this + 0x280); }
};

class C_BaseCombatWeapon : public C_BaseEntity {
   public:
    CCSWeaponInfo* GetCSWpnData() {
        typedef CCSWeaponInfo* (*oGetCSWpnData)(void*);
        return getvfunc<oGetCSWpnData>(this, 514)(this);
    }

    float GetSpread() {
        typedef float (*oGetSpread)(void*);
        return getvfunc<oGetSpread>(this, 507)(this);  // 553
    }

    float GetInaccuracy() {
        typedef float (*oGetInaccuracy)(void*);
        return getvfunc<oGetInaccuracy>(this, 537)(this);
    }

    void UpdateAccuracyPenalty() {
        typedef void (*oUpdateAccuracyPenalty)(void*);
        return getvfunc<oUpdateAccuracyPenalty>(this, 538)(this);  // 554
    }
};

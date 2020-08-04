
/*
 *
 *	This is the modules player resource area for getting things like Names,
 *team, and etc.
 *
 */

#include "../hacks/interfaces.hpp"  // The games entitys
#include "classes.hpp"              // Classnames
#include "netvars.hpp"              // Netvar offsets

#include "playerresource.hpp"

namespace modules {
namespace csgo {

// Used to store our player resource ent. We dont use a entity pointer as that
// might become invalid
static int player_resource_ent = 0;
/*
// For finding our player resource if we dont have it.
static bool GetPlayerResource() {

        // Try to get our current player resource entity
        IClientEntity* raw_entity =
g_IEntityList->GetClientEntity(player_resource_ent);

        // Check if we have a player resource
        if (raw_entity && !raw_entity->IsDormant() &&
raw_entity->GetClientClass()->m_ClassID == classes::CPlayerResource) return
true;

        // If we dont already have our player resource, we need to find it.
        player_resource_ent = 0;
        for (const auto& entity : g_CatEntitys) {
                raw_entity = g_IEntityList->GetClientEntity(entity.IDX);
                if (!raw_entity || raw_entity->GetClientClass()->m_ClassID !=
classes::CPlayerResource) continue; player_resource_ent = entity.IDX; return
true;
        }

        // We dont have our resource...
        return false;
}

// This is tf2 only stuff
#if defined(CATHOOK_TF2)
int GetMaxHealth(const CatEntity& player) {

        if (CE_BAD(player) || !GetPlayerResource()) return 0;
        if (player.IDX >= 64 || player.IDX < 0) return 0;

        IClientEntity* raw_player = g_IEntityList->GetClientEntity(player.IDX);
        if (!raw_player || raw_player->IsDormant()) return 0;

        return
*(int*)((uintptr_t)g_IEntityList->GetClientEntity(player_resource_ent) +
netvars::res_iMaxHealth + 4 * player.IDX);
}

int GetClass(const CatEntity& player) {

        if (CE_BAD(player) || !GetPlayerResource()) return 0;
        if (player.IDX >= 64 || player.IDX < 0) return 0;

        IClientEntity* raw_player = g_IEntityList->GetClientEntity(player.IDX);
        if (!raw_player || raw_player->IsDormant()) return 0;

        return
*(int*)((uintptr_t)g_IEntityList->GetClientEntity(player_resource_ent) +
netvars::res_iPlayerClass + 4 * player.IDX);
}
#endif
*/
}  // namespace csgo
}  // namespace modules


/*
 *
 *	Esp additions
 *
 */

#include "../../../features/esp.hpp"  // So we can get the esp menu location so we can add to it
#include "../../../framework/entitys.hpp"  // So we can use entitys
#include "../hacks/interfaces.hpp"         // Get client entitys
#include "../util/netvars.hpp"  // Contains definition for use of netvars

#include "esp.hpp"

namespace modules {
namespace csgo {
namespace cheats {
namespace esp {

static CatVarBool show_entity_classnames(features::esp::esp_menu,
                                         "esp_classname", true,
                                         "Show Entity Class Name",
                                         "Shows entitys classnames");
static CatVarBool show_team_num(features::esp::esp_menu, "esp_teamnum", true,
                                "Show Entity Team Name", "debug team nums");

// Function to run on world tick
void WorldTick() {
    // Check if esp is enabled
    // if (!features::esp::esp_enabled) return;
    /*
    for (const auto& entity : g_CatEntitys) {
            if (CE_BAD(entity) || !entity.alive) continue;

            IClientEntity* raw_entity =
    g_IEntityList->GetClientEntity(entity.IDX); if (!raw_entity ||
    raw_entity->GetDormant()) continue;

            // Buffer for sprintf
            char buf[64];
            // Classname esp
            if (show_entity_classnames)
                    features::esp::AddEspString(entity,
    raw_entity->GetClientClass()->m_pNetworkName);
            // Team number
            if (show_team_num && entity.type == ETYPE_PLAYER) {
                    sprintf(buf, "Team: %i", NET_VAR(raw_entity,
    netvars::m_iTeamNum, int)); features::esp::AddEspString(entity, buf);
            }
    }*/
}

}  // namespace esp
}  // namespace cheats
}  // namespace csgo
}  // namespace modules


/*
 *
 *	Esp additions
 *
 */

#include "../../../features/esp.hpp"  // So we can get the esp menu location so we can add to it
#include "../../../framework/entitys.hpp"  // So we can use entitys
#include "../hacks/interfaces.hpp"         // Get client entitys
#include "../util/netvars.hpp"  // Contains definition for use of netvars
#include "../util/playerresource.hpp"

#include "esp.hpp"

namespace modules::source::features::esp {

#if defined(CATHOOK_TF2)
static CatVarBool show_class(::features::esp::esp_menu, "esp_class", false,
                             "Show Classes");
#endif
static CatVarBool show_entity_classnames(::features::esp::esp_menu,
                                         "esp_debug_classname", false,
                                         "Show Entity Class Name",
                                         "Shows entitys classnames");
static CatVarBool show_team_num(::features::esp::esp_menu, "esp_debug_teamnum",
                                false, "Show Entity Team Name",
                                "debug team nums");

// Function to run on world tick
void Init() {
    /*
    #if defined(CATHOOK_TF2)
    // class
          ::features::esp::GetEntityStrings.push_back([](CatEntity* entity){
      std::pair<const char*, CatVector4> ret = {nullptr,
    colors::EntityColor(entity)}; switch(PRGetClass(entity)) { case 1: ret.first
    = "Scout"; break; case 2: ret.first = "Sniper"; break; case 3: ret.first =
    "Soldier"; break; case 4: ret.first = "Demoman"; break; case 5: ret.first =
    "Medic"; break; case 6: ret.first = "Heavy"; break; case 7: ret.first =
    "Pyro"; break; case 8: ret.first = "Spy"; break; case 9: ret.first =
    "Engineer"; break;
      }
      return ret;
    });
    #endif

    // Debug

    // Classname esp
    ::features::esp::GetEntityStrings.push_back([](CatEntity* entity){
      std::pair<const char*, CatVector4> ret = {nullptr, colors::white};
      if (!show_entity_classnames) return ret;
      ret.first = raw_entity->GetClientClass()->m_pNetworkName;
      return ret;
    });
    // Team number
    ::features::esp::GetEntityStrings.push_back([](CatEntity* entity){
      std::pair<const char*, CatVector4> ret = {nullptr, colors::white};
      if (!show_team_num) return ret;
      static char buf[12];
      sprintf(buf, "Team: %i", NET_VAR(entity, netvars::m_iTeamNum, int));
      ret.first = buf;
      return ret;
    });*/
}

}  // namespace modules::source::features::esp

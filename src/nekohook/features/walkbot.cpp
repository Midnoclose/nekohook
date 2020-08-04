
/*
 * Nekohook: Free, fast and modular cheat software
 * Copyright (C) 2018 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// c+p from followbot, please prune
#include "../framework/drawing.hpp"  // draw some crumbs
#include "../framework/game.hpp"  // So we can run things in draw and world tick
#include "../framework/trace.hpp"
#include "../util/catvars.hpp"
#include "../util/logging.hpp"

#include "../framework/console.hpp"  // Using console as a wrapper for ipc is even better
#include "../framework/ipc.hpp"  // Ipc to control followbots would be nice...

#include "walkbot.hpp"

namespace features::walkbot {

// A node in the walkbot
class Node {
   public:
    Node(const CatVector& _origin) : origin(_origin) {
        node_pool.push_back(this);
    }
    ~Node() {
        // Remove other connections to this node
        for (Node* i : node_pool)
            for (auto ii = i->connected.begin(); ii != i->connected.end(); ii++)
                if (*ii == this) i->connected.erase(ii);
        node_pool.erase(std::find(node_pool.begin(), node_pool.end(), this));
    }

    void Connect(Node* to_connect) {
        if (trace::Terrain(this->origin, to_connect->origin)
                .DistTo(to_connect->origin) > 2) {
            debug_log.Puts("This cant see other node!");
            return;
        }
        auto find = std::find(connected.begin(), connected.end(), to_connect);
        if (find != connected.end())
            debug_log.Puts("Cannot connect node, already connected!");
        else
            connected.push_back(to_connect);
    }
    void Disconnect(Node* to_disconnect) {
        auto find =
            std::find(connected.begin(), connected.end(), to_disconnect);
        if (find == connected.end())
            debug_log.Puts("Cannot disconnect node, not connected!");
        else
            connected.erase(find);
    }

    const math::Vector& GetOrigin() { return origin; }
    const std::vector<Node*>& GetConnected() { return connected; }
    static const std::vector<Node*>& GetNodePool() { return node_pool; }

   private:
    CatVector origin;
    std::vector<Node*> connected;
    static std::vector<Node*> node_pool;  // all the nodes
};
std::vector<Node*> Node::node_pool;

static Node* GetClosestNode(const CatVector& point) {
    Node* ret = nullptr;
    float cur_dist = 8192.0f;
    for (const auto& i : Node::GetNodePool()) {
        if (point.DistTo(i->GetOrigin()) > cur_dist) continue;
        if (trace::Terrain(point, i->GetOrigin()).DistTo(i->GetOrigin()) > 2)
            continue;
        ret = i;
    }
    return ret;
}
inline Node* GetClosestNode(Entity* entity) {
    return GetClosestNode(entity->GetOrigin());
}

class Path {
public:
    float GetDistance(){
        float dist = 0;
        auto end = this->int_path.end() - 1;
        for (auto i = this->int_path.begin(); i != end; i++){
            Node* tmp1, tmp2;
            tmp1 = *i;
            tmp2 = *(i + 1);
            dist += tmp1.GetOrigin().DistTo(tmp2.GetOrigin());
        }
        return dist;
    }
private:
    std::vector<Node*> int_path;
}
// Everything is a fucking mess in here,
// no real good way to order things nicely so deal with it for now during
// development cleaning comes later

static CatEnum wb_menu({"Autonomy", "Walkbot"});
enum class WbState {
    kIdle,
    kEditing,
    kRecording,
    kReplay,
    kPathing  // Pathing is different than replay, here we actually want to path
              // to players
};
static WbState cur_state;

static CatEnum state_catenum({"DISABLED", "RECOVERY", "EDITING", "RECORDING",
                              "REPLAY", "PATHING"});
static CatVarBool walkbot(wb_menu, "wb", false, "Walkbot");
static CatVarEnum wb_state(wb_menu, state_catenum, "wb_state",
                           static_cast<int>(State::kReplay), "Walkbot State");

static CatCommand add_node("wb_add", [](const std::vector<std::string_view>&) {

});
static CatCommand remove_node("wb_remove",
                              [](const std::vector<std::string_view>&) {});
static uservar::Int health_thresh(wb_menu, "wb_health_thresh")
static std::vector<Node> path;
static void WorldTick() {
    if (!walkbot) return;

    Entity* local_ent = Entity::GetLocalPlayer();
    if (!local_ent || local_ent->GetDormant() || !local_ent->GetAlive()) return;

    //if ()
    switch(cur_state) {

    case WbState::kReplay:

    case WbState::kPathing:
        // Health is most important
        if (path_state != PathState::kHealth) {
            int ent_count = Entity::GetCount();
            std::vector closest_pack;
            for (int i = 0; i < ent_count; i++) {
                Entity* ent = Entity::
                //if
            }
        } else {
            switch(path_state)


        }

    default:


    }
}

void Init() {}

}  // namespace features::walkbot

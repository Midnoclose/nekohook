
#include "gui/hud.hpp"

namespace neko::hook::hud {

static bool active = false;
static int length;
void Reset() {
    length = 0;
    Draw("Nekohook!");
}

void Draw(std::string_view str) {
    //draw::String({0, length}, str);
    //length += draw::GetLength(str).y + 2;
}

}

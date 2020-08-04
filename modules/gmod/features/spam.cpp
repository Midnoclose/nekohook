
#include "../../../features/spam.hpp"
#include "../hacks/interfaces.hpp"

#include "spam.hpp"

namespace modules::source::features::spam {

void Init() {
    ::features::spam::SayChat = [](const char* in) {
        g_IEngine->ServerCmd(("say \"" + std::string(in) + "\"").c_str());
    };
}

}  // namespace modules::source::features::spam

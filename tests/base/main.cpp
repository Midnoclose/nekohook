
#include "nekohook/ui/console.hpp"
#include "nekohook/entry.hpp"

namespace nekohook::module {

int main(std::vector<std::string_view> args) {
    ui::console::log << "Run Success" << std::endl;
    std::cout << "Uhjhhhhh" << std::endl;
    return 0;
}

}

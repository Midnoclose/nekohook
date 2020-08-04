
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

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>

#include "util/log.hpp"
#if defined(NEKO_EXTERNAL)
#include "framework/game.hpp"
#endif

#include "init.hpp"

namespace neko::init {

void Main() {
    // We wait to allow the constructors to finish before we initialize
    // Crashes occor otherwise, TODO, fix!
    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    debug_log.Puts("Initializing...");
    std::srand(std::time(nullptr));

    debug_log.Puts("Loading modules!");
    routine::Module::Init();

#if defined(NEKO_EXTERNAL)
    debug_log.Puts("Starting world thread!");
    std::thread world_thread([]() {
        for (;;) events::world.Emit();
    });
    // From what i currently know of gl, the thread needs gl context
    // We are starting a new thread thus it doesnt have one. Maybe we need to do
    // some kind of init inside the thread
    // TODO: Work out a clean way of doing init in the thread
    debug_log.Puts("Starting draw thread!");
    std::thread draw_thread([]() {
        for (;;) events::draw.Emit();
    });
#endif

    debug_log.Puts("Initializing Done!");

#if defined(NEKO_EXTERNAL)
    world_thread.detach();
    draw_thread.join();
#endif
}

}  // namespace neko::init

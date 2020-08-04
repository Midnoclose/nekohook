
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

#include <thread>

#include "init.hpp"  // Contains main init

// Using as a executable external
#if defined(NEKO_EXTERNAL)

int main() {
    neko::init::Main();
    while (true)
        ;
    return 0;  // this shouldnt happen
}

// Shared library
#elif defined(__linux__)

void __attribute__((constructor)) entry() {
    std::thread init_thread(neko::init::Main);
    init_thread.detach();
}

// Dynamic linking library
#elif defined(_WIN32)

#include <windows.h>

BOOL WINAPI DllMain(HMODULE hInstance, DWORD dwReason, LPVOID lpReserved) {
    if (dwReason == DLL_PROCESS_ATTACH) {
        std::thread init_thread(neko::init::Main);
        init_thread.detach();
    }
    return true;
}

#endif

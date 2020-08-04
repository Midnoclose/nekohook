
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

#pragma once

#if defined(__linux__)
#include <unistd.h>
#elif defined(_WIN32)
#include <Windows.h>
#endif
#include <cstdint>
#include <cstring>

namespace neko::mem {

// Offsetting something
template <typename Type, class Pointer>
inline Type* Offset(Pointer src, int offset) {
    return reinterpret_cast<Type*>(reinterpret_cast<uintptr_t>(src) + offset);
}

// For writing in a replacement at a specified address
template <class P>
void ForceWrite(P& replacement, void* address) {
#if defined(__linux__)
    // TODO: make method to write into all pages
    static int page_size = sysconf(_SC_PAGESIZE);
    // I dont understand how this works... halp...
    // https://stackoverflow.com/questions/6387771/get-starting-address-of-a-memory-page-in-linux
    void* page = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(address) &
                                         ~(page_size - 1));
    mprotect(page, page_size, PROT_WRITE | PROT_EXEC);
    std::memcpy(address, &replacement, sizeof(replacement));
    mprotect(page, page_size, PROT_EXEC);
#elif defined(_WIN32)
    // TODO, find page boundry
    DWORD last_protection, tmp;
    VirtualProtect(address, sizeof(replacement), PAGE_EXECUTE_READWRITE,
                   &last_protection);
    std::memcpy(address, patch, sizeof(replacement));
    VirtualProtect(address, sizeof(replacement), last_protection, &tmp);
#else
#pragma message("ForceWrite memory not supported on this platform")
#endif
}

}  // namespace neko::mem

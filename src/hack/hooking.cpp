
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

#include <stdlib.h>  // calloc
#include <string.h>  // memcpy
#include <limits>

#include "../util/logging.hpp"
#include "memory.hpp"

#include "hooking.hpp"

namespace neko {

void VMTHook::Set(void* inst) {
    this->Release();  // Release any hooks currently in place

    // Get our vtable from out base pointer and offset
    this->vtable_ptr = (void***)inst;
    this->vtable_original = *vtable_ptr;  // save original for release

    // Count how many functions avaible
    auto func_count = 0;
    while (this->vtable_original[func_count]) func_count++;
    debug_log.Fmt("Hooking vtable %#x with %i methods", this->vtable_ptr,
                  func_count);

    // Create a copy of the current vtable
    this->vtable_replacement = std::make_unique<void*[]>(func_count);
    ;  // add 2 to the count and make the pointer 2 of the alloc to give room
       // for the guards
    memcpy(this->vtable_replacement.get(), *this->vtable_ptr,
           sizeof(void*) * func_count);
}

void VMTHook::HookMethod(void* func, size_t idx) {
    debug_log.Fmt("Hooking method %d of vtable %#x, replacing %#x", idx,
                  this->vtable_ptr, this->GetMethod<void*>(idx));
    this->vtable_replacement[idx] = func;
}

void VMTHook::Release() {
    // Check if we have a vtable pointer and that the vtable pointer points to
    // our replacement
    if (!this->vtable_ptr ||
        *this->vtable_ptr != this->vtable_replacement.get())
        return;
    debug_log.Fmt("Un-hooking %#x", *vtable_ptr);
    *this->vtable_ptr = this->vtable_original;
}

void ASMHook(void* func_to_hook,
             void* replacement) {  // Set the place to hook, if size is
                                   // untouched u cant call the original

    // TODO, Copy original function

    // x86 & x86-64
    /*#if defined(__x86_64__) || defined(_M_AMD64) || defined(__i386__) ||
    defined(_M_IX86)

        // In x86 related systems, we will write in a jmp opcode so when the
    function is called, we will jump back

        // Why -5, TODO find out
        uintptr_t relative = replacement - func_to_hook - 5;

        // jump opcode
        uint8_t jmp = 0xE9;

        // Write in our jmp
        ForceWrite(jmp, func_to_hook);
        // Add the pointer to jmp to after the jmp opcode
        ForceWrite(replacement, func_to_hook + sizeof(jmp));
    #else
        #pragma message ("ASM hook not supported for this language")
    #endif*/
}

}  // namespace neko

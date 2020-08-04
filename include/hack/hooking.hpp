
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

#include <cstddef>  // size_t
#include <memory>   // std::unique_ptr

// WINDOWS IS FUCKING GAY AND BAD AND YOU SHOULD FEEL BAD
// TODO: windows does "this calls" we need to do multiple things allow vmt hooks
// to work.

// Class member functions are always "this calls" which i believe places the
// this ptr onto a register The hook replacement cant be defined with
// "__thiscall" as they arent member functions so the replacement needs
// "__fastcall" after the return value to allow us to get the register like
// normal. This causes an anoying thing that causes us to add a second variable
// to hold the edx register as well. This isnt the end of the world, just
// annoying.

// Then when you call the original, you have to make sure the original function
// pointer is a "__thiscall"

// Here is an example of one of my current hooks
#if !1  // To make ides not make this commented in my ide but still not compile
#if defined(_WIN32)
static bool __fastcall CreateMove_hook(void* thisptr, void* edx,
                                       float inputSample, CUserCmd* cmd) {
    using CreateMove_t = bool(__thiscall*)(void*, float, CUserCmd*);
#else
static bool CreateMove_hook(void* thisptr, float inputSample, CUserCmd* cmd) {
    using CreateMove_t = bool (*)(void*, float, CUserCmd*);
#endif
    const CreateMove_t original =
        clientmode.GetMethod<CreateMove_t>(offsets::CreateMove);
#endif

    // Dealing with the hook replacement
    // Some solutions might be some template magic to make the function work.
    // I dont know how i could do this tho

    // For the calling of the original,
    // Maybe adding a method to call the function and taking template arguments
    // like a std::function/cat::Function would. Could also do the template
    // thing from above and call a member or something to reuse the template
    // args Suggestion by f1:
    //  #ifndef _MSC_VER
    //      #define __thiscall
    //  #endif

    // So
    // 1. Make a template class with static members to use as hook replacement
    //    This allows us to do all sorts of template magic to it and limiting
    //    the ifdefs to one place Calling the orginal would also be easy as hell
    //    as we already have the arg types Problems occur of how to construct
    //    this class.
    //        Would name collisions occur, how would we handle the VMTHook with
    //        this style
    //
    // 2. TODO: I want more solutions that could be better than the code i have
    // now and solution #1
    //

    // TODO: make a temporary hooking class that serves one purpose to retrieve
    // data from args in a function
    //       IE: give it stuff to hook like normal, it adds its own function
    //       that when run, deletes "this" and calls a callback with the args
    //       wanted. Then returns the result of original func and continues like
    //       normal.

    namespace neko {

    // Class used to hook functions in objects with virtual functions
    class VMTHook {
       public:
        ~VMTHook() { this->Release(); }
        void Set(void* inst);  // For when you start hooking.
        void HookMethod(
            void* func,
            size_t idx);  // Give it the function you are replacing with and the
                          // number position of the function to replace
        void Apply() {
            *this->vtable_ptr = this->vtable_replacement.get();
        }                // To finish your hook
        void Release();  // To release this hook
        template <class T = void*>
        inline T GetMethod(size_t idx) const {
            return reinterpret_cast<T>(vtable_original[idx]);
        }

        // TODO: this->CallMethod<>();
        /*template<
        inline RET*/

        void*** vtable_ptr = nullptr;  // location to the pointer in the object
                                       // that contains its vtable
        void** vtable_original =
            nullptr;  // location of the objects original vtable
        std::unique_ptr<void*[]>
            vtable_replacement;  // location of our vtable replacement
    };

    template <typename F>
    inline F vfunc(void* thisptr, uintptr_t idx, uintptr_t offset = 0) {
        void** vmt = *reinterpret_cast<void***>(uintptr_t(thisptr) + offset);
        return reinterpret_cast<F>((vmt)[idx]);
    }

    }  // namespace neko

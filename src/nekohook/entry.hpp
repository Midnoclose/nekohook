
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

#include <vector>
#include <string_view>

template<typename ConstOptions>
class Nekohook {
public:
    entity
};

static int RealMain(std::vector<std::string_view> args) {
    int ret = module::main(std::move(args)); // needed to setup hooks, find offsets etc
    #if defined(NEKOHOOK_EXTERNAL)
    //std::thread();
    #endif
    return ret; 
}

}
int main(int argc, const char** args) {
    return nekohook::RealMain(std::vector<std::string_view>(args, &args[argc]));
}

static std::vector<std::string_view> ParseEnvArgs() {
    const char* argc_r = std::getenv("NEKOHOOK_ARGC");
    int argc = 0;
    if (argc_r) {
        std::size_t len = strlen(argc_r);
        if (std::from_chars(argc_r, argc_r + len, argc).ec != std::errc())
            throw std::logic_error("Recieved unknown value for NEKOHOOK_ARGC env variable");
    }
    std::vector<std::string_view> ret;
    ret.reserve(argc);
    for (int i = 0; i < argc; i++) {
        const char* args = std::getenv("NEKOHOOK_ARGS" + std::to_string(i));
        if (!args)
            throw std::logic_error("Missing an expected NEKOHOOK_ARGS value");
        ret.emplace_back(args);
    }
    return ret;
}

}

#if defined(__linux__) 

    void __attribute__((constructor)) Entry() {
        psudocrt::CallAfterInit([](){
            RealMain(ParseEnvArgs());
        );
    }

#elif defined(_WIN32)

    BOOL WINAPI DllMain(HINSTANCE this_dll, DWORD reason, LPVOID) {
        switch( fdwReason ) { 
            case DLL_PROCESS_ATTACH:
                static_assert(false);
                //Entry(); break;
            case DLL_THREAD_ATTACH: break;
            case DLL_THREAD_DETACH: break;
            case DLL_PROCESS_DETACH: break;
        }
        return TRUE;
    }

#endif
#endif




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

#include <oxide.h>
#include "GL/glew.h"
#define NANOVG_GLEW
#define NANOVG_GL3_IMPLEMENTATION
#include <nanovg.h>
#include <nanovg_gl.h>
#include <nanovg_gl_utils.h>


#include "oxide.hpp"

namespace nekohook::gfx::oxide {

static std::string to_string(Oxide_InitResult r) {
    switch(r) {
    oxide_init_success:
        assert(false);
        return "Init Success";
    oxide_init_window_failed:
        return "Failed to create window";
    oxide_init_gl_failed:
        return "Failed to init opengl";
    oxide_init_target_failed:
        return "Target window name not found.";
    default:
        assert(false);
        return std::string();
    };
}

NVGcontext* CreateContext(const char* window_name) {
    auto res = oxide_init(window_name);
    if (res != oxide_init_success)
        throw std::runtime_error(to_string(res));
    return nvgCreateGL3(NVG_STENCIL_STROKES);
}

#if !defined(NEKOHOOK_EXTERNAL) && defined(__linux__)

static Window GetWindowByPidName(Display* display, Window current, std::string_view process_name) {
    XClassHint hint;
    if (XGetClassHint(display, current, &hint)) {
        bool found = hint.res_class && hint.res_class == process_name;
        XFree(hint.res_name); XFree(hint.res_class);
        if (found)
            return current;
    }

    Window root, parent; Window* children; unsigned size;
    if (XQueryTree(display, current, &root, &parent, &children, &size) != 0) {
        for (unsigned i = 0; i < size; i++) {
            if (Window found_window = GetWindowByPidName(display, children[i], process_name)) {
                XFree(children);
                return found_window; 
            }
        }
        XFree(children);
    }
    throw std::runtime_error("Unable to find x window by PID name");
}

NVGcontext* CreateContext() {
    std::ifstream proc_status("/proc/self/status");
    if (!proc_status) 
        throw std::runtime_error("Unable to open /proc/self/status");

    std::string proc_name;
    std::getline(proc_status, proc_name);

    Display* d = XOpenDisplay(NULL);
    Window w = GetWindowByPidName(d, DefaultRootWindow(display), proc_name.substr(6).c_str());
    char* name = nullptr;
    if (!XFetchName(display, current, &name)
        throw std::runtime_error("Unable to retrieve window name");

    NVGcontext* ctx = CreateContext(name);
    XFree(name);
    return ctx;
}
#endif
}

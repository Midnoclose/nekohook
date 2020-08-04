
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

#include <fstream>
#include <stack>

#include <nanovg_gl.h>
#include <oxide.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

// Xlib fix
#ifdef Bool
#undef Bool
#endif

#include "ui/settings/bool.hpp"
#include "features/debug.hpp"
#include "features/esp.hpp"
#include "features/followbot.hpp"
#include "features/radar.hpp"
#include "features/walkbot.hpp"
#include "ui/console.hpp"

#include "draw.hpp"

namespace nekohook {
namespace draw { 

static setting::TreeMap menu({"Visuals", "Ui"});
static setting::Bool using_oxide(menu, "oxide", true);

static std::string GetProcessName() {
    #ifdef __linux__
        std::ifstream proc_status("/proc/self/status");
        if (!proc_status) 
            throw std::runtime_error("Unable to open /proc/self/status");

        std::string proc_name;
        std::getline(proc_status, proc_name);
        return proc_name.substr(6);
    #else
        assert(false);
    #endif
    return std::string();
}

namespace xlib {

Display* display;
Window window;

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

}

// find good time to init oxide, im too high, autoget name
void Init() {
    
    const char* TODO_get_name = "null";
    Oxide_InitResult err = oxide_init(TODO_get_name); 

    if (err)
        throw std::runtime_error("Unable to init oxide overlay!");

}

// TODO! make it run it
void Shutdown() {

if (using_oxide)
    oxide_shutdown();

}

const Color Color::white = Color::FromRGB(255, 255, 255);

}

namespace events {
void Draw() {
    using namespace draw;
    if (using_oxide)
        oxide_begin_frame();
    if (using_oxide)
        oxide_end_frame();
}}

}


/*
 *
 * This file is for giving access to main xlib stuff
 *
 *
 */

#include <X11/Xutil.h>  // So we can see process names, and geometry of windows
#include <cstring>      // strcmp()
#include <fstream>      // std::ifstream

#include "../../util/iohelper.hpp"  // For our process name
#include "../../util/logging.hpp"   // Logging is always cool!

#include "xlib.hpp"

// TODO, have xlib store display on init rather than every draw
// TODO: inline everything and place into a single or few hpp files...
// Makes managing cmake easier and easy inclusion of it ;)

// TODO, Make own xoverlay to use the same systems as xinput

namespace xlib {

Display* xAppDisplay;
Window xAppWindow;

// Check if we have display/window.
bool GetXDisplay() {
    // If we dont have a display, attempt to get one.
    if (!xAppDisplay) {
        // Use the "DISPLAY" enviroment var for our display. This may not always
        // be the case but its close enough!
        if (!(xAppDisplay = XOpenDisplay(nullptr)))
            return false;  // check if we recieved a display
        debug_log.Puts("Xlib Input: Recieved XDisplay!");
    }
    return true;
}

// Gets name of process using unix goodies
static std::string GetProcessName() {
#ifdef __linux__
    // Open /proc/self/status to get our process name
    std::ifstream proc_status("/proc/self/status");
    if (!proc_status.is_open()) return "unknown";

    // Get the first line
    char proc_name[32];
    proc_status.getline(
        proc_name, sizeof(proc_name));  // We should only need the first line as
                                        // unix keeps "Name: " on first
    proc_status.close();

    // Seperate "Name: " from our string, this isnt as reliable as regex but it
    // gets the job done and quick
    return std::string(proc_name).substr(6);
#else
#warning "Cannot get process name"
#endif
    return std::string();
}

// Searches for windows with a pid name
static bool SearchForWindow(
    Window w = XDefaultRootWindow(xAppDisplay),
    const char* process_name = GetProcessName().c_str()) {
    if (!GetXDisplay()) return false;  // Make sure we have a display

    // Get the process name for the current window
    XClassHint classhint;
    if (XGetClassHint(xAppDisplay, w, &classhint)) {
        if (classhint.res_class) {
            // Check if the process name of the window matches the one we are in
            if (!strcmp(classhint.res_class, process_name)) {
                xAppWindow = w;
                return true;
            }
        }
    }

    // Recurse into child windows.
    Window wRoot, wParent;
    Window* wChild;
    unsigned nChildren;
    if (XQueryTree(xAppDisplay, w, &wRoot, &wParent, &wChild, &nChildren) !=
        0) {
        for (unsigned i = 0; i < nChildren; i++) {
            if (SearchForWindow(wChild[i], process_name))
                return true;  // Since a child returned true, we return true to
                              // go up the chain
        }
    }
    return false;
}

bool GetXWindow() {
    // We need display to get a window
    if (!GetXDisplay()) return false;

    // If we dont have the game window, we try to find it here!
    if (!xAppWindow) {
        // Attempt to get our window
        if (!SearchForWindow()) return false;
        debug_log.Fmt("Xlib Input: Recieved XWindow: 0x%x", xAppWindow);
    }
    return true;
}

}  // namespace xlib

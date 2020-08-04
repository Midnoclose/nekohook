
/*
 *
 *	Header for use of our shared objects
 *
 *
 */

#pragma once

#include "../../../hacks/sharedobj.hpp"  // For the normal shared obj class

// I dont know what this does
typedef void* (*fn_CreateInterface_t)(const char*, int*);

class SourceSo : public SharedObject {
   public:
    SourceSo(const char* _file_name);
    void* CreateInterface(const char* interface);

   private:
    fn_CreateInterface_t fptr = nullptr;  // Used by source but is usefull
};

namespace modules::source::hacks::sharedobj {

// Create move hook + controling attack and movement
extern SourceSo client;

extern SourceSo server;
// For player names
extern SourceSo engine;
// Used for surface drawing
extern SourceSo vgui2;
// CVars
extern SourceSo vstdlib;
// Used for our paint traverse hook
#if defined(CATHOOK_GFX_SURFACE)
extern SourceSo vguimatsurface;
#endif

}  // namespace modules::source::hacks::sharedobj

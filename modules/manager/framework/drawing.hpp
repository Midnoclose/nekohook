
#include <functional>  // std::pair()

#include "../../../util/mathlib.hpp"  // CatVector4
#include "../../../util/platform.hpp"

#if defined(NEKO_DYNAMIC)

#include "../util/functions.hpp"  // CMFunction

extern CMFunction<void(int, int, int, int, CatVector4)> Line;
extern CMFunction<void(int, int, int, int, CatVector4)> Rect;  // Outline rect
extern CMFunction<void(int, int, int, int, CatVector4)>
    RectFilled;  // Filled rect
extern CMFunction<void(int, int, float, int, CatVector4)>
    Circle;  // Outline circle
extern CMFunction<void(int, int, float, int, CatVector4)>
    CircleFilled;  // filled circle
extern CMFunction<void(const char*, int, int, int, int, CatVector4)> String;
extern CMFunction<std::pair<int, int>(const char*, int, int)>
    GetStringLength;  // get size of string in pixels, x and y
extern CMFunction<bool(CatVector, std::pair<int, int>&)>
    WorldToScreen;  // Get a world vector to screen
// Fonts, please put font names, the name that the font is named in the font
// itself... Ones that your draw system can draw
extern std::vector<std::string> Fonts;

// If we arent dynamic, include your modules entity header here, then use "using
// namespace" to get out of your namespace and let the framework use the
// function
#else
// Source 2013
#if defined(NEKO_SOURCE2013)
#define SOURCE2013_DRW_HEADER \
    "../../source2013/framework/drawing.hpp"  // so i dont need to type twice
//#if !HAS_INCLUDE(SOURCE2013_DRW_HEADER)
//  #error "Cant include source2013 entities header"
//#else
#include SOURCE2013_DRW_HEADER
using namespace modules::source::framework;
//#endif
// CSGO
#elif defined(NEKO_CSGO)
#define CSGO_DRW_HEADER \
    "../../csgo/framework/entitys.hpp"  // so i dont need to type twic
#if HAS_INCLUDE(CSGO_DRW_HEADER)
#error "Cant include csgo entities header"
#else
#include CSGO_DRW_HEADER
using namespace modules::csgo::framework;
#endif
#else
#pragma message("Module Manager: No proper entity header defined")
#endif
#endif

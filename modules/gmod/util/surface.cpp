
/*
 *
 *	Welcome to the Valve surface drawing module!
 *	Run the init function below if you wish to use this drawing module.
 *	You must be using a source 2013 game with access to the valve surface
 *interface. -Onee
 *
 */

#if defined(CATHOOK_GFX_SURFACE)

#include <algorithm>  // Min() Max()

#include "../../../framework/drawing.hpp"  // To pass our functions to the drawing mgr
#include "../../../util/logging.hpp"  // We log stuff
#include "../../../util/strings.hpp"  // to format stuff
#include "../hacks/interfaces.hpp"    // We use the surface interface from here

#include "surface.hpp"

namespace modules::source::valvesurface {

// allows us to convert from rgba into something valve surface understands
static inline Color convert(const CatVector4& _color) {
    return Color(_color.x, _color.y, _color.z, _color.a);
}

static void Line(int x, int y, int w, int h, CatVector4 color) {
    g_ISurface->DrawSetColor(convert(color));
    g_ISurface->DrawLine(x, y, x + w, y + h);
}

static void Rect(int x, int y, int w, int h, CatVector4 color) {
    g_ISurface->DrawSetColor(convert(color));
    g_ISurface->DrawOutlinedRect(x, y, x + w, y + h);
}

static void RectFilled(int x, int y, int w, int h, CatVector4 color) {
    g_ISurface->DrawSetColor(convert(color));
    g_ISurface->DrawFilledRect(x, y, x + w, y + h);
}

// Font system, We only use 12 fonts to save on memory
static unsigned long surface_fonts[FONT_COUNT][12];

// Retrieves one of the fonts generated and saved into
static const unsigned long& GetSurfaceFont(int font, int size) {
    // Init fonts if we havent
    static bool font_init = false;
    if (!font_init) {
        // Per font
        for (int i = 0; i < FONT_COUNT; i++) {
            // Per size
            for (int ii = 0; ii < 12; ii++) {
                surface_fonts[i][ii] = g_ISurface->CreateFont();
                g_ISurface->SetFontGlyphSet(
                    surface_fonts[i][ii], draw::Fonts[i], ii + 20, 0, 0, 0, 0);
            }
        }
        font_init = true;
    }
    // Clamping as we dont have that many font sizes
    return surface_fonts[font][std::max(std::min(32, size), 20) - 1];
}

// Get string height and length in pixels
static std::pair<int, int> StringLength(const char* string, int font,
                                        int size) {
    // Convert our string to wchar
    wchar_t buf[1024];
    mbstowcs(buf, string, sizeof(buf));
    // Draw
    std::pair<int, int> ret;
    g_ISurface->GetTextSize(GetSurfaceFont(font, size), buf, ret.first,
                            ret.second);
    return ret;
}

// String drawing system
// Main string draw
static void String3(const char* text, int x, int y, int font, int size,
                    CatVector4 color) {
    // Set Precursor
    g_ISurface->DrawSetTextPos(x, y);
    g_ISurface->DrawSetTextColor(convert(color));
    g_ISurface->DrawSetTextFont(GetSurfaceFont(font, size));
    // Conversion from char to wchar
    wchar_t buf[1024];
    mbstowcs(buf, text, 1024);
    // Draw
    g_ISurface->DrawUnicodeString(buf);
}
// Shadow processor
#define shadow          \
    CatVector4(0, 0, 0, \
               255)  // We use full as a transparent can make things weird
static void String2(const char* text, int x, int y, int font, int size,
                    CatVector4 color) {
    // We make a nice outline with this
    String3(text, x - 2, y - 2, font, size, shadow);  // top left
    String3(text, x + 2, y - 2, font, size, shadow);  // top right
    String3(text, x - 2, y + 2, font, size, shadow);  // bot left
    String3(text, x + 2, y + 2, font, size, shadow);  // bot right
    String3(text, x, y - 2, font, size, shadow);      // top center
    String3(text, x, y + 2, font, size, shadow);      // bot center
    String3(text, x - 2, y, font, size, shadow);      // left center
    String3(text, x + 2, y, font, size, shadow);      // right center

    String3(text, x, y, font, size, color);
}
// String input, fixes newlines
static void String1(const char* text, int x, int y, int font, int size,
                    CatVector4 color) {
    // Check if newlined
    bool newlined = false;
    auto len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (text[i] == '\n') {
            newlined = true;
            break;
        }
    }
    // Correct for newlines?
    if (newlined) {
        int buf_height = 0;  // Hight in pixels of used space
        int cur_len = 0;     // How many chars have we passed
        for (int i = 0; i < len; i++) {
            cur_len++;

            // Check for newline
            if (text[i] == '\n' || i == len - 1) {
                // Get our substring and draw it
                char buf[512];
                substr(buf, text, len - cur_len, cur_len);
                String2(buf, x, y + buf_height, font, size, color);

                // Update our book keepers
                cur_len = 0;
                buf_height += StringLength(buf, font, size).second + 1;
            }
        }
    } else {
        String2(text, x, y, font, size, color);
    }
}

// Use this to init our draw functions to the drawing mgr
void Init() {
    debug_log.log("Begin Valve Surface Draw Module Init...");

    // Pass the surface functions to the drawmodule manager
    draw::Line = Line;
    draw::Rect = Rect;
    draw::RectFilled = RectFilled;
    draw::String = String1;
    draw::GetStringLength = StringLength;
}

}  // namespace modules::source::valvesurface

#endif

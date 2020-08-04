
/*
 *
 *
 * Gl Draw using libglez
 *
 *
 */

#include <GL/glew.h>

#include "../../../res/fonts/opensans.ttf.h"
#include "../../../res/fonts/unispace.ttf.h"
#include "../../../res/fonts/verasans.ttf.h"
#include "../../framework/drawing.hpp"  // Set draw funcs
#include "../../framework/game.hpp"     // Run on draw
#include "../../framework/input.hpp"    // For bounds
#include "../../util/iohelper.hpp"
#include "../../util/logging.hpp"
#include "libglez/include/glez.h"  // Include the lib_glez for easy open gl drawing ;)

#include "gl_draw.hpp"

namespace modules {
namespace gl_draw {

static io::PackedFile packed_fonts[] = {
    io::PackedFile(opensans_ttf, sizeof(opensans_ttf)),
    io::PackedFile(verasans_ttf, sizeof(verasans_ttf)),
    io::PackedFile(unispace_ttf, sizeof(unispace_ttf)),
};
// Font system, We only use 12 fonts to save on memory
static glez_font_t glez_fonts[draw::Font::kFontCount]
                             [GLEZ_FONT_COUNT / draw::Font::kFontCount];

// Convert frameworks colors into glez colors
static inline glez_rgba_t convert(const CatColor& in) {
    return *reinterpret_cast<const glez_rgba_t*>(&in);
}

// Run to init glez
void Init() {
    debug_log.Puts("Loading gl_draw!");

    // Setup glez
    auto bounds = input::GetBounds();
    glClearColor(1.0, 0.0, 0.0, 0.5);
    glewExperimental = GL_TRUE;
    debug_log.Fmt("glewInit: %i", glewInit());
    glez_init(bounds.first, bounds.second);
    input::bounds_event.Listen([](std::pair<int, int> new_bounds) {
        glez_resize(new_bounds.first, new_bounds.second);
    });

    // Per font
    for (int i = 0; i < draw::Font::kFontCount; i++)
        for (int ii = 0; ii < 32; ii++)  // Per size
            glez_fonts[i][ii] =
                glez_font_load(packed_fonts[i].GetPath().c_str(), ii);

    // Glez wants to know before and after we draw
    events::draw.Listen(glez_begin, cat::Order::kBefore);
    events::draw.Listen(glez_end, cat::Order::kAfter);

    // Give the drawmgr our glez draw functions
    draw::Line = [](int x, int y, int w, int h, CatColor color) {
        glez_line(x, y, w, h, convert(color), 1);
    };
    draw::Rect = [](int x, int y, int w, int h, CatColor color) {
        glez_rect_outline(x, y, w, h, convert(color), 1);
    };
    draw::RectFilled = [](int x, int y, int w, int h, CatColor color) {
        glez_rect(x, y, w, h, convert(color));
    };

    draw::Circle = [](int x, int y, float radius, int steps, CatColor color) {
        glez_circle(x, y, radius, convert(color), 1, steps);
    };

    draw::String = [](const char* text, int x, int y, int font, int size,
                      CatColor color) {
        float xx, yy;
        glez_string_with_outline(x, y, text, glez_fonts[font][size],
                                 convert(color), convert(colors::black), 2, 100,
                                 &xx, &yy);
    };
    draw::GetStringLength = [](const char* string, int font,
                               int size) -> std::pair<int, int> {
        float x, y;
        glez_font_string_size(glez_fonts[font][size], string, &x, &y);
        return {x + 2, y + 2};
    };
}

}  // namespace gl_draw
}  // namespace modules

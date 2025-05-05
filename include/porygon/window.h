#ifndef PORYGON_WINDOW_GUARD
#define PORYGON_WINDOW_GUARD

////////////////////////////////////////////////////////////////////////////////
// Dependencies
////////////////////////////////////////////////////////////////////////////////

#include <porygon/color.h>
#include <porygon/vector.h>

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

void          porygon_window_create       (int width, int height, const char* title);
void          porygon_window_destroy      (void);

void          porygon_window_clear        (void);
void          porygon_window_present      (void);
void          porygon_window_color        (PorygonColor color);
void          porygon_window_vsync        (int flag);
void          porygon_window_fullscreen   (int flag);

int           porygon_window_should_close (void);
PorygonVector porygon_window_get_position (void);
PorygonVector porygon_window_get_size     (void);

#endif // PORYGON_WINDOW_GUARD
#ifndef PORYGON_COLOR_GUARD
#define PORYGON_COLOR_GUARD

////////////////////////////////////////////////////////////////////////////////
// Macros
////////////////////////////////////////////////////////////////////////////////

#define PORYGON_COLOR_WHITE     (PorygonColor) { 1.0f, 1.0f, 1.0f, 1.0f }
#define PORYGON_COLOR_GRAY      (PorygonColor) { 0.5f, 0.5f, 0.5f, 1.0f }
#define PORYGON_COLOR_BLACK     (PorygonColor) { 0.0f, 0.0f, 0.0f, 1.0f }
#define PORYGON_COLOR_RED       (PorygonColor) { 1.0f, 0.0f, 0.0f, 1.0f }
#define PORYGON_COLOR_ORANGE    (PorygonColor) { 1.0f, 0.5f, 0.0f, 1.0f }
#define PORYGON_COLOR_YELLOW    (PorygonColor) { 1.0f, 1.0f, 0.0f, 1.0f }
#define PORYGON_COLOR_LIME      (PorygonColor) { 0.5f, 1.0f, 0.0f, 1.0f }
#define PORYGON_COLOR_GREEN     (PorygonColor) { 0.0f, 1.0f, 0.0f, 1.0f }
#define PORYGON_COLOR_MINT      (PorygonColor) { 0.0f, 1.0f, 0.5f, 1.0f }
#define PORYGON_COLOR_CYAN      (PorygonColor) { 0.0f, 1.0f, 1.0f, 1.0f }
#define PORYGON_COLOR_AZURE     (PorygonColor) { 0.0f, 0.5f, 1.0f, 1.0f }
#define PORYGON_COLOR_BLUE      (PorygonColor) { 0.0f, 0.0f, 1.0f, 1.0f }
#define PORYGON_COLOR_VIOLET    (PorygonColor) { 0.5f, 0.0f, 1.0f, 1.0f }
#define PORYGON_COLOR_MAGENTA   (PorygonColor) { 1.0f, 0.0f, 1.0f, 1.0f }
#define PORYGON_COLOR_BUBBLEGUM (PorygonColor) { 1.0f, 0.0f, 0.5f, 1.0f }

////////////////////////////////////////////////////////////////////////////////
// Types
////////////////////////////////////////////////////////////////////////////////

typedef struct PorygonColor
{
    float red;
    float green;
    float blue;
    float alpha;
}
PorygonColor;

#endif // PORYGON_COLOR_GUARD
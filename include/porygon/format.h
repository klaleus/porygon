#ifndef PORYGON_FORMAT_GUARD
#define PORYGON_FORMAT_GUARD

////////////////////////////////////////////////////////////////////////////////
// Types
////////////////////////////////////////////////////////////////////////////////

typedef struct PorygonBuffer PorygonBuffer;

typedef enum PorygonFormatAttribute
{
    PORYGON_FORMAT_ATTRIBUTE_POSITION,
    PORYGON_FORMAT_ATTRIBUTE_COLOR,
    PORYGON_FORMAT_ATTRIBUTE_COUNT
}
PorygonFormatAttribute;

typedef struct PorygonFormat
{
    int glfw_handle;
    int attributes[PORYGON_FORMAT_ATTRIBUTE_COUNT];
    int attribute_offsets[PORYGON_FORMAT_ATTRIBUTE_COUNT];
    int attribute_count;
    int vertex_size;
}
PorygonFormat;

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

PorygonFormat porygon_format_create(const PorygonFormatAttribute* attributes, int attribute_count);
void porygon_format_destroy(const PorygonFormat* format);

void porygon_format_activate(const PorygonFormat* format);

void porygon_format_vertex_buffer(const PorygonFormat* format, const PorygonBuffer* buffer);
void porygon_format_index_buffer(const PorygonFormat* format, const PorygonBuffer* buffer);

#endif // PORYGON_FORMAT_GUARD

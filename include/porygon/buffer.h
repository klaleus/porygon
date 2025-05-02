#ifndef PORYGON_BUFFER_GUARD
#define PORYGON_BUFFER_GUARD

////////////////////////////////////////////////////////////////////////////////
// Types
////////////////////////////////////////////////////////////////////////////////

typedef enum PorygonBufferType
{
    PORYGON_BUFFER_TYPE_VERTEX,
    PORYGON_BUFFER_TYPE_INDEX,
    PORYGON_BUFFER_TYPE_INDIRECT,
    PORYGON_BUFFER_TYPE_UNIFORM,
    PORYGON_BUFFER_TYPE_SHADER_STORAGE
}
PorygonBufferType;

typedef struct PorygonBuffer
{
    int glfw_handle;
    PorygonBufferType type;
    int capacity;
    int binding;
    int active;
}
PorygonBuffer;

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

PorygonBuffer porygon_buffer_create(PorygonBufferType type, int capacity, int binding);
void porygon_buffer_destroy(const PorygonBuffer* buffer);

void porygon_buffer_activate(PorygonBuffer* buffer);
void porygon_buffer_deactivate(PorygonBuffer* buffer);

void porygon_buffer_edit(const PorygonBuffer* buffer, const void* data, int size, int offset);

#endif // PORYGON_BUFFER_GUARD
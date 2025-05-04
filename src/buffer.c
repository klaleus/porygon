////////////////////////////////////////////////////////////////////////////////
// Dependencies
////////////////////////////////////////////////////////////////////////////////

#include <porygon/buffer.h>

#include <chatot/chatot.h>
#include <glad/gl.h>

////////////////////////////////////////////////////////////////////////////////
// Functions <porygon/buffer.h>
////////////////////////////////////////////////////////////////////////////////

PorygonBuffer porygon_buffer_create(PorygonBufferType type, int capacity, int binding)
{
    PorygonBuffer buffer = { 0 };

    buffer.type = type;
    buffer.capacity = capacity;
    buffer.binding = binding;

    glCreateBuffers(1, &buffer.glfw_handle);
    if (!buffer.glfw_handle)
    {
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to create buffer.");
    }

    glNamedBufferStorage(buffer.glfw_handle, capacity, 0, GL_DYNAMIC_STORAGE_BIT);

    return buffer;
}

void porygon_buffer_destroy(const PorygonBuffer* buffer)
{
    if (buffer->glfw_handle)
    {
        glDeleteBuffers(1, &buffer->glfw_handle);
    }
}

void porygon_buffer_activate(PorygonBuffer* buffer)
{
    switch (buffer->type)
    {
        case PORYGON_BUFFER_TYPE_VERTEX:
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to activate buffer. Vertex buffers should be attached to a format, then that format should be activated with `porygon_format_activate()`.");
        break;

        case PORYGON_BUFFER_TYPE_INDEX:
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to activate buffer. Index buffers should be attached to a format, then that format should be activated with `porygon_format_activate()`.");
        break;

        case PORYGON_BUFFER_TYPE_INDIRECT:
        glBindBuffer(GL_DRAW_INDIRECT_BUFFER, buffer->glfw_handle);
        break;

        case PORYGON_BUFFER_TYPE_UNIFORM:
        glBindBufferBase(GL_UNIFORM_BUFFER, buffer->binding, buffer->glfw_handle);
        break;

        case PORYGON_BUFFER_TYPE_SHADER_STORAGE:
        glBindBufferBase(GL_SHADER_STORAGE_BUFFER, buffer->binding, buffer->glfw_handle);
        break;
    }
}

void porygon_buffer_edit(const PorygonBuffer* buffer, const void* data, int size, int offset)
{
    if (offset + size > buffer->capacity)
    {
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to edit buffer.");
    }

    glNamedBufferSubData(buffer->glfw_handle, offset, size, data);
}
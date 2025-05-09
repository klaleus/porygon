////////////////////////////////////////////////////////////////////////////////
// Dependencies
////////////////////////////////////////////////////////////////////////////////

#include <porygon/buffer.h>
#include <porygon/format.h>

#include <chatot/chatot.h>
#include <glad/gl.h>

////////////////////////////////////////////////////////////////////////////////
// Private Variables
////////////////////////////////////////////////////////////////////////////////

static int _porygon_format_attribute_sizes[] =
{
    [PORYGON_FORMAT_ATTRIBUTE_POSITION] = sizeof(float) * 3,
    [PORYGON_FORMAT_ATTRIBUTE_COLOR] = sizeof(float) * 4
};

////////////////////////////////////////////////////////////////////////////////
// Functions <porygon/format.h>
////////////////////////////////////////////////////////////////////////////////

PorygonFormat porygon_format_create(const PorygonFormatAttribute* attributes, int attribute_count)
{
    PorygonFormat format = { 0 };

    format.attribute_count = attribute_count;

    glCreateVertexArrays(1, &format.gl_handle);
    if (!format.gl_handle)
    {
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to create format.");
    }

    for (int i = 0; i < attribute_count; i++)
    {
        PorygonFormatAttribute attribute = attributes[i];

        switch (attribute)
        {
            case PORYGON_FORMAT_ATTRIBUTE_POSITION:
            glVertexArrayAttribFormat(format.gl_handle, i, 3, GL_FLOAT, GL_FALSE, format.vertex_size);
            break;

            case PORYGON_FORMAT_ATTRIBUTE_COLOR:
            glVertexArrayAttribFormat(format.gl_handle, i, 4, GL_FLOAT, GL_FALSE, format.vertex_size);
            break;
        }

        glVertexArrayAttribBinding(format.gl_handle, i, 0);
        glEnableVertexArrayAttrib(format.gl_handle, i);

        format.attributes[attribute] = 1;
        format.attribute_offsets[attribute] = format.vertex_size;
        format.vertex_size += _porygon_format_attribute_sizes[attribute];
    }

    return format;
}

void porygon_format_destroy(const PorygonFormat* format)
{
    if (format->gl_handle)
    {
        glDeleteVertexArrays(1, &format->gl_handle);
    }
}

void porygon_format_activate(const PorygonFormat* format)
{
    glBindVertexArray(format->gl_handle);
}

void porygon_format_vertex_buffer(const PorygonFormat* format, const PorygonBuffer* buffer)
{
    glVertexArrayVertexBuffer(format->gl_handle, buffer->binding, buffer->gl_handle, 0, format->vertex_size);
}

void porygon_format_index_buffer(const PorygonFormat* format, const PorygonBuffer* buffer)
{
    glVertexArrayElementBuffer(format->gl_handle, buffer->gl_handle);
}
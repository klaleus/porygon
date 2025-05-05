////////////////////////////////////////////////////////////////////////////////
// Dependencies
////////////////////////////////////////////////////////////////////////////////

#include <porygon/shader.h>

#include <chatot/chatot.h>
#include <glad/gl.h>

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

PorygonShader porygon_shader_create(const char* vertex_text, const char* fragment_text)
{
    PorygonShader shader = { 0 };

    GLuint gl_vertex_handle = glCreateShader(GL_VERTEX_SHADER);
    if (!gl_vertex_handle)
    {
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to create vertex shader.");
    }

    const char* vertex_text_const = vertex_text;
    glShaderSource(gl_vertex_handle, 1, &vertex_text_const, 0);
    glCompileShader(gl_vertex_handle);

    int vertex_compile_result;
    glGetShaderiv(gl_vertex_handle, GL_COMPILE_STATUS, &vertex_compile_result);
    if (!vertex_compile_result)
    {
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to compile vertex shader.");
    }

    GLuint gl_fragment_handle = glCreateShader(GL_FRAGMENT_SHADER);
    if (!gl_fragment_handle)
    {
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to create fragment shader.");
    }

    const char* fragment_text_const = fragment_text;
    glShaderSource(gl_fragment_handle, 1, &fragment_text_const, 0);
    glCompileShader(gl_fragment_handle);

    int fragment_compile_result;
    glGetShaderiv(gl_fragment_handle, GL_COMPILE_STATUS, &fragment_compile_result);
    if (!fragment_compile_result)
    {
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to compile fragment shader.");
    }

    shader.gl_handle = glCreateProgram();
    if (!shader.gl_handle)
    {
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to create shader program.");
    }

    glAttachShader(shader.gl_handle, gl_vertex_handle);
    glAttachShader(shader.gl_handle, gl_fragment_handle);
    glLinkProgram(shader.gl_handle);

    int program_link_result;
    glGetProgramiv(shader.gl_handle, GL_LINK_STATUS, &program_link_result);
    if (!program_link_result)
    {
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to link shader program.");
    }

    glDetachShader(shader.gl_handle, gl_vertex_handle);
    glDetachShader(shader.gl_handle, gl_fragment_handle);
    glDeleteShader(gl_vertex_handle);
    glDeleteShader(gl_fragment_handle);

    return shader;
}

void porygon_shader_destroy(const PorygonShader* shader)
{
    if (shader->gl_handle)
    {
        glDeleteProgram(shader->gl_handle);
    }
}

void porygon_shader_activate(const PorygonShader* shader)
{
    glUseProgram(shader->gl_handle);
}
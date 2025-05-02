////////////////////////////////////////////////////////////////////////////////
// Dependencies
////////////////////////////////////////////////////////////////////////////////

#define GLFW_INCLUDE_NONE

#include "./internal.h"

#include <porygon/color.h>
#include <porygon/vector.h>
#include <porygon/window.h>

#include <chatot/chatot.h>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////

static void porygon_window_opengl_error_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* user_param)
{
    if (type == GL_DEBUG_TYPE_ERROR)
    {
        chatot_chatter(CHATOT_SEVERITY_FATAL, "OpenGL Error: %s", message);
    }
}

static void porygon_window_glfw_position_callback(GLFWwindow* glfw_handle, int x, int y)
{
    if (!_porygon_framework.window.fullscreen)
    {
        _porygon_framework.window.restore_position = (PorygonVector) { (float) x, (float) y, 0.0f };
    }
}

static void porygon_window_glfw_size_callback(GLFWwindow* glfw_handle, int width, int height)
{
    if (!_porygon_framework.window.fullscreen)
    {
        _porygon_framework.window.restore_size = (PorygonVector) { (float) width, (float) height };
    }
}

////////////////////////////////////////////////////////////////////////////////
// Functions <porygon/window.h>
////////////////////////////////////////////////////////////////////////////////

void porygon_window_create(int width, int height, const char* title)
{
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    _porygon_framework.window.glfw_handle = glfwCreateWindow(width, height, title, 0, 0);
    if (!_porygon_framework.window.glfw_handle)
    {
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to create window.");
    }

    glfwMakeContextCurrent(_porygon_framework.window.glfw_handle);
    gladLoadGL(glfwGetProcAddress);

    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(porygon_window_opengl_error_callback, 0);

    glfwSetWindowPosCallback(_porygon_framework.window.glfw_handle, porygon_window_glfw_position_callback);
    glfwSetWindowSizeCallback(_porygon_framework.window.glfw_handle, porygon_window_glfw_size_callback);

    _porygon_framework.window.restore_position = porygon_window_get_position();
    _porygon_framework.window.restore_size = porygon_window_get_size();

    porygon_window_color(PORYGON_COLOR_BLACK);
    porygon_window_vsync(1);
}

void porygon_window_destroy(void)
{
    glfwDestroyWindow(_porygon_framework.window.glfw_handle);
    _porygon_framework.window = (PorygonWindow) { 0 };
}

void porygon_window_clear(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void porygon_window_present(void)
{
    glfwSwapBuffers(_porygon_framework.window.glfw_handle);
}

void porygon_window_color(PorygonColor color)
{
    glClearColor(color.red, color.green, color.blue, color.alpha);
}

void porygon_window_vsync(int flag)
{
    glfwSwapInterval(flag ? 1 : 0);
}

void porygon_window_fullscreen(int flag)
{
    if (flag == _porygon_framework.window.fullscreen)
    {
        return;
    }

    _porygon_framework.window.fullscreen = flag;

    if (flag)
    {
        GLFWmonitor* primary_monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* video_mode = glfwGetVideoMode(primary_monitor);

        glfwSetWindowMonitor(_porygon_framework.window.glfw_handle, primary_monitor, GLFW_DONT_CARE, GLFW_DONT_CARE, video_mode->width, video_mode->height, GLFW_DONT_CARE);
    }
    else
    {
        glfwSetWindowMonitor(_porygon_framework.window.glfw_handle, 0, _porygon_framework.window.restore_position.x, _porygon_framework.window.restore_position.y, _porygon_framework.window.restore_size.x, _porygon_framework.window.restore_size.y, GLFW_DONT_CARE);
    }
}

int porygon_window_should_close(void)
{
    return glfwWindowShouldClose(_porygon_framework.window.glfw_handle);
}

PorygonVector porygon_window_get_position(void)
{
    int x;
    int y;
    glfwGetWindowPos(_porygon_framework.window.glfw_handle, &x, &y);
    PorygonVector result =
    {
        (float) x,
        (float) y,
        0.0f
    };
    return result;
}

PorygonVector porygon_window_get_size(void)
{
    int width;
    int height;
    glfwGetWindowPos(_porygon_framework.window.glfw_handle, &width, &height);
    PorygonVector result =
    {
        (float) width,
        (float) height,
        0.0f
    };
    return result;
}
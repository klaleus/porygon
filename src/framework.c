////////////////////////////////////////////////////////////////////////////////
// Dependencies
////////////////////////////////////////////////////////////////////////////////

#define GLAD_GL_IMPLEMENTATION
#define GLFW_INCLUDE_NONE

#include "./internal.h"

#include <porygon/framework.h>

#include <chatot/chatot.h>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

PorygonFramework _porygon_framework = { 0 };

////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////

static void porygon_framework_glfw_error_callback(int error, const char* description)
{
    chatot_chatter(CHATOT_SEVERITY_FATAL, "GLFW Error [%i]: %s", error, description);
}

////////////////////////////////////////////////////////////////////////////////
// Functions <porygon/framework.h>
////////////////////////////////////////////////////////////////////////////////

void porygon_framework_create(void)
{
    glfwSetErrorCallback(porygon_framework_glfw_error_callback);

    if(!glfwInit())
    {
        chatot_chatter(CHATOT_SEVERITY_FATAL, "Failed to initialize GLFW.");
    }
}

void porygon_framework_update(void)
{
    glfwPollEvents();
}

void porygon_framework_destroy(void)
{
    glfwTerminate();
}
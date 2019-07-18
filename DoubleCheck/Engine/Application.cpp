#include "Application.hpp"
#include <iostream>
#include "vector2.hpp"
#include "Input.h"

Application* Application::application = nullptr;


namespace
{
    void    key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void    cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    void    mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    void    scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    bool    is_full = false;
}


void Application::Init()
{
    if (!glfwInit())
    {
        glfwTerminate();
        return;
    }
    GLenum glew_err_check;

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);

    window = glfwCreateWindow(1280, 720, "sangministhebest", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if (!window)
    {
        glfwTerminate();
        return;
    }
    glew_err_check = glewInit();

    if (glew_err_check != GLEW_NO_ERROR)
    {
        glfwTerminate();
        return;
    }

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    GLFWmonitor*       monitor = glfwGetPrimaryMonitor();
    glfwSetWindowMonitor(window, nullptr,
        200,
        200,
        static_cast<int>(1280),
        static_cast<int>(720), 0);

    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSwapInterval(true);
}

void Application::Update(float dt)
{
    input.Triggered_Reset();

    glfwSwapBuffers(window);
    glfwPollEvents();

    int w, h;
    glfwGetWindowSize(window, &w, &h);
    window_size.width = (float)w;
    window_size.height = (float)h;

    if(input.Is_Mouse_Double_Clicked(GLFW_MOUSE_BUTTON_LEFT))
    {
        std::cout << "aaa" << std::endl;
    }
}

void Application::Delete()
{


}

void Application::Toggle_Fullscreen()
{
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    GLFWmonitor*       monitor = glfwGetPrimaryMonitor();
    vector2 desired_size;

    if(is_full)
    {
        //glfwSetWindowMonitor(window, nullptr, prev_x_pos, prev_y_pos, prev_width, prev_height, 0);
        //glViewport(0, 0, prev_width, prev_height);
        //desired_size.width = prev_width;
        //desired_size.height = prev_height;
        glfwGetWindowPos(window, &prev_x_pos, &prev_y_pos);
        glfwGetWindowSize(window, &prev_width, &prev_height);
        glfwSetWindowMonitor(window, monitor, 0, 0, static_cast<int>(mode->width), static_cast<int>(mode->height), 0);
        //glViewport(0, 0, mode->width, mode->height);
        desired_size.width = mode->width;
        desired_size.height = mode->height;
        glfwSwapInterval(true);
    }
    else
    {
        glfwSetWindowMonitor(window, nullptr, prev_x_pos, prev_y_pos, prev_width, prev_height, 0);
        //glViewport(0, 0, prev_width, prev_height);
        desired_size.width = prev_width;
        desired_size.height = prev_height;
        glfwSwapInterval(true);
    }
}

Application* Application::Get_Application()
{
    if (application == nullptr)
        application = new Application;

    return application;

}

namespace
{
    void mouse_button_callback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
    {
        input.Set_Mouse_Input(button, action);
    }
    void cursor_position_callback(GLFWwindow* /*window*/, double xpos, double ypos)
    {
        input.Set_Mouse_Position(xpos, ypos);
    }
    void key_callback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
    {
        input.Set_Keyboard_Input(key, action);
    }
    void scroll_callback(GLFWwindow* /*window*/, double xoffset, double yoffset)
    {
        input.Set_Mouse_Wheel(xoffset, yoffset);
    }
}

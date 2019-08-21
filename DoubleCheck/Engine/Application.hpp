#pragma once
#include "vector2.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Application
{
private:
    Application() {}
    static Application* application;

    GLFWwindow* window;
    int prev_x_pos, prev_y_pos;
    int prev_width, prev_height;
    vector2 window_size{};

public:
    static Application* Get_Application();
    void Init();
    void Update(float dt);
    void Delete();
    void Toggle_Fullscreen();
    vector2 Get_Window_Size()
    {
        return window_size;
    }
};

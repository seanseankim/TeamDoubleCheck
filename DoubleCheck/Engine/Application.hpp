#pragma once
#include "vector2.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
class Application
{
private:
    Application() {}
    static Application* application;

    GLFWwindow* window;
    int prev_x_pos, prev_y_pos;
    int prev_width, prev_height;
    vector2 window_size{};
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

public:
    static Application* Get_Application();
    void Init();
    void Update(float dt);
    void Delete();
    void Toggle_Fullscreen();
    void Imgui_Init();
    void Imgui_Update();
    vector2 Get_Window_Size()
    {
        return window_size;
    }
};

#pragma once
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

public:
    static Application* Get_Application();
    void Init();
    void Update(float dt);
    void Delete();
    void Toggle_Fullscreen();
};

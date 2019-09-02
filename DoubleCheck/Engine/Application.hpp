#pragma once
#include "vector2.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Engine.hpp"

#include "StateManager.h"
#include "Graphic.h"
#include "ObjectManager.h"
#include "Application.hpp"

#include "Component_Sprite.h"
#include "Component_Transform.h"
#include "Component_TopDownMovement.h"
#include "example.hpp"
#include "../DoubleCheck/MainMenu.h"
#include "../DoubleCheck/Level1.h"

#include "Transform.hpp"

class Application
{
private:
    Application() {}
    static Application* application;

    GLFWwindow* window;
	bool get_vsync;
    int x_pos, y_pos;
    int width, height;

	float save_dt = 0.0f;
	int FPS_frame = 0;

    vector2 window_size{};
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

public:
    static Application* Get_Application();
    void Init();
    void Update(float dt);
    void Delete();
	bool IsFullScreen();
    void Toggle_Fullscreen();
    void Imgui_Init();
    void Imgui_Update();
	void Clear();
	void Save();

	void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	void TurnOnMonitorVerticalSynchronization(bool enable);
	
    vector2 Get_Window_Size()
    {
        return window_size;
    }
};

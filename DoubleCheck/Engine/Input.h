#pragma once

#include <bitset>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "vector2.hpp"

class Input
{
private:
    std::bitset<GLFW_KEY_LAST> key_pressed;
    std::bitset<GLFW_KEY_LAST> key_released;
    std::bitset<GLFW_KEY_LAST> key_triggered;

    std::bitset<GLFW_MOUSE_BUTTON_LAST> mouse_triggered;
    std::bitset<GLFW_MOUSE_BUTTON_LAST> mouse_released;
    std::bitset<GLFW_MOUSE_BUTTON_LAST> mouse_double_clicked;
    std::bitset<GLFW_MOUSE_BUTTON_LAST> mouse_pressed;

    vector2 mouse_position{};
    double x_offset = 0.0;
    double y_offset = 0.0;

public:
    void Triggered_Reset();
    void Set_Keyboard_Input(int key, int action);
    void Set_Mouse_Input(int button, int action);
    void Set_Mouse_Position(double x, double y);
    void Set_Mouse_Wheel(double x, double y);
    void Init();

    bool Is_Key_Triggered(int key);
    bool Is_Key_Released(int key);
    bool Is_Key_Pressed(int key);
    
    bool Is_Mouse_Triggered(int button);
    bool Is_Mouse_Pressed(int button);
    bool Is_Mouse_Released(int button);
    bool Is_Mouse_Double_Clicked(int button);
    double Mouse_Wheel_Scroll();
    vector2 Get_Mouse_Pos();

};

extern Input input;
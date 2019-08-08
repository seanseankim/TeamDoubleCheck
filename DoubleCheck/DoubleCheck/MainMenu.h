#pragma once
#include "State.h"
#include <string>
#include <iostream>
#include "Input.h"
#include <GLFW/glfw3.h>

class Menu : public State
{
public:
    Menu()
    {
        current_state = GameState::Menu;
    }

    virtual void Load()
    {
        std::cout << "Menu init" << std::endl;
    }
    virtual void Update(float dt)
    {
        std::cout << "Menu Update" << std::endl;

        if(input.Is_Key_Triggered(GLFW_KEY_N))
        {
            is_next = true;
            next_level = "Level1";
        }
    }
    virtual void UnLoad()
    {
        next_level = {};
        is_next = false;
    }
};
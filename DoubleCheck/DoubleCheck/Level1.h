#pragma once
#include "State.h"
#include <string>
#include <iostream>
//#include "Input.h"
#include <GLFW/glfw3.h>
#include "Object.h"

class Level1 : public State
{
public:
    Level1()
    {
        current_state = GameState::Game;
    }

    virtual void Load();
    virtual void Update(float dt);
    /*
    std::cout << "Level1 Update" << std::endl;

    if (input.Is_Key_Triggered(GLFW_KEY_N))
    {
        is_next = true;
        next_level = "Menu";
    }*/

    virtual void UnLoad()
    {
        next_level = {};
        is_next = false;
    }

private:
    Object* player;
};
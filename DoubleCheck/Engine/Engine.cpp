#include "Engine.hpp"
#include "Application.hpp"
#include "ObjectManager.h"
#include "Input.h"
#include <iostream>
#include "Player.h"
#include "StateManager.h"
#include "../DoubleCheck/MainMenu.h"
#include "../DoubleCheck/Level1.h"

namespace
{
    Application* app_ = nullptr;
    ObjectManager* object_manager = nullptr;
    StateManager* state_manager = nullptr;
}

void Engine::Init()
{
    app_ = Application::Get_Application();
    object_manager = ObjectManager::GetObjectManager();
    state_manager = StateManager::GetStateManager();

    app_->Init();
    object_manager->Init();
    state_manager->Init();

    state_manager->AddState("Menu", new Menu);
    state_manager->AddState("Level1", new Level1);

    Object* temp = new Object();
    temp->AddComponent(new Player());
    object_manager->AddObject(temp);

    game_timer.Reset();
}

void Engine::Update()
{
    m_dt = game_timer.GetElapsedSeconds();
    game_timer.Reset();

    app_->Update(m_dt);
    object_manager->Update(m_dt);
    state_manager->Update(m_dt);

    //if (input.Is_Key_Triggered(GLFW_KEY_D))
    //    object_manager->GetObjectManagerContainer()[0]->SetDeadCondition(true);
    //
    //if (object_manager->GetObjectManagerContainer().size() <= 0)
    //    std::cout << "Empty!" << std::endl;
    if (input.Is_Key_Triggered(GLFW_KEY_1))
        state_manager->is_pause = !state_manager->is_pause;
}

void Engine::Delete()
{

}


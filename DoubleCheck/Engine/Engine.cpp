#include "Engine.hpp"
#include "Application.hpp"
#include "ObjectManager.h"
#include "Input.h"
#include <iostream>
#include "Component_Player.h"
#include "Graphic.h"
#include "StateManager.h"
#include "../DoubleCheck/MainMenu.h"
#include "../DoubleCheck/Level1.h"
#include "Component_Sprite.h"
#include "Component_Transform.h"
#include "Component_TopDownMovement.h"
#include "GL.hpp"
#include "Physics.h"
#include "Message_Manager.h"
#include "Component_Enemy.h"

#include<iostream>
#include"Transform.hpp"

namespace
{
    Application* app_ = nullptr;
    ObjectManager* object_manager = nullptr;
    StateManager* state_manager = nullptr;
    Graphic* graphic = nullptr;
    Message_Manager* msg_manager = nullptr;
}

void Engine::Init()
{
    app_ = Application::Get_Application();
    object_manager = ObjectManager::GetObjectManager();
    state_manager = StateManager::GetStateManager();
    graphic = Graphic::GetGraphic();
    msg_manager = Message_Manager::Get_Message_Manager();

    app_->Init();
    object_manager->Init();
    state_manager->Init();
    graphic->Init();
    msg_manager->Init();
    
    state_manager->AddState("Menu", new Menu);
    state_manager->AddState("Level1", new Level1);

    Object* temp = new Object();
    temp->AddComponent(new Physics);
    temp->AddComponent(new Sprite());
    temp->AddComponent(new Player());
    temp->AddComponent(new Component_Transform());
    temp->AddComponent(new Component_TopDownMovement());
    temp->GetComponentByTemplate<Physics>()->BoxToBoxCollision(temp->GetMesh());
    temp->GetComponentContainer()[0]->SetComponentName("CircleToCircleCollision");

    temp->Set_Name("first");

    Object* temp_sec = new Object();
    temp_sec->AddComponent(new Physics);
    temp_sec->AddComponent(new Sprite());
    temp_sec->AddComponent(new Component_Transform());
    temp_sec->GetComponentByTemplate<Physics>()->BoxToBoxCollision(temp->GetMesh());
    temp_sec->GetComponentContainer()[0]->SetComponentName("CircleToCircleCollision");
    temp_sec->Set_Name("second");

    object_manager->AddObject(temp);
    object_manager->AddObject(temp_sec);

    game_timer.Reset();
}
void Engine::Test()
{
	state_manager->AddState("Menu", new Menu);
	state_manager->AddState("Level1", new Level1);

	Object* temp = new Object();
	temp->AddComponent(new Sprite());
	temp->AddComponent(new Component_Transform());
	temp->AddComponent(new Component_TopDownMovement());
	temp->Set_Name("first");

	Object* temp_sec = new Object();
	temp_sec->AddComponent(new Sprite());
	temp_sec->AddComponent(new Component_Transform());
	temp_sec->Set_Name("second");

	//std::cout << temp->GetTransform.GetTranslation();


	//std::cout << temp->GetTransform().Get_Save_Translation().x;


	/*Object* temp_third = new Object();
	temp_third->AddComponent(new Sprite());
	temp_third->AddComponent(new Component_Transform);
	temp_third->Set_Name("save");

	temp_third->AddComponent(new Transform(1, 1));
	*/
	object_manager->AddObject(temp);
	object_manager->AddObject(temp_sec);
	//object_manager->AddObject(temp_third);

	game_timer.Reset();
}

void Engine::Update()
{
    m_dt = game_timer.GetElapsedSeconds();
    game_timer.Reset();

    app_->Update(m_dt);
    state_manager->Update(m_dt);
    graphic->Update(m_dt);
    object_manager->Update(m_dt);
    msg_manager->Update(m_dt);

    //Reset camera zoom
    Reset();

    if (input.Is_Key_Triggered(GLFW_KEY_1))
        state_manager->is_pause = !state_manager->is_pause;
}

void Engine::Delete()
{

}

void Engine::Reset()
{
    Graphic::GetGraphic()->Get_View().Get_Camera_View().SetZoom(1.0f);
    Graphic::GetGraphic()->Get_View().Get_Camera().SetCenter({ 0,0 });
}
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

#include<iostream>
#include"Transform.hpp"

namespace
{
    Application* app_ = nullptr;//Ű����
    ObjectManager* object_manager = nullptr;//���object����
    StateManager* state_manager = nullptr;//
    Graphic* graphic = nullptr;
}

void Engine::Init()
{
    app_ = Application::Get_Application();
    object_manager = ObjectManager::GetObjectManager();
    state_manager = StateManager::GetStateManager();
    graphic = Graphic::GetGraphic();

    app_->Init();
    object_manager->Init();
    state_manager->Init();
    graphic->Init();
    

    state_manager->AddState("Menu", new Menu);
    state_manager->AddState("Level1", new Level1);

    Object* temp = new Object();
    temp->AddComponent(new Sprite());
    temp->AddComponent(new Component_Transform());//����component
    temp->AddComponent(new Component_TopDownMovement());
    temp->Set_Name("first");

    Object* temp_sec = new Object();
    temp_sec->AddComponent(new Sprite());
    temp_sec->AddComponent(new Component_Transform());
    temp_sec->Set_Name("second");

    object_manager->AddObject(temp);
    object_manager->AddObject(temp_sec);

    game_timer.Reset();
}
void Engine::Test()//���߿� game level�� ��ü
{
	state_manager->AddState("Menu", new Menu);
	state_manager->AddState("Level1", new Level1);

	Object* temp = new Object();
	temp->AddComponent(new Sprite());
	temp->AddComponent(new Component_Transform());//����component
	temp->AddComponent(new Component_TopDownMovement());
	temp->Set_Name("first");

	Object* temp_sec = new Object();
	temp_sec->AddComponent(new Sprite());
	temp_sec->AddComponent(new Component_Transform());
	temp_sec->Set_Name("second");
	//transform�ȿ�gettranslation ��ġ, �̵�

	//std::cout << temp->GetTransform.GetTranslation();
	std::cout << temp->GetTransform().Get_Save_Translation().x;
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


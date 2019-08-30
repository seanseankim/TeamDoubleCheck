#include "Component_Player.h"
#include "Message_Manager.h"
#include "ObjectManager.h"
#include "Input.h"

void Player::Init(Object* obj)
{
    m_owner = obj;
    std::cout << "Player is init" << std::endl;
}

void Player::Update(float dt)
{
    //Attack();
}

void Player::Attack()
{
    if (input.Is_Mouse_Triggered(GLFW_MOUSE_BUTTON_LEFT))
    {
        Object* obj = &(*ObjectManager::GetObjectManager()->GetObjectManagerContainer_Value()[1]);
        Message_Manager::Get_Message_Manager()->Save_Message(new Message(obj, m_owner, "attack"));
    }
}

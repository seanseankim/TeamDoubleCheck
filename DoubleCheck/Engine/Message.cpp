#include "Message.h"
#include "Component_Player.h"
#include "Component_Sprite.h"
#include "Component_Enemy.h"
#include "Message_Manager.h"

void Message::Init()
{
}

void Message::Update(float dt)
{
    if(message_name == "attack")
    {
        m_target->GetComponentByTemplate<Component_Enemy>()->Decrease_HP(m_from->GetComponentByTemplate<Player>()->Get_Damage());
    }

    std::string log = m_from->Get_Name() + " " + message_name + " " + m_target->Get_Name();

    Message_Manager::Get_Message_Manager()->Get_Log().push_back(log);

    delete(this);
}

void Message::Delete()
{
}

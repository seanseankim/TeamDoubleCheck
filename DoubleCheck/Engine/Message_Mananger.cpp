#include "Message_Manager.h"

Message_Manager* Message_Manager::msg_manager = nullptr;

Message_Manager* Message_Manager::Get_Message_Manager()
{
    if (msg_manager == nullptr)
        msg_manager = new Message_Manager();

    return msg_manager;
}

void Message_Manager::Save_Message(Message* msg)
{
    messages.push_back(msg);
}

void Message_Manager::Init()
{

}
void Message_Manager::Update(float dt)
{
    if(!messages.empty())
    {
        for(auto& msg : messages)
        {
            msg->Update(dt);
        }
        messages.clear();
    }
}
void Message_Manager::Delete()
{

}

#include "Component_TopDownMovement.h"
#include "Graphic.h"


void Component_TopDownMovement::Init(Object* obj)
{
    m_owner = obj;
}

void Component_TopDownMovement::Update(float dt)
{
    //WASD pressed movement
    if (input.Is_Key_Pressed(GLFW_KEY_W))
    {
        m_owner->GetTransform().SetTranslation({ 0.0f, 1.0f });

        if (input.Is_Key_Pressed((GLFW_KEY_A)))
        {
            m_owner->GetTransform().SetTranslation({ -1.0f, 1.0f });
        }
        else if (input.Is_Key_Pressed((GLFW_KEY_D)))
        {
            m_owner->GetTransform().SetTranslation({ 1.0f, 1.0f });
        }

        m_owner->GetMesh().Get_Is_Moved() = true;
        //Graphic::GetGraphic()->get_need_update_sprite() = true;
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_S))
    {
        m_owner->GetTransform().SetTranslation({ 0.0f, -1.0f });

        if (input.Is_Key_Pressed((GLFW_KEY_A)))
        {
            m_owner->GetTransform().SetTranslation({ -1.0f, -1.0f });
        }
        else if (input.Is_Key_Pressed((GLFW_KEY_D)))
        {
            m_owner->GetTransform().SetTranslation({ 1.0f, -1.0f });
        }

        //Graphic::GetGraphic()->get_need_update_sprite() = true;
        m_owner->GetMesh().Get_Is_Moved() = true;
    }
    else if (input.Is_Key_Pressed((GLFW_KEY_A)))
    {
        m_owner->GetTransform().SetTranslation({ -1.0f, 0.0f });

        //Graphic::GetGraphic()->get_need_update_sprite() = true;
        m_owner->GetMesh().Get_Is_Moved() = true;
    }
    else if (input.Is_Key_Pressed((GLFW_KEY_D)))
    {
        m_owner->GetTransform().SetTranslation({ 1.0f, 0.0f });

       // Graphic::GetGraphic()->get_need_update_sprite() = true;
        m_owner->GetMesh().Get_Is_Moved() = true;
    }
    else
    {
        //m_owner->GetTransform().SetTranslation({ 0.0f, 0.0f });
    }
}

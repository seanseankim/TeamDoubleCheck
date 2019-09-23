#include "Physics.h"
#include "ObjectManager.h"
#include <cmath>
#include <vector>
#include "../Math_lib/vector2.hpp"
#include "Input.h"

void Physics::Init(Object* obj)
{
    m_owner = obj;
}

void Physics::Acceleration()
{
    if (input.Is_Key_Pressed(GLFW_KEY_W))
    {
        acceleration += {0, 0.03};
        m_owner->GetTransform().AddTranslation(acceleration);

        if (input.Is_Key_Pressed(GLFW_KEY_A))
        {
            acceleration += {-0.03, 0.00};
            m_owner->GetTransform().AddTranslation(acceleration);
        }
        else if (input.Is_Key_Pressed((GLFW_KEY_D)))
        {
            acceleration += {0.03, 0.00};
            m_owner->GetTransform().AddTranslation(acceleration);
        }

        m_owner->GetMesh().Get_Is_Moved() = true;
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_S))
    {
        acceleration += {0, -0.03};
        m_owner->GetTransform().AddTranslation(acceleration);

        if (input.Is_Key_Pressed((GLFW_KEY_A)))
        {
            acceleration += {-0.03, -0.00};
            m_owner->GetTransform().AddTranslation(acceleration);
        }
        else if (input.Is_Key_Pressed((GLFW_KEY_D)))
        {
            acceleration += {0.03, -0.00};
            m_owner->GetTransform().AddTranslation(acceleration);
        }

        m_owner->GetMesh().Get_Is_Moved() = true;
    }
    else if (input.Is_Key_Pressed((GLFW_KEY_A)))
    {
        acceleration += {-0.03, 0};
        m_owner->GetTransform().AddTranslation(acceleration);

        m_owner->GetMesh().Get_Is_Moved() = true;
    }
    else if (input.Is_Key_Pressed((GLFW_KEY_D)))
    {
        acceleration += {0.03, 0};
        m_owner->GetTransform().AddTranslation(acceleration);

        m_owner->GetMesh().Get_Is_Moved() = true;
    }
    else
    {
        acceleration -= {acceleration.x/200, acceleration.y/ 200};
        m_owner->GetTransform().AddTranslation(acceleration);
        m_owner->GetMesh().Get_Is_Moved() = true;
    }


}

bool Physics::BoxToBoxCollision(Mesh mesh) const
{
    if(m_owner->GetMesh().GetPoint(0).x > mesh.GetPoint(2).x || m_owner->GetMesh().GetPoint(0).y > mesh.GetPoint(2).y)
    {
        return false;
    }
    else if(m_owner->GetMesh().GetPoint(1).x > mesh.GetPoint(3).x || m_owner->GetMesh().GetPoint(1).y < mesh.GetPoint(3).y)
    {
        return false;
    }
    else if(m_owner->GetMesh().GetPoint(2).x < mesh.GetPoint(0).x || m_owner->GetMesh().GetPoint(2).y < mesh.GetPoint(0).y)
    {
        return false;
    }
    else if(m_owner->GetMesh().GetPoint(3).x < mesh.GetPoint(1).x || m_owner->GetMesh().GetPoint(3).y > mesh.GetPoint(1).y)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Physics::CircleToCircleCollision(Object* object) const
{
    const vector2 my_position = m_owner->Get_Object_Points();
    float distance;
    float owner_radius;
    float radius;
    float ssiba;
    owner_radius = m_owner->GetTransform().GetScale().x
    radius = object->GetScale().x
    ssiba = (my_position.x - object->Get_Object_Points()[0].x) * (my_position.x - object->Get_Object_Points());
    distance = sqrt((my_position.x - position.x) * (my_position.x - position.x));
    distance += sqrt((my_position.y - position.y) * (my_position.y - position.y));

    if(distance <= (owner_radius + radius))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Physics::Update(float dt)
{
    //printf("%f, %f \n\n\n", m_owner->GetMesh().GetCenterPoint().x, m_owner->GetMesh().GetCenterPoint().y);
    for (const auto& i : ObjectManager::GetObjectManager()->GetObjectManagerContainer())
    {
        if (i.get()->GetName() == m_owner->GetName())
        {
            continue;
        }
        if (i->GetComponentContainer()[0]->GetComponentName() == "BoxToBoxCollision" && m_owner->GetComponentContainer()[0]->GetComponentName() == "BoxToBoxCollision")
        {
            if (BoxToBoxCollision(i.get()->GetMesh()))
            {
                printf("fuck\n");
            }
        }
        else if(i->GetComponentContainer()[0]->GetComponentName() == "CircleToCircleCollision" && m_owner->GetComponentContainer()[0]->GetComponentName() == "CircleToCircleCollision")
        {
            if(CircleToCircleCollision(i->GetTransform()))
            {
                printf("shit\n");
            }
        }

        if (i->GetName() == "first")
        {
            Acceleration();
        }
    }
}
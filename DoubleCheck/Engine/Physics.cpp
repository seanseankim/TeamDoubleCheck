#include "Physics.h"
#include "ObjectManager.h"
#include "math.h"

void Physics::Init(Object* obj)
{
    m_owner = obj;
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

bool Physics::CircleToCircleCollision(Transform transform) const
{
    const vector2 my_translation = m_owner->GetTransform().GetTranslation();
    float distance;

    if((my_translation.x * my_translation.x) + (my_translation.y * my_translation.y) >= (transform.GetTranslation().x * transform.GetTranslation().x) + (transform.GetTranslation().y * transform.GetTranslation().y))
    {
        distance = sqrt((my_translation.x * my_translation.x) + (my_translation.y * my_translation.y) - (transform.GetTranslation().x * transform.GetTranslation().x) + (transform.GetTranslation().y * transform.GetTranslation().y));
    }
    else
    {
        distance = sqrt((transform.GetTranslation().x * transform.GetTranslation().x) + (transform.GetTranslation().y * transform.GetTranslation().y) - (my_translation.x * my_translation.x) + (my_translation.y * my_translation.y));
    }

    if(distance > (m_owner->GetTransform().GetScale().x + transform.GetScale().x) / 2.f)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Physics::Update(float dt)
{
    printf("%f, %f \n\n\n", m_owner->GetMesh().GetCenterPoint().x, m_owner->GetMesh().GetCenterPoint().y);
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
    }
}

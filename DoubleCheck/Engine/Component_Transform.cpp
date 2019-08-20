#include "Component_Transform.h"
#include "Input.h"

void Component_Transform::Init(Object* obj)
{
    m_owner = obj;

    //m_owner->GetTransform().SetTranslation({ 1.0f, 1.0f });
}

void Component_Transform::Update(float dt)
{
    /*
    for (auto& i : m_owner->GetMesh().Get_Points())
    {
        i += m_owner->GetTransform().GetTranslation();
    }*/
}

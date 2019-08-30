#include <algorithm>
#include "Object.h"

void Object::AddComponent(Component* comp)
{
    comp->Init(this);
    components_.push_back(comp);
}

void Object::DeleteComponent(Component* comp)
{
     components_.erase(std::find(components_.begin(), components_.end(), comp));
}

void Object::SetTranslation(vector2 pos)
{
    m_transform.SetTranslation(pos);
}

void Object::SetRotation(float angle)
{
    m_transform.SetRotation(angle);
}

void Object::SetScale(vector2 scale)
{
    m_transform.SetScale(scale);
}

void Object::SetScale(float scale)
{
    m_transform.SetScale(scale);
}

void Object::SetDepth(float depth)
{
    m_transform.SetDepth(depth);
}

void Object::SetMesh(Mesh mesh)
{
    m_mesh = mesh;
}

std::string Object::GetName()
{
    return m_name;
}
#pragma once
#include "Transform.hpp"
#include "Mesh.hpp"
#include "Component.hpp"

class Object
{
private:
    Transform m_transform;
    Mesh m_mesh;
    std::vector<Component*>components_;
    bool is_dead;

public:
    Transform GetTransform() { return m_transform; }
    std::vector<Component*>GetComponentContainer() { return components_; }

    Mesh GetMesh() { return m_mesh; }
    template <typename COMPONENT>
    COMPONENT* GetComponentByTemplate() const;
public:
    void SetDeadCondition(bool condition) { is_dead = condition; }
    bool IsDead() { return is_dead; }
    void AddComponent(Component* comp);
    void DeleteComponent(Component* comp);

    void SetTranslation(vector2 pos);
    void SetRotation(float angle);
    void SetScale(vector2 scale);
    void SetScale(float scale);
    void SetDepth(float depth);
    void SetMesh(Mesh mesh);

    /*bool IsDead()
    {
        return is_dead;
    }*/
};

template <typename COMPONENT>
COMPONENT* Object::GetComponentByTemplate() const
{
    for(auto i : components_)
    {
        if(typeid(COMPONENT) == typeid(*i))
        {
            return dynamic_cast<COMPONENT*>(i);
        }
    }

    return nullptr;
}
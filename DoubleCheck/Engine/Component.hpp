#pragma once
#include <string>

class Object;

class Component
{
public:
    virtual  void Init(Object* obj) = 0;
    virtual  void Update(float dt) = 0;

    void SetComponentName(std::string component)
    {
        component_name = component;
    }
    std::string GetComponentName() const
    {
        return component_name;
    }
    
    Object* m_owner = nullptr;

private:
    std::string component_name;
};

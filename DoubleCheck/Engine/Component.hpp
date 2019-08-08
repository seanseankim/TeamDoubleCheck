#pragma once

class Object;

class Component
{
public:
    virtual  void Init(Object* obj) = 0;
    virtual  void Update(float dt) = 0;

    Object* m_owner = nullptr;
private:
};

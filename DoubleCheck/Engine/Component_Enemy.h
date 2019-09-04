#pragma once
#include "Component.hpp"
#include <iostream>
#include "Object.h"

class Component_Enemy : public Component
{
public:
    void Init(Object *obj) override;
    void Update(float dt) override;
    void Decrease_HP(int dmg = 1);

private:
    int hp = 20;

};
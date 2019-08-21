#pragma once
#include "Component.hpp"
#include "Transform.hpp"
#include <iostream>
#include "Object.h"

class Component_Transform : public Component
{
public:  
    void Init(Object *obj) override;
    void Update(float dt) override;
};
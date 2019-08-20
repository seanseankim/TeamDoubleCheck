#pragma once
#include "Component.hpp"
#include "Transform.hpp"
#include <iostream>
#include "Object.h"
#include "Input.h"

class Component_TopDownMovement : public Component
{
public:
    void Init(Object *obj) override;
    void Update(float dt) override;
private:
};
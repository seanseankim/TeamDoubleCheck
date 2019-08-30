#pragma once

#include "Component.hpp"
#include "Object.h"
#include "Mesh.hpp"

class Physics : public Component
{
public:
    void Init(Object *obj) override;
    bool BoxToBoxCollision(Mesh mesh) const;
    bool CircleToCircleCollision(Transform transform) const;
    void Update(float dt) override;
      
private:
    std::vector<vector2> points{};
};
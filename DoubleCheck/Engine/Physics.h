#pragma once

#include "Component.hpp"
#include "Object.h"
#include "Mesh.hpp"

class Physics : public Component
{
public:
    void Init(Object *obj) override;
    void Acceleration();
    bool BoxToBoxCollision(Mesh mesh) const;
    bool CircleToCircleCollision(Object* object) const;
    void Update(float dt) override;
      
private:
    std::vector<vector2> points{};
    vector2 acceleration{};
};
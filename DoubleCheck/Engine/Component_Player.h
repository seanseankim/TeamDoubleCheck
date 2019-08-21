#pragma once
#include "Component.hpp"
#include <iostream>

class Player : public Component
{
public:
    void Init(Object *obj) override;
    void Update(float dt) override;
};

inline void Player ::Init(Object*obj)
{
    std::cout << "New Player Has Coming" << std::endl;
    m_owner = obj;
}
inline void Player::Update(float dt)
{
    //std::cout << "I am a Player" << std::endl;
}
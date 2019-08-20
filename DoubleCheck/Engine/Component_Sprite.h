#pragma once
#include "Component.hpp"
#include <iostream>
#include "Shader.hpp"
#include "Vertices.hpp"
#include "Material.hpp"
#include "Image.hpp"
#include "Texture.hpp"

class Sprite : public Component
{
public:
    void Init(Object *obj) override;
    void Update(float dt) override;

private:
    Shader shader;
    Vertices shape;
    material material;
    Texture texture;
    Image image;

    float seconds = 0;
    int width = 1280, height = 720;
};
/*
inline void Sprite::Init(Object*obj)
{
    std::cout << "New Player Has Coming" << std::endl;
    m_owner = obj;
}
inline void Sprite::Update(float dt)
{
    //std::cout << "I am a Player" << std::endl;
}*/
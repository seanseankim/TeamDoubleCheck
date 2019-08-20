#pragma once

#include "Shader.hpp"
#include "Camera.hpp"
#include "Vertices.hpp"
#include "Material.hpp"
#include "View.h"

//#include "StockShader.h"

class Graphic
{
public:
    static Graphic* GetGraphic();

    void Init();
    void Update(float dt);
    void Delete();
    void Draw(Vertices& shape, material material);
    View& Get_View()
    {
        return view;
    }
    bool& get_need_update_sprite()
    {
        return need_update_sprite;
    }
    

private:
    static Graphic* graphic;
    View view;
    int width = 1280, height = 720;
    float seconds = 0;
    bool need_update_sprite = false;
};
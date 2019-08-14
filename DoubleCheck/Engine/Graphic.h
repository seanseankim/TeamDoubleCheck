#pragma once

#include "Shader.hpp"
//#include "StockShader.h"

class Graphic
{
public:
    static Graphic* GetGraphic();

    void Init();
    void Update(float dt);
    void Delete();

    

private:
    static Graphic* graphic;
    //Shader shader(std::string(VertexShader), std::string(FragmentShader));
    Shader shader;
};
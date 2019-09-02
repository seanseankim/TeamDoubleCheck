#include "Graphic.h"
#include "StockShaders.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Application.hpp"
#include "Mesh.hpp"
#include "angles.hpp"
#include "GL.hpp"
#include <iostream>



Graphic* Graphic::graphic = nullptr;

Graphic* Graphic::GetGraphic()
{
    if (graphic == nullptr)
        graphic = new Graphic();

    return graphic;
}

void Graphic::Init()
{
    glewInit();
    glEnable(GL_DEPTH | GL_BLEND);
    view.Init();
    Application::Get_Application()->Imgui_Init();
    //background color
    glClearColor(1 ,1,1,1);


}

void Graphic::Update(float dt)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Application::Get_Application()->Imgui_Update();

    seconds += dt;

    view.Update(dt);
    //material.floatUniforms["time"] = seconds;
}



void Graphic::Delete()
{
	graphic = nullptr;
}

void Graphic::Draw(Vertices& shape, material material)
{
    //GL::begin_drawing();

    GL::draw(shape, material);

    GL::end_drawing();
}

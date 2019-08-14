#include "Graphic.h"
#include "StockShader.h"

Graphic* Graphic::graphic = nullptr;

Graphic* Graphic::GetGraphic()
{
    if (graphic == nullptr)
        graphic = new Graphic();

    return graphic;
}

void Graphic::Init()
{
    shader.LoadFromSource(VertexShader, FragmentShader);
}

void Graphic::Update(float dt)
{
    shader.Select(shader);
}

void Graphic::Delete()
{
}

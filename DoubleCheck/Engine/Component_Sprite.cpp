#include "Component_Sprite.h"
#include "angles.hpp"
#include "Mesh.hpp"
#include <GL/glew.h>
#include "StockShaders.hpp"
#include "Graphic.h"
#include "Object.h"

void Helper_Addpoint_Circle(std::size_t& point_count, Mesh& mesh, float& radius, float position_x = 0, float position_y = 0, bool move_up_down = true)
{
    float theta;
    float location_x;
    float location_y;
    for (int i = 1; i <= point_count + 1; i++)
    {
        theta = (TWO_PI * i) / static_cast<float>(point_count);
        location_x = (radius * cosf(theta)) - position_x;
        location_y = (radius * sinf(theta)) - position_y;
        mesh.AddPoint({ location_x,location_y });
        if (move_up_down)
        {
            mesh.AddTextureCoordinate({ to_radians(270.f), 10.f });
        }
        else if (!move_up_down)
        {
            mesh.AddTextureCoordinate({ to_radians(180.f), 10.f });
        }
    }

}
void Helper_Addpoint_Ellipse(std::size_t& point_count, Mesh& mesh, float& radius, float position_x = 0, float position_y = 0)
{
    float theta;
    float location_y;
    float location_x;
    for (int i = 1; i <= point_count + 1; i++)
    {
        theta = (TWO_PI * i) / static_cast<float>(point_count);
        location_x = (radius * cosf(theta)) - position_x;
        location_y = (radius * sinf(theta) / 2) - position_y;
        mesh.AddPoint({ location_x ,location_y });
        mesh.AddTextureCoordinate({ to_radians(270.f), 10.f });
    }

}

Mesh m_create_circle(float radius, Color4ub color, std::size_t point_count, vector2 origin = { 0.1f, 0.1f }, bool is_ellipse = false, float location_x = 0, float location_y = 0, bool move_up_down = true) noexcept
{
    Mesh temp_mesh;
    (origin);
    temp_mesh.AddColor(color);
    temp_mesh.SetPointListType(PointListPattern::TriangleFan);
    if (!is_ellipse)
    {
        Helper_Addpoint_Circle(point_count, temp_mesh, radius, location_x, location_y, move_up_down);
    }
    else if (is_ellipse)
    {
        Helper_Addpoint_Ellipse(point_count, temp_mesh, radius, location_x, location_y);
    }

    return temp_mesh;
}

Mesh m_create_wire_circle(float radius, Color4ub color, std::size_t point_count) noexcept
{
    Mesh temp_mesh;
    temp_mesh.SetPointListType(PointListPattern::LineLoop);
    temp_mesh.AddColor(color);
    Helper_Addpoint_Circle(point_count, temp_mesh, radius);

    return temp_mesh;
}


void Sprite::Init(Object* obj)
{
    m_owner = obj;

    //texture.LoadFromPNG("../Sprite/temp.png");

    material.shader = &SHADER::interpolated_colors();
    material.matrix3Uniforms["to_ndc"] = MATRIX3::build_scale(2.0f / width, 2.0f / height);

    const auto layout = { VertexLayoutDescription::Position2WithFloats,
    VertexLayoutDescription::Color4WithUnsignedBytes,
    VertexLayoutDescription::TextureCoordinates2WithFloats };

    Mesh square;
    //square = MESH::create_circle(100, { 50, 0,0, 255 });
    square = MESH::create_box(100, { 100,100,100,255 });
    shape.InitializeWithMeshAndLayout(square, layout);

    m_owner->SetMesh(square);
    m_owner->Get_Object_Points() = m_owner->GetMesh().Get_Points();
    m_owner->curr_mat = MATRIX3::build_identity();
}
/*
 * Original
 */
 void Sprite::Update(float dt)
{
    shape.UpdateVerticesFromMesh(m_owner->GetMesh());

    seconds += dt;

    if(m_owner->GetMesh().Get_Is_Moved() || Graphic::GetGraphic()->get_need_update_sprite())
    {
        matrix3 mat_ndc = Graphic::GetGraphic()->Get_View().Get_Camera_View().GetCameraToNDCTransform();
        mat_ndc *= Graphic::GetGraphic()->Get_View().Get_Camera().WorldToCamera();
        mat_ndc *= m_owner->GetTransform().GetModelToWorld();

        m_owner->GetMesh().Get_Is_Moved() = false;
        material.matrix3Uniforms["to_ndc"] = mat_ndc;
    }


    material.floatUniforms["time"] = seconds;

    Graphic::GetGraphic()->Draw(shape, material);
}
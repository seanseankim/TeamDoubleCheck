#include "View.h"
#include <iostream>
#include "Input.h"
#include "Graphic.h"

void View::Init()
{
    camera_view.SetViewSize(1280, 720);
}

void View::Update(float dt)
{
    if(input.Mouse_Wheel_Scroll() < 0)
    {
        camera_view.AddZoom(-0.1f);
        input.Set_Mouse_Wheel(0.0, 0.0);
        Graphic::GetGraphic()->get_need_update_sprite() = true;
    }
    else if(input.Mouse_Wheel_Scroll() > 0)
    {
        camera_view.AddZoom(0.1f);
        input.Set_Mouse_Wheel(0.0, 0.0);
        Graphic::GetGraphic()->get_need_update_sprite() = true;
    }

    if(input.Is_Key_Pressed(GLFW_KEY_RIGHT))
    {
        vector2 new_center = camera.GetCenter();
        new_center.x += 1.0f;
        camera.SetCenter(new_center);
        Graphic::GetGraphic()->get_need_update_sprite() = true;
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_LEFT))
    {
        vector2 new_center = camera.GetCenter();
        new_center.x -= 1.0f;
        camera.SetCenter(new_center);
        Graphic::GetGraphic()->get_need_update_sprite() = true;
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_DOWN))
    {
        vector2 new_center = camera.GetCenter();
        new_center.y -= 1.0f;
        camera.SetCenter(new_center);
        Graphic::GetGraphic()->get_need_update_sprite() = true;
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_UP))
    {
        vector2 new_center = camera.GetCenter();
        new_center.y += 1.0f;
        camera.SetCenter(new_center);
        Graphic::GetGraphic()->get_need_update_sprite() = true;
    }
}
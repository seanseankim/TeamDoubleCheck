#pragma once
#include "Camera.hpp"
#include "CameraView.hpp"

class View
{
private:
    Camera camera{};
    CameraView camera_view{};
public:
    void Init();
    void Update(float dt);

    Camera& Get_Camera()
    {
        return camera;
    }
    CameraView& Get_Camera_View()
    {
        return camera_view;
    }


};
#pragma once

#include <matrix3.hpp>
#include <vector2.hpp>



class[[nodiscard]] Camera
{
public:
    constexpr Camera() noexcept = default;
    Camera(vector2 camera_center, vector2 camera_up) noexcept;

    vector2 GetCenter() const noexcept { return center; }
    void    SetCenter(vector2 camera_center) noexcept { center = camera_center; }
    vector2 GetUp() const noexcept { return up; }
    vector2 GetRight() const noexcept { return right; }

    void ResetUp(vector2 camera_up = {0, 1}) noexcept;

    void MoveUp(float distance) noexcept;
    void MoveRight(float distance) noexcept;
    void Rotate(float angle_radians) noexcept;

    matrix3 CameraToWorld() const noexcept;
    matrix3 WorldToCamera() const noexcept;

private:
    vector2 center{};
    vector2 up{0, 1};
    vector2 right{1, 0};
};


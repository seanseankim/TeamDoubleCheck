#pragma once
#include <matrix3.hpp>
#include <vector2.hpp>


class[[nodiscard]] Transform
{
public:
    Transform() noexcept = default;
    matrix3 GetModelToWorld() const noexcept;
    matrix3 GetWorldToModel() const noexcept;

    float CalculateWorldDepth() const noexcept;
    float GetDepth() const noexcept;
    void  SetDepth(float new_depth) noexcept;

    vector2 GetTranslation() const noexcept;
    void    SetTranslation(const vector2& new_translation) noexcept;

    vector2 GetScale() const noexcept;

    void    SetScale(const float& new_scale) noexcept;
    void    SetScale(const vector2& new_scale) noexcept;

    float GetRotation() const noexcept;
    void  SetRotation(float new_rotation) noexcept;

    const Transform* GetParent() const noexcept;
    void             SetParent(const Transform* transform_parent) noexcept;

private:
    vector2          translation{};
    vector2          scale{1.0f, 1.0f};
    float            rotation = 0.0f;
    float            depth = 0.0f;
    const Transform* parent = nullptr;
};


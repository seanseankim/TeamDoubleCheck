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
    vector2 &GetTranslation_Reference()
    {
        return translation;
    }
    void    SetTranslation(const vector2& new_translation) noexcept;
    void AddTranslation(const vector2& translation);
	vector2 Get_Save_Translation()const noexcept;
	//void Set_Save_Translation(const vector2& new_translation)noexcept;

    vector2 GetScale() const noexcept;
    vector2 &GetScale_Reference()
    {
        return scale;
    }

    vector2 &GetCenter()
    {
        return center;
    }
    void    SetScale(const float& new_scale) noexcept;
    void    SetScale(const vector2& new_scale) noexcept;

    float GetRotation() const noexcept;
    void  SetRotation(float new_rotation) noexcept;

    const Transform* GetParent() const noexcept;
    void             SetParent(const Transform* transform_parent) noexcept;

private:
    vector2          translation{};
    vector2          scale{1.0f, 1.0f};
	vector2			 save_translation{0, 0};
    float            rotation = 0.0f;
    float            depth = 0.0f;
    const Transform* parent = nullptr;

    vector2          center{0.0f, 0.0f};
};


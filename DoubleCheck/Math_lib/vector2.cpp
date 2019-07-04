/************************************************
 *NAME              : sangmin.kim
 *ASSIGNMENT NUMBER : 1
 *COURSE NAME       : CS230
 *TERM              : Spring 2019
 ************************************************/
#include "vector2.hpp"
#include <cassert>
#include <limits>

vector2::vector2() noexcept
{
    //Fuck you
    x = 0.0f;
    y = 0.0f;
};
vector2::vector2(float repeated_float) noexcept
{
    x = repeated_float;
    y = repeated_float;
};
vector2::vector2(float fx, float fy) noexcept
{
    x = fx;
    y = fy;
};

void operator+=(vector2& v, const vector2& adding_vector) noexcept
{
    v.x += adding_vector.x;
    v.y += adding_vector.y;
}
void operator-=(vector2& v, const vector2& subtracting_vector) noexcept
{
    v.x -= subtracting_vector.x;
    v.y -= subtracting_vector.y;
}
void operator*=(vector2& v, float scale) noexcept
{
    v.x *= scale;
    v.y *= scale;
}
void operator/=(vector2& v, float divisor) noexcept
{
    assert(divisor != 0);
    v.x /= divisor;
    v.y /= divisor;
}
vector2 operator-(const vector2& v) noexcept
{
    vector2 result_vec;
    result_vec.x = -(v.x);
    result_vec.y = -(v.y);

    return result_vec;
}
vector2 operator+(const vector2& v1, const vector2& v2) noexcept
{
    vector2 result_vec;
    result_vec.x = v1.x + v2.x;
    result_vec.y = v1.y + v2.y;

    return result_vec;
}
vector2 operator-(const vector2& v1, const vector2& v2) noexcept
{
    vector2 result_vec;
    v2.x > v1.x ? result_vec.x = v2.x - v1.x : result_vec.x = v1.x - v2.x;
    v2.y > v1.y ? result_vec.y = v2.y - v1.y : result_vec.y = v1.y - v2.y;

    return result_vec;
}
vector2 operator*(const vector2& v, float scale) noexcept
{
    vector2 result_vec;
    result_vec.x = v.x * scale;
    result_vec.y = v.y * scale;

    return result_vec;
}
vector2 operator*(float scale, const vector2& v) noexcept
{
    vector2 result_vec;
    result_vec.x = v.x * scale;
    result_vec.y = v.y * scale;

    return result_vec;
}
vector2 operator/(const vector2& v, float divisor) noexcept
{
    assert(divisor != 0);

    vector2 result_vec;
    result_vec.x = v.x / divisor;
    result_vec.y = v.y / divisor;

    return result_vec;
}
bool operator==(const vector2& v1, const vector2& v2) noexcept
{
    if (std::abs(v1.x - v2.x) <= std::numeric_limits<float>::epsilon() &&
        std::abs(v1.y - v2.y) <= std::numeric_limits<float>::epsilon())
    {
        return true;
    }
    else
        return false;
}
bool operator!=(const vector2& v1, const vector2& v2) noexcept
{
    if (std::abs(v1.x - v2.x) <= std::numeric_limits<float>::epsilon() &&
        std::abs(v1.y - v2.y) <= std::numeric_limits<float>::epsilon())
    {
        return false;
    }
    else
        return true;
}

float dot(vector2 a, vector2 b) noexcept
{
    float dot_product = 0.0f;

    dot_product += (a.x * b.x);
    dot_product += (a.y * b.y);

    return dot_product;
}
vector2 perpendicular_to(vector2 a) noexcept
{
    vector2 result_vec;
    result_vec.x = -(a.y);
    result_vec.y = a.x;

    return result_vec;
}
float magnitude_squared(vector2 a) noexcept
{
    float magnitude_val_squared = 0.0f;

    magnitude_val_squared += dot(a, a);

    return magnitude_val_squared;
}
float magnitude(vector2 a) noexcept
{
    float magnitude_val = 0.0f;

    magnitude_val = sqrt(dot(a, a));

    return magnitude_val;
}
vector2 normalize(vector2 a) noexcept
{
    vector2 result_vec;
    float   magnitude_val = 0.0f;

    magnitude_val = magnitude(a);
    result_vec.x = a.x / magnitude_val;
    result_vec.y = a.y / magnitude_val;

    return result_vec;
}
float distance_between_squared(vector2 a, vector2 b) noexcept
{
    float distance_squared = 0.0f;
    float distance_x = 0.0f;
    float distance_y = 0.0f;

    distance_x = b.x - a.x;
    distance_y = b.y - a.y;

    distance_squared = ((distance_x * distance_x) + (distance_y * distance_y));

    return distance_squared;
}
float distance_between(vector2 a, vector2 b) noexcept
{
    float distance = 0.0f;
    float distance_x = 0.0f;
    float distance_y = 0.0f;

    distance_x = b.x - a.x;
    distance_y = b.y - a.y;

    distance = sqrt((distance_x * distance_x) + (distance_y * distance_y));

    return distance;
}
float angle_between(vector2 a, vector2 b) noexcept
{
    float cos_theta = dot(a, b) / (magnitude(a) * magnitude(b));
    float radian = acosf(cos_theta);
    float angle = radian;

    return angle;
}
vector2 rotate_by(float angle_in_radians, vector2 v) noexcept
{
    vector2 result_vec;
    result_vec.x = ((cos(angle_in_radians) * v.x) - (sin(angle_in_radians) * v.y));
    result_vec.y = ((sin(angle_in_radians) * v.x) + (cos(angle_in_radians) * v.y));

    return result_vec;
}


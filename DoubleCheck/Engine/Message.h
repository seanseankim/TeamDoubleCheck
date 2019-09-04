#pragma once
#include "vector2.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Object.h"


class Message
{
private:
    std::string message_name;
    Object* m_target = nullptr;
    Object* m_from = nullptr;

public:
    Message(Object* target, Object* from, std::string message_name_) : 
    m_target(target), m_from(from), message_name(message_name_)
    {}
    void Init();
    void Update(float dt);
    void Delete();
};

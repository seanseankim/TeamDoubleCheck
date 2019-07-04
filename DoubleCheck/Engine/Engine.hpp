#pragma once
#include "Timer.hpp"

class Engine
{
public:
    Engine() = default;

    void Init();
    void Update();
    void Delete();

    bool IsDone() { return is_done; }

private:
    bool is_done = false;
    float m_dt;
    Timer game_timer;
};
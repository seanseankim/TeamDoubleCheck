#include "Engine.hpp"
#include "Application.hpp"

namespace
{
    Application* app_;
}

void Engine::Init()
{
    game_timer.Reset();

    app_ = Application::Get_Application();
    app_->Init();
}

void Engine::Update()
{
    m_dt = game_timer.GetElapsedSeconds();

    game_timer.Reset();

    app_->Update(m_dt);
}

void Engine::Delete()
{
}

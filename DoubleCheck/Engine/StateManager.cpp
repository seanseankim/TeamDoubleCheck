#include "StateManager.h"
#include <iostream>

StateManager* StateManager::state_manager = nullptr;

StateManager* StateManager::GetStateManager()
{
    if (state_manager == nullptr)
        state_manager = new StateManager();

    return state_manager;
}

void StateManager::Init()
{
    current_state = nullptr;
    states.clear();
}

void StateManager::Update(float dt)
{
    if (is_pause)
    {
        current_state->Update(dt);

        if (current_state->IsNextLevel())
        {
            std::string temp_name = current_state->GetNextLevelName();
            current_state->UnLoad();
            current_state = states.find(temp_name)->second.get();
            current_state->Load();
        }
    }
    else
    {
        std::cout << "Resume" << std::endl;
    }
}

void StateManager::Delete()
{
    current_state = nullptr;
    states.clear();
}

void StateManager::AddState(std::string name, State* state)
{
    auto temp = std::make_pair(name, state);

    if (current_state == nullptr)
    {
        if (state->GetStateInfo() == GameState::Menu)
        {
            current_state = state;
            current_state->Load();
        }
    }
    states.insert(temp);
}

void StateManager::DeleteState(std::shared_ptr<State> state)
{
}

#pragma once
#include <string>

enum class GameState
{
    Menu, Game, Credit, None
};

class State
{
public:
    virtual void Load() = 0;
    virtual void Update(float dt) = 0;
    virtual void UnLoad() = 0;
    bool IsNextLevel()
    {
        return is_next;
    }
    void MoveLevel(std::string name)
    {
        next_level = name;
    }
    std::string GetNextLevelName()
    {
        return next_level;
    }
    GameState GetStateInfo()
    {
        return current_state;
    }
protected:
    std::string next_level;
    bool is_next = false;
    GameState current_state = GameState::None;
};
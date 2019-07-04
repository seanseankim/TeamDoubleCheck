#include <iostream>
#include "Engine.hpp"

int main()
{
    Engine engine;
    engine.Init();
    while (!engine.IsDone())
        engine.Update();

    engine.Delete();
    return 0;
}
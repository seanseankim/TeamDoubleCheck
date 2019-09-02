#include "Level1.h"
#include "Component_Player.h"
#include "ObjectManager.h"

void Level1::Load()
{
    player = new Object();

    ObjectManager::GetObjectManager()->AddObject(player);
}

void Level1::Update(float dt)
{
}

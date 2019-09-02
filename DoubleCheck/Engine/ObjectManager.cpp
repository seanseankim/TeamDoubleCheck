#include "ObjectManager.h"
#include <functional>
#include "StateManager.h"
#include <iostream>

ObjectManager* ObjectManager::object_manager = nullptr;

ObjectManager* ObjectManager::GetObjectManager()
{
    if (object_manager == nullptr)
        object_manager = new ObjectManager();

    return object_manager;
}

void ObjectManager::Init()
{
    objects.clear();
    delete_obj.clear();
}

void ObjectManager::Update(float dt)
{
    if (StateManager::GetStateManager()->is_pause)//
    {
        delete_obj.clear();

        for (auto& obj : objects)
        {
            for (auto component : obj->GetComponentContainer())
            {
                component->Update(dt);
            }
            if (obj->IsDead())
                delete_obj.push_back(obj);
        }

        for (auto& remove_obj : delete_obj)
        {
            DeleteObject(remove_obj);
        }
    }
    else
    {
        
    }
}

void ObjectManager::Delete()
{
    objects.clear();
    delete_obj.clear();

    delete object_manager;
    object_manager = nullptr;
}

void ObjectManager::AddObject(Object* obj)
{
    for (auto component : obj->GetComponentContainer())
    {
        component->Init(obj);
    }

    objects.push_back(std::shared_ptr<Object>(obj));
}

void ObjectManager::DeleteObject(std::shared_ptr<Object> obj)
{
    objects.erase(std::find(objects.begin(), objects.end(), obj));
}

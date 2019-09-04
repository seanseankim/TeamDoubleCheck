#pragma once
#include <vector>
#include "Object.h"
#include <memory>
#include <unordered_map>

class ObjectManager
{
public:
    static ObjectManager* GetObjectManager();

    void Init();
    void Update(float dt);
    void Delete();

    void AddObject(Object* obj);
    void DeleteObject(std::shared_ptr<Object> obj);

    std::vector<std::shared_ptr<Object>>& GetObjectManagerContainer()
    {
        return objects;
    }
    std::vector<std::shared_ptr<Object>> GetObjectManagerContainer_Value()
    {
        return objects;
    }
    


private:
    static ObjectManager* object_manager;
    std::vector<std::shared_ptr<Object>> objects{};
    std::vector<std::shared_ptr<Object>> delete_obj{};
    //std::unordered_map<std::string, std::unique_ptr<Object>> objects{};
};
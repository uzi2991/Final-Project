#include "Engine/PhysicSystem.hpp"
#include <algorithm>
#include "Engine/Entity.hpp"

void PhysicSystem::fixedUpdate(float deltaTime)
{
    this->refresh();
    // for (const auto &object : this->dynamicObjects)
    // {
    //     object->fixedUpdate(deltaTime);
    // }

    // Dynamic vs Static
    for (const auto& dObject: this->dynamicObjects)
    {
        for (const auto& sObject: this->staticObjects)
        {
            if (dObject->entity->isActive() && sObject->entity->isActive() && dObject->isCollide(sObject))
            {
                dObject->entity->onCollision(sObject->entity);
                sObject->entity->onCollision(dObject->entity);
            }
        }
    }

    // Dynamic vs Dynamic

    for (int i = 0; i < this->dynamicObjects.size(); ++i)
    {
        for (int j = i + 1; j < this->dynamicObjects.size(); ++j)
        {
            auto object1 = this->dynamicObjects[i];
            auto object2 = this->dynamicObjects[j];
            if (object1->entity->isActive() && object2->entity->isActive() && object1->isCollide(object2))
            {
                object1->entity->onCollision(object2->entity);
                object2->entity->onCollision(object1->entity);
            }
            
        }
    }
}

void PhysicSystem::addObject(RigidBody *body, bool isStatic)
{
    if (isStatic)
    {
        this->staticObjects.emplace_back(body);
    }
    else
    {
        this->dynamicObjects.emplace_back(body);
    }
}

void PhysicSystem::refresh()
{
    this->staticObjects.erase(
        std::remove_if(
            this->staticObjects.begin(),
            this->staticObjects.end(),
            [](RigidBody *object)
            { return !object->entity->isActive(); }),
        this->staticObjects.end());

    this->dynamicObjects.erase(
        std::remove_if(
            this->dynamicObjects.begin(),
            this->dynamicObjects.end(),
            [](RigidBody *object)
            { return !object->entity->isActive(); }),
        this->dynamicObjects.end());
}
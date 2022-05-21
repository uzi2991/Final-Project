#pragma once

#include <vector>
#include "Engine/RigidBody.hpp"

class PhysicSystem
{
public:
    void fixedUpdate(float deltaTime);

    void addObject(RigidBody* body, bool isStatic = true);

private:
    void refresh();

private:
    std::vector<RigidBody*> staticObjects;
    std::vector<RigidBody*> dynamicObjects;
};
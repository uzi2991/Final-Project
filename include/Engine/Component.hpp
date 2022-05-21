#pragma once

class Entity;

/*
    Base Component Class
*/
class Component
{
public:
    Component() {}

    virtual ~Component() {}

    virtual bool init() { return true; }

    virtual void fixedUpdate(float deltaTime) {}

    virtual void update(float deltaTime) {}

    virtual void lateUpdate(float deltaTime) {}

    virtual void draw() {}

    // The entity this component attached to
    Entity *entity;
};
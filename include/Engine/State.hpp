#pragma once

/*
    Base State class
*/
class State
{
public:
    State() {}

    virtual ~State() {}

    virtual void init() {}

    virtual void handleInput() {}

    virtual void fixedUpdate(float deltaTime) {}

    virtual void update(float deltaTime) {}

    virtual void lateUpdate(float deltaTime) {}

    virtual void draw() {}

    virtual void pause() {}

    virtual void resume() {}

    virtual void destroy() {}
};
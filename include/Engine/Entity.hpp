#pragma once

#include "Engine/ECS.hpp"
#include <vector>
#include <memory>
#include "Engine/Transform.hpp"

/*
    Base Entity Class
*/
class Entity
{
public:
    Entity()
    {
        this->active = true;
        this->transform = this->addComponent<Transform>();
    }

    virtual ~Entity() {}

    virtual void init() {}

    virtual void fixedUpdate(float deltaTime)
    {
        for (const auto &comp : this->components)
        {
            comp->fixedUpdate(deltaTime);
        }
    }

    virtual void update(float deltaTime)
    {
        for (const auto &comp : this->components)
        {
            comp->update(deltaTime);
        }
    }

    virtual void lateUpdate(float deltaTime)
    {
        for (const auto &comp : this->components)
        {
            comp->lateUpdate(deltaTime);
        }
    }

    virtual void draw()
    {
        for (const auto &comp : this->components)
        {
            comp->draw();
        }
    }

    virtual void destroy() { this->active = false; }

    virtual void onCollision(Entity *other) {}

    bool isActive() const { return this->active; }

    template <class T, class... TArgs>
    T *addComponent(TArgs &&...args)
    {
        static_assert(std::is_base_of<Component, T>::value, "T must be a Component\n");
        T *comp(new T(std::forward<TArgs>(args)...));
        std::unique_ptr<Component> uPtr(comp);
        this->components.emplace_back(std::move(uPtr));

        comp->entity = this;

        if (comp->init())
        {
            this->compList[getComponentTypeID<T>()] = comp;
            this->compBitset[getComponentTypeID<T>()] = true;

            return comp;
        }

        return nullptr;
    }

    template <class T>
    T *getComponent() const
    {
        static_assert(std::is_base_of<Component, T>::value, "T must be a Component\n");

        auto ptr(this->compList[getComponentTypeID<T>()]);
        return (T *)ptr;
    }

    template <class T>
    bool hasComponent() const
    {
        static_assert(std::is_base_of<Component, T>::value, "T must be a Component\n");
        return this->compBitset[getComponentTypeID<T>()];
    }

public:

    // The transform component of this entity
    Transform *transform;

    // Tag
    std::string tag;

protected:
    bool active;

private:
    ComponentList compList;
    ComponentBitset compBitset;
    std::vector<std::unique_ptr<Component>> components;
};
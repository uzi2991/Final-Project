#pragma once

#include "Engine/Entity.hpp"
#include <vector>

class EntityManager
{
public:
    EntityManager() {}

    void fixedUpdate(float deltaTime)
    {
        for (const auto &ent : this->entities)
        {
            ent->fixedUpdate(deltaTime);
        }
    }

    void update(float deltaTime)
    {
        for (const auto &ent : this->entities)
        {
            ent->update(deltaTime);
        }
    }

    void lateUpdate(float deltaTime)
    {
        for (const auto &ent : this->entities)
        {
            ent->lateUpdate(deltaTime);
        }
    }

    void draw()
    {
        for (const auto &ent : this->entities)
        {
            ent->draw();
        }
    }

    void refresh()
    {
        this->entities.erase(
            std::remove_if(
                this->entities.begin(),
                this->entities.end(),
                [](const std::unique_ptr<Entity> &ent)
                {
                    return !ent->isActive();
                }),
            this->entities.end());
    }

    template <class T, class... TArgs>
    T *addEntity(TArgs &&...args)
    {
        static_assert(std::is_base_of<Entity, T>::value, "T must be an Entity\n");

        T *ent(new T(std::forward<TArgs>(args)...));
        ent->init();

        std::unique_ptr<Entity> uPtr(ent);
        this->entities.emplace_back(std::move(uPtr));

        return ent;
    }

private:
    std::vector<std::unique_ptr<Entity>> entities;
};
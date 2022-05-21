#include "GameState/Terrain.hpp"
#include "GameState/Level.hpp"
#include <iostream>

Terrain::Terrain(Level& level, const sf::Vector2f &position, const sf::Vector2f &size) : level(level), Entity()
{
    this->position = position;
    this->size = size;
}

void Terrain::init()
{
    
    this->transform->position = this->position;
    this->addComponent<BoxCollider>(this->size);
    this->level.physic.addObject(this->addComponent<RigidBody>());
}
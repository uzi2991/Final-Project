#include "GameState/Level.hpp"
#include "Engine/SharedContext.hpp"
#include "GameState/TilemapParser.hpp"

Level::Level(const std::string &levelNum)
{
    this->view.setSize(System.window.getSize().x, System.window.getSize().y);
    this->view.zoom(0.75f);

    TileMapParser parser(*this);
    parser.readLevelData(levelNum);

    this->levelSprite.setTexture(System.asset.getTexture("level " + levelNum));
    this->levelSprite.setPosition(0.f, 0.f);

    this->player = this->entMng.addEntity<Player>(*this);

    this->win = this->lose = false;

    this->pickups = 0;
    this->chests = 0;
}

void Level::handleInput()
{
}

void Level::fixedUpdate(float deltaTime)
{
    this->entMng.refresh();
    this->entMng.fixedUpdate(deltaTime);
    this->physic.fixedUpdate(deltaTime);
}

void Level::update(float deltaTime)
{
    this->entMng.refresh();
    this->entMng.update(deltaTime);
}

void Level::lateUpdate(float deltaTime)
{
    this->entMng.refresh();
    this->entMng.lateUpdate(deltaTime);
    this->updateView();
}

void Level::draw()
{
    System.window.setView(this->view);

    this->levelSprite.draw(System.window);

    this->entMng.refresh();
    this->entMng.draw();
}

void Level::updateView()
{
    this->view.setCenter(this->player->transform->position);
}
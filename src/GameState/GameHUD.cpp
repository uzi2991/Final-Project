#include "GameState/GameHUD.hpp"
#include "Engine/SharedContext.hpp"

#define BORDER 2.f
#define FONT_SIZE 20.f

GameHUD::GameHUD()
{
    this->progess = this->delay;
    this->view = System.window.getDefaultView();

    this->pickups = 0;
    this->chests = 0;

    this->pickupText.setFont(System.asset.getFont("font"));
    this->pickupText.setFillColor(sf::Color::White);
    this->pickupText.setOutlineThickness(BORDER);
    this->pickupText.setOutlineColor(sf::Color::Black);
    this->pickupText.setCharacterSize(FONT_SIZE);
    this->pickupText.setString("Pickup: 0");
    this->pickupText.setPosition(0.f, 0.f);

    this->fpsText.setFont(System.asset.getFont("font"));
    this->fpsText.setFillColor(sf::Color::White);
    this->fpsText.setOutlineThickness(BORDER);
    this->fpsText.setOutlineColor(sf::Color::Black);
    this->fpsText.setCharacterSize(FONT_SIZE);
    this->fpsText.setString("FPS: 0000");
    this->fpsText.setPosition(System.window.getSize().x - this->fpsText.getGlobalBounds().width, 0.f);

    this->chestText.setFont(System.asset.getFont("font"));
    this->chestText.setFillColor(sf::Color::White);
    this->chestText.setOutlineThickness(BORDER);
    this->chestText.setOutlineColor(sf::Color::Black);
    this->chestText.setCharacterSize(FONT_SIZE);
    this->chestText.setString("Chest: 0/3");
    this->chestText.setPosition(0.f, this->pickupText.getGlobalBounds().top + this->pickupText.getGlobalBounds().height + 10.f);
}

void GameHUD::update(float deltaTime)
{
    this->progess += deltaTime;
    if (this->progess >= this->delay)
    {
        this->progess -= this->delay;

        this->fpsText.setString("FPS: " + std::to_string(System.fps));

        this->pickupText.setString("Pickup: " + std::to_string(this->pickups));
        
        this->chestText.setString("Chest: " + std::to_string(this->chests) + "/3");
    }
}

void GameHUD::setPickups(int pickups) {
    this->pickups = pickups;
}

void GameHUD::setChests(int chests) {
    this->chests = chests;
}

void GameHUD::draw()
{
    System.window.setView(this->view);

    System.window.draw(this->chestText);
    System.window.draw(this->fpsText);

    System.window.draw(this->pickupText);
}
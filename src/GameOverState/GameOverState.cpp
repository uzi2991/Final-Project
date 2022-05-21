#include "GameOverState/GameOverState.hpp"
#include "MenuState/MenuState.hpp"
#include "Engine/SharedContext.hpp"

#define MENU_BUTTON_SIZE_X 250.f
#define MENU_BUTTON_SIZE_Y 50.f

void GameOverState::init()
{
    this->gameOverText.setFont(System.asset.getFont("font"));
    this->gameOverText.setFillColor(sf::Color::Black);

    this->gameOverText.setString(this->win ? "You Pass The Level!" : "You Lost!");

    this->gameOverText.setPosition(
        System.window.getSize().x / 2 - this->gameOverText.getGlobalBounds().width / 2,
        System.window.getSize().y / 2 - this->gameOverText.getGlobalBounds().height / 2);

    this->backToMenuButton = std::make_unique<Button>(
        sf::Vector2f(MENU_BUTTON_SIZE_X, MENU_BUTTON_SIZE_Y),
        "Back to Menu");

    this->backToMenuButton->setPosition(
        System.window.getSize().x / 2,
        this->gameOverText.getGlobalBounds().top + this->gameOverText.getGlobalBounds().height + MENU_BUTTON_SIZE_Y / 2 + 20.f);
}

void GameOverState::update(float deltaTime)
{
    this->backToMenuButton->update(deltaTime);

    if (this->backToMenuButton->isClick())
    {
        System.machine.addState(StateRef(std::make_unique<MenuState>()));
    }
}

void GameOverState::draw()
{
    System.window.clear(sf::Color::White);

    System.window.draw(this->gameOverText);

    this->backToMenuButton->draw();

    System.window.display();
}

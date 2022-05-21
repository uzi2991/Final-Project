#include "MenuState/TutorialState.hpp"
#include "Engine/SharedContext.hpp"
#include "MenuState/MenuState.hpp"

#define BACK_BUTTON_SIZE_X 40.f
#define BACK_BUTTON_SIZE_Y 40.f

void TutorialState::init()
{
    this->backButton = std::make_unique<Button>(sf::Vector2f(BACK_BUTTON_SIZE_X, BACK_BUTTON_SIZE_Y), "<");
    this->backButton->setPosition(10.f + BACK_BUTTON_SIZE_X / 2.f, 10.f + BACK_BUTTON_SIZE_Y / 2.f);

    this->tutorialText.setFont(System.asset.getFont("font"));
    this->tutorialText.setFillColor(sf::Color::Black);
    this->tutorialText.setString("Press A, D to move. W to jump");

    auto [left, top, width, height] = this->tutorialText.getGlobalBounds();
    this->tutorialText.setPosition(System.window.getSize().x / 2 - width / 2, System.window.getSize().y / 2 - height / 2);
}

void TutorialState::update(float deltaTime)
{
    this->backButton->update(deltaTime);

    if (this->backButton->isClick())
    {
        System.machine.addState(StateRef(std::make_unique<MenuState>()));
    }
}

void TutorialState::draw()
{
    System.window.clear(sf::Color::White);

    System.window.draw(this->tutorialText);
    this->backButton->draw();

    System.window.display();
}
#include "Engine/Input.hpp"

void Input::update()
{
    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            this->isClose = true;
        }
    }

    this->mousePosition = sf::Vector2f(sf::Mouse::getPosition(this->window));
    this->lastFrameMouse.setMask(this->currentFrameMouse);
    this->currentFrameMouse.setBit((int)Mouse::Left, sf::Mouse::isButtonPressed(sf::Mouse::Left));
    this->currentFrameMouse.setBit((int)Mouse::Right, sf::Mouse::isButtonPressed(sf::Mouse::Right));

    this->lastFrameKeys.setMask(this->currentFrameKeys);
    this->currentFrameKeys.setBit((int)Key::A, sf::Keyboard::isKeyPressed(sf::Keyboard::A));
    this->currentFrameKeys.setBit((int)Key::D, sf::Keyboard::isKeyPressed(sf::Keyboard::D));
    this->currentFrameKeys.setBit((int)Key::W, sf::Keyboard::isKeyPressed(sf::Keyboard::W));
    this->currentFrameKeys.setBit((int)Key::S, sf::Keyboard::isKeyPressed(sf::Keyboard::S));
    this->currentFrameKeys.setBit((int)Key::Escape, sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
    this->currentFrameKeys.setBit((int)Key::Enter, sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));

}

bool Input::checkWindowClose() const
{
    return this->isClose;
}

bool Input::isMousePressed(Mouse mouseButton) const
{
    return this->currentFrameMouse.getBit((int)mouseButton);
}

bool Input::isMouseDown(Mouse mouseButton) const
{
    return this->currentFrameMouse.getBit((int)mouseButton) && !this->lastFrameMouse.getBit((int)mouseButton);
}

bool Input::isMouseUp(Mouse mouseButton) const
{
    return !this->currentFrameMouse.getBit((int)mouseButton) && this->lastFrameMouse.getBit((int)mouseButton);
}

sf::Vector2f Input::getMousePosition() const
{
    return this->mousePosition;
}

bool Input::isKeyPressed(Key key) const
{
    return this->currentFrameKeys.getBit((int)key);

}

bool Input::isKeyDown(Key key) const
{
    return this->currentFrameKeys.getBit((int)key) && !this->lastFrameKeys.getBit((int)key);
}

bool Input::isKeyUp(Key key) const
{
    return !this->currentFrameKeys.getBit((int)key) && this->lastFrameKeys.getBit((int)key);
}
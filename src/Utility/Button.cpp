#include "Utility/Button.hpp"
#include <iostream>
#include "Engine/SharedContext.hpp"

#define BORDER_SIZE 3.f

Button::Button(const sf::Vector2f &size, const std::string &content)
{
    this->box.setSize(size);

    this->box.setFillColor(sf::Color::Transparent);
    this->box.setOutlineThickness(BORDER_SIZE);
    this->box.setOutlineColor(sf::Color::Black);
    sf::FloatRect boxRect = this->box.getGlobalBounds();
    this->box.setOrigin(boxRect.left + boxRect.width / 2, boxRect.top + boxRect.height / 2);

    this->contentString = content;
    this->content.setString(content);
    this->content.setFont(System.asset.getFont("font"));
    this->content.setFillColor(sf::Color::Black);
    sf::FloatRect textRect = this->content.getGlobalBounds();
    this->content.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);

    this->setPosition(System.window.getSize().x / 2, System.window.getSize().y / 2);

    this->click = false;
    this->hover = false;
}

void Button::setPosition(float x, float y)
{
    this->box.setPosition(x, y);

    this->content.setPosition(x, y);
}

void Button::setPosition(const sf::Vector2f &position)
{
    this->setPosition(position.x, position.y);
}

void Button::update(float deltaTime)
{
    this->click = false;
    this->hover = false;
    this->box.setScale(1.f, 1.f);
    this->content.setScale(1.f, 1.f);

    if (this->box.getGlobalBounds().contains(System.input.getMousePosition()))
    {
        this->hover = true;
        if (System.input.isMouseDown(Input::Mouse::Left))
        {
            this->click = true;
        }
    }

    if (this->hover)
    {
        this->box.setScale(1.1f, 1.1f);
        this->content.setScale(1.1f, 1.1f);
    }
}

void Button::draw()
{
    System.window.draw(this->box);
    System.window.draw(this->content);
}

bool Button::isClick() const
{
    return this->click;
}

std::string Button::getContent() const
{
    return this->contentString;
}
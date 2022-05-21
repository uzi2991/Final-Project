#pragma once
#include "SFML/Graphics.hpp"

class Button
{
public:
    Button(const sf::Vector2f &size, const std::string &content);

    void setPosition(float x, float y);

    void setPosition(const sf::Vector2f &position);

    void update(float deltaTime);

    void draw();

    bool isClick() const;

    std::string getContent() const;

private:
    sf::RectangleShape box;

    bool click;

    bool hover;

    std::string contentString;

    sf::Text content;
};
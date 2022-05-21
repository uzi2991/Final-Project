#pragma once

#include "SFML/Graphics.hpp"
#include "Utility/Bitmask.hpp"

class Input
{
public:
    enum class Key
    {
        None = 0,
        W = 1,
        A = 2, 
        S = 3,
        D = 4,
        Enter = 5,
        Escape = 6
    };

    enum class Mouse
    {
        None = 0,
        Left = 1,
        Right = 2
    };

    Input(sf::RenderWindow& window): window(window) {}

    void update();

    bool checkWindowClose() const;

    bool isMousePressed(Mouse mouseButton) const;

    bool isMouseDown(Mouse mouseButton) const;

    bool isMouseUp(Mouse mouseButton) const;

    sf::Vector2f getMousePosition() const;

    bool isKeyPressed(Key key) const;

    bool isKeyDown(Key key) const;

    bool isKeyUp(Key key) const;

public:
    sf::RenderWindow& window;

private:
    bool isClose;

    Bitmask lastFrameMouse;
    Bitmask currentFrameMouse;
    sf::Vector2f mousePosition;

    Bitmask lastFrameKeys;
    Bitmask currentFrameKeys;
};
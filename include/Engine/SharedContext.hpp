#pragma once

#include "SFML/Graphics.hpp"
#include "Engine/AssetManager.hpp"
#include "Engine/Input.hpp"
#include "Engine/StateMachine.hpp"

class SharedContext
{
public:
    static SharedContext &Instance()
    {
        static SharedContext instance;
        return instance;
    }

    SharedContext(SharedContext &) = delete;
    SharedContext &operator=(SharedContext &) = delete;

private:
    SharedContext() : input(window)
    {
    }

public:
    sf::RenderWindow window;

    Input input;

    AssetManager asset;

    StateMachine machine;

    sf::Clock clock;

    int fps;
};

#define System (SharedContext::Instance())
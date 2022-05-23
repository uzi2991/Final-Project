#include "Engine/Game.hpp"
#include "MenuState/MenuState.hpp"
#include "Engine/SharedContext.hpp"
#include <iostream>

#define MAIN_THEME_FILEPATH "../res/Sounds/Main Theme.wav"
#define JUMP_SOUND_FILEPATH "../res/Sounds/jump.wav"
#define FONT_FILEPATH "../res/Fonts/Aller_Rg.ttf"

#define FIXED_FPS 60.f

Game::Game(int width, int height, const std::string &title)
{
    System.window.create(
        sf::VideoMode(width, height),
        title,
        sf::Style::Close | sf::Style::Titlebar);

    System.asset.loadSoundBuffer("main theme", MAIN_THEME_FILEPATH);
    System.asset.loadSoundBuffer("jump", JUMP_SOUND_FILEPATH);

    System.asset.loadFont("font", FONT_FILEPATH);

    System.machine.addState(StateRef(std::make_unique<MenuState>()));

    System.asset.loadSoundBuffer("main theme", MAIN_THEME_FILEPATH);
    System.asset.loadSoundBuffer("jump", JUMP_SOUND_FILEPATH);
}

void Game::run()
{
    float accumulator = 0.f;
    float fixedDeltaTime = 1 / FIXED_FPS;

    System.clock.restart();
    while (System.window.isOpen())
    {
        System.machine.processStateChanges();

        System.input.update();
        if (System.input.checkWindowClose())
        {
            System.window.close();
        }
        System.machine.getActiveState()->handleInput();

        float deltaTime = System.clock.restart().asSeconds();
        System.fps = 1.f / deltaTime;
        accumulator += deltaTime;

        // Fixed update
        while (accumulator >= fixedDeltaTime)
        {
            System.machine.getActiveState()->fixedUpdate(fixedDeltaTime);

            accumulator -= fixedDeltaTime;
        }

        // Update
        System.machine.getActiveState()->update(deltaTime);

        // Late update
        System.machine.getActiveState()->lateUpdate(deltaTime);

        // Draw
        System.machine.getActiveState()->draw();
    }
}
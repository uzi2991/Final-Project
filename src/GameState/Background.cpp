#include "GameState/Background.hpp"
#include "Engine/SharedContext.hpp"

Background::Background()
{
    this->sprite1.setTexture(System.asset.getTexture("background"));
    this->sprite2.setTexture(System.asset.getTexture("background"));

    this->height = this->sprite1.getSize().y;

    y1 = 0.f;
    y2 = this->height;

    this->sprite1.setPosition(0.f, y1);
    this->sprite2.setPosition(0.f, y2);

    this->view = System.window.getDefaultView();
}

void Background::update(float deltaTime)
{
    this->y1 += this->speed * deltaTime;

    this->y2 += this->speed * deltaTime;

    if (this->y1 > System.window.getSize().y)
    {
        this->y1 = this->y2 - this->height;
    }

    if (this->y2 > System.window.getSize().y)
    {
        this->y2 = this->y1 - this->height;
    }
}

void Background::draw()
{
    System.window.setView(this->view);

    this->sprite1.setPosition(0.f, this->y1);
    this->sprite2.setPosition(0.f, this->y2);

    this->sprite1.draw(System.window);
    this->sprite2.draw(System.window);
}
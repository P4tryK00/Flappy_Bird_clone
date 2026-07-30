#include "Bird.h"
#include <iostream>
#include <SFML/System.hpp>

Bird::Bird() : texture_("Resources/Textures/Bird/bird_orange_0.png"), sprite_(texture_)
{
    auto bounds = sprite_.getLocalBounds();
    float targetHeight = static_cast<float>(SCREEN_HEIGHT) * 0.08f;
    float scale = targetHeight / bounds.size.y;
    sprite_.setScale(sf::Vector2f(scale, scale));
    sprite_.setPosition(sf::Vector2f(SCREEN_WIDTH / 4, static_cast<float>(y)));
}




void Bird::draw(sf::RenderWindow& window) const
{

    window.draw(sprite_);
}

void Bird::update(sf::Time& dt)
{
    vel += gravity * dt.asSeconds();
    sprite_.move({0.0f, static_cast<float>(vel*dt.asSeconds())});

}


void Bird::tap()
{
    vel = tap_speed;
}
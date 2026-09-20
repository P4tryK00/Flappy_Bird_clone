#ifndef FLAPPY_BIRD_CLONE_BIRD_H
#define FLAPPY_BIRD_CLONE_BIRD_H

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"

class Bird
{
public:
    Bird();
    ~Bird() = default;

    void draw(sf::RenderWindow& window) const;
    void update(sf::Time &dt);
    void tap();
    sf::FloatRect getBounds() const { return sprite_.getGlobalBounds(); }
    
private:
    sf::Texture texture_;
    sf::Sprite sprite_;

    double vel = 0;
    double y = 400;

    const double gravity = 800.0;
    const double tap_speed = -400.0;
};

#endif //FLAPPY_BIRD_CLONE_BIRD_H
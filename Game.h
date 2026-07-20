#ifndef FLAPPY_BIRD_CLONE_GAME_H
#define FLAPPY_BIRD_CLONE_GAME_H

#include <SFML/Graphics.hpp>
#include "Bird.h"

class Game
{
    public:
    Game();
    ~Game();

    void update();
    void run();
    void draw();



    private:
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    sf::RenderWindow window_;
    sf::Clock clock_;
    sf::Time timePassed_ = sf::Time::Zero;
    Bird bird_;
};


#endif //FLAPPY_BIRD_CLONE_GAME_H

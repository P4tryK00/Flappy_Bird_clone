//
// Created by patryk on 20.07.2026.
//

#ifndef FLAPPY_BIRD_CLONE_STATE_H
#define FLAPPY_BIRD_CLONE_STATE_H



#include <SFML/Graphics.hpp>

class State {
public:
    virtual ~State() {}
    virtual void init() = 0;

    virtual void handleInput(const sf::Event& event) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(float dt) = 0;
    virtual void pause() {}
    virtual void resume() {}
};

#endif //FLAPPY_BIRD_CLONE_STATE_H



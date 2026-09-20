#ifndef FLAPPY_BIRD_CLONE_PIPE_H
#define FLAPPY_BIRD_CLONE_PIPE_H

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"

class Pipe
{
public:
    Pipe(float startX);

    void update(const sf::Time& dt);
    void draw(sf::RenderWindow& window) const;

    bool isOffScreen() const;
    sf::FloatRect getTopBounds() const { return topSprite_.getGlobalBounds(); }
    sf::FloatRect getBottomBounds() const { return bottomSprite_.getGlobalBounds(); }

    bool isScored() const { return m_isScored; }
    void setScored(bool scored) { m_isScored = scored; }
    float getPositionX() const { return topSprite_.getPosition().x; }

private:
    sf::Sprite topSprite_;
    sf::Sprite bottomSprite_;
    bool m_isScored = false;

    float speed_ = 200.0f;
    float pipeGap_ = 160.0f;
};

#endif //FLAPPY_BIRD_CLONE_PIPE_H

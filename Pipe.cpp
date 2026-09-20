#include "DEFINITIONS.h"
#include "Pipe.h"

#include "TextureManager.h"
#include <algorithm>

Pipe::Pipe(float startX)
    : topSprite_(TextureManager::get("pipe_upper")), bottomSprite_(TextureManager::get("pipe_bottom"))
{
    float margin = 80.0f;
    float groundLevel = static_cast<float>(SCREEN_HEIGHT) - GROUND_HEIGHT;
    auto minY = margin + pipeGap_ / 2.0f;
    auto maxY = groundLevel - margin - pipeGap_ / 2.0f;
    auto gapCenterY = minY + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxY - minY));

    auto bounds = topSprite_.getLocalBounds();
    auto targetWidth = static_cast<float>(SCREEN_WIDTH) * 0.12f;
    float scaleX = targetWidth / bounds.size.x;

    // Ensure pipe is tall enough so that it always extends beyond the top and bottom screen edges
    float requiredHeight = static_cast<float>(SCREEN_HEIGHT);
    float scaleY = std::max(scaleX, requiredHeight / bounds.size.y);

    topSprite_.setScale(sf::Vector2f(scaleX, scaleY));
    topSprite_.setPosition(sf::Vector2f(startX, gapCenterY - pipeGap_ / 2.0f - topSprite_.getGlobalBounds().size.y));

    bottomSprite_.setScale(sf::Vector2f(scaleX, scaleY));
    bottomSprite_.setPosition(sf::Vector2f(startX, gapCenterY + pipeGap_ / 2.0f));
}

void Pipe::update(const sf::Time& dt)
{
    auto dx = -speed_ * dt.asSeconds();
    topSprite_.move(sf::Vector2f(dx, 0.0));
    bottomSprite_.move(sf::Vector2f(dx, 0.0));
}

void Pipe::draw(sf::RenderWindow& window) const
{
    window.draw(topSprite_);
    window.draw(bottomSprite_);
}

bool Pipe::isOffScreen() const
{
    return (bottomSprite_.getPosition().x + bottomSprite_.getGlobalBounds().size.x) < 0.0f;
}

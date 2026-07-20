#include "Game.h"
#include "DEFINITIONS.h"
#include "SFML/Graphics.hpp"
#include "Bird.h"
#include <optional>


Game::Game()
{
}

Game::~Game() = default;

void Game::run()
{

    window_.create(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), TITLE);
    window_.setFramerateLimit(60);

    while (window_.isOpen())
    {

        while (const std::optional<sf::Event> event = window_.pollEvent())
        {
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scan::Space)
                {
                     bird_.tap();
                }
            }

            if (event->is<sf::Event::Closed>())
            {
                window_.close();
            }
        }

            timePassed_ = clock_.restart();
            update();
            draw();
    }

}

void Game::update()
{
    bird_.update(timePassed_);
}

void Game::draw()
{
    window_.clear();
    bird_.draw(window_);
    window_.display();




}

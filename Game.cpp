#include "Game.h"
#include "DEFINITIONS.h"
#include "SFML/Graphics.hpp"
#include "Bird.h"
#include <optional>
#include <string>
#include "GameState.h"
#include "ResourceManager.h"
#include "MenuState.h"

Game::Game(int width, int height, std::string title)
{
    m_data->window.create(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), TITLE, sf::Style::Close | sf::Style::Titlebar);
    m_data->window.setVerticalSyncEnabled(true);
    m_data->machine.addState(std::make_unique<GameState>(m_data));
}

Game::~Game() = default;

void Game::run() {
    float newTime, frameTime, interpolation;
    float currentTime = this->clock_.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while (m_data->window.isOpen()) {
        m_data->machine.processStateChanges();

        newTime = this->clock_.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        if (frameTime > 0.25f) frameTime = 0.25f;

        currentTime = newTime;
        accumulator += frameTime;

        while (const std::optional<sf::Event> event = m_data->window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                m_data->window.close();
            }

            m_data->machine.getActiveState()->handleInput(*event);
        }
        while (accumulator >= timePerFrame.asSeconds()) {
            m_data->machine.getActiveState()->update(timePerFrame.asSeconds());
            accumulator -= timePerFrame.asSeconds();
        }

        interpolation = accumulator / timePerFrame.asSeconds();
        m_data->machine.getActiveState()->draw(interpolation);
    }
}

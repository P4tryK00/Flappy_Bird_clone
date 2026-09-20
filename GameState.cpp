#include "GameState.h"
#include "GameOverState.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "DEFINITIONS.h"

GameState::GameState(GameDataRef data)
    : m_data(data),
      background_(TextureManager::get("background_day")),
      ground_(TextureManager::get("ground")),
      m_score(0)
{
}

void GameState::init()
{
    auto bgBounds = background_.getLocalBounds();
    auto groundBounds = ground_.getLocalBounds();
    if (bgBounds.size.x > 0 && bgBounds.size.y > 0)
    {
        background_.setScale({
            static_cast<float>(SCREEN_WIDTH) / bgBounds.size.x,
            static_cast<float>(SCREEN_HEIGHT) / bgBounds.size.y
        });
    }
    if (groundBounds.size.x > 0 && groundBounds.size.y > 0)
    {
        float scaleX = static_cast<float>(SCREEN_WIDTH) / groundBounds.size.x;
        float scaleY = GROUND_HEIGHT / groundBounds.size.y;
        ground_.setScale({scaleX, scaleY});
        ground_.setPosition({0.0f, static_cast<float>(SCREEN_HEIGHT) - GROUND_HEIGHT});
    }

    m_score = 0;
    m_scoreText.emplace(FontManager::get("font"), "0", 70);
    m_scoreText->setFillColor(sf::Color::White);
    m_scoreText->setOutlineColor(sf::Color::Black);
    m_scoreText->setOutlineThickness(3.0f);
    auto bounds = m_scoreText->getLocalBounds();
    m_scoreText->setOrigin({bounds.position.x + bounds.size.x / 2.0f, bounds.position.y + bounds.size.y / 2.0f});
    m_scoreText->setPosition({SCREEN_WIDTH / 2.0f, 60.0f});

    m_pipeSpawnClock.restart();
}

void GameState::handleInput(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scan::Space)
        {
            m_bird.tap();
        }
    }

    if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mousePressed->button == sf::Mouse::Button::Left)
        {
            m_bird.tap();
        }
    }
}

void GameState::update(float dt)
{
    sf::Time time = sf::seconds(dt);
    m_bird.update(time);

    if (m_pipeSpawnClock.getElapsedTime().asSeconds() > 1.5f)
    {
        m_pipes.emplace_back(static_cast<float>(SCREEN_WIDTH));
        m_pipeSpawnClock.restart();
    }

    for (auto& pipe : m_pipes)
    {
        pipe.update(time);
    }

    sf::FloatRect birdBounds = m_bird.getBounds();

    // Collision with ground or ceiling
    if (birdBounds.position.y + birdBounds.size.y >= (static_cast<float>(SCREEN_HEIGHT) - GROUND_HEIGHT) || birdBounds.position.y <= 0.0f)
    {
        m_data->machine.addState(std::make_unique<GameOverState>(m_data, m_score), true);
        return;
    }

    // Collision with pipes
    for (const auto& pipe : m_pipes)
    {
        if (birdBounds.findIntersection(pipe.getTopBounds()) ||
            birdBounds.findIntersection(pipe.getBottomBounds()))
        {
            m_data->machine.addState(std::make_unique<GameOverState>(m_data, m_score), true);
            return;
        }
    }

    // Score counting
    for (auto& pipe : m_pipes)
    {
        if (!pipe.isScored() && birdBounds.position.x > pipe.getPositionX())
        {
            m_score++;
            pipe.setScored(true);

            if (m_scoreText)
            {
                m_scoreText->setString(std::to_string(m_score));
                auto bounds = m_scoreText->getLocalBounds();
                m_scoreText->setOrigin({bounds.position.x + bounds.size.x / 2.0f, bounds.position.y + bounds.size.y / 2.0f});
                m_scoreText->setPosition({SCREEN_WIDTH / 2.0f, 60.0f});
            }
        }
    }

    std::erase_if(m_pipes, [](const Pipe& pipe)
    {
        return pipe.isOffScreen();
    });
}

void GameState::draw(float dt)
{
    m_data->window.clear();

    m_data->window.draw(background_);

    for (const auto& pipe : m_pipes)
    {
        pipe.draw(m_data->window);
    }

    m_data->window.draw(ground_);

    m_bird.draw(m_data->window);

    if (m_scoreText)
    {
        m_data->window.draw(*m_scoreText);
    }

    m_data->window.display();
}

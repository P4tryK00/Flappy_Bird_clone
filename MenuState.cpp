#include "MenuState.h"
#include "GameState.h"
#include "DEFINITIONS.h"
#include "FontManager.h"
#include "TextureManager.h"

MenuState::MenuState(GameDataRef data)
    : m_data(data),
      m_alpha(0.f),
      m_isTransitioning(false),
      m_isFadingIn(false),
      m_goToLeaderboard(false)
{
}

void MenuState::init()
{
    m_background.emplace(TextureManager::get("background_day"));
    m_title.emplace(TextureManager::get("title"));
    m_playButton.emplace(TextureManager::get("play_button"));

    if (m_background) {
        auto bgBounds = m_background->getLocalBounds();

        if (bgBounds.size.x > 0 && bgBounds.size.y > 0) {
            m_background->setScale({
                static_cast<float>(SCREEN_WIDTH) / bgBounds.size.x,
                static_cast<float>(SCREEN_HEIGHT) / bgBounds.size.y
            });
        }
    }

    if (m_title) {
        auto titleBounds = m_title->getLocalBounds();
        m_title->setScale({2.0f, 2.0f});
        m_title->setOrigin({titleBounds.size.x / 2.f, titleBounds.size.y / 2.f});
        m_title->setPosition({SCREEN_WIDTH / 2.f, SCREEN_HEIGHT * 0.25f});

    }

    if (m_playButton) {
        auto btnBounds = m_playButton->getLocalBounds();
        m_playButton->setScale({2.0f, 2.0f});
        m_playButton->setOrigin({btnBounds.size.x / 2.f, btnBounds.size.y / 2.f});
        m_playButton->setPosition({SCREEN_WIDTH / 2.f, SCREEN_HEIGHT * 0.55f});
    }
}

void MenuState::handleInput(const sf::Event& event)
{
    if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        if (mousePressed->button == sf::Mouse::Button::Left) {
            if (m_playButton) {
                sf::Vector2f mousePos = m_data->window.mapPixelToCoords(mousePressed->position);
                if (m_playButton->getGlobalBounds().contains(mousePos)) {
                    m_data->machine.addState(std::make_unique<GameState>(m_data), true);
                }
            }
        }
    }

    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scan::Space || keyPressed->scancode == sf::Keyboard::Scan::Enter) {
            m_data->machine.addState(std::make_unique<GameState>(m_data), true);
        }
    }
}

void MenuState::update(float dt)
{
}

void MenuState::draw(float dt)
{
    m_data->window.clear();

    if (m_background) {
        m_data->window.draw(*m_background);
    }
    if (m_title) {
        m_data->window.draw(*m_title);
    }
    if (m_playButton) {
        m_data->window.draw(*m_playButton);
    }

    m_data->window.display();
}

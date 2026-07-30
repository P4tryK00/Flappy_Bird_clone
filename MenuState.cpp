#include "MenuState.h"
#include "GameState.h"
#include "DEFINITIONS.h"
#include "FontManager.h"
#include "TextureManager.h"


MenuState::MenuState(GameDataRef data) : m_data(data) {}


void MenuState::init()
{
    m_data->window.setView(m_data->window.getDefaultView());
    const sf::Texture& title = TextureManager::get("title");

    m_title.setTexture(title);
}

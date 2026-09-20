#include "ResourceManager.h"
#include "DEFINITIONS.h"
#include "FontManager.h"
#include "TextureManager.h"


void ResourceManager::cleanUpAllResources()
{
    TextureManager::cleanup();
    FontManager::cleanup();
}


void ResourceManager::loadAllResources()
{
    //Textures
    TextureManager::load("bird", BIRD_TEXTURE_PATH);
    TextureManager::load("title", TITLE_TEXTURE_PATH);
    TextureManager::load("background_day", BACKGROUND_DAY_TEXTURE_PATH);
    TextureManager::load("background_night", BACKGROUND_NIGHT_TEXTURE_PATH);
    TextureManager::load("PlayButton", PLAY_BUTTON_TEXTURE_PATH);
    TextureManager::load("play_button", PLAY_BUTTON_TEXTURE_PATH);
    TextureManager::load("play_button_pressed", PLAY_BUTTON_PRESSED_TEXTURE_PATH);
    TextureManager::load("pipe_upper", PIPE_UPPER_TEXTURE_PATH);
    TextureManager::load("pipe_bottom", PIPE_BOTTOM_TEXTURE_PATH);
    TextureManager::load("ground", GROUND_TEXTURE_PATH);

    //GameOver Textures
    TextureManager::load("game_over_title", GAME_OVER_TITLE_PATH);
    TextureManager::load("score_panel", SCORE_PANEL_PATH);
    TextureManager::load("medal_bronze", MEDAL_BRONZE_PATH);
    TextureManager::load("medal_silver", MEDAL_SILVER_PATH);
    TextureManager::load("medal_gold", MEDAL_GOLD_PATH);
    TextureManager::load("medal_platinum", MEDAL_PLATINUM_PATH);

    //fonts
    FontManager::load("font", FONT_PATH);
}

#include "ResourceManager.h"
#include "DEFINITIONS.h"
#include "FontManager.h"
#include "TextureManager.h"


void ResourceManager::cleanUpAllResources()
{
    TextureManager::cleanup();
}


void ResourceManager::loadAllResources()
{
    //Textures
    TextureManager::load("bird", BIRD_TEXTURE_PATH);
    TextureManager::load("title", TITLE_TEXTURE_PATH);

    //fonts
    FontManager::load("font", FONT_PATH);

    
}

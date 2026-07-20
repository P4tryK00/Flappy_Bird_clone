//
// Created by patryk on 20.07.2026.
//

#include "ResourceManager.h"

#include "TextureManager.h"


void ResourceManager::cleanUpAllResources()
{

}


void ResourceManager::cleanUp()
{
    TextureManager::cleanup();
    
}

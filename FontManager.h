#ifndef FLAPPY_BIRD_CLONE_FONTMANAGER_H
#define FLAPPY_BIRD_CLONE_FONTMANAGER_H

#include <string>
#include <map>
#include "SFML/Graphics.hpp"
#include <iostream>

class FontManager
{
public:
    FontManager() = delete;
    static void load(const std::string& key, const std::string& path);
    static const sf::Font& get(const std::string& key);
    static void cleanup();

private:
    static std::map<std::string, sf::Font> m_Font;
};


#endif //FLAPPY_BIRD_CLONE_FONTMANAGER_H

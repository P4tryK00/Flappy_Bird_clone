#ifndef FLAPPY_BIRD_CLONE_GAME_H
#define FLAPPY_BIRD_CLONE_GAME_H

#include <SFML/Graphics.hpp>
#include "Bird.h"
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "DEFINITIONS.h"


struct GameData {
    StateMachine machine;
    sf::RenderWindow window;
};

typedef std::shared_ptr<GameData> GameDataRef;


class Game
{
    public:
    Game();
    ~Game();

    void run();



    private:
    const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
    sf::Clock clock_;
    GameDataRef m_data = std::make_shared<GameData>();
};


#endif //FLAPPY_BIRD_CLONE_GAME_H

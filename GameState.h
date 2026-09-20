#ifndef FLAPPY_BIRD_CLONE_GAMESTATE_H
#define FLAPPY_BIRD_CLONE_GAMESTATE_H

#include <optional>
#include <vector>
#include "State.h"
#include "Game.h"
#include "Bird.h"
#include "Pipe.h"


class GameState : public State
{
public:
    GameState(GameDataRef data);

    void init() override;
    void handleInput(const sf::Event& event) override;
    void update(float dt) override;
    void draw(float dt) override;

private:
    GameDataRef m_data;
    Bird m_bird;
    std::vector<Pipe> m_pipes;
    sf::Clock m_pipeSpawnClock;
    sf::Sprite background_;
    sf::Sprite ground_;

    int m_score = 0;
    std::optional<sf::Text> m_scoreText;
};

#endif //FLAPPY_BIRD_CLONE_GAMESTATE_H

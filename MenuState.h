#ifndef FLAPPY_BIRD_CLONE_MENUSTATE_H
#define FLAPPY_BIRD_CLONE_MENUSTATE_H

#include <optional>
#include "State.h"
#include "Game.h"

class MenuState : public State {
public:
    MenuState(GameDataRef data);

    void init() override;
    void handleInput(const sf::Event& event) override;
    void update(float dt) override;
    void draw(float dt) override;

private:
    GameDataRef m_data;

    std::optional<sf::Sprite> m_background;
    std::optional<sf::Sprite> m_title;
    std::optional<sf::Sprite> m_playButton;
    std::optional<sf::Sprite> m_playButtonPressed;

    sf::RectangleShape m_fadeRect;
    float m_alpha;
    bool m_isTransitioning;
    bool m_isFadingIn;
    bool m_goToLeaderboard;
};

#endif //FLAPPY_BIRD_CLONE_MENUSTATE_H

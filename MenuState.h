#ifndef FLAPPY_BIRD_CLONE_MENUSTATE_H
#define FLAPPY_BIRD_CLONE_MENUSTATE_H

#ifndef MINI_GOLF_MAINMENUSTATE_H
#define MINI_GOLF_MAINMENUSTATE_H

#include "State.h"
#include "Game.h"


class MenuState : public State {
public:

    MenuState(GameDataRef data);

    void init() override;
    void handleInput(sf::Event& event) override;
    void update(float dt) override;
    void draw(float dt) override;

private:
    GameDataRef m_data;

    sf::Sprite m_background;

    sf::Sprite m_title;
    sf::Sprite m_playButton;
    sf::Sprite m_playButtonPressed;



    sf::RectangleShape m_fadeRect;
    float m_alpha;
    bool m_isTransitioning;
    bool m_isFadingIn;
    bool m_goToLeaderboard;
};

#endif //MINI_GOLF_MAINMENUSTATE_H


#endif //FLAPPY_BIRD_CLONE_MENUSTATE_H

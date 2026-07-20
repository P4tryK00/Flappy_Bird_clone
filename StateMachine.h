//
// Created by patryk on 20.07.2026.
//

#ifndef FLAPPY_BIRD_CLONE_STATEMACHINE_H
#define FLAPPY_BIRD_CLONE_STATEMACHINE_H


#include <stack>
#include <memory>
#include "State.h"


typedef std::unique_ptr<State> StateRef;
class StateMachine {
public:
    StateMachine() : m_isRemoving(false), m_isAdding(false), m_isReplacing(false) {}
    ~StateMachine() {}

    void addState(StateRef newState, bool isReplacing = true);
    void removeState();
    void processStateChanges();
    void switchState(StateRef newState);

    StateRef& getActiveState();

private:
    std::stack<StateRef> m_states;
    StateRef m_newState;
    bool m_isRemoving;
    bool m_isAdding;
    bool m_isReplacing;
    bool m_isClearing;
};


#endif //FLAPPY_BIRD_CLONE_STATEMACHINE_H

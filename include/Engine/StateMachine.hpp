#pragma once

#include <memory>
#include <stack>
#include "Engine/State.hpp"

using StateRef = std::unique_ptr<State>;

/*
    manage states of the Game
*/

class StateMachine
{
public:
    StateMachine() {}

    void addState(StateRef newState, bool isReplacing = true);

    void removeState();

    void processStateChanges();

    StateRef &getActiveState();

private:
    std::stack<StateRef> states;

    StateRef newState;

    bool isAdding;

    bool isReplacing;

    bool isRemoving;
};
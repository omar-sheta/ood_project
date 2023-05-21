#pragma once
#include "fsm.h"
#include "state.h"
#include "transition.h"

using namespace std;

class FSMFactory {
public:
    static shared_ptr<FSM> create(vector<shared_ptr<State>> states, vector<shared_ptr<Transition>> transitions, shared_ptr<State> initialState);
};
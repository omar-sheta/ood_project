#pragma once
#include "fsm.h"

using namespace std;

class FSMFactory
{
public:
    static shared_ptr<FSM> create(string name, vector<shared_ptr<State>> states, vector<shared_ptr<Transition>> transitions, vector<shared_ptr<Variable>> variables, shared_ptr<State> initialState, int initialValue);
};
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "transition.h"

using namespace std;
class FSM
{
private:
    vector<shared_ptr<State>> states;
    vector<shared_ptr<Transition>> transitions;
    shared_ptr<State> current_state;

public:
    FSM() {}
    void add_state(shared_ptr<State> state);
    void add_transition(shared_ptr<Transition> transition);
    void set_current_state(shared_ptr<State> state);
    void execute_next_step();
};
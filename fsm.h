#pragma once
#include <iostream>
#include <vector>
#include "transition.h"

using namespace std;
class FSM
{
private:
    string name;
    vector<shared_ptr<State>> states;
    vector<shared_ptr<Transition>> transitions;
    vector<shared_ptr<Variable>> variables;
    shared_ptr<State> current_state;
    int current_value;

public:
    FSM();
    ~FSM();
    FSM(string name, vector<shared_ptr<State>> states, vector<shared_ptr<Transition>> transitions, vector<shared_ptr<Variable>> variables, shared_ptr<State> current_state, int current_value);
    void add_state(shared_ptr<State> state);
    void add_transition(shared_ptr<Transition> transition);
    vector<shared_ptr<State>> get_states();
    vector<shared_ptr<Transition>> get_transitions();
    vector<shared_ptr<Variable>> get_variables();
    shared_ptr<State> get_current_state();
    void set_current_state(shared_ptr<State> state);
    void set_current_value(int value);
    void execute_next_step();
};
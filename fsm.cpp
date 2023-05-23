#include "fsm.h"

FSM::FSM()
{
    current_state = nullptr;
}

FSM::~FSM()
{
    states.clear();
    transitions.clear();
}

FSM::FSM(string name, vector<shared_ptr<State>> states, vector<shared_ptr<Transition>> transitions, vector<shared_ptr<Variable>> variables, shared_ptr<State> current_state, int current_value)
{
    this->name = name;
    this->states = states;
    this->transitions = transitions;
    this->variables = variables;
    this->current_state = current_state;
    this->current_value = current_value;
}

void FSM::add_state(shared_ptr<State> state)
{
    states.push_back(state);
}

void FSM::add_transition(shared_ptr<Transition> transition)
{
    transitions.push_back(transition);
}

void FSM::set_current_state(shared_ptr<State> state)
{
    current_state = state;
}

void FSM::execute_next_step()
{
    // use this to create a shared pointer to current fsm object
    shared_ptr<FSM> fsm = shared_from_this();
    current_state->execute_operations(fsm);


    // // Find the next transition based on the current value
    // shared_ptr<Transition> nextTransition = nullptr;
    // for (const auto &transition : transitions)
    // {
    //     if (transition->get_source_state() == current_state && transition->get_input_value() == current_value)
    //     {
    //         nextTransition = transition;
    //         break;
    //     }
    // }

    // if (nextTransition)
    // {
    //     // Change the current state to the destination state of the transition
    //     current_state = nextTransition->get_destination_state();
    // }
    // else
    // {
    //     cout << "No valid transition found. Exiting." << endl;
    //     return;
    // }
}
vector<shared_ptr<State>> FSM::get_states()
{
    return states;
}

vector<shared_ptr<Transition>> FSM::get_transitions()
{
    return transitions;
}

vector<shared_ptr<Variable>> FSM::get_variables()
{
    return variables;
}
void FSM::set_current_value(int value)
{
    current_value = value;
}
shared_ptr<State> FSM::get_current_state()
{
    return current_state;
}
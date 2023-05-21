#include "fsm.h"

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
    current_state->enter();

    int input;
    cin >> input;

    for (const auto &transition : transitions)
    {
        if (transition->get_source_state() == current_state && transition->get_input_value() == input)
        {
            current_state = transition->get_destination_state();
            break;
        }
    }

    current_state->exit();
}

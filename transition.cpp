#include "transition.h"

Transition::Transition(shared_ptr<State> source_state, shared_ptr<State> destination_state, int input_value)
    : source_state(source_state), destination_state(destination_state), input_value(input_value) {}

void Transition::trigger()
{
    cout << "Triggering transition from " << source_state->get_name() << " to " << destination_state->get_name() << endl;
}

shared_ptr<State> Transition::get_source_state() const
{
    return source_state;
}

shared_ptr<State> Transition::get_destination_state() const
{
    return destination_state;
}

int Transition::get_input_value() const
{
    return input_value;
}
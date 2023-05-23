#include "jump.h"

bool isPathPossible(shared_ptr<FSM> fsm, shared_ptr<State> source, shared_ptr<State> destination)
{
    if (source == destination)
    {
        return true;
    }

    for (auto transition : fsm->get_transitions())
    {
        if (transition->get_source_state() == source)
        {
            if (isPathPossible(fsm, transition->get_destination_state(), destination))
            {
                return true;
            }
        }
    }

    return false;
}

void Jump::execute(shared_ptr<FSM> fsm)
{
    bool isState = false;
    for (auto &state : fsm->get_states())
    {
        if (state->get_name() == this->state)
        {
            isState = true;
            break;
        }
    }

    if (!isState)
    {
        cout << "Invalid state name: " << this->state << endl;
        exit(1);
    }

    shared_ptr<State> currentState = fsm->get_current_state();
    shared_ptr<State> destinationState;

    for (auto state : fsm->get_states())
    {
        if (state->get_name() == this->state)
        {
            destinationState = state;
            break;
        }
    }

    if (!isPathPossible(fsm, currentState, destinationState))
    {
        cout << "Path is not possible" << endl;
        exit(1);
    }

    fsm->set_current_state(destinationState);
}

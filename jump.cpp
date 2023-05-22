#include "jump.h"

bool isPathPossible(shared_ptr<FSM> fsm, shared_ptr<State> source, shared_ptr<State> destination)
{
    if (source == destination)
    {
        return true;
    }

    for (auto transition : fsm->get_transitions())
    {
        if (transition->get_source_state() == fsm->get_current_state())
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
        }
    }
    if (!isState)
    {
        cout << "Invalid state name: " << this->state << endl;
        exit(1);
    }
    for (auto state : fsm->get_states())
    {
        if (state->get_name() == this->state)
        {
            if (isPathPossible(fsm, fsm->get_current_state(), state))
            {
                fsm->set_current_state(state);
                return;
            }
            else
            {
                cout << "Path is not possible" << endl;
                exit(1);
            }
        }
    }
}

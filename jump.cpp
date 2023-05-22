#include "jump.h"

void Jump::execute(shared_ptr<FSM> fsm)
{

    // loop through transition vector and see if a path (through multiple transitions) exists to the state
    for (auto transition : fsm->get_transitions())
    {
        if (transition->get_source_state()->get_name() == fsm->get_current_state()->get_name() && transition->get_destination_state()->get_name() == state)
        {
            fsm->set_current_state(transition->get_destination_state());
            break;
        }
    }
}

#include "FsmFactory.h"

shared_ptr<FSM> FSMFactory::create(vector<shared_ptr<State>> states, vector<shared_ptr<Transition>> transitions, shared_ptr<State> initialState)
{
    shared_ptr<FSM> fsm = make_shared<FSM>();
    for (const auto &state : states)
    {
        fsm->add_state(state);
    }
    for (const auto &transition : transitions)
    {
        fsm->add_transition(transition);
    }
    fsm->set_current_state(initialState);
    return fsm;
}
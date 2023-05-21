#include "FsmFactory.h"

static shared_ptr<FSM> createcreate(string name, vector<shared_ptr<State>> states, vector<shared_ptr<Transition>> transitions, vector<shared_ptr<Variable>> variables, shared_ptr<State> initialState)
{
    return make_shared<FSM>(name, states, transitions, variables, initialState);
}
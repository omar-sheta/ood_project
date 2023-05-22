#include "state.h"

void State::enter()
{
    cout << "Entering state " << name << endl;
}

void State::exit()
{
    cout << "Exiting state " << name << endl;
}

string State::get_name() const
{
    return name;
}

vector<shared_ptr<Operation>> State::get_operations() const
{
    return operations;
}
void State::execute_operations(shared_ptr<FSM> fsm)
{
    for (auto operation : operations)
    {
        operation->execute(fsm);
    }
}
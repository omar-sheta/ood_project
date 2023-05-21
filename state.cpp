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

#include "wait.h"

void Wait::execute(shared_ptr<FSM> fsm)
{
    cout << "Enter input value: ";
    int value;
    cin >> value;
    fsm->set_current_value(value);
}

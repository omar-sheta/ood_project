#include "print.h"

void Print::setMessage(string message)
{
    this->message = message;
}
void Print::execute(shared_ptr<FSM> fsm, shared_ptr<Variable> variable)
{
    cout << message << endl;
}

std::string Print::get_name() const
{
    return "PRINT";
}

// Path: print.h
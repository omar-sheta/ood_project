#include "print.h"

void Print::setMessage(string message)
{
    this->message = message;
}
void Print::execute(shared_ptr<FSM> fsm)
{
    cout << message << endl;
}

std::string Print::get_name() const
{
    return "PRINT";
}

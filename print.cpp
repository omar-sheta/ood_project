#include "print.h"

void Print::setMessage(string message)
{
    this->message = message;
}
void Print::execute() const
{
    cout << message << endl;
}

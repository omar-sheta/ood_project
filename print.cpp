#include "print.h"

void Print::setMessage(string message)
{
    this->message = message;
}
void Print::execute(shared_ptr<FSM> fsm)
{
    // check if it is a variable
    // check if there is quotes
    if (message[0] == '\"' && message[message.length() - 1] == '\"')
    {
        message = message.substr(1, message.length() - 2);
        cout << message << endl;
    }
    else
    {
        for (auto var : fsm->get_variables())
        {
            if (var->get_name() == message)
            {
                message = to_string(var->get_value());

                cout << message << endl;
                break;
            }
        }
    }
}

std::string Print::get_name() const
{
    return "PRINT";
}

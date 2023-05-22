#include "arithmetic.h"

void Arithmetic::execute(shared_ptr<FSM> fsm, shared_ptr<Variable> variable)
{
    if (get_name() == "add")
    {
        variable->set_value(num1 + num2);
    }
    else if (get_name() == "multi")
    {
        variable->set_value(num1 * num2);
    }
}

void Arithmetic::setNum1(int num1)
{
    this->num1 = num1;
}
void Arithmetic::setNum2(int num2)
{
    this->num2 = num2;
}
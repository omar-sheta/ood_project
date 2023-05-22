#include "arithmetic.h"

void Arithmetic::execute(shared_ptr<FSM> fsm)
{

    vector<shared_ptr<Variable>> variables = fsm->get_variables();
    shared_ptr<Variable> variable = nullptr;
    for (auto v : variables)
    {
        if (v->get_name() == result)
        {
            variable = v;
            break;
        }
    }
    if (get_name() == "ADD")
    {
        variable->set_value(num1 + num2);
    }
    else if (get_name() == "MULTI")
    {
        variable->set_value(num1 * num2);
    }
    // update the variable value in the fsm
    for (auto variable : fsm->get_variables())
    {
        if (variable->get_name() == result)
        {
            variable->set_value(variable->get_value());
            break;
        }
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
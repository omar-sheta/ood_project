#include "arithmetic.h"

void Arithmetic::execute(shared_ptr<FSM> fsm)
{

    vector<shared_ptr<Variable>> variables = fsm->get_variables();
    shared_ptr<Variable> variable = nullptr;
    bool isVariable1 = false;
    int first_operand_value;
    for (auto &variable : variables)
    {
        if (variable->get_name() == num1)
        {
            isVariable1 = true;
            first_operand_value = variable->get_value();
        }
    }
    if (!isVariable1)
    {
        if (!isdigit(num1[0]))
        {
            cout << "Invalid first operand: " << num1 << endl;
            exit(1);
        }
        else
        {
            first_operand_value = stoi(num1);
        }
    }
    bool isVariable2 = false;
    int second_operand_value;
    for (auto &variable : variables)
    {
        if (variable->get_name() == num2)
        {
            isVariable2 = true;
            second_operand_value = variable->get_value();
        }
    }
    if (!isVariable2)
    {
        if (!isdigit(num2[0]))
        {
            cout << "Invalid second operand: " << num2 << endl;
            exit(1);
        }
        else
        {
            second_operand_value = stoi(num2);
        }
    }
    int result_value;
    if (get_name() == "ADD")
    {
        result_value = first_operand_value + second_operand_value;
    }
    else if (get_name() == "MULTI")
    {
        result_value = first_operand_value * second_operand_value;
    }
    else
    {
        cout << "Invalid operation: " << get_name() << endl;
        exit(1);
    }

    for (auto &variable : variables)
    {
        if (variable->get_name() == result)
        {
            variable->set_value(result_value);
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
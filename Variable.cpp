#include "Variable.h"

Variable::Variable(string name, string value) : name(name), value(value) {}

string Variable::get_name() const
{
    return name;
}

string Variable::get_value() const
{
    return value;
}

void Variable::set_value(string value)
{
    this->value = value;
}


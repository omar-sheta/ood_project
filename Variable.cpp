#include "Variable.h"

Variable::Variable(string name) : name(name), value(0) {}

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


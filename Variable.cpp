#include "Variable.h"

Variable::Variable(string name) : name(name), value(0) {}

string Variable::get_name() const
{
    return name;
}

int Variable::get_value() const
{
    return value;
}

void Variable::set_value(int value)
{
    this->value = value;
}

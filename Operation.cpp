#pragma once
#include "Operation.h"

Operation::Operation(string name) : name(name) {}

string Operation::get_name() const
{
    return name;
}

void Operation::execute() const
{
}
#pragma once

#include <iostream>
#include "Operation.h"
#include "Variable.h"
using namespace std;

// arithmetic operation either add or multi that inherits from Operation
class Arithmetic : public Operation
{
private:
    int num1;
    int num2;

public:
    Arithmetic(string name, int num1, int num2) : Operation(name), num1(num1), num2(num2) {}
    void execute(Variable &result) const;
    ~Arithmetic() {}
    void setNum1(int num1);
    void setNum2(int num2);
};
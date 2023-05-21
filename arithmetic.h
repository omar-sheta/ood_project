#pragma once

#include <iostream>
#include "Operation.h"
using namespace std;

// arithmetic operation either add or multi that inherits from Operation
class Arithmetic : public Operation
{
private:
    int num1;
    int num2;

public:
    Arithmetic(string name, int num1, int num2) : Operation(name), num1(num1), num2(num2) {}
    void execute() const;
    ~Arithmetic() {}
};
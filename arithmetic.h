#pragma once

#include <iostream>
#include "Operation.h"
// #include "Variable.h"
#include "fsm.h"
using namespace std;

// arithmetic operation either add or multi that inherits from Operation
class Arithmetic : public Operation
{
private:
    string result;
    int num1;
    int num2;

public:
    Arithmetic(string name, int num1, int num2, string result) : Operation(name), num1(num1), num2(num2), result(result) {}
    void execute(shared_ptr<FSM> fsm) override;
    ~Arithmetic() {}
    void setNum1(int num1);
    void setNum2(int num2);
};
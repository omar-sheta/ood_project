#pragma once

#include <iostream>
#include "Operation.h"
using namespace std;

// print operation that inherits from Operation
class Print : public Operation
{
private:
    string message;

public:
    Print(string message) : Operation("Print"), message(message) {}
    void execute() const;
    ~Print() {}
};

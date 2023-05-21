#pragma once

#include <iostream>
#include "Operation.h"

using namespace std;

class Wait : public Operation
{
private:
    int time;

public:
    Wait(string name, int time) : Operation(name), time(time) {}
    void execute() const;
    ~Wait() {}
    void setTime(int time);
};

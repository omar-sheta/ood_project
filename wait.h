#pragma once

#include <iostream>
#include "Operation.h"
// #include "fsm.h"

using namespace std;

class Wait : public Operation
{
private:
    int time;

public:
    Wait(string name, int time, FSM &fsm) : Operation(name), time(time) {}
    void execute(FSM &fsm) const;
    ~Wait() {}
    void setTime(int time);
};

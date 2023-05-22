#pragma once

#include <iostream>
#include "Operation.h"
using namespace std;
#include <chrono>
#include <thread>

// Delay for 1 second

// sleep operation that inherits from Operation
class Sleep : public Operation
{
private:
    int seconds;

public:
    Sleep(string name, int seconds) : Operation(name), seconds(seconds) {}
    void execute(shared_ptr<FSM> fsm) override;
    void setSeconds(int seconds);
    ~Sleep() {}
};

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
    Sleep(int seconds) : Operation("Sleep"), seconds(seconds) {}
    void execute() const;
    void setSeconds(int seconds);
    ~Sleep() {}
};

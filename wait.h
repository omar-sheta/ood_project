#pragma once

#include <iostream>
#include "Operation.h"
#include "fsm.h"

using namespace std;

class Wait : public Operation
{

public:
    Wait(string name) : Operation(name) {}
    void execute(shared_ptr<FSM> fsm, shared_ptr<Variable> variable) override;
    ~Wait() {}
};

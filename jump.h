#pragma once

#include <iostream>
#include "Operation.h"
#include "Variable.h"
#include "fsm.h"
using namespace std;

class Jump : public Operation
{
private:
    string state;

public:
    Jump(string name, string state) : Operation(name), state(state) {}
    void execute(shared_ptr<FSM> fsm) override;
    ~Jump() {}
    void setState(string state);
};
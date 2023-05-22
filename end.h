#pragma once
#include "Operation.h"

using namespace std;

class End : public Operation
{
public:
    End(string name) : Operation(name) {}
    void execute(shared_ptr<FSM> fsm) override;
    
    ~End() {}
};
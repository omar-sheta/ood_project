#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "Variable.h"
#include "Operation.h"

using namespace std;

class State
{
private:
    string name;
    vector<shared_ptr<Operation>> operations;

public:
    State(string name, vector<shared_ptr<Operation>> operations) : name(name), operations(operations) {}
    virtual ~State() {}
    virtual void enter();
    virtual void exit();
    string get_name() const;
    vector<shared_ptr<Operation>> get_operations() const;
    void execute_operations(shared_ptr<FSM> fsm);
};

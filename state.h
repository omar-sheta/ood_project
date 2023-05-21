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
    vector<shared_ptr<Variable>> variables;

public:
    State(string name, vector<shared_ptr<Operation>> operations, vector<shared_ptr<Variable>> variables) : name(name), operations(operations), variables(variables) {}
    virtual ~State() {}
    virtual void enter();
    virtual void exit();
    string get_name() const;
};

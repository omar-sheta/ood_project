#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "Variable.h"

using namespace std;

class State
{
private:
    string name;
    vector<string> operations;
    vector<Variable> variables;
    

public:
    State(string name) : name(name) {}
    virtual ~State() {}
    virtual void enter();
    virtual void exit();
    string get_name() const;
};

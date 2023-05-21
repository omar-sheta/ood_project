#pragma once

#include <iostream>

using namespace std;

class Operation
{
private:
    string name;

public:
    Operation(string name) : name(name) {}
    virtual ~Operation() {}
    virtual void execute() const;
    string get_name() const;
};

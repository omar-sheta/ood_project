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
    string get_name() const;
};

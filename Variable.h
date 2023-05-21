#pragma once
#include <iostream>

using namespace std;

class Variable
{
private:
    string name;
    string value;
public:
    Variable(string name) {}
    virtual ~Variable() {}
    string get_name() const;
    string get_value() const;
    void set_value(string value);
};
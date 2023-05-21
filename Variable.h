#pragma once
#include <iostream>

using namespace std;

class Variable
{
private:
    string name;
    int value;

public:
    Variable(string name);
    string get_name() const;
    int get_value() const;
    void set_value(int value);
};
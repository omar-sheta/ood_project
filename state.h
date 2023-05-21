#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <memory>

using namespace std;

class State
{
private:
    string name;

public:
    State(string name) : name(name) {}
    virtual ~State() {}
    virtual void enter();
    virtual void exit();
    string get_name() const;
};

#pragma once

#include <memory>
#include <iostream>

class FSM;      // Forward declaration of FSM class
class Variable; // Forward declaration of Variable class
class Operation
{
private:
    std::string name;

public:
    Operation(std::string name) : name(name) {}
    virtual ~Operation() {}
    virtual void execute(std::shared_ptr<FSM> fsm) = 0;
    virtual std::string get_name() const;
};

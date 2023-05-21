#pragma once

#include <iostream>
#include "Operation.h"
using namespace std;

// print operation that inherits from Operation
class Print : public Operation
{
private:
    string message;

public:
    Print(string name, string message) : Operation(name), message(message) {}
    void execute(shared_ptr<FSM> fsm) override;
    void setMessage(string message);
    std::string get_name() const;
    ~Print() {}
};

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "state.h"

using namespace std;
class Transition
{
private:
    shared_ptr<State> source_state;
    shared_ptr<State> destination_state;
    int input_value;

public:
    Transition(shared_ptr<State> source_state, shared_ptr<State> destination_state, int input_value);
    void trigger();
    shared_ptr<State> get_source_state() const;
    shared_ptr<State> get_destination_state() const;
    int get_input_value() const;
};
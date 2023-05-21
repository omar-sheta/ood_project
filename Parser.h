#pragma once
#include <iostream>
#include <fstream>
#include "Transition.h"
#include "State.h"
#include "FsmFactory.h"
#include "Operation.h"
#include "Variable.h"
using namespace std;
#include "fsm.h"
class Parser
{
public:
  Parser(string filename);
  string filename;
  FSM get_fsm();
};

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "transition.h"
#include "print.h"
#include "FsmFactory.h"
using namespace std;

class Parser
{
public:
  Parser(string filename);
  string filename;
  shared_ptr<FSM> get_fsm();
};

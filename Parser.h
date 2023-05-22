#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "transition.h"
#include "print.h"
#include "arithmetic.h"
#include "wait.h"
#include "sleep.h"
#include "end.h"
#include "jump.h"
#include "FsmFactory.h"
using namespace std;

class Parser
{
public:
  Parser(string filename);
  string filename;
  shared_ptr<FSM> get_fsm();
};

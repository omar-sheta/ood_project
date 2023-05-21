#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "fsm.h"
class Parser {
public:
  Parser(string file_name);
  FSM get_fsm() { return fsm; }
private:
    FSM fsm;
    };


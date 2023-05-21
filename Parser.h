#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "fsm.h"
class Parser {
private:
    Parser(string filename);
    string filename;

public:
  FSM get_fsm();
};



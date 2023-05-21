#include "fsm.h"
#include "state.h"
#include "transition.h"
#include "Parser.h"

using namespace std;

int main()
{
  string file_name;

  file_name = "fsm1.txt";
  Parser parser(file_name);

  FSM fsm = parser.get_fsm();

  cout << "FSM: " << endl;
  // print states
  cout << "States: " << endl;
  for (auto state : fsm.get_states())
  {
    cout << state->get_name() << endl;
  }
}

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
  cout << "Transitions:" << endl;
  // print transitions
  for (auto transition : fsm.get_transitions())
  {
    cout << transition->get_source_state()->get_name() << " -> " << transition->get_destination_state()->get_name() << endl;
  }
  cout << "Variables" << endl;
  for (auto variable : fsm.get_variables())
  {
    cout << variable->get_name() << endl;
  }
}

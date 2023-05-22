
#include "Parser.h"

using namespace std;

int main()
{
  string file_name;

  file_name = "fsm1.txt";
  Parser parser(file_name);

  shared_ptr<FSM> fsm = parser.get_fsm();

  cout << "FSM: " << endl;
  // print states
  cout << "States: " << endl;
  for (auto state : fsm->get_states())
  {
    cout << state->get_name() << endl;
  }

  cout << "Transitions:" << endl;

  for (auto transition : fsm->get_transitions())
  {
    cout << transition->get_source_state()->get_name() << " -> " << transition->get_destination_state()->get_name() << endl;
  }
  cout << "Variables" << endl;
  for (auto variable : fsm->get_variables())
  {
    cout << variable->get_name() << endl;
  }
  cout << "Operations" << endl;
  for (auto states : fsm->get_states())
  {
    cout << "State: " << states->get_name() << endl;
    for (auto operation : states->get_operations())
    {
      string name = operation->get_name();

      if (name.find("PRINT") != string::npos)
      {
        operation->execute(fsm);
      }
      else if (name.find("ADD") != string::npos || name.find("MULTI") != string::npos)
      {
        operation->execute(fsm);
      }
    }
  }
  // print out the variables values
  cout << "Variables" << endl;
  for (auto variable : fsm->get_variables())
  {
    cout << variable->get_name() << " = " << variable->get_value() << endl;
  }
}

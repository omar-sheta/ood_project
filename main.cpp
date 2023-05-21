#include "fsm.h"
#include "state.h"
#include "transition.h"

using namespace std;

// Transitions:
// a, b, 1
// b, a, 2
// a, a, 2
// b, b, 1
// b, c, 3

class Parser
{
  // parse the file and create the states and transitions
  // create the FSM
  // return the FSM
  Parser(string file_name);
  FSM getFSM();

private:
  FSM fsm;
};

Parser::Parser(string file_name)
{
  // parse the file and create the states and transitions
  // create the FSM
  // return the FSM
  // fsm = new FSM();
  map<string, shared_ptr<State>> states;
  map<string, shared_ptr<Transition>> transitions;
  shared_ptr<State> state1 = make_shared<State>("state1");
  shared_ptr<State> state2 = make_shared<State>("state2");
  shared_ptr<State> state3 = make_shared<State>("state3");
  shared_ptr<State> state4 = make_shared<State>("state4");

  fsm.add_state(state1);
  fsm.add_state(state2);
  fsm.add_state(state3);
  fsm.add_state(state4);

  shared_ptr<Transition> transition1 = make_shared<Transition>(state1, state2, 1);
  shared_ptr<Transition> transition2 = make_shared<Transition>(state2, state1, 2);
  shared_ptr<Transition> transition3 = make_shared<Transition>(state2, state3, 3);
  shared_ptr<Transition> transition4 = make_shared<Transition>(state3, state4, 4);
  shared_ptr<Transition> transition5 = make_shared<Transition>(state4, state1, 5);

  vector<shared_ptr<Transition>> transitions_vec;
  transitions_vec.push_back(transition1);
  transitions_vec.push_back(transition2);
  transitions_vec.push_back(transition3);
  transitions_vec.push_back(transition4);
  transitions_vec.push_back(transition5);

  for (const auto &transition : transitions_vec)
  {
    fsm.add_transition(transition);
  }
}

int main()
{
  FSM fsm;
  shared_ptr<State> state1 = make_shared<State>("state1");
  shared_ptr<State> state2 = make_shared<State>("state2");
  shared_ptr<State> state3 = make_shared<State>("state3");
  shared_ptr<State> state4 = make_shared<State>("state4");

  fsm.add_state(state1);
  fsm.add_state(state2);
  fsm.add_state(state3);
  fsm.add_state(state4);

  shared_ptr<Transition> transition1 = make_shared<Transition>(state1, state2, 1);
  shared_ptr<Transition> transition2 = make_shared<Transition>(state2, state1, 2);
  shared_ptr<Transition> transition3 = make_shared<Transition>(state2, state3, 3);
  shared_ptr<Transition> transition4 = make_shared<Transition>(state3, state4, 4);
  shared_ptr<Transition> transition5 = make_shared<Transition>(state4, state1, 5);

  vector<shared_ptr<Transition>> transitions;
  transitions.push_back(transition1);
  transitions.push_back(transition2);
  transitions.push_back(transition3);
  transitions.push_back(transition4);
  transitions.push_back(transition5);

  for (const auto &transition : transitions)
  {
    fsm.add_transition(transition);
  }

  fsm.set_current_state(state1);

  while (true)
  {
    fsm.execute_next_step();
  }

  return 0;
}

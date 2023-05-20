#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class State;
class Transition;

// Transitions:
// a, b, 1 
// b, a, 2 
// a, a, 2 
// b, b, 1 
// b, c, 3

class Parser{
    // parse the file and create the states and transitions
    // create the FSM
    // return the FSM
    Parser(string file_name);
    FSM getFSM();

private:
    FSM fsm;


};

Parser::Parser(string file_name){
    // parse the file and create the states and transitions
    // create the FSM
    // return the FSM
    //fsm = new FSM();
    map <string, shared_ptr<State> > states;
    map <string, shared_ptr<Transition> > transitions;
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

    vector<shared_ptr<Transition> > transitions;
    transitions.push_back(transition1);
    transitions.push_back(transition2);
    transitions.push_back(transition3);
    transitions.push_back(transition4);
    transitions.push_back(transition5);

    for (const auto& transition : transitions) {
      fsm.add_transition(transition);
    }  
}

class FSM {
public:
  FSM() {}

  void add_state(shared_ptr<State> state);
  void add_transition(shared_ptr<Transition> transition);
  void set_current_state(shared_ptr<State> state);
  void execute_next_step();

private:
  vector<shared_ptr<State> > states;
  vector<shared_ptr<Transition> > transitions;
  shared_ptr<State> current_state;
};

class State {
public:
  State(string name) : name(name) {}
  virtual ~State() {}

  virtual void enter();
  virtual void exit();
  string get_name() const;

private:
  string name;
};

class Transition {
public:
  Transition(shared_ptr<State> source_state, shared_ptr<State> destination_state, int input_value);
  void trigger();
  shared_ptr<State> get_source_state() const;
  shared_ptr<State> get_destination_state() const;
  int get_input_value() const;

private:
  shared_ptr<State> source_state;
  shared_ptr<State> destination_state;
  int input_value;
};

void FSM::add_state(shared_ptr<State> state) {
  states.push_back(state);
}

void FSM::add_transition(shared_ptr<Transition> transition) {
  transitions.push_back(transition);
}

void FSM::set_current_state(shared_ptr<State> state) {
  current_state = state;
}

void FSM::execute_next_step() {
  current_state->enter();

  int input;
  cin >> input;

  for (const auto& transition : transitions) {
    if (transition->get_source_state() == current_state && transition->get_input_value() == input) {
      current_state = transition->get_destination_state();
      break;
    }
  }

  current_state->exit();
}

void State::enter() {
  cout << "Entering state " << name << endl;
}

void State::exit() {
  cout << "Exiting state " << name << endl;
}

string State::get_name() const {
  return name;
}

Transition::Transition(shared_ptr<State> source_state, shared_ptr<State> destination_state, int input_value)
    : source_state(source_state), destination_state(destination_state), input_value(input_value) {}

void Transition::trigger() {
  cout << "Triggering transition from " << source_state->get_name() << " to " << destination_state->get_name() << endl;
}

shared_ptr<State> Transition::get_source_state() const {
  return source_state;
}

shared_ptr<State> Transition::get_destination_state() const {
  return destination_state;
}

int Transition::get_input_value() const {
  return input_value;
}

int main() {
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

    vector<shared_ptr<Transition> > transitions;
    transitions.push_back(transition1);
    transitions.push_back(transition2);
    transitions.push_back(transition3);
    transitions.push_back(transition4);
    transitions.push_back(transition5);

    for (const auto& transition : transitions) {
      fsm.add_transition(transition);
    }  


  fsm.set_current_state(state1);

  while (true) {
    fsm.execute_next_step();
  }

  return 0;
}

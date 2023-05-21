#include <fstream>
#include <iostream>
#include "Parser.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

Parser::Parser(string filename) : filename(filename) {}

vector<string> split(const string &s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

FSM Parser::get_fsm()
{
    // create a vector of states
    vector<shared_ptr<State>> states;
    // create a vector of transitions
    vector<shared_ptr<Transition>> transitions;
    // create a shared_ptr of initial state
    shared_ptr<State> initial_state;

    shared_ptr<Operation> operation;
    vector<shared_ptr<Variable>> variables;

    string fsm_name;

    // open the file
    ifstream file(filename);

    // read the file line by line
    string line;

    int ln = 0;
    bool inStatesSection = false;
    bool inTransitionsSection = false;

    while (getline(file, line))
    {
        if (ln == 0)
        {
            // find FSM name
            int pos = line.find("FSM");
            if (pos != string::npos)
            {
                fsm_name = line.substr(pos + 4); // skip "FSM "
                // remove whitespace
                fsm_name.erase(remove_if(fsm_name.begin(), fsm_name.end(), ::isspace), fsm_name.end());
                cout << "FSM name: " << fsm_name << endl;
            }
            else
            {
                cout << "FSM name not found" << endl;
                exit(1);
            }
        }
        else if (ln == 1)
        {
            // check if this line is variable declaration
            int pos = line.find("VAR");
            // variable declaration found
            // VAR X, Y

            if (pos != string::npos)
            {
                // remove "VAR "
                line = line.substr(pos + 4);
                // remove whitespace
                line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
                // split the line by comma
                vector<string> extracted_variables = split(line, ',');

                // create a vector of shared_ptr of Variable
                for (const auto &variable : extracted_variables)
                {
                    shared_ptr<Variable> var = make_shared<Variable>(variable);
                    // add the variable to the vector
                    variables.push_back(var);
                }
            }
            else
            {
                cout << "VAR not found" << endl;
                exit(1);
            }
        }

        // now parse states
        /*
        States:
a: PRINT “state A”, X=X+1, sleep 10, wait
b: PRINT “state B”, Y=Y+1, sleep 10, wait
c: PRINT “thank you for using fsm1”, PRINT X, PRINT Y, end

        */

        if (line.find("States:") != string::npos)
        {
            inStatesSection = true;
            inTransitionsSection = false;
            continue;
        }
        else if (line.find("Transitions:") != string::npos)
        {
            inStatesSection = false;
            inTransitionsSection = true;
            continue;
        }

        if (inStatesSection)
        {
            // parse states
            string state_name = line.substr(0, line.find(":"));
            line = line.substr(line.find(":") + 1);
            vector<shared_ptr<Operation>> operations;
            vector<string> extracted_operations = split(line, ',');

            for (const auto &operation : extracted_operations)
            {
                shared_ptr<Operation> op = make_shared<Operation>(operation);
                operations.push_back(op);
            }

            shared_ptr<State> state = make_shared<State>(state_name, operations, variables);
            states.push_back(state);
        }
        else if (inTransitionsSection)
        {
            // parse transitions
            vector<string> extracted_transitions = split(line, ',');

            if (extracted_transitions.size() != 3)
            {
                cout << "Invalid transition found" << endl;
                exit(1);
            }

            string source_state_name = extracted_transitions[0];
            string destination_state_name = extracted_transitions[1];

            // Find the source and destination states in the states vector
            shared_ptr<State> source_state;
            shared_ptr<State> destination_state;
            for (auto &state : states)
            {
                if (state->get_name() == source_state_name)
                {
                    source_state = state;
                }
                else if (state->get_name() == destination_state_name)
                {
                    destination_state = state;
                }
            }

            if (!source_state || !destination_state)
            {
                cout << "Invalid source or destination state in transition" << endl;
                exit(1);
            }

            shared_ptr<Transition> transition = make_shared<Transition>(
                source_state,
                destination_state,
                stoi(extracted_transitions[2]));

            transitions.push_back(transition);
        }

        ln++;
    }

    // find the initial state
    shared_ptr<State> initial_state_ptr;
    initial_state_ptr = states[0];
    // create a shared_ptr of FSM
    shared_ptr<FSM> fsm = make_shared<FSM>(fsm_name, states, transitions, variables, initial_state);

    return *fsm;
}
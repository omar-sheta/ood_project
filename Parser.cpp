#include <fstream>
#include <iostream>
#include "Parser.h"
#include "Transition.h"
#include "State.h"
#include "FsmFactory.h"
#include "Operation.h"
#include "Variable.h"
#include <string>
#include <sstream>
#include <vector>


Parser::Parser(string filename) : filename(filename) {}


vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
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

    while (getline(file, line))
    {
        if (ln == 0){
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
        else if (ln == 1){
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

        else if (ln == 2){
        //  search for States:
        // check if this line contains States:
        int pos = line.find("States:");
        // check if this line contains States:
        if (pos != string::npos){
            // get next line
            getline(file, line);
            
            // line is now "a: PRINT “state A”, X=X+1, sleep 10, wait"
            // first one is the state name
            string state_name = line.substr(0, line.find(":"));
            // remove state name from line
            line = line.substr(line.find(":") + 1);
            vector<shared_ptr<Operation>> operations;
            // split the line by comma
            vector<string> extracted_operations = split(line, ',');

            // create a vector of shared_ptr of Operation
            for (const auto &operation : extracted_operations)
            {
                shared_ptr<Operation> op = make_shared<Operation>(operation);
                // add the operation to the vector
                operations.push_back(op);
            }

            // create a shared_ptr of State
            shared_ptr<State> state = make_shared<State>(state_name, operations, variables);

        }
        else
        {
            cout << "States not found" << endl;
            exit(1);
        }
        }
    




           




            
        


     


    }




    
}
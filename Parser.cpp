#include "Parser.h"

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

string trim(const string &str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == string::npos || end == string::npos)
    {
        return "";
    }
    return str.substr(start, end - start + 1);
}

shared_ptr<FSM> Parser::get_fsm()
{
    vector<shared_ptr<State>> states;
    vector<shared_ptr<Transition>> transitions;
    vector<shared_ptr<Variable>> variables;
    shared_ptr<State> initial_state;
    int current_value = 0;
    shared_ptr<Operation> operation;
    string fsm_name;

    ifstream file(filename);
    string line;
    int ln = 0;
    bool inStatesSection = false;
    bool inTransitionsSection = false;
    string state_name;

    while (getline(file, line))
    {
        if (ln == 0)
        {
            int pos = line.find("FSM");
            if (pos != string::npos)
            {
                fsm_name = line.substr(pos + 4);
                fsm_name = trim(fsm_name);
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
            int pos = line.find("VAR");
            if (pos != string::npos)
            {
                line = line.substr(pos + 4);
                line = trim(line);
                vector<string> extracted_variables = split(line, ',');

                for (const auto &variable : extracted_variables)
                {
                    shared_ptr<Variable> var = make_shared<Variable>(trim(variable));
                    variables.push_back(var);
                }
            }
            else
            {
                cout << "VAR not found" << endl;
                exit(1);
            }
        }

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
            state_name = line.substr(0, line.find(":"));
            line = line.substr(line.find(":") + 1);
            vector<shared_ptr<Operation>> operations;
            vector<string> extracted_operations = split(line, ',');

            for (const auto &operation : extracted_operations)
            {
                if (operation.find("PRINT") != string::npos)
                {
                    if (operation.find("\"") != string::npos)
                    {
                        // PRINT "String"
                        size_t start_quote_pos = operation.find("\"");
                        size_t end_quote_pos = operation.find("\"", start_quote_pos + 1);
                        if (start_quote_pos != string::npos && end_quote_pos != string::npos)
                        {
                            string print_statement = operation.substr(start_quote_pos + 1, end_quote_pos - start_quote_pos - 1);
                            // cout << "Print statement: " << print_statement << endl;
                            shared_ptr<Operation> op = make_shared<Print>("PRINT", print_statement);
                            operations.push_back(op);
                        }
                        else
                        {
                            cout << "Invalid print statement: " << operation << endl;
                        }
                    }
                    else
                    {
                        // PRINT VAR
                        size_t print_pos = operation.find("PRINT");
                        if (print_pos != string::npos)
                        {
                            string variable_statement = operation.substr(print_pos + 5);
                            variable_statement = trim(variable_statement);
                            // cout << "Print variable: " << variable_statement << endl;
                            shared_ptr<Operation> op = make_shared<Print>("PRINT", variable_statement);
                            operations.push_back(op);
                        }
                        else
                        {
                            cout << "Invalid print statement: " << operation << endl;
                        }
                    }
                }
                // CHECK FOR ARITHMETIC OPERATION WITH FORMAT X=X+1,
                if (operation.find("=") != string::npos)
                {

                    string variable_statement = operation.substr(0, operation.find("="));
                    variable_statement = trim(variable_statement);
                    bool isVariable = false;
                    for (auto &variable : variables)
                    {
                        if (variable->get_name() == variable_statement)
                        {
                            isVariable = true;
                        }
                    }
                    if (!isVariable)
                    {
                        cout << "Invalid variable statement: " << operation << endl;
                        exit(1);
                    }
                    if (operation.find("+") != string::npos)
                    {
                        string first_operand = operation.substr(operation.find("=") + 1, operation.find("+") - operation.find("=") - 1);
                        first_operand = trim(first_operand);
                        bool isVariable1 = false;
                        int first_operand_value;
                        for (auto &variable : variables)
                        {
                            if (variable->get_name() == first_operand)
                            {
                                isVariable1 = true;
                                first_operand_value = variable->get_value();
                            }
                        }
                        if (!isVariable1)
                        {
                            if (!isdigit(first_operand[0]))
                            {
                                cout << "Invalid first operand: " << first_operand << endl;
                                exit(1);
                            }
                            else
                            {
                                first_operand_value = stoi(first_operand);
                            }
                        }
                        // GETTING SECOND OPERAND
                        string second_operand = operation.substr(operation.find("+") + 1);
                        second_operand = trim(second_operand);
                        bool isVariable2 = false;
                        int second_operand_value;
                        for (auto &variable : variables)
                        {
                            if (variable->get_name() == second_operand)
                            {
                                isVariable2 = true;
                                second_operand_value = variable->get_value();
                            }
                        }
                        if (!isVariable2)
                        {
                            if (!isdigit(second_operand[0]))
                            {
                                cout << "Invalid second operand: " << second_operand << endl;
                                exit(1);
                            }
                            else
                            {
                                second_operand_value = stoi(second_operand);
                            }
                        }
                        shared_ptr<Operation> op = make_shared<Arithmetic>("add", first_operand_value, second_operand_value);
                        operations.push_back(op);
                    }
                    else if (operation.find("*") != string::npos)
                    {
                        string first_operand = operation.substr(operation.find("=") + 1, operation.find("+") - operation.find("=") - 1);
                        first_operand = trim(first_operand);
                        bool isVariable1 = false;
                        int first_operand_value;
                        for (auto &variable : variables)
                        {
                            if (variable->get_name() == first_operand)
                            {
                                isVariable1 = true;
                                first_operand_value = variable->get_value();
                            }
                        }
                        if (!isVariable1)
                        {
                            if (!isdigit(first_operand[0]))
                            {
                                cout << "Invalid first operand: " << first_operand << endl;
                                exit(1);
                            }
                            else
                            {
                                first_operand_value = stoi(first_operand);
                            }
                        }
                        // GETTING FIRST OPERAND
                        string second_operand = operation.substr(operation.find("+") + 1);
                        second_operand = trim(second_operand);
                        bool isVariable2 = false;
                        int second_operand_value;
                        for (auto &variable : variables)
                        {
                            if (variable->get_name() == second_operand)
                            {
                                isVariable2 = true;
                                second_operand_value = variable->get_value();
                            }
                        }
                        if (!isVariable2)
                        {
                            if (!isdigit(second_operand[0]))
                            {
                                cout << "Invalid second operand: " << second_operand << endl;
                                exit(1);
                            }
                            else
                            {
                                second_operand_value = stoi(second_operand);
                            }
                        }
                        shared_ptr<Operation> op = make_shared<Arithmetic>("multi", first_operand_value, second_operand_value);
                        operations.push_back(op);
                    }
                    else
                    {
                        cout << "Invalid arithmetic statement." << operation << endl;
                    }
                }
                //check if operation has wait
                if (operation.find("wait") != string::npos)
                {
                    shared_ptr<Operation> op = make_shared<Wait>("WAIT");
                    operations.push_back(op);
                }
            }
            // check
            //  cout << "State name: " << state_name << endl;
            // for (auto &op : operations)
            // {
            //      cout << "Operation: " << op->get_name() << endl;
            // }

            shared_ptr<State> state = make_shared<State>(state_name, operations);
            states.push_back(state);
        }
        else if (inTransitionsSection)
        {
            vector<string> extracted_transitions = split(line, ',');

            if (extracted_transitions.size() != 3)
            {
                cout << "Invalid transition found" << endl;
                exit(1);
            }

            string source_state_name = trim(extracted_transitions[0]);
            string destination_state_name = trim(extracted_transitions[1]);

            shared_ptr<State> source_state;
            shared_ptr<State> destination_state;

            for (auto &state : states)
            {
                if (state->get_name() == source_state_name)
                {
                    source_state = state;
                }
                if (state->get_name() == destination_state_name)
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

    shared_ptr<State> initial_state_ptr = states[0];
    shared_ptr<FSM> fsm = make_shared<FSM>(fsm_name, states, transitions, variables, initial_state_ptr, current_value);
    return fsm;
}

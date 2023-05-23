#include "wait.h"

void Wait::execute(shared_ptr<FSM> fsm)
{
    cout << "Enter input value: ";
    int value;
    cin >> value;
    fsm->set_current_value(value);

    // Check if a valid transition can occur
    bool validTransition = false;
    shared_ptr<Transition> transition;
    for (const auto &t : fsm->get_transitions())
    {
        if (t->get_source_state() == fsm->get_current_state() && t->get_input_value() == value)
        {
            validTransition = true;
            transition = t;
            break;
        }
    }

    if (validTransition)
    {
        cout << "Valid transition found. Changing state from " << fsm->get_current_state()->get_name()
             << " to " << transition->get_destination_state()->get_name() << endl;

        // Change state
        fsm->set_current_state(transition->get_destination_state());

        // Perform any other actions associated with the transition, if needed
        // transition->trigger();
    }
    else
    {
        cout << "Invalid transition. No matching transition found for the input value." << endl;
    }
}

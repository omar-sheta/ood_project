#include "end.h"

void End::execute(shared_ptr<FSM> fsm)
{
    cout << "FSM ended.";
    exit(0);
}

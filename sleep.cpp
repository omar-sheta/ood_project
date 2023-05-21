#include "time.h"
#include "sleep.h"
void Sleep::setSeconds(int seconds)
{
    this->seconds = seconds;
}

void Sleep::execute() const
{
    cout << "Sleeping for " << seconds << " seconds" << endl;
    this_thread::sleep_for(chrono::seconds(1));
}
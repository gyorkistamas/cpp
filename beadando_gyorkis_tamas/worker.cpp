#include "worker.hpp"
#include <iostream>
#include <string>

using namespace std;

ostream& operator<<(ostream &s, Worker& w)
{
    Date d = w.birthDate();
    s << w.name() << ", " << d;
    return s;
}

int Worker::getWageAndContribution()
{
    return getWageForMonth() + getContribution();
}

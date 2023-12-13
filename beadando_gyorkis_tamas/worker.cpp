#include "worker.hpp"
#include <iostream>
#include <string>

using namespace std;

ostream& Worker::operator<<(ostream &s)
{
    Date d = birthDate();
    s << name() << ", " << d;
    return s;
}

int Worker::getWageAndContribution()
{
    return getWageForMonth() + getContribution();
}

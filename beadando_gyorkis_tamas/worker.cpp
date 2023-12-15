#include "worker.hpp"
#include <iostream>
#include <string>
#include "address.hpp"

using namespace std;

ostream& operator<<(ostream &s, Worker& w)
{
    return w.printData(s);
}

ostream& Worker::printData(ostream& s)
{
    Address a = address();
    s << "Worker id: " << id() << "Name: " << name() << ", Address: " << a;
    return s;
}

int Worker::getWageAndContribution()
{
    return getWageForMonth() + getContribution();
}

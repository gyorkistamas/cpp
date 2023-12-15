#include "worker.hpp"
#include <iostream>
#include <string>
#include "address.hpp"

using namespace std;

ostream& operator<<(ostream &s, Worker& w)
{
    return w.printData(s);
}

/** Teljes bérköltség számítása
 */
int Worker::getWageAndContribution()
{
    return getWageForMonth() + getContribution();
}

#include "worker.hpp"
#include <iostream>
#include <string>
#include "address.hpp"

using namespace std;

ostream& operator<<(ostream &s, Worker& w)
{
    return w.printData(s);
}

/** Teljes b�rk�lts�g sz�m�t�sa
 */
int Worker::getWageAndContribution()
{
    return getWageForMonth() + getContribution();
}

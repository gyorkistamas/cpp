#include "worker.hpp"
#include <iostream>
#include "date.hpp"

using namespace std;

ostream& operator<<(ostream &s, Worker& w)
{
    Date date = w.birthDate();
    s << w.name() << ", " << date;
    return s;
}

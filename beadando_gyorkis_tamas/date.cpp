#include "date.hpp"
#include <iostream>

using std::ostream;

ostream& operator<<(ostream& s, Date& date)
{
    s << date.year() << "." << date.month() << "." << date.day();
    return s;
}

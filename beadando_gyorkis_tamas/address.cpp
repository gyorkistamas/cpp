#include "address.hpp"
#include <string>
#include <iostream>

using namespace std;

ostream& operator<<(ostream& s, Address& a)
{
    s << a.country() << ", " << a.postCode() << ", " << a.city() << ", " << a.street() << " street " << a.houseNumber() << ". ";
    return s;
}


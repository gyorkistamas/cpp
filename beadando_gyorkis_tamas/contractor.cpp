#include "contractor.hpp"
#include <string>
#include <iostream>

using namespace std;

int Contractor::getWageForMonth()
{
    return 0;
}

int Contractor::getContribution()
{
    return 0;
}

ostream& operator<<(ostream &s, Contractor& e)
{
    s << "Contractor: " << static_cast<Worker&>(e) << ", Work hours: " << e.workHours() << ", Hourly wage: " << e.hourlyWage();
    return s;
}

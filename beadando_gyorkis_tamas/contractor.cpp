#include "contractor.hpp"
#include <string>
#include <iostream>
#include "constants.hpp"
#include <cmath>

using namespace std;

int Contractor::getWageForMonth()
{
    return workHours() * hourlyWage();
}

int Contractor::getContribution()
{
    return round(getWageForMonth() * contractor_cont);
}

ostream& operator<<(ostream &s, Contractor& e)
{
    s << "Contractor: " << static_cast<Worker&>(e) << ", Work hours: " << e.workHours() << ", Hourly wage: " << e.hourlyWage();
    return s;
}

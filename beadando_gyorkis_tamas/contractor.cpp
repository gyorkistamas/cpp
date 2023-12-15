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
    return round(getWageForMonth() * contractor_contributon);
}

ostream& Contractor::printData(ostream &s)
{
    Address a = address();
    s << "Contractor id: " << id() << ", Name: " << name() << ", Address: " << a << ", WorkHours: " << workHours() << ", Wage: " << getWageForMonth();
    s << ", Contribution: " << getContribution();
    return s;
}

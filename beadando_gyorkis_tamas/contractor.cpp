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

ostream& operator<<(ostream &s, Employee& e)
{
    s << "Employee: " << static_cast<Worker&>(e) << ", Work days: " << e.workDays() << ", Sick days: " << e.sickDays();
    s << ", MonthlyWage: " << e.monthlyWage();
    return s;
}

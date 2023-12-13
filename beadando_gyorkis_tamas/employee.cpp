#include "employee.hpp"
#include <iostream>
#include "date.hpp"
#include "worker.hpp"
#include <string>
#include "constants.hpp"
#include <cmath>

using namespace std;

ostream& Employee::operator<<(ostream &s)
{
    Date a = birthDate();
    s << "Employee: " << "Name: " << name() << ", BirthDay: " << a;
    return s;
}

int Employee::getWageForMonth()
{
    return 0;
}

int Employee::getContribution()
{
    return round(getWageForMonth() * employee_contribution);
}

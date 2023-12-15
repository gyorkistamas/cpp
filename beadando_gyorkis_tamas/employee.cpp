#include "employee.hpp"
#include <iostream>
#include "date.hpp"
#include "worker.hpp"
#include <string>
#include "constants.hpp"
#include <cmath>

using namespace std;

ostream& Employee::printData(ostream& s)
{
    Address a = address();
    s << "Employee id: " << id() << ", Name: " << name() << ", Address: " << a << ", WorkDays: " << workDays() << ", SickDays: " << sickDays();
    s << ", Wage: " << getWageForMonth() << ", Contribution: " << getContribution();
    return s;
}

int Employee::getWageForMonth()
{
    // 30 napos hónapokkal számolva
    int dailyWage = round(monthlyWage() / 30);

    int wage = dailyWage * workDays();

    wage += round(dailyWage * sickDays() * 0.6);
    return wage;
}

int Employee::getContribution()
{
    // Munkában töltött
    return round(getWageForMonth() * employee_contribution);
}

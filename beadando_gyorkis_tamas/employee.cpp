#include "employee.hpp"
#include <iostream>
#include "date.hpp"
#include "worker.hpp"
#include <string>

using namespace std;

ostream& operator<<(ostream &s, Employee& e)
{
    s << "Employee: " << static_cast<Worker&>(e) << ", Work days: " << e.workDays() << ", Sick days: " << e.sickDays();
    return s;
}

int Employee::getWageForMonth()
{
    return 0;
}

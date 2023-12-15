#include "contractor.hpp"
#include <string>
#include <iostream>
#include "constants.hpp"
#include <cmath>
#include "checkedReading.hpp"

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

void Contractor::update()
{
    bool doReading = true;

    while (doReading)
    {
        cout << "1. Update name" << endl;
        cout << "2. Update address" << endl;
        cout << "3. Update work hours" << endl;
        cout << "4. Update hourly wage" << endl;
        cout << "5. Go back" << endl;

        cout << "Enter your selection: ";
        int selection = readChecked<int>();

        switch(selection)
        {
        case 1:
            cout << "Enter new name: ";
            setName(readChecked<string>());
            break;
        case 2:
            {
                Address a = address();
                a.update();
                setAddress(a);
                break;
            }
        case 3:
            cout << "Enter new work hours: ";
            setWorkHours(readChecked<int>());
            break;
        case 4:
            cout << "Enter new hourly wage: ";
            setHourlyWage(readChecked<int>());
            break;
        case 5:
            doReading = false;
            break;
        default:
            cout << "Invalid option, try again" << endl;
            break;
        }
    }
}

#include "leader.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include "constants.hpp"
#include "checkedReading.hpp"

using namespace std;

ostream& Leader::printData(ostream &s)
{
    Address a = address();
    s << "Leader id: " << id() << ", Name: " << name() << ", Address: " << a << ", Fix wage: " << fixWage() << ", Wage for month (with company revenue): " << getWageForMonth();
    return s;
}

int Leader::getWageForMonth()
{
    return fixWage() + round(company_revenue * leader_company_share);
}

int Leader::getContribution()
{
    return round(getWageForMonth() * leader_contribution);
}

void Leader::update()
{
        bool doReading = true;

    while (doReading)
    {
        cout << "1. Update name" << endl;
        cout << "2. Update address" << endl;
        cout << "3. Update fix wage" << endl;
        cout << "4. Go back" << endl;

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
            cout << "Enter new fix wage: ";
            setFixWage(readChecked<int>());
            break;
        case 4:
            doReading = false;
            break;
        default:
            cout << "Invalid option, try again" << endl;
            break;
        }
    }
}

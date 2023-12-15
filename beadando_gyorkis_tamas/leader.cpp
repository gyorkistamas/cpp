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

    s << "Id: " << id() << ", Leader: " << name() << ", Address: " << a << endl;
    s << "\t" <<"Fix wage: " << fixWage() << endl;
    s << "\t" <<"Wage for month: " << getWageForMonth() << ", Contribution to be payed: " << getContribution() << ", Total: " << getWageAndContribution();

    return s;
}

int Leader::getWageForMonth()
{
    int wage = fixWage() + round(company_revenue * leader_company_share);
    if (wage < 0) return 0;
    else return wage;
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
        cout << "Editing Leader with id " << id() << ": " << name() << endl << endl;

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

string Leader::getFileFormat()
{
    string line = "L;" + name() + ";" + address().getFileFormat() + ";" + to_string(fixWage());
    return line;
}

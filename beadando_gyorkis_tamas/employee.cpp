#include "employee.hpp"
#include <iostream>
#include "date.hpp"
#include "worker.hpp"
#include <string>
#include "constants.hpp"
#include <cmath>
#include "checkedReading.hpp"

using namespace std;

ostream& Employee::printData(ostream& s)
{
    Address a = address();
    s << "Id: " << id() << ", Employee: " << name() << ", Address: " << a << endl;
    s << "\t" << "Working days: " << workDays() << ", Sick days: " << sickDays() << endl;
    s << "\t" <<"Wage for month: " << getWageForMonth() << ", Contribution to be payed: " << getContribution() << ", Total: " << getWageAndContribution();
    return s;
}

/** Alkalmazott eset�n havi fix munkab�r�rt dolgozik (30 napos h�napokkal sz�molva)
 *  A t�nylegesen ledolgozott napokb�l, illetve a betegszabads�gb�l sz�mol�dik a t�nyleges b�rd�j
 */
int Employee::getWageForMonth()
{
    int dailyWage = round(monthlyWage() / 30);
    int wage = dailyWage * workDays();
    wage += round(dailyWage * sickDays() * 0.6);
    return wage;
}

int Employee::getContribution()
{
    // TODO Munk�ban t�lt�tt
    return round(getWageForMonth() * employee_contribution);
}

/** Alkalmazott friss�t�se men� rendszer seg�ts�g�vel
 */
void Employee::update()
{
    bool doReading = true;

    while (doReading)
    {
        cout << "Editing Employee with id " << id() << ": " << name() << endl << endl;

        cout << "1. Update name" << endl;
        cout << "2. Update address" << endl;
        cout << "3. Update workdays" << endl;
        cout << "4. Update sickdays" << endl;
        cout << "5. Update wage" << endl;
        cout << "6. Go back" << endl;

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
            cout << "Enter new workday count: ";
            setWorkDays(readChecked<int>());
            break;
        case 4:
            cout << "Enter new sick day count: ";
            setSickDays(readChecked<int>());
            break;
        case 5:
            cout << "Enter new wage: ";
            setMonthlyWage(readChecked<int>());
            break;
        case 6:
            doReading = false;
            break;
        default:
            cout << "Invalid option, try again" << endl;
            break;
        }
    }
}

/** Alkalmazott f�jlba �r�sakor haszn�land�
 */
string Employee::getFileFormat()
{
    string line = "E;" + name() + ";" + address().getFileFormat() + ";" + to_string(workDays()) + ";" + to_string(sickDays()) + ";" + to_string(monthlyWage());
    return line;
}

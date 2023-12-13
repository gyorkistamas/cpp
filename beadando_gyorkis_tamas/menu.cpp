#include <string>
#include <cmath>
#include <vector>
#include "worker.hpp"
#include "employee.hpp"
#include "contractor.hpp"
#include "leader.hpp"
#include "menu.hpp"
#include "date.hpp"
#include "checkedReading.hpp"

Menu::Menu()
{
    execute();
}

Menu::~Menu()
{
    for (Worker* worker_ptr :  workers_m)
    {
        delete worker_ptr;
    }
}

void Menu::execute()
{
    int selection;
    bool isRunning = true;
    while (isRunning)
    {
        cout << "1. List all data" << endl;
        cout << "2. Create new Employee" << endl << "3. Create new Contractor" << endl << "4. Create new Leader" << endl;
        cout << "5. List all data" << endl << endl;

        cout << "Enter the selected item: ";
        selection = readChecked<int>();

        switch (selection)
        {
        case 1:
            listAllData();
            break;

        case 2:
            newEmployee();
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        default:
            cout << endl << "Wrong selection, please try again" << endl;
            break;
        }
        cout << endl;
    }
}

Date getDate()
{
    cout << "The birth year: ";
    int year = readChecked<int>();

    cout << "The birth month: ";
    int month = readChecked<int>();

    cout << "The birth day: ";
    int day = readChecked<int>();

    Date a(year, month, day);
    return a;
}

void Menu::newEmployee()
{
    cout << "Enter the name: ";
    string name = readChecked<string>();

    Date birth = getDate();

    cout << "How many days did they work last month? ";
    int workDays = readChecked<int>();

    cout << "How many sick days did they have last month? ";
    int sickDays = readChecked<int>();

    cout << "What is the monthly wage of the employee? ";
    int wage = readChecked<int>();

    Employee* e = new Employee(name, birth, workDays, sickDays, wage);
    workers_m.push_back(e);
}

void Menu::listAllData()
{
    for(Worker* w : workers_m)
    {
        cout << (*w) << endl;
    }
}

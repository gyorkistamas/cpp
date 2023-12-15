#include <string>
#include <cmath>
#include <vector>
#include "worker.hpp"
#include "employee.hpp"
#include "contractor.hpp"
#include "leader.hpp"
#include "menu.hpp"
#include "address.hpp"
#include "checkedReading.hpp"
#include "filter_menu.hpp"

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
        cout << "5. Filter data" << endl;


        cout << "5. Exit" << endl << endl;

        cout << "Enter the selected item: ";
        selection = readChecked<int>();

        switch (selection)
        {
        case 1: listAllData(); break;

        case 2: newEmployee(); break;

        case 3: newContractor(); break;

        case 4: newLeader(); break;

        case 5: filterData(); break;

        default:
            cout << endl << "Wrong selection, please try again" << endl;
            break;
        }
        cout << endl;
    }
}

Address getAddress()
{
    cout << "Country: ";
    string country = readChecked<string>();

    cout << "Postal code: ";
    int postal = readChecked<int>();

    cout << "City: ";
    string city = readChecked<string>();

    cout << "Street: ";
    string street = readChecked<string>();

    cout << "House number: ";
    int number = readChecked<int>();

    Address a(country, postal, city, street, number);
    return a;
}

void Menu::newEmployee()
{
    cout << "Enter id: ";
    int id = readChecked<int>();

    cout << "Enter the name: ";
    string name = readChecked<string>();

    Address address = getAddress();

    cout << "How many days did they work last month? ";
    int workDays = readChecked<int>();

    cout << "How many sick days did they have last month? ";
    int sickDays = readChecked<int>();

    cout << "What is the monthly wage of the employee? ";
    int wage = readChecked<int>();

    Employee* e = new Employee(id, name, address, workDays, sickDays, wage);
    workers_m.push_back(e);
}

void Menu::newContractor()
{
    cout << "Enter id: ";
    int id = readChecked<int>();

    cout << "Enter the name: ";
    string name = readChecked<string>();

    Address address = getAddress();

    cout << "How many hours do they work in a month? ";
    int hours = readChecked<int>();

    cout << "What is their hourly wage? ";
    int hourlyWage = readChecked<int>();

    Contractor* e = new Contractor(id, name, address, hours, hourlyWage);
    workers_m.push_back(e);
}

void Menu::newLeader()
{
    cout << "Enter id: ";
    int id = readChecked<int>();

    cout << "Enter the name: ";
    string name = readChecked<string>();

    Address address = getAddress();

    cout << "What is their fix wage? ";
    int wage = readChecked<int>();
    Leader* e = new Leader(id, name, address, wage);
    workers_m.push_back(e);
}

void Menu::listAllData()
{
    for(Worker* w : workers_m)
    {
        cout << (*w) << endl;
    }
}

void Menu::filterData()
{
    FilterMenu menu(workers_m);
    menu.execute();
}

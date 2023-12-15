#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "worker.hpp"
#include "employee.hpp"
#include "contractor.hpp"
#include "leader.hpp"
#include "menu.hpp"
#include "address.hpp"
#include "checkedReading.hpp"
#include "filter_menu.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include "constants.hpp"

Menu::Menu()
{
    execute();
}

Menu::~Menu()
{
    storeFile();
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
        cout << endl << "--------------------------------" << endl;
        cout << "1.  List all data" << endl;
        cout << "2.  Create new Employee" << endl << "3.  Create new Contractor" << endl << "4.  Create new Leader" << endl;
        cout << "5.  Filter data" << endl;
        cout << "6.  Delete worker from list" << endl;
        cout << "7.  Update worker information" << endl;
        cout << "8.  Summarize company-wide payouts" << endl;
        cout << "9.  Read data from csv file" << endl;
        cout << "10. Store data in csv file" << endl;
        cout << "11. Exit" << endl << endl;

        cout << "Enter the selected item: ";
        selection = readChecked<int>();
        cout << endl;
        switch (selection)
        {
        case 1: listAllData(); break;
        case 2: newEmployee(); break;
        case 3: newContractor(); break;
        case 4: newLeader(); break;
        case 5: filterData(); break;
        case 6: deleteWorker(); break;
        case 7: updateWorker(); break;
        case 8: companyData(); break;
        case 9: readFile(); break;
        case 10: storeFile(); break;
        case 11: isRunning = false; break;
        default: cout << endl << "Wrong selection, please try again" << endl; break;
        }
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
    int id = getNextId();

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
    int id = getNextId();

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
    int id = getNextId();

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
        cout << (*w) << endl << endl;
    }
}

void Menu::filterData()
{
    FilterMenu menu(workers_m);
    menu.execute();
}

void Menu::deleteWorker()
{
    cout << "ID of the worker: ";
    int id = readChecked<int>();

    Worker* selected = NULL;

    for(Worker* w : workers_m)
    {
        if (w->id() == id)
        {
            selected = w;
            break;
        }
    }

    if (selected != NULL)
    {
        auto pos = std::find(workers_m.begin(), workers_m.end(), selected);
        workers_m.erase(pos);
        delete selected;
        cout << "Worker deleted" << endl;
    }
    else
    {
        cout << "Worker not found with that ID" << endl;
    }

}

void Menu::updateWorker()
{
    cout << "ID of the worker: ";
    int id = readChecked<int>();

    Worker* selected = NULL;

    for(Worker* w : workers_m)
    {
        if (w->id() == id)
        {
            selected = w;
            break;
        }
    }

    if (selected != NULL)
    {
        selected->update();
    }
    else
    {
        cout << "Worker not found with that ID" << endl;
    }
}

void Menu::companyData()
{
    // Teljes céges bérköltség
    int companyPayout = 0;

    // Csak a fizetések összege
    int companyWages = 0;

    // Csak a járulékok összege
    int companyContribution = 0;

    for (Worker* w : workers_m)
    {
        companyPayout += w->getWageAndContribution();
        companyWages += w->getWageForMonth();
        companyContribution += w->getContribution();
    }

    cout << "Company data:" << endl;
    cout << "Company revenue: " << company_revenue << endl;
    cout << "All company payout: " << companyPayout << endl;
    cout << "All company wages payout: " << companyWages << endl;
    cout << "All company contribution payout: " << companyContribution << endl;
}

int Menu::getNextId()
{
    return workers_m.size();
}

void Menu::readFile()
{
    try
    {
        string line;

        ifstream backupFile("backup.csv");

        while (getline(backupFile, line))
        {
            try
            {
                std::istringstream iss(line);

                vector<string> split;

                string temp;
                while (getline(iss, temp, ';'))
                {
                    split.push_back(temp);
                }

                int id = getNextId();
                Address a(split[2], stoi(split[3]), split[4], split[5], stoi(split[6]));
                Worker* w;

                if (split[0] == "E")
                {
                    w = new Employee(id, split[1], a, stoi(split[7]), stoi(split[8]), stoi(split[9]));
                }

                if (split[0] == "C")
                {
                    w = new Contractor(id, split[1], a, stoi(split[7]), stoi(split[8]));
                }

                if (split[0] == "L")
                {
                    w = new Leader(id, split[1], a, stoi(split[7]));
                }

                workers_m.push_back(w);
            }
            catch(...)
            {
                cout << "Error when reading a line of the file, maybe the file is corrupted" << endl;
            }

        }

        backupFile.close();
    }
    catch(...)
    {
        cout << "An error occurred while opening the file, import aborted" << endl;
    }

    cout << "Reading file is done" << endl;
}

void Menu::storeFile()
{
    ofstream workerFile("backup.csv");

    for (Worker* w : workers_m)
    {
        workerFile << w->getFileFormat();
        workerFile << endl;
    }
    workerFile.close();

    cout << "Data written to file successfully" << endl;
}

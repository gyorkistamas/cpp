#include <string>
#include <cmath>
#include <vector>
#include "worker.hpp"
#include "employee.hpp"
#include "contractor.hpp"
#include "leader.hpp"
#include "filter_menu.hpp"
#include "address.hpp"
#include "checkedReading.hpp"

void FilterMenu::execute()
{
    int selection;
    bool isRunning = true;
    while (isRunning)
    {
        cout << "1. Filter by name" << endl;
        cout << "2. Filter by country" << endl;
        cout << "3. Show filtered data" << endl;
        cout << "4. Exit filtering back to main menu" << endl;

        cout << "Enter the selected item: ";
        selection = readChecked<int>();

        switch (selection)
        {
        case 1: filterByName(); break;

        case 2: filterByCountry(); break;

        case 3:  displayFiltered(); break;

        case 4:  isRunning = false; break;

        case 5: break;

        default:
            cout << endl << "Wrong selection, please try again" << endl;
            break;
        }
        cout << endl;
    }
}

void FilterMenu::filterByName()
{
    std::vector<Worker*> toFilter;

    if (firstFilter) toFilter = original_vector_m;
    else toFilter = filtered_vector_m;

    cout << "Name to filter for: ";
    string name = readChecked<string>();

    std::vector<Worker*> filtered;

    for(Worker* w : toFilter)
    {
        if (w->name() == name)
        {
            filtered.push_back(w);
        }
    }
    firstFilter = false;
    filtered_vector_m = filtered;
}

void FilterMenu::filterByCountry()
{
    std::vector<Worker*> toFilter;

    if (firstFilter) toFilter = original_vector_m;
    else toFilter = filtered_vector_m;

    cout << "Country to filter for: ";
    string country = readChecked<string>();

    std::vector<Worker*> filtered;

    for(Worker* w : toFilter)
    {
        if (w->address().country() == country)
        {
            filtered.push_back(w);
        }
    }
    firstFilter = false;
    filtered_vector_m = filtered;
}

void FilterMenu::displayFiltered()
{
    for (Worker* w : filtered_vector_m)
    {
        cout << *w << endl;
    }
}

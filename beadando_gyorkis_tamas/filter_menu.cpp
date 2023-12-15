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

/** \brief Az alkalmazott típus szûréskor használandó
 *
 * Template metódus, hogy megvizsgáljuk,
 * hogy egy adott objektum példánya-e
 * a megadott típusnak (sikeres-e a castolás)
 */
template<typename Base, typename T>
bool instanceof(T *ptr) {
   return dynamic_cast<Base*>(ptr) != nullptr;
}


/** \brief A szűrés menü elindítása
 */
void FilterMenu::execute()
{
    int selection;
    bool isRunning = true;
    while (isRunning)
    {
        cout << endl << "---------------------------" << endl;
        cout << "1. Filter by ID" << endl;
        cout << "2. Filter by name" << endl;
        cout << "3. Filter by country" << endl;
        cout << "4. Filter Employees" << endl;
        cout << "5. Filter Contractors" << endl;
        cout << "6. Filter Leaders" << endl << endl;
        cout << "7. Show filtered data" << endl;
        cout << "8. Exit filtering back to main menu" << endl << endl;

        cout << "Enter the selected item: ";
        selection = readChecked<int>();
        cout << endl;
        switch (selection)
        {
        case 1: filterById(); break;
        case 2: filterByName(); break;
        case 3: filterByCountry(); break;
        case 4: filterEmployees(); break;
        case 5: filterContractors(); break;
        case 6: filterLeaders(); break;
        case 7: displayFiltered(); break;
        case 8: isRunning = false; break;
        default: cout << endl << "Wrong selection, please try again" << endl; break;
        }
    }
}

/** \brief Szűrés ID alapján
 *  Ha már volt előtte szűrés, akkro abból a listából szűrünk, egyébként az eredetiből
 */
void FilterMenu::filterById()
{
    std::vector<Worker*> toFilter;

    // Ha nem volt még szűrés, akkor az erdeti listán szűrünk
    // egyébként a már szűrt listát szűrjük újra.
    if (firstFilter) toFilter = original_vector_m;
    else toFilter = filtered_vector_m;

    cout << "Id to filter for: ";
    int id = readChecked<int>();

    std::vector<Worker*> filtered;

    for(Worker* w : toFilter)
    {
        if (w->id() == id)
        {
            filtered.push_back(w);
        }
    }
    firstFilter = false;
    filtered_vector_m = filtered;
}

/** \brief Szűrés név alapján
 */
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

/** \brief Szűrés Ország alapján
 */
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

/** \brief Szűrt elemek megjelenítése
 */
void FilterMenu::displayFiltered()
{
    for (Worker* w : filtered_vector_m)
    {
        cout << *w << endl;
    }
}

/** \brief Alkalmazottak szűrése
 */
void FilterMenu::filterEmployees()
{
    std::vector<Worker*> toFilter;

    if (firstFilter) toFilter = original_vector_m;
    else toFilter = filtered_vector_m;

    std::vector<Worker*> filtered;

    for(Worker* w : toFilter)
    {
        if (instanceof<Employee>(w))
        {
            filtered.push_back(w);
        }
    }
    firstFilter = false;
    filtered_vector_m = filtered;
}

/** \brief Szerződésesek szűrése
 */
void FilterMenu::filterContractors()
{
        std::vector<Worker*> toFilter;

    if (firstFilter) toFilter = original_vector_m;
    else toFilter = filtered_vector_m;

    std::vector<Worker*> filtered;

    for(Worker* w : toFilter)
    {
        if (instanceof<Contractor>(w))
        {
            filtered.push_back(w);
        }
    }
    firstFilter = false;
    filtered_vector_m = filtered;
}

/** \brief Vezetők szűrése
 */
void FilterMenu::filterLeaders()
{
        std::vector<Worker*> toFilter;

    if (firstFilter) toFilter = original_vector_m;
    else toFilter = filtered_vector_m;

    std::vector<Worker*> filtered;

    for(Worker* w : toFilter)
    {
        if (instanceof<Leader>(w))
        {
            filtered.push_back(w);
        }
    }
    firstFilter = false;
    filtered_vector_m = filtered;
}

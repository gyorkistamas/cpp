#pragma once
#include <string>
#include <cmath>
#include <vector>
#include "worker.hpp"
#include "employee.hpp"
#include "contractor.hpp"
#include "leader.hpp"

/**
 * A szûrés egy külön osztály segítségével van megvalósítva
 * Ehhez bekérjük a dolgozókat tartalmazó vektort, amin szűrni szeretnénk
 * Lehetõség van szûrni ID, név, Ország, ileltve munkaerõ típus szerint szûrni.
 * Ezeket lehet egymásra halmozni, és kapcsolattal
 * Majd végül megjeleníteni
 * (Ha egy emberre vagyunk kíváncsiak, akkor szûrhetünk névre vagy ID-ra, és csak az fog kilistázódni)
 * Szûrés során megjelenik a dolgozóhoz tartozó munkabér, fizetendõ járulék, illetve a cég által összesen fizetendõ összeg
 * Visszalépve a menüben, a dolgozó adait frissítve ezek újraszámolódnak természetesen
 */

class FilterMenu
{
public:
    FilterMenu(std::vector<Worker*> original_data)
    : original_vector_m(original_data) {}

    void execute();

    void filterById();
    void filterByName();
    void filterByCountry();

    void filterEmployees();
    void filterContractors();
    void filterLeaders();

    void displayFiltered();

private:
    std::vector<Worker*> original_vector_m;
    std::vector<Worker*> filtered_vector_m;
    bool firstFilter = true;
};

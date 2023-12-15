#pragma once
#include <string>
#include <cmath>
#include <vector>
#include "worker.hpp"
#include "employee.hpp"
#include "contractor.hpp"
#include "leader.hpp"

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

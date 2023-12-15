#pragma once
#include <string>
#include <cmath>
#include <vector>
#include "worker.hpp"
#include "employee.hpp"
#include "contractor.hpp"
#include "leader.hpp"

class Menu
{
public:
    Menu();
    void execute();
    ~Menu();

private:
    void newEmployee();
    void newContractor();
    void newLeader();

    void listAllData();

    void filterData();

    std::vector<Worker*> workers_m;
};

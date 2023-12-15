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
    // Létrehozások
    void newEmployee();
    void newContractor();
    void newLeader();

    // Listázás, szûrés, törlés, frissítés menüpontok
    void listAllData();
    void filterData();
    void deleteWorker();
    void updateWorker();

    // Céges adatok (összes bérköltség)
    void companyData();

    // A vektorban a betöltés során autoamtikusan növekvõ ID-t kapnak a dolgozók,
    // hogy törlés, frissítés során könnyen lehessen referálni rá.
    int getNextId();

    // Fájlba való írás illetve olvasás
    void readFile();
    void storeFile();

    std::vector<Worker*> workers_m;
};

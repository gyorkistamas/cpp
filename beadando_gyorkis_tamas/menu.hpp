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
    // L�trehoz�sok
    void newEmployee();
    void newContractor();
    void newLeader();

    // List�z�s, sz�r�s, t�rl�s, friss�t�s men�pontok
    void listAllData();
    void filterData();
    void deleteWorker();
    void updateWorker();

    // C�ges adatok (�sszes b�rk�lts�g)
    void companyData();

    // A vektorban a bet�lt�s sor�n autoamtikusan n�vekv� ID-t kapnak a dolgoz�k,
    // hogy t�rl�s, friss�t�s sor�n k�nnyen lehessen refer�lni r�.
    int getNextId();

    // F�jlba val� �r�s illetve olvas�s
    void readFile();
    void storeFile();

    std::vector<Worker*> workers_m;
};

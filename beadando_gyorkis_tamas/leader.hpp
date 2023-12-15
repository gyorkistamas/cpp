#pragma once
#include <string>
#include "worker.hpp"
#include <iostream>

using namespace std;

/*
 * A vezetõ osztály
 * Havi fix díjat kap, ezt konstruktorban kérjük be, az objektum frissítésével módosítható
 * Illetve még hozzá jön ehhez a céges bevétel 1%-a (vagy levonásban)
 */
class Leader : public Worker
{
public:
    Leader(int id, string name, Address address, int fixWage):
        Worker(id, name, address), fixWage_m(fixWage) {}

    int fixWage() {return fixWage_m;}
    void setFixWage(int value) {fixWage_m = value;}

    ostream& printData(ostream& s);
    int getWageForMonth();
    int getContribution();
    void update();
    string getFileFormat();

private:
    int fixWage_m;
};


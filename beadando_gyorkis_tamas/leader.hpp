#pragma once
#include <string>
#include "worker.hpp"
#include <iostream>

using namespace std;

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

private:
    int fixWage_m;
};


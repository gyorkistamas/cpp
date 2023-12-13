#pragma once
#include <string>
#include "worker.hpp"
#include <iostream>

using namespace std;

class Leader : public Worker
{
public:
    Leader(string name, Date birthDate, int workDays, int fixWage):
        Worker(name, birthDate), fixWage_m(fixWage) {}

    int fixWage() {return fixWage_m;}
    void setFixWage(int value) {fixWage_m = value;}

    int getWageForMonth();
    int getContribution();

private:
    int fixWage_m;
};

ostream& operator<<(ostream &s, Leader& e);

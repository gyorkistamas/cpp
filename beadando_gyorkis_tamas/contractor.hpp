#pragma once
#include <string>
#include "worker.hpp"
#include <iostream>

using namespace std;

class Contractor : public Worker
{
public:
    Contractor(string name, Date birthDay, int workHours, int hourlyWage):
        Worker(name, birthDay), workHours_m(workHours), hourlyWage_m(hourlyWage) {}

        int workHours() {return workHours_m;}
        void setWorkHours(int value) {workHours_m = value;}

        int hourlyWage() {return hourlyWage_m;}
        void setHourlyWage(int value) {hourlyWage_m = value;}

        int getWageForMonth();
        int getContribution();

private:
    int workHours_m;
    int hourlyWage_m;
};

ostream& operator<<(ostream &s, Contractor& e);

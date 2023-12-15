#pragma once
#include <string>
#include "worker.hpp"
#include <iostream>

using namespace std;

class Contractor : public Worker
{
public:
    Contractor(int id, string name, Address address, int workHours, int hourlyWage):
        Worker(id, name, address), workHours_m(workHours), hourlyWage_m(hourlyWage) {}

        int workHours() {return workHours_m;}
        void setWorkHours(int value) {workHours_m = value;}

        int hourlyWage() {return hourlyWage_m;}
        void setHourlyWage(int value) {hourlyWage_m = value;}

        ostream& printData(ostream& s);
        int getWageForMonth();
        int getContribution();
        void update();

private:
    int workHours_m;
    int hourlyWage_m;
};

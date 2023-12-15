#pragma once
#include <string>
#include "worker.hpp"
#include <iostream>

using namespace std;

class Employee : public Worker
{
public:
    Employee(int id, string name, Address address, int workDays, int sickDays, int monthlyWage) :
        Worker(id, name, address), workDays_m(workDays), sickDays_m(sickDays), monthlyWage_m(monthlyWage) {}

    int workDays() {return workDays_m;}
    int sickDays() {return sickDays_m;}
    int monthlyWage() {return monthlyWage_m;}

    void setWorkDays(int days) {workDays_m = days;}
    void setSickDays(int days) {sickDays_m = days;}
    void setMonthlyWage(int wage) {monthlyWage_m = wage;}

    ostream& printData(ostream& s);

    int getWageForMonth();
    int getContribution();
    void update();

private :
    int workDays_m;
    int sickDays_m;
    int monthlyWage_m;
};


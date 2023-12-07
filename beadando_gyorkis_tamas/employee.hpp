#pragma once
#include <string>
#include "worker.hpp"
#include <iostream>

using namespace std;

class Employee : public Worker
{
public:
    Employee(string name, int birthYear, int birthMonth, int birthDay, int workDays, int sickDays) :
        Worker(name, birthYear, birthMonth, birthDay), workDays_m(workDays), sickDays_m(sickDays) {}

    int workDays() {return workDays_m;}
    int sickDays() {return sickDays_m;}

    void setWorkDays(int days) {workDays_m = days;}
    void setSickDays(int days) {sickDays_m = days;}

    int getWageForMonth();

private :
    int workDays_m;
    int sickDays_m;
};

ostream& operator<<(ostream &s, Employee& e);

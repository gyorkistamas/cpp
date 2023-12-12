#pragma once
#include <string>
#include "worker.hpp"
#include <iostream>

using namespace std;

class Leader : public Worker
{
public:
    Leader(string name, int birthYear, int birthMonth, int birthDay, int workDays, int fixWage, int companyResult):
        Worker(name, birthYear, birthMonth, birthDay), fixWage_m(fixWage), companyResult_m(companyResult) {}

    int fixWage() {return fixWage_m;}
    void setFixWage(int value) {fixWage_m = value;}

    int companyResult() {return companyResult_m;}
    void setCompanyResult(int value) { companyResult_m = value;}

    int getWageForMonth();
    int getContribution();

private:
    int fixWage_m;
    int companyResult_m;
};

ostream& operator<<(ostream &s, Leader& e);

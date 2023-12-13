#pragma once
#include <string>
#include "date.hpp"
#include <iostream>

using std::ostream;

using namespace std;

class Worker
{
public:
    Worker(string name, Date birthDay) : name_m(name), birthDate_m(birthDay) {}

    string name() {return name_m;}
    Date birthDate() {return birthDate_m;}

    void setName(string name) {name_m = name;}
    void setBirthDate(int birthYear, int birthMonth, int birthDay) {birthDate_m = Date(birthYear, birthMonth, birthDay);}

    virtual int getWageForMonth() = 0;
    virtual int getContribution() = 0;

    virtual ostream& operator<<(ostream& s);

    int getWageAndContribution();
    virtual ~Worker() {};
private:
    string name_m;
    Date birthDate_m;
};

//ostream& operator<<(ostream& s, Worker& w);

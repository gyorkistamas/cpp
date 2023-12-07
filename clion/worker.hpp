#pragma once
#include <string>
#include "date.hpp"
#include <iostream>

using std::ostream;

using namespace std;

class Worker
{
public:
    Worker(string name, int birthYear, int birthMonth, int birthDay) : name_m(name), birthDate_m(birthYear, birthMonth, birthDay) {}

    string name() {return name_m;}
    Date birthDate() {return birthDate_m;}

    void setName(string name) {name_m = name;}
    void setBirthDate(int birthYear, int birthMonth, int birthDay) {birthDate_m = Date(birthYear, birthMonth, birthDay);}

    virtual string getType() = 0;
    virtual ~Worker() = default;
private:
    string name_m;
    Date birthDate_m;
};

ostream& operator<<(ostream& s, Worker& w);

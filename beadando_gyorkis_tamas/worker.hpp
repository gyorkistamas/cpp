#pragma once
#include <string>
#include "address.hpp"
#include <iostream>

using std::ostream;

using namespace std;

class Worker
{
public:
    Worker(int id, string name, Address address) : id_m(id), name_m(name), address_m(address) {}

    int id() {return id_m;}
    void setId(int value) {id_m = value;}

    string name() {return name_m;}
    Address address() {return address_m;}

    void setName(string name) {name_m = name;}
    void setAddress(Address a) {address_m = a;}

    virtual int getWageForMonth() = 0;
    virtual int getContribution() = 0;
    virtual void update() = 0;

    virtual ostream& printData(ostream& s);

    int getWageAndContribution();
    virtual ~Worker() {};
private:
    int id_m;
    string name_m;
    Address address_m;
};

ostream& operator<<(ostream& s, Worker& w);

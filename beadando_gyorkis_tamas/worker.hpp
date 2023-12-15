#pragma once
#include <string>
#include "address.hpp"
#include <iostream>

using std::ostream;

using namespace std;

// Fõ, absztrakt osztály
class Worker
{
public:
    Worker(int id, string name, Address address) : id_m(id), name_m(name), address_m(address) {}

    // Getterek és setterek az egyes mezõknek.
    int id() {return id_m;}
    void setId(int value) {id_m = value;}

    string name() {return name_m;}
    Address address() {return address_m;}

    void setName(string name) {name_m = name;}
    void setAddress(Address a) {address_m = a;}

    // A teljes összeget (munkabér + járulék) ezzel számoljuk
    int getWageAndContribution();

    // Absztrakt munkabér számolás
    virtual int getWageForMonth() = 0;

    // Absztrakt járulék számolás
    virtual int getContribution() = 0;

    // A frissítés során használatos
    virtual void update() = 0;

    // A '<<' operátor ennek az értékét adja vissza, így egy sorban ki lehet íratni egyes dolgozók adatait
    virtual ostream& printData(ostream& s) = 0;

    // Ez pedig a fájlba bekerülõ, ';'-val elválasztott formáját adja vissza az objektumnak
    virtual string getFileFormat() = 0;

    virtual ~Worker() {};
private:
    int id_m;
    string name_m;
    Address address_m;
};

ostream& operator<<(ostream& s, Worker& w);

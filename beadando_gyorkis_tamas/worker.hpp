#pragma once
#include <string>
#include "address.hpp"
#include <iostream>

using std::ostream;

using namespace std;

// F�, absztrakt oszt�ly
class Worker
{
public:
    Worker(int id, string name, Address address) : id_m(id), name_m(name), address_m(address) {}

    // Getterek �s setterek az egyes mez�knek.
    int id() {return id_m;}
    void setId(int value) {id_m = value;}

    string name() {return name_m;}
    Address address() {return address_m;}

    void setName(string name) {name_m = name;}
    void setAddress(Address a) {address_m = a;}

    // A teljes �sszeget (munkab�r + j�rul�k) ezzel sz�moljuk
    int getWageAndContribution();

    // Absztrakt munkab�r sz�mol�s
    virtual int getWageForMonth() = 0;

    // Absztrakt j�rul�k sz�mol�s
    virtual int getContribution() = 0;

    // A friss�t�s sor�n haszn�latos
    virtual void update() = 0;

    // A '<<' oper�tor ennek az �rt�k�t adja vissza, �gy egy sorban ki lehet �ratni egyes dolgoz�k adatait
    virtual ostream& printData(ostream& s) = 0;

    // Ez pedig a f�jlba beker�l�, ';'-val elv�lasztott form�j�t adja vissza az objektumnak
    virtual string getFileFormat() = 0;

    virtual ~Worker() {};
private:
    int id_m;
    string name_m;
    Address address_m;
};

ostream& operator<<(ostream& s, Worker& w);

#pragma once
#include <string>
#include "worker.hpp"
#include <iostream>

using namespace std;

/*
 * A vezet� oszt�ly
 * Havi fix d�jat kap, ezt konstruktorban k�rj�k be, az objektum friss�t�s�vel m�dos�that�
 * Illetve m�g hozz� j�n ehhez a c�ges bev�tel 1%-a (vagy levon�sban)
 */
class Leader : public Worker
{
public:
    Leader(int id, string name, Address address, int fixWage):
        Worker(id, name, address), fixWage_m(fixWage) {}

    int fixWage() {return fixWage_m;}
    void setFixWage(int value) {fixWage_m = value;}

    ostream& printData(ostream& s);
    int getWageForMonth();
    int getContribution();
    void update();
    string getFileFormat();

private:
    int fixWage_m;
};


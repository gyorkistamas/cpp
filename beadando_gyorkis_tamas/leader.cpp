#include "leader.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include "constants.hpp"

using namespace std;

ostream& Leader::printData(ostream &s)
{
    Address a = address();
    s << "Leader id: " << id() << ", Name: " << name() << ", Address: " << a << ", Fix wage: " << fixWage() << ", Wage for month (with company revenue): " << getWageForMonth();
    return s;
}

int Leader::getWageForMonth()
{
    return fixWage() + round(company_revenue * leader_company_share);
}

int Leader::getContribution()
{
    return round(getWageForMonth() * leader_contribution);
}

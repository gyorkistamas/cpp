#include "leader.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include "constants.hpp"

using namespace std;

ostream& operator<<(ostream &s, Leader& e)
{
    s << "Leader: " << static_cast<Worker&>(e) << ", Fix wage: " << e.fixWage();
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

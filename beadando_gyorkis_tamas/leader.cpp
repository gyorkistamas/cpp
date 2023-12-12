#include "leader.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include "constants.hpp"

using namespace std;

ostream& operator<<(ostream &s, Leader& e)
{
    s << "Leader: " << static_cast<Worker&>(e) << ", Fix wage: " << e.fixWage() << ", Company revenue: " << e.companyResult();
    return s;
}

int Leader::getWageForMonth()
{
    return fixWage() + round(companyResult() * leader_cont);
}

int Leader::getContribution()
{
    return getWageForMonth();
}

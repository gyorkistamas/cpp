#include <iostream>
#include "worker.hpp"
#include "date.hpp"
#include "employee.hpp"
#include "contractor.hpp"
#include "leader.hpp"
using namespace std;

int main()
{
    Contractor c("Teszt", 2001, 4, 30, 10, 1500);

    cout << c << endl;

    cout << c.getWageForMonth() << endl;

    cout << c.getContribution() << endl;

    cout << c.getWageAndContribution() << endl;

    return 0;
}

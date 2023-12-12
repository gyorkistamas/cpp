#include <iostream>
#include "worker.hpp"
#include "date.hpp"
#include "employee.hpp"
#include "contractor.hpp"
using namespace std;

const float employee_cont = 1;
const float contractor_cont = 0.3;
const float leader_cont = 1;

int main()
{
    Employee e("Nev", 2001, 4, 30, 300, 300, 500);

    cout << contractor_cont;

    return 0;
}

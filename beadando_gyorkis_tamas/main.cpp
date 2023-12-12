#include <iostream>
#include "worker.hpp"
#include "date.hpp"
#include "employee.hpp"
#include "contractor.hpp"
using namespace std;

int main()
{
    Employee e("Nev", 2001, 4, 30, 300, 300, 500);

    cout << e;

    return 0;
}

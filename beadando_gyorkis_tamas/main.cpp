#include <iostream>
#include "worker.hpp"
#include "date.hpp"
#include "employee.hpp"
using namespace std;

int main()
{
    Employee e("Nev", 2001, 4, 30, 300, 300);

    cout << e;

    return 0;
}

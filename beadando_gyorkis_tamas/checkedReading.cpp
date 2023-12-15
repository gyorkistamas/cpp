#include <iostream>
#include <string>
#include "checkedReading.hpp"

using namespace std;

template<typename T>
T readChecked()
{
    T retval;
    cin >> retval;

    return retval;
}

template<>
int readChecked()
{
    int retval;
    string inputBuffer;
    bool doReading = true;
    while(doReading)
    {
        cin >> inputBuffer;
        doReading = false;
        try
        {
            retval = stoi(inputBuffer);
        }
        catch(...)
        {
            cout << "Please use an integer, try again: ";
            doReading = true;
        }
    }
    return retval;
}



template<>
string readChecked()
{
    string retval;
    bool doReading = true;
    while(doReading)
    {
        // Az�rt sz�ks�ges, hogy a sz�k�z�k ne okozzanak probl�m�t, azok is be legyenek olvasva
        getline(cin >> ws, retval);
        doReading = false;
        // Megvizsg�lom azt is, hogy nehogy �res string legyen
        if (retval.length() == 0)
        {
            cout << "Please don't leave it empty, try again: ";
            doReading = true;
        }
    }
    return retval;
}

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
        getline(cin >> ws, retval);
        doReading = false;
        if (retval.length() == 0)
        {
            cout << "Please don't leave it empty, try again: ";
            doReading = true;
        }
    }
    return retval;
}

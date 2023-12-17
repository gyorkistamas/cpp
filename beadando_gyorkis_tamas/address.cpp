#include "address.hpp"
#include <string>
#include <iostream>
#include "checkedReading.hpp"

using namespace std;

/** << oper�tor t�lterhel�s
 */
ostream& operator<<(ostream& s, Address& a)
{
    s << a.country() << ", " << a.postCode() << ", " << a.city() << ", " << a.street() << " street " << a.houseNumber() << ". ";
    return s;
}

/** B�rmely dolgoz�nak a lakc�m m�dos�t�sa sor�n ez a met�dus h�v�dik meg,
 *  ahol men�b�l kiv�laszthatja, hogy a c�m melyik r�sz�t szeretn� megv�ltoztatni
 */
void Address::update()
{
    bool doReading = true;

    while (doReading)
    {
        cout << "1. Update Country" << endl;
        cout << "2. Update postcode" << endl;
        cout << "3. Update city" << endl;
        cout << "4. Update street" << endl;
        cout << "5. Update house number" << endl;
        cout << "6. Go back" << endl;

        cout << "Enter your selection: ";
        int selection = readChecked<int>();

        switch(selection)
        {
        case 1:
            cout << "Enter new country: ";
            setCountry(readChecked<string>());
            break;
        case 2:
            cout << "Enter new postcode: ";
            setPostCode(readChecked<int>());
            break;
        case 3:
            cout << "Enter new city: ";
            setCity(readChecked<string>());
            break;
        case 4:
            cout << "Enter new street: ";
            setStreet(readChecked<string>());
            break;
        case 5:
            cout << "Enter new house number: ";
            setHouseNumber(readChecked<int>());
            break;
        case 6:
            doReading = false;
            break;
        default:
            cout << "Invalid option, try again" << endl;
            break;
        }
    }
}

/** C�m objektum �talak�t�sa olyan form�tumra,
 *  ahogy a csv f�jlba fog �r�dni
 */
string Address::getFileFormat()
{
    string line = country() + ";" + to_string(postCode()) + ";" + city() + ";" + street() + ";" + to_string(houseNumber());
    return line;
}

#pragma once
#include <string>

// Ellen�rz�tt beolvas�s int �s string eset�re
template<typename T>
T readChecked();

template<>
int readChecked();

template<>
std::string readChecked();

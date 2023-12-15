#pragma once
#include <string>

// Ellenõrzött beolvasás int és string esetére
template<typename T>
T readChecked();

template<>
int readChecked();

template<>
std::string readChecked();

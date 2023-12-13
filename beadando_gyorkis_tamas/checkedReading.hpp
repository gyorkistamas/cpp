#pragma once
#include <string>

template<typename T>
T readChecked();

template<>
int readChecked();

template<>
std::string readChecked();

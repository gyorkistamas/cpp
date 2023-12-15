#pragma once
#include <string>
#include <iostream>

using namespace std;

class Address
{
public:
    Address(string country, int postCode, string city, string street, int houseNumber):
        country_m(country), postcode_m(postCode), city_m(city), street_m(street), house_number_m(houseNumber) {}

    string country() {return country_m;}
    int postCode() {return postcode_m;}
    string city() {return city_m;}
    string street() {return street_m;}
    int houseNumber() {return house_number_m;}

    void setCountry(string value) {country_m = value;}
    void setPostCode(int value) {postcode_m = value;}
    void setCity(string value) {city_m = value;}
    void setStreet(string value) {street_m = value;}
    void setHouseNumber(int value) {house_number_m = value;}

private:
    string country_m;
    int postcode_m;
    string city_m;
    string street_m;
    int house_number_m;
};

ostream& operator<<(ostream& s, Address& a);

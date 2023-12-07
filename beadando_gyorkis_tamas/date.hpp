#pragma once
#include <iostream>

using std::ostream;

class Date
{
public:
    Date(int year, int month, int day) : year_m(year), month_m(month), day_m(day) {}

    int year() {return year_m;}
    int month() {return month_m;}
    int day() {return day_m;}

    void setYear(int year) {year_m = year;}
    void setMonth(int month) {month_m = month;}
    void setDay(int day) {day_m = day;}


private:
    int year_m;
    int month_m;
    int day_m;
};

ostream& operator<<(ostream &s, Date &date);


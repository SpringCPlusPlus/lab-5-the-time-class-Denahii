#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const
{   
    int totalMinutes = (hours * 60 + minutes) + (other.hours * 60 + other.minutes);
    return Time(totalMinutes / 60, totalMinutes % 60);
}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{   
    int totalMinutes = (hours * 60 + minutes) + (other.hours * 60 + other.minutes);
    hours = totalMinutes / 60;
    minutes = totalMinutes % 60;
    return *this;
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
    return(hours * 60 + minutes) < (other.hours * 60 + other.minutes);
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    return(hours * 60 + minutes) > (other.hours * 60 + other.minutes);
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    return(hours * 60 + minutes) == (other.hours * 60 + other.minutes);
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    os<< tm.hours << "h " << tm.minutes << "m";
    return os;
}

/*
 *Tititle{ COMP3140 Project Stage 2
 *File name{} Date.cpp
 *File Type{} Imlementation File 
 *Date{} 11/16/2020
 */
#include "Date.h"
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
//Constructors
Date::Date(const int &newDay, const int &newMonth, const int &newYear)
    : day(newDay), month(newMonth), year(newYear)
{
    checkValidDate();
}
Date::Date()
{
    //default Date? do we even want this?
}
Date::Date(const Date &date)
    : day(date.day), month(date.month), year(date.year)
{
}
//Destructors
Date::~Date() {}
//Mutators
void Date::setDay(const int &newDay) { this->day = newDay; }
void Date::setMonth(const int &newMonth) { this->month = newMonth; }
void Date::setYear(const int &newYear) { this->year = newYear; }
//Accessors
int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }
//Return full date information
string Date::getDate()
{
    return (to_string(month) + "/" + to_string(getDay()) + "/" + to_string(year));
}
//Converts a numbered month into a worded one. i.e. January, Febuary, March, April... etc
string Date::converMonth(int m)
{
    std::vector<std::string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return (months[m-1]);
}
//Checks if the given numbers is a valid date by checking if days is between
//1 - 31, Months is 1 - 12, and Year is correct.
bool Date::checkValidDate()
{
    //checking if days is between 1 - 31
    if(day<0 || day >31)
    return false;

    //Months is 1 - 12
    if(month<0 || month >12)
    return false;

   time_t now = time(0);
   tm *ltm = localtime(&now);

    if(year>1900 + ltm->tm_year)
    return false;

    return true;
}
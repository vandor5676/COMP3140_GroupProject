/*
 *Tititle: COMP3140 Project Stage 2
 *File name: Manager.cpp
 *File Type: Imlementation File 
 *Date: 11/16/2020
 */
#include "Manager.h"
#include "Date.h"
#include "Person.cpp"
using namespace std;
#include <iostream>

//Constructors
Manager::Manager(const string &newName, const int &newAge, const string &newGender, const Date &newHired_date, const double &newSalary, const double &newBouns, const double &newMonthly_expense)
    : Person(newName, newAge, newGender), bouns(newBouns), salary(newSalary), Monthly_expense(newMonthly_expense)
{
    this->hired_date = Date(newHired_date);
}
Manager::Manager()
{
}
//Destructors
Manager::~Manager()
{
}
//Mutators
void Manager::setHired_Date(const Date &date)
{
    this->hired_date = date;
}
void Manager::setSalary(const double &newSalary)
{
    this->salary = newSalary;
}
void Manager::setBouns(const double &newBouns)
{
    this->bouns = newBouns;
}
void Manager::setMonthly_expense(const double &new_me)
{
    this->Monthly_expense = new_me;
}
//Accessors
Date Manager::getHired_Date(Date date)
{
    return (this->hired_date);
}
double Manager::getSalary(double newSalary)
{
    return (this->salary);
}
double Manager::getBouns(double newBouns)
{
    return (this->bouns);
}
double Manager::getMonthly_expense(double new_me)
{
    return (this->Monthly_expense);
}
//Print information of Manager
void Manager::printInfo() const
{
    cout << "ManagerInfo" << endl;
    cout << "Date: notImplemented" << endl;
    cout << "Salary: " + to_string(salary) << endl;
    cout << "Bouns: " + to_string(bouns) << endl;
    cout << "Monthly Expence: " + to_string(Monthly_expense) << endl;
}
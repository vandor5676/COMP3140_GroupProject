/*
 *Tititle: COMP3140 Project Stage 2
 *File name: Manager.cpp
 *File Type: Imlementation File 
 *Date: 11/16/2020
 */
#include "Manager.h"
using namespace std;
#include <iostream>

//Constructors
Manager::Manager(const string &newName, const int &newAge, const string &newGender, const Date &newHired_date, const double &newSalary, const double &newBouns, const double &newMonthly_expense)
    : Person(newName, newAge, newGender), bouns(newBouns), salary(newSalary), Monthly_expense(newMonthly_expense)
{
    this->hired_date = Date(newHired_date);
    this->hired_date.getDate();
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
    this->hired_date.getDate();
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
void useablePrintInfo(Manager m)
{
    const Date newDate(1, 1, 1);
    cout << "ManagerInfo" << endl;
    cout << "Name: " << m.getName() << endl;
    cout << "Date: "+ m.getHired_Date(newDate).getDate() << endl;
    cout << "Salary: " + to_string(m.getSalary(1.0)) << endl;
    cout << "Bouns: " + to_string(m.getBouns(1)) << endl;
    cout << "Monthly Expence: " + to_string(m.getMonthly_expense(1)) << endl;
}
//Print information of Manager
void Manager::printInfo() const
{
    
    useablePrintInfo(*this);
}

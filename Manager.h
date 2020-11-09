/*
* Title: COMP 3140 project
* File: Manager.h
* Description: this is the interface file for the Manager class
*
* Author: shane steiner
* Version (optional)
* Student ID: t00622768
* Date: 11/6/2020
*/

//implement later
//#include "Manager.cpp"
#ifndef MANAGER_CPP
#define MANAGER_CPP
#endif

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Manager //: public Person
{
private:
    /* name , age , gender inherited from person class */
   
    time_t hireDate; //date hired in utc format
    double salary;
    double bonus;
    double monthlyExpense;

public:
    //constructors
    Manager(string name, int age, string gender, time_t hireDate, double salary, double bonus, double monthlyExpense);
    Manager(const Manager &m);
    ~Manager();

    //get set
    time_t getHireDate();
    void setHireDate(time_t hireDate);

    double getSalary();
    void setSalary(double salary);

    double getBonus();
    void setBonus(double bonus);

    double getMonthlyExpense();
    void setMonthlyExpense(double monthlyExpense);
    //
    //member fuctions
    //

    //gets total manager expense for a set number of months 
    double managerTotalExpense(int numberOfMonths);

    //gets total manager salary and bonus for a set number of months 
    double managerSalarieAndBonus(int numberOfMonths);

    //Profile of each tenant and manager(i assume this means a print function)
    void Profile();
    
    //
    //end member fuctions
    //
};

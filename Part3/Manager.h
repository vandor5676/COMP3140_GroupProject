/*********************************************************************************************************
* Title: COMP 3140 Team Project - Stage 1 -  Manager.h
* Description: Interface file for Manager
* Author: Kiel Riley, Cody Painter, and C. Malcolm Todd
* Student ID: T00538035, T00546693, T00232792
* Date: November 13th, 2020
*********************************************************************************************************/
#ifndef MANAGER_H
#define MANAGER_H

#include "Person.h"
#include <string>
#include <vector>

using namespace std;

class Manager : public Person {

private:
    string hireDate;
    double salary;
    double bonus;
    vector<double> monthlyExpenses;

public:
    // The default constructor and destructor are sufficient
    Manager() = default;
    ~Manager() = default;

    Manager(string name, int age, string gender, string hireDate,
                double salary, double bonus);

    string getHireDate() const;
    double getSalary() const;
    double getBonus() const;
    vector<double> getMonthlyExpenses() const;
    void setHireDate(string newHireDate);
    void setSalary(double newSalary);
    void setBonus(double newBonus);
    void setMonthlyExpenses(vector<double> monthlyExpenses);
    
    // Get and set individual monthly expenses
    double getExpenseForMonth(int month) const;
    void setExpenseForMonth(int month, double expense);

    // Calculate the total expense over the six month period
    double calcExpenseTotal() const;

    // Calculate this managers bonus for each month and for six months
    double calcSalaryForMonth(int month) const;
    double calcSalaryTotal() const;

    // Calculate this managers bonus for each month and for six months
    double calcBonusForMonth(int month) const;
    double calcBonusTotal() const;

    // Calculate this managers remuneration for each month and for six months
    double calcRemunerationForMonth(int month) const;
    double calcRemunerationTotal() const;

    // Returns a string containing a visual representation of manager information.
    string getProfile() const;
};
#endif

#include "Manager.h"
#include <iostream>
#include <assert.h>
#include <sstream>
#include <iomanip>

Manager :: Manager(string name, int age, string gender, string hireDate, double salary, double b)
:Person (name,age,gender), hireDate(hireDate), salary(salary), bonus(b)
{    
   monthlyExpenses = vector<double>{0.0,6};
}

string Manager :: getHireDate() const {
    return hireDate;
}

double Manager :: getSalary() const {
    return salary;
}

double Manager :: getBonus() const {
    return bonus;
}

vector<double>  Manager :: getMonthlyExpenses() const {
    return monthlyExpenses;
}
 
void Manager :: setHireDate(string hd) {
    hireDate= hd;
}

void Manager :: setSalary(double s) {
    salary= s;
}

void Manager :: setBonus(double b) {
    bonus = b;
}

void Manager :: setMonthlyExpenses(vector <double> monthlyExpenses) {
    Manager::monthlyExpenses.assign(monthlyExpenses.begin(), monthlyExpenses.end());
}

double Manager :: getExpenseForMonth(int month) const {
    assert(month >= 0 && month <= 5);
    return monthlyExpenses[month];
}

void Manager :: setExpenseForMonth(int month, double monthlyExpense) {
    assert(month >= 0 && month <= 5);
    monthlyExpenses[month]= monthlyExpense ;
}

double Manager :: calcExpenseTotal() const {
    int size = monthlyExpenses.size();
    double total = 0.0;
    if(size-6 >= 0) {
        for(int i = size; i > size-6; i--) {
            total+=monthlyExpenses[i];
        }
    }
    else {
       for(int i = size; i >= 0; i--) {
            total+=monthlyExpenses[i];
        }
    }    
    return total;
}

double Manager :: calcSalaryForMonth(int m) const {
    return salary;
}

double Manager :: calcSalaryTotal() const {
    double total = 0.0;
    total = getSalary();
    total*=6;
    return total;
}

double Manager :: calcBonusForMonth(int month) const {
    return bonus;
}

double Manager :: calcBonusTotal() const {
    double total = 0.0;
    total = getBonus();
    total*=6;
    return total;
}

double  Manager ::  calcRemunerationForMonth(int month) const {
    double total= 0.0;
    total += getBonus();
    total += getSalary();
    return total;
}

double  Manager :: calcRemunerationTotal() const {
    double total = 0.0;
    total+= calcSalaryTotal();
    total+= calcBonusTotal();
    return total;
}

string Manager::getProfile() const {
    stringstream profile;
    profile.setf(ios::left);
    profile.setf(ios::fixed);
    profile.precision(2);
    profile << "[MANAGER]" << endl
            << setw(14) << "MANAGER Name: " << name << endl
            << setw(14) << "Age: " << age << endl
            << setw(14) << "Gender: " << gender << endl
            << setw(14) << "Hired date: " << hireDate << endl
            << setw(14) << "Salary: $: " << salary << endl
            << setw(14) << "Bonus: $" << bonus << endl;
            "\n";
    return profile.str();
}
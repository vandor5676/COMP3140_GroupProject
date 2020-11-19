/*
 *Tititle: COMP3140 Project Stage 1
 *File name: Manager.h
 *File Type: Interface File 
 *Date: 11/13/2020
 */
#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include"Date.h"
#include"Person.h"

using namespace std;

class Manager : public Person
{
    private:
        //date manager was hired using a Date object
        Date hired_date;

        // the managers salary
        double salary;

        // the managers bonus 
        double bouns;

        //the managers monthly expences
        double Monthly_expense;
    public:

        //
        //Constructors
        //

        //creates a new manager with a name, age, gender, hiredate, dalary, bonus and monthly expence
        Manager(const string& newName,const int& newAge,
        const string& newGender,const Date& newHired_date,
        const double& newSalary,const double& newBouns,
        const double& newMonthly_expense);

        //creates a new manager
        Manager();

        //
        //Destructors
        //

        //deconstructs a manager
        virtual ~Manager();

        //
        //Mutators
        //

        // sets the hired date
        void setHired_Date(const Date& date);
        //sets the salary
        void setSalary(const double& newSalary);
        //sets the bonus
        void setBouns(const double& newBouns);
        //sets the monthly expence
        void setMonthly_expense(const double& new_me);
        //
        //Accessors
        //
        //gets the hired date
        Date getHired_Date(Date date);
        //gets the salary
        double getSalary(double newSalary);
        //gets the bonus
        double getBouns(double newBouns);
        // getst the monthly expence
        double getMonthly_expense(double new_me);
        //Print information of Manager
        virtual void printInfo() const;
};
#endif


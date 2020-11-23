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
        Date hired_date;
        double salary;
        double bouns;
        double monthly_expense;
    public:
        //Constructors
        Manager(const string& newName,const int& newAge,
        const string& newGender,const Date& newHired_date,
        const double& newSalary,const double& newBouns,
        const double& newMonthly_expense);
        Manager();
        //Destructors
        virtual ~Manager();
        //Mutators
        void setHired_Date(const Date& date);
        void setSalary(const double& newSalary);
        void setBouns(const double& newBouns);
        void setMonthly_expense(const double& new_me);
        //Accessors
        Date getHired_Date(Date date);
        double getSalary(double newSalary);
        double getBouns(double newBouns);
        double getMonthly_expense(double new_me);
        //Print information of Manager
        virtual void printInfo() const;
};
#endif


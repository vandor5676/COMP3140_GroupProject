/*
* Title: COMP 3140 Assignment 6
* File: driver.cpp
* Description: this is the main driver 
*
* Date: 9/25/2020
*/

#include <iostream>
#include <string>
// #include "ManagementExtraFunctions.h" 
// #include "Date.h"
// #include "Tenant.h" 

#include "Management.cpp"   
#include "Manager.cpp" 
#include "ManagementExtraFunctions.cpp"   
#include "Date.cpp"
#include "Tenant.cpp" 
#include "Person.cpp"
using namespace std; 

int main()
{
    bool shanesTests = true;
    if (shanesTests)
    {
        cout << "Start" << endl;
        //test date
        Date d(1, 2, 2021);

        //test readFile() using ManagementExtraFunctions also tests populateTenantList() and populateManagerList() in ManagementExtraFunctions
        cout << "\ntest readFile and ManagementExtraFunctions populateTenantList() class" << endl;
        ManagementExtraFunctions management("Managers.csv", "Tenants.csv");
        management.accessableTenantArr[2].printInfo();
        cout << management.tenantPaymentHistory[0][0] << endl
             << endl;

        //test Date class
        cout << "\ntest Date class" << endl;
        Date newDate(11, 21, 2020);
        cout << newDate.getDate() << endl;
        newDate.setDay(1);
        newDate.setYear(1999);
        newDate.setMonth(2);
        cout << newDate.getDate() << endl;

        //test manager class
        cout << "\ntest manager class" << endl;
        Manager testmanager("Shane", 24,
                            "Male", newDate,
                            100.0, 200.0,
                            300.0);
        testmanager.printInfo();
        cout << endl;
        testmanager.setSalary(1.0);
        testmanager.setMonthly_expense(2.0);
        testmanager.setHired_Date(newDate);
        testmanager.setBouns(3.0);
        testmanager.printInfo();

        //test collectRentalFee function
        cout << "\ntest collectRentalFee function" << endl;
        management.collectRentalFee();
        cout << management.getTotalRentCollected() << endl;
        cout << management.getTotalRentCollectedPerMonth(0) << endl;

        //test listTenantsNotPaid()
        cout << "\ntest listTenantsNotPay function" << endl;
        management.listTenantsNotPay();

        //test missingRental function
        cout << "\ntest missingRental function" << endl;
        management.missingRental();
        cout << management.getTotalUnPaidRentCollected() << endl;
        cout << management.getTotalUnPaidRentCollectedPerMonth(1) << endl;

        //test Person class
        cout << "\ntest Person class" << endl;
        Person p("Shane", 24, "Male");
        string  name = "notShane" ;
        p.setName(name);  
        string age = "1"; 
        p.setAge(age);
        int gender = 2; 
        p.setGender(gender);
        p.printInfo();

//test Tenant class
        cout << "\ntest Tenant class" << endl;
    Tenant t("shane",24,"Male", "Programmer", 100,newDate, 1.0, 'y' );
    string name2 = "newName";
    t.setName(name2);
    string age2 = "1"; 
    t.setAge(age2);
    int gender2 = 3; 
    t.setGender(gender2);
    t.setJob("newJob");
    t.setUnitNumber(1);
    t.setMonthlyRent(2.0);
    t.setPaymentStatus('n');
    t.printInfo();


        
    }

    bool LoganTest = true;
    if(LoganTest){ 
        ManagementExtraFunctions management2("Managers.csv", "Tenants.csv");
        management2.collectRentalFee();
        cout << "The profiles of all managers: " << endl;
        management2.profile_manager();
        cout << endl;
        cout << "The profiles of all tenants: " << endl;
        management2.profile_tenant();
        cout << endl;
        cout << "The salaries and bonuses of all managers: " << endl;
        management2.managerSalary_bouns();
        cout << endl;
        cout << "The total expenses of all managers: " << endl;
        management2.totalExpense();
        cout << endl;
        cout << "The net income: " << endl;
        management2.netIncome();
    }

    system("pause");
    return 0;
}
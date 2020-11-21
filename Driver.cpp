/*
* Title: COMP 3140 Assignment 6
* File: driver.cpp
* Description: this is the main driver 
*
* Date: 9/25/2020
*/
#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <string>
#include "Manager.cpp"
#include "Management.cpp"
#include "ManagementExtraFunctions.cpp"
#include "Date.cpp"
#include "Tenant.cpp"

using namespace std;

int main()
{
    bool shanesTests = true;
    if (shanesTests)
    {
        cout << "Start" << endl;
        //test date
        Date d(1, 2, 2021);

        //test readFile() using ManagementExtraFunctions also tests populateTenantList() in ManagementExtraFunctions
        cout << "\ntest readFile and ManagementExtraFunctions populateTenantList() class" << endl;
        ManagementExtraFunctions managment("Managers.csv", "Tenants.csv");
        managment.accessableTenantArr[2].printInfo();
        cout << managment.tenantPaymentHistory[0][0] << endl;

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
        Manager testmanager("Shnae", 24,
                            "Male", newDate,
                            100.0, 200.0,
                            300.0);
        testmanager.printInfo();
        cout<<endl;
        testmanager.setSalary(1.0);
        testmanager.setMonthly_expense(2.0);
        testmanager.setHired_Date(newDate);
        testmanager.setBouns(3.0);
        testmanager.printInfo();

        //test collectRentalFee function
        cout << "\ntest collectRentalFee function" << endl;
        managment.collectRentalFee();
        cout << managment.getTotalRentCollected() << endl;
        cout << managment.getTotalRentCollectedPerMonth(0) << endl;

        int stopint = 1;
    }
}
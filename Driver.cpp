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
    if(shanesTests)
    {
        cout<< "Start"<<endl;
        //test date
        Date d(1, 2, 2021);

        //test readFile() using ManagementExtraFunctions
        ManagementExtraFunctions managment("Managers.csv", "Tenants.csv");
        cout<<managment.tenantPaymentHistory[0][0]<<endl; 
       
       //test collectRentalFee function
       cout<< "\ntest collectRentalFee function" <<endl;
       managment.collectRentalFee();
       cout << managment.getTotalRentCollected() << endl;
       cout << managment.getTotalRentCollectedPerMonth(0) << endl;

       int stopint = 1;
    }
    
    
}
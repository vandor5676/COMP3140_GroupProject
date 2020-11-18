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
        Date d(1, 2, 2021);
        //Management managment("Managers.csv");
        ManagementExtraFunctions managment("Managers.csv", "Tenants.csv");
        cout<<managment.tenantPaymentHistory[0][0]<<endl; 
        int stopint = 1;
    }
    
    // Manager m("Sarah",23,
    //     "female",d,
    //     100.01,50.01,
    //     200.01);

    
}
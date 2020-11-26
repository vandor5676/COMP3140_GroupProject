/*
* Title: COMP 3140 project
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

// #include "Manager.h"
#include "RentalPropertyManager.h" 

// #include "Tenant.h"
// #include "Person.h"
using namespace std;

int main()
{
    bool shanesTests = true;
    if (shanesTests)
    {
        cout << "Start" << endl;

        RentalPropertyManager rpm;
        rpm.loadManagers("Managers.csv");
        rpm.RentalPropertyManager::loadTenants("Tenants.csv");

        int stopInt=0;
    }
}
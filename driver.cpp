/*
* Title: COMP 3140 project
* File: driver.cpp
* Description: this is the main driver 
*
* Date: 9/25/2020
*/

#include <iostream>
#include <string>

//these imports might cause problems for you. add or delete them if you need to.
#include "RentalPropertyManager.cpp"
#include "Person.cpp"
#include "Manager.cpp"
#include "Tenant.cpp"

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
        cout << "End" << endl;

    }
}
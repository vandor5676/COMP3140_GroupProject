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
#include "ExtendedPropertyManager.cpp"
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
        rpm.loadTenants("Tenants.csv");

        ExtendedPropertyManager erpm; 
        erpm.loadManagers("Managers.csv");
        erpm.loadTenants("Tenants.csv");
        cout << erpm.publicManagerList.at(1).getName() <<endl;
        cout << erpm.publicTenantList.at(10).getName()<<endl;
      
      int stopInt = 0;
      cout << "End" << endl;

    }
}
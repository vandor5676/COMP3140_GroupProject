/*********************************************************************************************************
* Title: COMP 3140 Team Project - Stage 1 -  RentalPropertyManager.h
* Description: need to acces private members
* Author: shane steiner

* Date: November 27th, 2020
*********************************************************************************************************/

#ifndef EXTENDEDPROPERTYMANAGER_H
#define EXTENDEDPROPERTYMANAGER_H

#include "RentalPropertyManager.h"

using namespace std;

class ExtendedPropertyManager : public RentalPropertyManager
{
private:
public:
    vector<Tenant> publicTenantList;
    vector<Manager> publicManagerList;

    //constructors
    ExtendedPropertyManager();


    // Load tenant and manager data from CSV file
    void loadManagers(string managerDataFile);
    void loadTenants(string tenantDataFile);
};
#endif
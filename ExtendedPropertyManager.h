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

    //Getters and Setters to be able to access managerList and tenantList from the driver program
    vector<Tenant> getTenantList();
    vector<Manager> getManagerList();

    void setManagerList(vector<Manager> newManagerList);
    void setTenantList(vector<Tenant> newTenantList);

    // Load tenant and manager data from CSV file
    void loadManagers(string managerDataFile);
    void loadTenants(string tenantDataFile);

    //load second tenant and manager files
    void loadExtraTenantData(string fileName);
    void loadExtraManagerData(string fileName);

    //print out tenant/manager info as csv string
    string getManagerCSV(Manager m, int i);
    string getTenantCSV(Tenant m, int i); 

    //generate a monthly summary of the net income
    string createNetIncomeMonthlySummary();

    //generate the total expense summary for each month and a year
    string createExpenseMonthlySummary();

    //generate a string showing the salaries and bonuses of each manager
    string getManagerSalariesBonuses();
    

};
#endif
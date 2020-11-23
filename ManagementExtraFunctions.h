/*
 *Tititle: COMP3140 Project Stage 1
 *File name: ManagementExtraFunctions.h
 *File Type: Interface File 
 *Date: 11/13/2020
 */
#ifndef MANAGEMENTEXTRAFUNCTIONS_H
#define MANAGEMENTEXTRAFUNCTIONS_H
#ifndef MANAGEMNET_DEF
#include "Management.h"
#endif


#include <list>
#include <iterator>
class ManagementExtraFunctions : public Management
{
private:
    //holds total rent from each tenant per month
    double totalRentCollectedPerMonth[12] ={0};
    // holds total rent for 6 months
    double totalRentCollected = 0;         

public:
    //holds all tenants 
    Tenant accessableTenantArr[100];     // cant access base class due to protection so this is our workaround i guess
    //holds tanant payment information( like paid or not paid)
    string tenantPaymentHistory[100][6]; //this is going to hold all of the info from the .CSV file that i cant put in the Tenant class (just the payment status)

    //holds all manager monthly expense information
    double managerMonthlyExpenses[2][12];
    //Similar to the tenant issue, the manager array is not accessable so this is a workaround
    Manager accessableManagerArr[2];

    //the name of the tenant file
    string tenantFileName;

    //constructs a object with all tennants and managers as well as functions to calulate information
    ManagementExtraFunctions(const string &newManagerFileName, const string &newTenantFileName);
    //deconstructs a ManagementExtraFunctions object
    ~ManagementExtraFunctions();

    //functions
    Date createDateFromString(string date);
    void populateTenantList(string tenantFileName);
    void populateManagerList(string managerFileName);
    //Scans through tenantArr[] and checks their payment status, if it's true it checks their rental fee and adds it to a total
    //for the month as well as a total for 6 months. Does this process 6 times for each month.
    void collectRentalFee();
    //Scans through the tenantArr[] and lists any tenants, along with their current index, with payment status set to false.
    void listTenantsNotPay();
    //method to determine who hasn't paid their rent, then adds up the total missing rent for the month
    //then continues to add the total of missing rent for the past 6 months before printing it out.
    void missingRental();
    //Scans through the managerArr[] and grabs the total expenses data held in every manager then adds them together and displays the total. It continues to do this for every month
    //as well as the past 6 months.
    void totalExpense();
    //Scans through the managerArr[] and displays the total salary and bonus of every month as well as the total earned the past 6 months. It does this for every individual manager.
    void managerSalary_bouns();
    //NetIncome = (total rent collection)- (managers expense)-(salary and bonus expense)
    void netIncome();
    //Print out all tenants' profile.
    void profile_tenant();
    //Print out all Manager' profile.
    void profile_manager();

    //
    //getter setter
    //

    //get and set the total rent per month and the total rent in 6 months
    double getTotalRentCollectedPerMonth(int i);
    void setTotalRentCollectedPerMonth(double totalRentCollected, int month);
    void addTotalRentCollectedPerMonth(double totalRentCollected, int month);//used to total up totalRentCollectedPerMonth array
    double getTotalRentCollected();
    void setTotalRentCollected(double totalRentCollected);
};

#endif

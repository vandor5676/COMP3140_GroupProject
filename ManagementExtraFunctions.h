/*
 *Tititle: COMP3140 Project Stage 1
 *File name: ManagementExtraFunctions.h
 *File Type: Interface File 
 *Date: 11/13/2020
 */
#ifndef MANAGEMNET_DEF
#include "Management.h"
#endif
#include <list>
#include <iterator>
class ManagementExtraFunctions : public Management
{
private:
    double totalRentCollectedPerMonth[12] ={0}; //holds total rent from each tenant per month
    double totalRentCollected = 0;         // holds total rent for 6 months

public:
    Tenant accessableTenantArr[100];     // cant access base class due to protection so this is our workaround i guess
    string tenantPaymentHistory[100][6]; //this is going to hold all of the info from the .CSV file that i cant put in the Tenant class (just the payment status)

    string tenantFileName;

    ManagementExtraFunctions(const string &newManagerFileName, const string &newTenantFileName);
    ~ManagementExtraFunctions();

    //functions
    Date createDateFromString(string date);
    void populateTenantList(string tenantFileName);
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

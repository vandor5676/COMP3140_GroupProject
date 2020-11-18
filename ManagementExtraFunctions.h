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
    // Tenant accessableTenantArr[100]; // cant access base class due to protection so this is our workaround i guess
    // list <list<string>> tenantPaymentHistory; //this is going to hold all of the info from the .CSV file that i cant put in the Tenant class (just the payment status)
    // string tenantFileName;
public:
    Tenant accessableTenantArr[100];         // cant access base class due to protection so this is our workaround i guess
    string tenantPaymentHistory[100][6]; //this is going to hold all of the info from the .CSV file that i cant put in the Tenant class (just the payment status)

    string tenantFileName;

    ManagementExtraFunctions(const string &newManagerFileName, const string &newTenantFileName);
    ~ManagementExtraFunctions();

    //functions
    Date createDateFromString(string date);
    void populateTenantList(string tenantFileName);
};

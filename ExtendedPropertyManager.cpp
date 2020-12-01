#include "ExtendedPropertyManager.h"

#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <assert.h>
#include <exception>
#include <vector>

/**************************************************************************************
 * HELPER FUNCITON PROTOTYPES
 **************************************************************************************/

Manager managerFromLine(string);
Tenant tenantFromLine(string);

//helpers
Manager addManagerFromLine(string line, Manager m);
Tenant addTenantFromLine(string line, Tenant t);
vector<string> tokenize(const string &input, string delims);
void trimSpaces(string &input);
template <class T>
void loadData(string filepath, vector<T> &container, T (*loadproc)(string, T));
template <class T>
void loadData(string, vector<T> &, T (*)(string));

bool mapPaymentStatus(string status);
void openDataFile(ifstream &file, string filename);
vector<string> readLines(ifstream &file);
string PaymentStatusToString(bool status);

//constants
const size_t TENANT_FILE_LINE_LENGTH = 13;
const size_t MANAGER_FILE_LINE_LENGTH = 12;

//constructor
ExtendedPropertyManager::ExtendedPropertyManager()
{
}

vector<Tenant> ExtendedPropertyManager::getTenantList(){
    return tenantList;
};
vector<Manager> ExtendedPropertyManager::getManagerList(){
    return managerList;
};

void ExtendedPropertyManager::setManagerList(vector<Manager> newManagerList){
    this->managerList = newManagerList;
};
void ExtendedPropertyManager::setTenantList(vector<Tenant> newTenantList){
    this->tenantList = newTenantList;
};

void ExtendedPropertyManager::loadTenants(string filepath)
{
    loadData(filepath, tenantList, tenantFromLine);
}
void ExtendedPropertyManager::loadManagers(string filepath)
{
    loadData(filepath, managerList, managerFromLine);
}

void ExtendedPropertyManager::loadExtraTenantData(string fileName)
{
    loadData(fileName, tenantList, addTenantFromLine);
}
void ExtendedPropertyManager::loadExtraManagerData(string fileName)
{
    loadData(fileName, managerList, addManagerFromLine);
}

//
//used to load second file into managerlist and tenantlist
//

//used to add payment history to exsisting manager object
Manager addManagerFromLine(string line, Manager m)
{

    auto tokens = tokenize(line, ",");

    if (tokens.size() != MANAGER_FILE_LINE_LENGTH)
    {
        throw invalid_argument("Caught malformed line in manager data file."
                               "Caused by: " +
                               line);
    }

    Manager manager = Manager(
        tokens.at(0),
        stoi(tokens.at(1)),
        tokens.at(2),
        tokens.at(3),
        stod(tokens.at(4)),
        stod(tokens.at(5)));

    manager.setMonthlyExpenses({
        m.getMonthlyExpenses().at(0),
        m.getMonthlyExpenses().at(1),
        m.getMonthlyExpenses().at(2),
        m.getMonthlyExpenses().at(3),
        m.getMonthlyExpenses().at(4),
        m.getMonthlyExpenses().at(5),
        stod(tokens.at(6)),
        stod(tokens.at(7)),
        stod(tokens.at(8)),
        stod(tokens.at(9)),
        stod(tokens.at(10)),
        stod(tokens.at(11)),
    });

    return manager;
}
/**
 * Builds a tenant object from a line read from a tenant data file.
 * 
 * @param line A line read from a tenant CSV data file.
 */
Tenant addTenantFromLine(string line, Tenant t)
{

    auto tokens = tokenize(line, ",");

    if (tokens.size() != TENANT_FILE_LINE_LENGTH)
    {
        throw invalid_argument("Caught malformed line in tenant data file.\n"
                               "Caused by: " +
                               line);
    }

    // sto_ functions can throw an invalid_argument exception
    Tenant newTenant = Tenant(
        tokens.at(0),
        stoi(tokens.at(1)),
        tokens.at(2),
        stoi(tokens.at(4)),
        tokens.at(5),
        stod(tokens.at(6)));
    newTenant.setJob(tokens.at(3));

    newTenant.setPaymentsStatus({
        t.getPaymentsStatus().at(0),
        t.getPaymentsStatus().at(1),
        t.getPaymentsStatus().at(2),
        t.getPaymentsStatus().at(3),
        t.getPaymentsStatus().at(4),
        t.getPaymentsStatus().at(5),
        mapPaymentStatus(tokens.at(7)),
        mapPaymentStatus(tokens.at(8)),
        mapPaymentStatus(tokens.at(9)),
        mapPaymentStatus(tokens.at(10)),
        mapPaymentStatus(tokens.at(11)),
        mapPaymentStatus(tokens.at(12)),
    });

    return newTenant;
}

/**
 * Function to load either tenants or managers from a data file.
 *
 * @param filepath The path of the file to read.
 * @param container The container that will hold the managers or tenants.
 * @param loadproc A function that takes in a line and returns a manager or a tenant.
 */
template <class T>
void loadData(string filepath, vector<T> &container, T (*loadproc)(string, T))
{

    int i = 0;
    ifstream file;
    openDataFile(file, filepath);

    // Consume the header line
    file.ignore(numeric_limits<streamsize>::max(), '\n');

    auto lines = readLines(file);
    for (auto line : lines)
    {
        container.at(i) = (loadproc(line, container.at(i)));
        i++;
    }
}

//
// end --> used to load second file into managerlist and tenantlist
//

//
//used for writing to the output file
//
string ExtendedPropertyManager::getManagerCSV(Manager m ,int i)
{
    string returnString = "";

    returnString += m.getName() + ",";
    returnString += to_string(m.getAge()) + ",";
    returnString += m.getGender() + ",";
    returnString += m.getHireDate() + ","; 
    returnString += to_string(m.getSalary()) + ",";
    returnString += to_string(m.getBonus()) + ",";

    if(i == 1)
    {
    returnString += to_string(m.getMonthlyExpenses().at(0)) + ",";
    returnString += to_string(m.getMonthlyExpenses().at(1)) + ",";
    returnString += to_string(m.getMonthlyExpenses().at(2)) + ",";
    returnString += to_string(m.getMonthlyExpenses().at(3)) + ",";
    returnString += to_string(m.getMonthlyExpenses().at(4)) + ",";
    returnString += to_string(m.getMonthlyExpenses().at(5));        
    }
    else
    {
    returnString += to_string(m.getMonthlyExpenses().at(6)) + ",";
    returnString += to_string(m.getMonthlyExpenses().at(7)) + ",";
    returnString += to_string(m.getMonthlyExpenses().at(8)) + ",";
    returnString += to_string(m.getMonthlyExpenses().at(9)) + ",";
    returnString += to_string(m.getMonthlyExpenses().at(10)) + ",";
    returnString += to_string(m.getMonthlyExpenses().at(11)); 
    }
    return returnString;

}
string ExtendedPropertyManager::getTenantCSV(Tenant t , int i)
{
    string returnString = "";

    returnString += t.getName() + ",";
    returnString += to_string(t.getAge()) + ",";
    returnString += t.getGender() + ",";
    returnString += t.getJob() + ","; 
    returnString += to_string(t.getUnitNo()) + ",";
    returnString += t.getMoveInDate() + ",";
    returnString += to_string(t.getRentalFee()) + ",";

    if(i == 1)
    {
    returnString += PaymentStatusToString(t.getPaymentsStatus().at(0)) + ",";
    returnString += PaymentStatusToString(t.getPaymentsStatus().at(1)) + ",";
    returnString += PaymentStatusToString(t.getPaymentsStatus().at(2)) + ",";
    returnString += PaymentStatusToString(t.getPaymentsStatus().at(3)) + ",";
    returnString += PaymentStatusToString(t.getPaymentsStatus().at(4)) + ",";
    returnString += PaymentStatusToString(t.getPaymentsStatus().at(5));     
    }
    else
    {
    returnString += PaymentStatusToString(t.getPaymentsStatus().at(6)) + ",";
    returnString += PaymentStatusToString(t.getPaymentsStatus().at(7)) + ",";
    returnString += PaymentStatusToString(t.getPaymentsStatus().at(8)) + ",";
    returnString += PaymentStatusToString(t.getPaymentsStatus().at(9)) + ",";
    returnString += PaymentStatusToString(t.getPaymentsStatus().at(0)) + ",";
    returnString += PaymentStatusToString(t.getPaymentsStatus().at(11));
    }
    return returnString;
}
string PaymentStatusToString(bool status) {
    if (status == true) return "Paid";
    return "Not Paid";
}
//
//end -->used for writing to the output file
//

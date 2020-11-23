/*
 *Tititle: COMP3140 Project Stage 1
 *File name: ManagementExtraFunctionscpp
 *File Type: implementation File 
 *Date: 11/13/2020
 */

//Management needs more functions, this class provides them
// add any functions you need here

#include "ManagementExtraFunctions.h"
#include <vector>
#include <utility>   // pair
#include <stdexcept> // runtime_error
#include <sstream>   // stringstream
#include <numeric>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
ManagementExtraFunctions::ManagementExtraFunctions(const string &newManagerFileName, const string &newTenantFileName)
    : Management(newManagerFileName), tenantFileName(newTenantFileName)
{

    populateTenantList(newTenantFileName);
    populateManagerList(newManagerFileName);
}

ManagementExtraFunctions::~ManagementExtraFunctions()
{
}

void ManagementExtraFunctions::populateTenantList(string TenantCSV)
{
    vector<pair<string, vector<int>>> result;
    ifstream myFile(TenantCSV);

    if (!myFile.is_open())
        throw runtime_error("Could not open file"); // change error type?
    string line, colname;
    int val, tenantNumber = -1;
    vector<string> tenantPropertyList;

    while (myFile.good())
    {
        getline(myFile, line); // gets first line from file
        stringstream ss(line);
        while (getline(ss, colname, ','))
        { // cuts out values from line

            //cout << colname << endl;
            tenantPropertyList.push_back(colname);
        }
        if (tenantNumber == -1) // first line is descriptions
        {
            tenantNumber++;
            tenantPropertyList.clear();
            continue;
        }
        else if (line != "") // populate if line is not empty
        {
            string tempPaymentHistory[6];
            tenantPaymentHistory[tenantNumber][0] = (tenantPropertyList.at(7).c_str());
            tenantPaymentHistory[tenantNumber][1] = (tenantPropertyList.at(8).c_str());
            tenantPaymentHistory[tenantNumber][2] = (tenantPropertyList.at(9).c_str());
            tenantPaymentHistory[tenantNumber][3] = (tenantPropertyList.at(10).c_str());
            tenantPaymentHistory[tenantNumber][4] = (tenantPropertyList.at(11).c_str());
            tenantPaymentHistory[tenantNumber][5] = (tenantPropertyList.at(12).c_str());

            Tenant newTenant(tenantPropertyList.at(0).c_str(), stoi(tenantPropertyList.at(1).c_str()),
                             tenantPropertyList.at(2).c_str(), tenantPropertyList.at(3).c_str(),
                             stoi(tenantPropertyList.at(4).c_str()), createDateFromString(tenantPropertyList.at(5).c_str()),
                             stod(tenantPropertyList.at(6).c_str()),
                             'a');

            accessableTenantArr[tenantNumber] = newTenant;

            tenantNumber++;
            tenantPropertyList.clear();
        }
    }
    myFile.close();
}

void ManagementExtraFunctions ::populateManagerList(string managerFileName)
{
    string managerCSV1 = managerFileName;
    string fileType = managerFileName.substr(managerFileName.find("."), (managerFileName.length() - 1));
    string managerCSV2 = managerFileName.substr(0, managerFileName.find(".")) + "2" + fileType;
    bool isFirstLine = true;
    vector<pair<string, vector<int>>> result;
    ifstream myFile1(managerCSV1);
    ifstream myFile2(managerCSV2);

    if (!myFile1.is_open())
        throw runtime_error("Could not open file"); // change error type?
    if (!myFile2.is_open())
        throw runtime_error("Could not open file"); // change error type?
    string line, colname;
    int managerNumber = -1;
    vector<string> currentManager;

    //Gets all the info from the first CSV file, storing it.
    while (myFile1.good())
    {
        getline(myFile1, line); // gets first line from file
        stringstream ss1(line);
        while (getline(ss1, colname, ','))
        { // cuts out values from line

            //cout << colname << endl;
            currentManager.push_back(colname);
        }
        if (isFirstLine) // first line is descriptions
        {
            managerNumber++;
            currentManager.clear();
            isFirstLine = false;
            continue;
        }
        else if (line != "") // populate if line is not empty
        {
            managerMonthlyExpenses[managerNumber][0] = (stod(currentManager.at(6).c_str()));
            managerMonthlyExpenses[managerNumber][1] = (stod(currentManager.at(7).c_str()));
            managerMonthlyExpenses[managerNumber][2] = (stod(currentManager.at(8).c_str()));
            managerMonthlyExpenses[managerNumber][3] = (stod(currentManager.at(9).c_str()));
            managerMonthlyExpenses[managerNumber][4] = (stod(currentManager.at(10).c_str()));
            managerMonthlyExpenses[managerNumber][5] = (stod(currentManager.at(11).c_str()));

            Manager newManager = Manager(currentManager.at(0).c_str(), stoi(currentManager.at(1).c_str()), currentManager.at(2).c_str(),
                                         createDateFromString(currentManager.at(3).c_str()), stod(currentManager.at(4).c_str()), stod(currentManager.at(5).c_str()), 0.0);

            accessableManagerArr[managerNumber] = newManager;

            managerNumber++;
            currentManager.clear();
        }
    }
    myFile1.close();

    //Commented out as we are only working with 6 months right now
    //
    //Gets the info from the second manager CSV file, only storing the monthly expenses. 
    /*
    vector<string> currentManager2;
    isFirstLine = true;
    while (myFile2.good())
    {
        getline(myFile2, line); // gets first line from file
        stringstream ss2(line);
        while (getline(ss2, colname, ','))
        { // cuts out values from line

            //cout << colname << endl;
            currentManager2.push_back(colname);
        }
        if (isFirstLine) // first line is descriptions
        {
            managerNumber++;
            currentManager2.clear();
            isFirstLine = false;
            continue;
        }
        else if (line != "") // populate if line is not empty
        {
            managerMonthlyExpenses[managerNumber][6] = (stod(currentManager2.at(6).c_str()));
            managerMonthlyExpenses[managerNumber][7] = (stod(currentManager2.at(7).c_str()));
            managerMonthlyExpenses[managerNumber][8] = (stod(currentManager2.at(8).c_str()));
            managerMonthlyExpenses[managerNumber][9] = (stod(currentManager2.at(9).c_str()));
            managerMonthlyExpenses[managerNumber][10] = (stod(currentManager2.at(10).c_str()));
            managerMonthlyExpenses[managerNumber][11] = (stod(currentManager2.at(11).c_str()));

            managerNumber++;
            currentManager2.clear();
        }
    }
    myFile2.close();*/
}

Date ManagementExtraFunctions::createDateFromString(string date)
{

    string s = date;
    string delimiter = "/";
    vector<string> dateList;
    size_t pos = 0;
    string token;

    while ((pos = s.find(delimiter)) != string::npos)
    {
        token = s.substr(0, pos);

        dateList.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    dateList.push_back(s);

    Date d(stoi(dateList[0]), stoi(dateList[1]), stoi(dateList[2]));
    return d;
}
//Scans through tenantArr[] and checks their payment status, if it's true it checks their rental fee and adds it to a total
//for the month as well as a total for 6 months. Does this process 6 times for each month.
void ManagementExtraFunctions::collectRentalFee()
{
    //Faustino Wilhoit  ,93,M,Executive Assistant,79,6/15/2003,694.67,Not Paid,Not Paid,Paid,Not Paid,Paid,Paid
    for (int i = 0; i < 100; i++)
    {
        double tenantRent = accessableTenantArr[i].getMonthlyRent();
        for (int j = 0; j < 6; j++)
        {
            double tenantMonthlyRent = 0;
            if (tenantPaymentHistory[i][j] == "Paid")
            {
                // add months rent to corresponding month
                totalRentCollectedPerMonth[j] += tenantRent;
                //calculate total rent for 6 months
                totalRentCollected += tenantRent;
            }
        }
    }
}
//Scans through the tenantArr[] and lists any tenants, along with their current index, with payment status set to false.
void ManagementExtraFunctions::listTenantsNotPay()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tenantPaymentHistory[i][j] == "Not Paid")
            {
                accessableTenantArr[i].printInfo();
                cout << "Curent index: " + to_string(i) << endl;
                cout << endl;
                break;
            }
        }
    }
}
//method to determine who hasn't paid their rent, then adds up the total missing rent for the month
//then continues to add the total of missing rent for the past 6 months before printing it out.
void ManagementExtraFunctions::missingRental()
{
    //Faustino Wilhoit  ,93,M,Executive Assistant,79,6/15/2003,694.67,Not Paid,Not Paid,Paid,Not Paid,Paid,Paid
    for (int i = 0; i < 100; i++)
    {
        double tenantRent = accessableTenantArr[i].getMonthlyRent();
        for (int j = 0; j < 6; j++)
        {
            double tenantMonthlyRent = 0;
            if (tenantPaymentHistory[i][j] == "Not Paid")
            {
                // add months rent to corresponding month
                totalUnPaidRentCollectedPerMonth[j] += tenantRent;
                //calculate total rent for 6 months
                totalUnPaidRentCollected += tenantRent;
            }
        }
    }
}
//Scans through the managerArr[] and grabs the total expenses data held in every manager then adds them together and displays the total. It continues to do this for every month
//as well as the past 6 months.
void ManagementExtraFunctions::totalExpense()
{
    int temp, managersMonthlyExpense = 0;

    for (int i = 0; i < 6; i++)
    {
        temp = managerMonthlyExpenses[0][i];
        managersMonthlyExpense += temp;
        cout << "The total expenses for manager 1 for month number " << (i+1) << " are: " << temp << endl;
        temp = managerMonthlyExpenses[1][i];
        managersMonthlyExpense += temp;
        cout << "The total expenses for manager 2 for month number " << (i+1) << " are: " << temp << endl;
        cout << "The total exepnses for all manager for month number " << (i+1) << " are: " << managersMonthlyExpense << endl;
        totalManagerExpenses += managersMonthlyExpense;
    }


}
//Scans through the managerArr[] and displays the total salary and bonus of every month as well as the total earned the past 6 months. It does this for every individual manager.
void ManagementExtraFunctions::managerSalary_bouns()
{
    int temp, totBonus = 0, totSalary = 0;
    for (int i = 0; i < 2; i++)
    {   
        cout << "Information for manager " << accessableManagerArr[i].getName() << endl;
        temp = accessableManagerArr[i].getSalary(0);
        totSalary += temp;
        cout << "Salary is: " << temp << endl;
        temp = accessableManagerArr[i].getBouns(0);
        totBonus += temp;
        cout << "Bonus is " << temp << endl
        << endl;
    }
    totalManagerSalary = totSalary;
    totalManagerBonus = totBonus;
    cout << "The total salary for all managers for the last 6 months is: " << totSalary << endl;
    cout << "The total bonus for all managers for the last 6 months is: " << totBonus << endl;

    //The bonus is constant for both CSV files and doesn't change month to month, so no point in displaying this information monthly
}
//NetIncome = (total rent collection)- (managers expense)-(salary and bonus expense)
void ManagementExtraFunctions::netIncome()
{
    int netIncome = totalRentCollected - (totalManagerExpenses + totalManagerSalary + totalManagerBonus);
}
//Print out all tenants' profile.
void ManagementExtraFunctions::profile_tenant()
{
    for(int i = 0; i < 100; i++){
        accessableTenantArr[i].printInfo();
    }
}
//Print out all Manager' profile.
void ManagementExtraFunctions::profile_manager()
{
        for(int i = 0; i < 2; i++){
        accessableManagerArr[i].printInfo();
    }
}

//
// getter setter
//

//paid rent
double ManagementExtraFunctions::getTotalRentCollectedPerMonth(int i)
{
    return this->totalRentCollectedPerMonth[i];
}
void ManagementExtraFunctions::setTotalRentCollectedPerMonth(double totalRentCollected, int month)
{
    this->totalRentCollectedPerMonth[month] = totalRentCollected;
}
void ManagementExtraFunctions::addTotalRentCollectedPerMonth(double totalRentCollected, int month)
{
    this->totalRentCollectedPerMonth[month] += totalRentCollected;
}

double ManagementExtraFunctions::getTotalRentCollected()
{
    return this->totalRentCollected;
}
void ManagementExtraFunctions::setTotalRentCollected(double totalRentCollected)
{
    this->totalRentCollected = totalRentCollected;
}

//unpaid rent

double ManagementExtraFunctions::getTotalUnPaidRentCollectedPerMonth(int i)
{
    return this->totalUnPaidRentCollectedPerMonth[i];
}
void ManagementExtraFunctions::setTotalUnPaidRentCollectedPerMonth(double totalRentNotCollected, int month)
{
    this->totalUnPaidRentCollectedPerMonth[month] = totalRentNotCollected;
}

double ManagementExtraFunctions::getTotalUnPaidRentCollected()
{
    return this->totalUnPaidRentCollected;
}
void ManagementExtraFunctions::setTotalUnPaidRentCollected(double totalUnPaidRentCollected)
{
    this->totalUnPaidRentCollected = totalUnPaidRentCollected;
}
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

            cout << colname << endl;
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
            //   string tenantPaymentHistoryCSV = ((string)tenantPropertyList.at(7).c_str() +","+
            //                          tenantPropertyList.at(8).c_str() +","+
            //                          tenantPropertyList.at(9).c_str() +","+
            //                          tenantPropertyList.at(10).c_str() +","+
            //                          tenantPropertyList.at(11).c_str() +","+
            //                          tenantPropertyList.at(12).c_str());
            tenantPaymentHistory[tenantNumber][0]=(tenantPropertyList.at(7).c_str());
            tenantPaymentHistory[tenantNumber][1]=(tenantPropertyList.at(8).c_str());
            tenantPaymentHistory[tenantNumber][2]=(tenantPropertyList.at(9).c_str());
            tenantPaymentHistory[tenantNumber][3]=(tenantPropertyList.at(10).c_str());
            tenantPaymentHistory[tenantNumber][4]=(tenantPropertyList.at(11).c_str());
            tenantPaymentHistory[tenantNumber][5]=(tenantPropertyList.at(12).c_str());     

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

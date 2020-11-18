/*
 *Tititle: COMP3140 Project Stage 2
 *File name: Management.cpp
 *File Type: Imlementation File 
 *Date: 11/16/2020
 */

#include "Management.h"
#ifndef MANAGER_H
#include "Manager.cpp"
#endif
#include <iostream>
using namespace std; 
#include <string>
#include <fstream>
#include <vector>
#include <utility>   // pair
#include <stdexcept> // runtime_error
#include <sstream>   // stringstream
#include <numeric>
#include <cstdlib>
//Parameter constructor, takes in a file name as a string.
Management::Management(const string &newFileName)
    : fileName(newFileName)
{
    readFile();
}
Management::Management()
{
}
Management::~Management()
{
}
Date createDateFromString(string date)
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

    Date d(stoi(dateList[0]),stoi(dateList[1]),stoi(dateList[2]));
    return d;
}
//Takes in an input file based on the fileName variable, scans through it and creates
//tenantArr[] with any tenats and managerArr[] with any managers.
void Management::readFile()
{
    vector<pair<string, vector<int>>> result;
    ifstream myFile(fileName);

    if(!myFile.is_open()) throw runtime_error("Could not open file"); // change error type?
    string line, colname;
    int val, managerNumber =-1;
    vector<string> managerPropertyList;

    
    while(myFile.good())
    {
        getline(myFile, line); // gets first line from file
        stringstream ss(line);
        while(getline(ss, colname, ',')){ // cuts out values from line
            
            cout<< colname <<endl; 
            managerPropertyList.push_back(colname);
           
        }
        if (managerNumber == -1) //first line is descriptions
        {
            managerNumber ++;
            managerPropertyList.clear();
            continue;
        }
        else if (line != "")
        {
            string name = managerPropertyList.at(0);
            cout << name << endl;
            int age = atoi(managerPropertyList.at(1).c_str());

            double d = stod(managerPropertyList[4].c_str());
            cout << d << endl;
            int stopint = 1;

            double totalExpence = (stod(managerPropertyList.at(6).c_str()) + stod(managerPropertyList.at(7).c_str()) + stod(managerPropertyList.at(8).c_str()) + stod(managerPropertyList.at(9).c_str()) + stod(managerPropertyList.at(10).c_str()) + stod(managerPropertyList.at(11).c_str()));
            Manager newManager(
                managerPropertyList.at(0).c_str(),
                stoi(managerPropertyList.at(1).c_str()),
                managerPropertyList.at(2).c_str(),
                createDateFromString(managerPropertyList.at(3).c_str()),
                stod(managerPropertyList.at(4).c_str()),
                stod(managerPropertyList.at(5).c_str()),
                totalExpence);
            managerArr[managerNumber] = newManager;
            managerNumber++;
            managerPropertyList.clear();
        }
    }
}

//Scans through tenantArr[] and checks their payment status, if it's true it checks their rental fee and adds it to a total
//for the month as well as a total for 6 months. Does this process 6 times for each month.
void Management::collectRentalFee()
{
}
//Scans through the tenantArr[] and lists any tenants, along with their current index, with payment status set to false.
void Management::listTenantsNotPay()
{
}
//method to determine who hasn't paid their rent, then adds up the total missing rent for the month
//then continues to add the total of missing rent for the past 6 months before printing it out.
void Management::missingRental()
{
}
//Scans through the managerArr[] and grabs the total expenses data held in every manager then adds them together and displays the total. It continues to do this for every month
//as well as the past 6 months.
void Management::totalExpense()
{
}
//Scans through the managerArr[] and displays the total salary and bonus of every month as well as the total earned the past 6 months. It does this for every individual manager.
void Management::managerSalary_bouns()
{
}
//NetIncome = (total rent collection)- (managers expense)-(salary and bonus expense)
void Management::netIncome()
{
}
//Print out all tenants' profile.
void Management::profile_tenant()
{
}
//Print out all Manager' profile.
void Management::profile_manager()
{
}
//Mutators
void Management::setFileName(const string &newFileName)
{
}
//Accessors
string Management::getFileName()
{
}
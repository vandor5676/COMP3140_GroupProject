/*
* Title: COMP 3140 project
* File: driver.cpp
* Description: this is the main driver 
*
* Date: 9/25/2020
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>

//these imports might cause problems for you. add or delete them if you need to.

#include "RentalPropertyManager.h"
#include "ExtendedPropertyManager.h"
#include "Person.h"
#include "Manager.h"
#include "Tenant.h"

using namespace std;

//helpers
void searchTenantProfile();
void changeJobTitle(int i);
void changeUnitnNumber(int i);
void changeRentalFee(int i);
void changeMoveinDate(int i);
void changePaymentStatus(int i);
void changeName(int i, string T);
void changeAge(int i,string T);
void changeGender(int i,string T);
void printMainOptions();

void savechanges(ExtendedPropertyManager eprm);
void serchManagerProfile();
void changeHireDate(int i);
void changeSalary(int i);
void changeBonus(int i);
void changeExpenses(int i);

//globals
ExtendedPropertyManager erpm;

void printMainOptions()
{
    //cout << "\n1 Import (load) all input files (Tenants.csv, Tenants2.csv, Managers.csv, and Managers2.csv) \n";
    cout << "\n1 Search for a tenant\'s profile by name, display the profile, and be able to modify his/her fields.\n";
    cout << "2 Display all managers\' profiles and be able to modify their fields.\n";
    cout << "3 Display the collected rental fees in total for each month and for a year.\n";
    cout << "4 Display total expense for each month and for a year.\n";
    cout << "5 Display the amount of missing rental fees in total for each month and for a year.\n";
    cout << "6 Display the list of the names and house numbers of the tenants who did not pay their rental fees\n";
    cout << "7 Display both managers\' salaries and bonuses in total for each month and for a year.\n";
    cout << "8 Display the net income for each month and for a year.\n";
    cout << "9 Display the summary of the financial statement for a year\n";
    cout << "-1 To Quit\n";
}

int main()
{
    //load information
    bool Testing = true;
    if (!Testing)
    {
        erpm.loadManagers("Managers.csv");
        erpm.loadTenants("Tenants.csv");
        erpm.loadExtraManagerData("Managers2.csv");
        erpm.loadExtraTenantData("Tenants2.csv");
    }
    else
    {
        //for testing
        erpm.loadManagers("testManager.csv");
        erpm.loadTenants("testTenant.csv");
        erpm.loadExtraManagerData("test2Manager.csv");
        erpm.loadExtraTenantData("test2Tenant.csv");
    }

    bool main = true;
    if (main)
    {
        printMainOptions();
        string choice = "0";
        while (choice != "-1")
        {
            cout << "Enter your selection" << endl;
            std::cin.clear();
            getline(cin, choice);
            //choice = 2;
            if (choice == "1")
            {
                searchTenantProfile();
            }
            else if (choice == "2")
            {
                serchManagerProfile();
            }
            else if (choice == "3")
            {
            }
            else if (choice == "4")
            {
            }
            else if (choice == "5")
            {
            }
            else if (choice == "6")
            {
            }
            else if (choice == "7")
            {
            }
            else if (choice == "8")
            {
            }
            else if (choice == "-1")
            {
                savechanges(erpm);
                return 1;
            }
            else
            {
            }
        }
    }

    bool shanesTests = false;
    if (shanesTests)
    {
        cout << "Start" << endl;

        RentalPropertyManager rpm;
        rpm.loadManagers("Managers.csv");
        rpm.loadTenants("Tenants.csv");

        erpm.loadManagers("Managers.csv");
        erpm.loadTenants("Tenants.csv");
        cout << erpm.publicManagerList.at(1).getName() << endl;
        cout << erpm.publicTenantList.at(10).getName() << endl;

        int stopInt = 0;
        cout << "End" << endl;
    }
}

void savechanges(ExtendedPropertyManager eprm)
{
    //change these to the real files before we submit
    ofstream Manager1("testManager.csv");
    ofstream Manager2("test2Manager.csv");
    ofstream Tenant1("testTenant.csv");
    ofstream Tenant2("test2Tenant.csv");

    //
    // print managers
    //
    Manager1 << "Name,Age,Gender,Hired Date,Salary,Bonus,Expense for January "
                "2020,Expense for February 2020,Expense for March 2020,Expense "
                "for April 2020,Expense for May 2020,Expense for June 2020\n";
    Manager2
        << "Name,Age,Gender,Hired Date,Salary,Bonus,Expense for July "
           "2020,Expense for August 2020,Expense for September 2020,Expense for "
           "October 2020,Expense for November 2020,Expense for December 2020\n";
    for (int i = 0; i < erpm.publicManagerList.size(); i++)
    {
        Manager1 << erpm.getManagerCSV(erpm.publicManagerList.at(i), 1) << "\n";
    }
    //file 2
    for (int i = 0; i < erpm.publicManagerList.size(); i++)
    {
        Manager2 << erpm.getManagerCSV(erpm.publicManagerList.at(i), 2) << "\n";
    }
    //
    //end print managers
    //

    //
    // print Tenants
    //
    Tenant1 << "Name,Age,Gender,Job,House Unit Number,Moving-in Date,Monthly Rental Fee,\"January, 2020\",\"February, 2020\",\"March, 2020\",\"April, 2020\",\"May, 2020\",\"June, 2020\"\n";
    Tenant2 << "Name,Age,Gender,Job,House Unit Number,Moving-in Date,Monthly Rental Fee,\"July, 2020\",\"August, 2020\",\"September, 2020\",\"October, 2020\",\"November, 2020\",\"December, 2020\"\n";
    for (int i = 0; i < erpm.publicTenantList.size(); i++)
    {
        Tenant1 << erpm.getTenantCSV(erpm.publicTenantList.at(i), 1) << "\n";
    }
    //file 2
    for (int i = 0; i < erpm.publicTenantList.size(); i++)
    {
        Tenant2 << erpm.getTenantCSV(erpm.publicTenantList.at(i), 2) << "\n";
    }
    //
    //end print Tenants
    //

    Manager1.close();
    Manager2.close();
    Tenant1.close();
    Tenant2.close();
}

//Searches for a tenant’s profile by name, display the profile, and is able to modify his/her fields.
void serchManagerProfile()
{
    for (int i = 0; i < erpm.publicManagerList.size() ; i++)
    {
        cout<< erpm.publicManagerList.at(i).getProfile()<<endl;
    }
    

    bool matchBool = false;
    string name;
    do
    {
        cout << "\nEnter a name, -1 to quit" << endl;
        getline(cin, name);
        //name = "Jennifer Dory";

        for (int i = 0; i < erpm.publicManagerList.size(); i++)
        {
            if (name == erpm.publicManagerList.at(i).getName())
            {
                matchBool = true;
                cout << endl
                     << erpm.publicManagerList.at(i).getProfile() << endl;

                cout << "1 Hire Date" << endl;
                cout << "2 Salary" << endl;
                cout << "3 Bonus" << endl;
                cout << "4 Expenses" << endl;
                cout << "5 Name " << endl;
                cout << "6 Age" << endl;
                cout << "7 Gender" << endl;

                string choice = "0";
                while (choice != "-1")
                {
                    cout << "What do you want to change? (-1 to exit)" << endl;
                    // cin.clear();
                    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(cin, choice);

                    if (choice == "1")
                    {
                        changeHireDate(i);
                    }
                    else if (choice == "2")
                    {
                        changeSalary(i);
                    }
                    else if (choice == "3")
                    {
                        changeBonus(i);
                    }
                    else if (choice == "4")
                    {
                        changeExpenses(i);
                    }
                    else if (choice == "5")
                    {
                        changeName(i, "m");
                    }
                    else if (choice == "6")
                    {
                        changeAge(i, "m");
                    }
                    else if (choice == "7")
                    {
                        changeGender(i, "m");
                    }
                    else if (choice == "-1")
                    {
                        printMainOptions();
                        return;
                    }
                    else
                    {
                    }
                }
            }
        }
        if (matchBool == false)
        {
            cout << "No matching name" << endl;
        }
    } while (matchBool == false || name != "-1");
}

//Searches for a tenant’s profile by name, display the profile, and is able to modify his/her fields.
void searchTenantProfile()
{
    bool matchBool = false;
    string name;
    do
    {
        cout << "\nEnter a name, -1 to quit" << endl;
        getline(cin, name);
        //name = "Damian Crase";

        for (int i = 0; i < 100; i++)
        {
            if (name == erpm.publicTenantList.at(i).getName())
            {
                matchBool = true;
                cout << endl
                     << erpm.publicTenantList.at(i).getProfile() << endl;

                cout << "1 Job" << endl;
                cout << "2 UnitNumber" << endl;
                cout << "3 Rental Fee" << endl;
                cout << "4 Move in Date" << endl;
                cout << "5 Payment status" << endl;
                cout << "6 Name " << endl;
                cout << "7 Age" << endl;
                cout << "8 Gender" << endl;

                string choice = "0";
                while (choice != "-1")
                {
                    cout << "What do you want to change? (-1 to exit)" << endl;
                    // cin.clear();
                    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(cin, choice);

                    if (choice == "1")
                    {
                        changeJobTitle(i);
                    }
                    else if (choice == "2")
                    {
                        changeUnitnNumber(i);
                    }
                    else if (choice == "3")
                    {
                        changeRentalFee(i);
                    }
                    else if (choice == "4")
                    {
                        changeMoveinDate(i);
                    }
                    else if (choice == "5")
                    {
                        changePaymentStatus(i);
                    }
                    else if (choice == "6")
                    {
                        changeName(i, "t");
                    }
                    else if (choice == "7")
                    {
                        changeAge(i, "t");
                    }
                    else if (choice == "8")
                    {
                        changeGender(i, "t");
                    }
                    else if (choice == "-1")
                    {
                        printMainOptions();
                        return;
                    }
                    else
                    {
                    }
                }
            }
        }
        if (matchBool == false)
        {
            cout << "No matching name" << endl;
        }
    } while (matchBool == false || name != "-1");
}

//
//used to change a tennants/manager profile
//
void changeJobTitle(int i)
{
    cout << "Enter the job Title" << endl;
    string job;
    getline(cin, job);
    erpm.publicTenantList.at(i).setJob(job);
    cout << "Job set!" << endl;
    //  cout<< erpm.publicTenantList.at(i).getProfile()<<endl;
    //  cout<<erpm.publicTenantList.at(i).getJob()<<endl;
}
void changeUnitnNumber(int i)
{
    cout << "Enter the Unit number" << endl;
    string number;
    getline(cin, number);
    try
    {
        int unitNum = stoi(number);
        erpm.publicTenantList.at(i).setUnitNo(unitNum);
        cout << "Unit number set!" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "not a integer" << endl;
    }

    //   cout<< erpm.publicTenantList.at(i).getProfile()<<endl;
    //   cout<<erpm.publicTenantList.at(i).getJob()<<endl;
}

void changeRentalFee(int i)
{
    cout << "Enter a new rental fee" << endl;
    string decimal;
    getline(cin, decimal);
    try
    {
        double unitNum = stod(decimal);
        erpm.publicTenantList.at(i).setRentalFee(unitNum);
        cout << "Rental fee set!" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "not a valid Renatal fee" << endl;
    }

    // cout << erpm.publicTenantList.at(i).getProfile() << endl;
    // cout << erpm.publicTenantList.at(i).getJob() << endl;
}
void changeMoveinDate(int i)
{
    cout << "Enter a new Date" << endl;
    string date;
    getline(cin, date);
    try
    {
        erpm.publicTenantList.at(i).setMoveInDate(date);
        cout << "Move in date set!" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "not a valid date" << endl;
    }

    // cout << erpm.publicTenantList.at(i).getProfile() << endl;
    // cout << erpm.publicTenantList.at(i).getJob() << endl;
}
void changePaymentStatus(int i)
{
    cout << "Enter new payment Statuses. enter -1 to quit, y for paid and n for notpaid" << endl;
    string payment;
    vector<bool> paymentStatus;
    while (payment != "-1")
    {
        getline(cin, payment);
        if (payment == "y")
        {
            paymentStatus.push_back(true);
        }
        if (payment == "n")
        {
            paymentStatus.push_back(false);
        }
    }

    try
    {
        erpm.publicTenantList.at(i).setPaymentsStatus(paymentStatus);
        cout << "Payment status set!" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "Problem with payment status" << endl;
    }
    // vector<bool> psTest = erpm.publicTenantList.at(i).getPaymentsStatus();
    // cout << erpm.publicTenantList.at(i).getProfile() << endl;
    // cout << erpm.publicTenantList.at(i).getJob() << endl;
}
void changeName(int i, string T)
{
    cout << "Enter new Name" << endl;
    string name;
    getline(cin, name);
    if(T == "t")
    erpm.publicTenantList.at(i).setName(name);
    if(T == "m")
    erpm.publicManagerList.at(i).setName(name);
    cout << "Name set!" << endl;

    //  cout<< erpm.publicTenantList.at(i).getProfile()<<endl;
    //  cout<<erpm.publicTenantList.at(i).getJob()<<endl;
}
void changeAge(int i,string T)
{
    cout << "Enter a new age" << endl;
    string number;
    getline(cin, number);
    try
    {
        int unitNum = stoi(number);
        if(T == "t")
        erpm.publicTenantList.at(i).setAge(unitNum);
        if(T == "m")
        erpm.publicManagerList.at(i).setAge(unitNum);
        cout << "new age set!" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "not a integer" << endl;
    }

    //   cout<< erpm.publicTenantList.at(i).getProfile()<<endl;
    //   cout<<erpm.publicTenantList.at(i).getJob()<<endl;
}
void changeGender(int i,string T)
{
    cout << "Enter new Gender" << endl;
    string gender;
    getline(cin, gender);
     if(T == "t")
    erpm.publicTenantList.at(i).setGender(gender);
     if(T == "m")
    erpm.publicManagerList.at(i).setGender(gender);
    cout << "Gender set!" << endl;

    //  cout<< erpm.publicTenantList.at(i).getProfile()<<endl;
    //  cout<<erpm.publicTenantList.at(i).getJob()<<endl;
}

//manager options
void changeHireDate(int i)
{
    cout << "Enter new Hire Date" << endl;
    string date;
    getline(cin, date);
    erpm.publicManagerList.at(i).setHireDate(date);
    cout << "Hire Date set!" << endl;
}
void changeSalary(int i)
{
    cout << "Enter a new Salary" << endl;
    string decimal;
    getline(cin, decimal);
    try
    {
        double salary = stod(decimal);
        erpm.publicManagerList.at(i).setSalary(salary);
        cout << "Salary set!" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "not a valid Salary" << endl;
    }
}
void changeBonus(int i)
{
    cout << "Enter a new Bonus" << endl;
    string decimal;
    getline(cin, decimal);
    try
    {
        double bonus = stod(decimal);
        erpm.publicManagerList.at(i).setBonus(bonus);
        cout << "Bonus set!" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "not a valid Bonus" << endl;
    }
}
void changeExpenses(int i)
{
    cout << "Enter new Expenses. enter -1 to quit" << endl;
    string input;
    vector<double> expences;
    while (input != "-1")
    {
        getline(cin, input);
        try
        {
            expences.push_back(stod(input));
        }
        catch (const std::exception &e)
        {
            cout << "Not a valid Expense" << endl;
        }
    }

    try
    {
        erpm.publicManagerList.at(i).setMonthlyExpenses(expences);
        cout << "Expences set!" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "Error seting payment status vector" << endl;
    }
    // vector<bool> psTest = erpm.publicTenantList.at(i).getPaymentsStatus();
    // cout << erpm.publicTenantList.at(i).getProfile() << endl;
    // cout << erpm.publicTenantList.at(i).getJob() << endl;
}

//
//end -> used to change a tennants profile
//

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

//these imports might cause problems for you. add or delete them if you need to.
#include "RentalPropertyManager.cpp"
#include "ExtendedPropertyManager.cpp"
#include "Person.cpp"
#include "Manager.cpp"
#include "Tenant.cpp"

using namespace std;

//helpers
void searchTenantProfile();
void changeJobTitle(int i);
void changeUnitnNumber(int i);
void changeRentalFee(int i);
void changeMoveinDate(int i);
void changePaymentStatus(int i);
void changeName(int i);
void changeAge(int i);
void changeGender(int i);

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
}

int main()
{
    //load information
    erpm.loadManagers("Managers.csv");
    erpm.loadTenants("Tenants.csv");

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
                cout <<endl << erpm.publicTenantList.at(i).getProfile() << endl;

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
                        changeName(i);
                    }
                    else if (choice == "7")
                    {
                        changeAge(i);
                    }
                    else if (choice == "8")
                    {
                        changeGender(i);
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
    } while (matchBool == false || name !="-1");
}

//
//used to change a tennants profile
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
        cout << "not a valid date" << endl;
    }
    // vector<bool> psTest = erpm.publicTenantList.at(i).getPaymentsStatus();
    // cout << erpm.publicTenantList.at(i).getProfile() << endl;
    // cout << erpm.publicTenantList.at(i).getJob() << endl;
}
void changeName(int i)
{
    cout << "Enter new Name" << endl;
    string name;
    getline(cin, name);
    erpm.publicTenantList.at(i).setName(name);
    cout << "Name set!" << endl;

    //  cout<< erpm.publicTenantList.at(i).getProfile()<<endl;
    //  cout<<erpm.publicTenantList.at(i).getJob()<<endl;
}
void changeAge(int i)
{
    cout << "Enter a new age" << endl;
    string number;
    getline(cin, number);
    try
    {
        int unitNum = stoi(number);
        erpm.publicTenantList.at(i).setAge(unitNum);
        cout << "new age set!" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "not a integer" << endl;
    }

    //   cout<< erpm.publicTenantList.at(i).getProfile()<<endl;
    //   cout<<erpm.publicTenantList.at(i).getJob()<<endl;
}
void changeGender(int i)
{
    cout << "Enter new Gender" << endl;
    string gender;
    getline(cin, gender);
    erpm.publicTenantList.at(i).setGender(gender);
    cout << "Gender set!" << endl;

    //  cout<< erpm.publicTenantList.at(i).getProfile()<<endl;
    //  cout<<erpm.publicTenantList.at(i).getJob()<<endl;
}

//
//end -> used to change a tennants profile
//
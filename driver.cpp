/*
* Title: COMP 3140 project
* File: driver.cpp
* Description: this is the main driver 
*
* Date: 9/25/2020
*/

#include <iostream>
#include <string>


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

//globals
ExtendedPropertyManager erpm;

int main()
{
    //load information
    erpm.loadManagers("Managers.csv");
    erpm.loadTenants("Tenants.csv");

    bool main = true;
    if (main)
    {
        cout << "1 Import (load) all input files (Tenants.csv, Tenants2.csv, Managers.csv, and Managers2.csv) \n";
        cout << "2 Search for a tenant\'s profile by name, display the profile, and be able to modify his/her fields.\n";
        cout << "3 Display all managers\' profiles and be able to modify their fields.\n";
        cout << "4 Display the collected rental fees in total for each month and for a year.\n";
        cout << "5 Display total expense for each month and for a year.\n";
        cout << "6 Display the amount of missing rental fees in total for each month and for a year.\n";
        cout << "7 Display the list of the names and house numbers of the tenants who did not pay their rental fees\n";
        cout << "8 Display both managers\' salaries and bonuses in total for each month and for a year.\n";
        cout << "9 Display the net income for each month and for a year.\n";
        cout << "10 Display the summary of the financial statement for a year\n";

        int choice = 0;
        while (choice != -1)
        {
            cout << "Enter your selection" << endl;
            std::cin.clear();
            //cin >> choice;
            choice = 2;

            if (cin.fail())
            {
                cout << "ERROR -- You did not enter an integer" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            switch (choice)
            {
            case 1:
                /* code */
                break;
            case 2:
                searchTenantProfile();
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            case 5:
                /* code */
                break;
            case 6:
                /* code */
                break;
            case 7:
                /* code */
                break;
            case 8:
                /* code */
                break;
            case 9:
                /* code */
                break;
            case 10:
                /* code */
                break;
            case -1:
                return 1;
                break;

            default:
                break;
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
    string name;
    cout << "Enter a name";
    //getline(cin, name);
    name = "Damian Crase";

    for (int i = 0; i < 100; i++)
    {
        if (name == erpm.publicTenantList.at(i).getName())
        {
            cout << "Match" << endl;
            cout << erpm.publicTenantList.at(i).getProfile() << endl;

            cout << "1 Job" << endl;
            cout << "2 UnitNumber" << endl;
            cout << "3 Rental Fee" << endl;
            cout << "4 Move in Date" << endl;
            cout << "5 Payment status" << endl;
            cout << "6 Name " << endl;
            cout << "7 Age" << endl;
            cout << "8 Gender" << endl;

            int choice = 0;
            while (choice != -1)
            {
                cout << "What do you want to change? (-1 to exit)" << endl;
                // cin.clear();
                // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin >> choice;

                switch (choice)
                {
                case 1:
                    changeJobTitle(i);
                    break;
                case 2:
                    changeUnitnNumber(i);
                    break;
                case 3:
                    /* code */
                    break;
                case 4:
                    /* code */
                    break;
                case 5:
                    /* code */
                    break;
                case 6:
                    /* code */ 
                    break;
                case 7:
                    /* code */
                    break;
                case 8:
                    return;
                    break;
                case (-1):
                    return;
                    break;

                default:
                    break;
                }
            }
        }
    }
}

void changeJobTitle(int i)
{
    cout << "Enter the job Title" << endl;
    string job;
    cin >> job;
    erpm.publicTenantList.at(i).setJob(job);
    cout << "Job set!" << endl;
    //  cout<< erpm.publicTenantList.at(i).getProfile()<<endl;
    //  cout<<erpm.publicTenantList.at(i).getJob()<<endl;
}
void changeUnitnNumber(int i)
{
    cout << "Enter the Unit number" << endl;
    string number;
    cin >> number;
    try
    { 
        int unitNum = stoi(number);
       erpm.publicTenantList.at(i).setUnitNo(unitNum);
       cout << "Unit number set!" << endl;
    }
    catch(const std::exception& e)
    {
        cout<< "not a integer"<<endl;
    }
        
    //   cout<< erpm.publicTenantList.at(i).getProfile()<<endl;
    //   cout<<erpm.publicTenantList.at(i).getJob()<<endl;
}
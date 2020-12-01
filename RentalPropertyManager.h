/*********************************************************************************************************
* Title: COMP 3140 Team Project - Stage 1 -  RentalPropertyManager.h
* Description: Manages a list of tenant and managers, and provides a series of useful methods for
*       for summarizing the information contained in those lists. Also provides methods for loading
*       tenant and manager data from CSV (comma separated value) files.
* Author: Kiel Riley, Cody Painter, and C. Malcolm Todd
* Student ID: T00538035, T00546693, T00232792
* Date: November 13th, 2020
*********************************************************************************************************/
#ifndef RENTALPROPERTYMANAGER_H
#define RENTALPROPERTYMANAGER_H

#include "Tenant.h"
#include "Manager.h"
#include <vector>
#include <string>

using namespace std;

// This class is intended to encapsulate the six-month summary the owner receives from their managers.
// Assuming this data will be distributed as a pair of comma separated value files for tenants and
// managers respectively:
//          - An instance of the class should be constructed in the Rental Management System driver file
//          - The instance should be used to load the tenant and manager data files
//          - The instance should then be used to provide the required functionality within the Rental Management System
class RentalPropertyManager {
    protected:
        vector<Tenant> tenantList;
        vector<Manager> managerList;

    public:
        // Default construction is sufficient since both private members are also default constructable
        RentalPropertyManager() = default;
        // This class contains no manual memory management, therefore the default destructor is sufficient
        ~RentalPropertyManager() = default;

        // Load tenant and manager data from CSV file
        void loadManagers(string managerDataFile);
        void loadTenants(string tenantDataFile);

        // Calculate the rent for all tenants for each month, for six months,
        // and generate a by-month summary of collected tenant rent.
        double calcCollectedRentTotal() const;
        double calcCollectedRentForMonth(int month) const;
        string generateCollectedRentMonthlySummary() const;

        // Calculate the amount of unpaid rent for each month, for six months,
        // and generate a by-month summary of uncollected tenant rent.
        double calcUnpaidRentTotal() const;
        double calcUnpaidRentForMonth(int month) const;
        string generateUnpaidRentMonthlySummary() const;

        // Calculate the expenses for all managers for each month, for six months,
        // and generate a by-month summary of manager expenses.
        double calcManagerExpenseTotal() const;
        double calcManagerExpenseForMonth(int month) const;
        string generateManagerExpenseMonthlySummary() const;

        // Calcuate the combined remuneration (salary+bonus) for all managers for each month,
        // for six months, and generate a by-month summary of manager remuneration.
        double calcManagerRemunerationTotal() const;
        double calcManagerRemunerationForMonth(int month) const;
        string generateManagerRemunerationMonthlySummary() const;

        // Calculate the net income for each month, for six months, and generate
        // a by-month summary of net income.
        double calcNetIncomeTotal() const;
        double calcNetIncomeForMonth(int month) const;
        string generateNetIncomeMonthlySummary() const;

        // Returns a string with all the combined tenant and manager profiles that are
        // currently in the system.
        vector<string> getAllProfiles();
        //string getAllProfiles();

        // Obtain a list of tenants that owe some amount of rent over the last six months.
        vector<Tenant> getTenantsWithUnpaidAmounts() const;
};
#endif
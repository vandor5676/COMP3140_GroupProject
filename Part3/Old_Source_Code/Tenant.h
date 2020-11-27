/*********************************************************************************************************
* Title: COMP 3140 Team Project - Stage 1 - Tenant.h
* Description: Interface file for Tenant
* Author: Kiel Riley, Cody Painter, and C. Malcolm Todd
* Student ID: T00538035, T00546693, T00232792
* Date: November 13th, 2020
*********************************************************************************************************/
#ifndef TENANT_H
#define TENANT_H

#include "Person.h"
#include <string>
#include <vector>

using namespace std;

class Tenant : public Person {

private:
    string job;
    int unitNo;
    string moveInDate;
    double rentalFee;
    vector<bool> paymentsStatus;

public:
    // The default constructor and destructor are sufficient
    Tenant() = default;
    ~Tenant() = default;

    Tenant( string name, int age, string gender, int unitNo,
        string moveInDate, double monthlyRentalFee);

    string getJob() const;
    int getUnitNo() const;
    double getRentalFee() const;
    string getMoveInDate() const;
    vector<bool> getPaymentsStatus() const;
    void setJob(string job);
    void setUnitNo(int unitNo);
    void setMoveInDate(string moveInDate);
    void setRentalFee(double rentalFee);
    void setPaymentsStatus(vector<bool> paymentsStatus);

    // Get and set the payment status for a given month
    bool getPaymentStatusForMonth(int month) const;
    void setPaymentStatusForMonth(int month, bool status);

    // Calculate the unpaid fees for each month and for six months.
    double calcUnpaidFeesForMonth(int month) const;
    double calcUnpaidFeesTotal() const;

    // Calculate the paid fees for each month and for six months.
    double calcPaidFeesforMonth(int month) const;
    double calcPaidFeesTotal() const;

    // Check if this tenant has unpaid rental fees over the specified six month period.
    bool hasUnpaidFees() const;
    
    // Returns a string containing a visual representation of tenant information.
    std::string getProfile() const;
};
#endif
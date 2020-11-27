/*********************************************************************************************************
* Title: COMP 3140 Team Project - Stage 2 - Tenant.cpp
* Description: Implementation file for Tenant
* Author: Kiel Riley, Cody Painter, and C. Malcolm Todd
* Student ID: T00538035, T00546693, T00232792
* Date: November 18th, 2020
*********************************************************************************************************/
#include "Tenant.h"
#include <assert.h>
#include <iomanip>
#include <sstream>

void assertPaymentsStatusValid();

Tenant::Tenant(string name, int age, string gender, int unitNo,
               string moveInDate, double rentalFee) :
    Person(name, age, gender),
    unitNo(unitNo),
    moveInDate(moveInDate),
    rentalFee(rentalFee)
{
    paymentsStatus = vector<bool>(6,false);
}

// Public function definitions

bool Tenant::getPaymentStatusForMonth(int month) const {
    assert(month >= 0 && month <= 5);

    return paymentsStatus.at(month);
}

void Tenant::setPaymentStatusForMonth(int month, bool status) {
    assert(month >= 0 && month <= 5);

    paymentsStatus.at(month) = status;
}

double Tenant::calcUnpaidFeesForMonth(int month) const {
    assert(month >= 0 && month <= 5);

    return !paymentsStatus.at(month) ?
        rentalFee : 0;
}

double Tenant::calcUnpaidFeesTotal() const {
    double sum = 0;
    for (bool value : paymentsStatus) {
        sum += !value ? rentalFee : 0;
    }
    return sum;
}

double Tenant::calcPaidFeesforMonth(int month) const {
    assert(month >= 0 && month <= 5);

    return (paymentsStatus.at(month) ?
        rentalFee : 0);
}

double Tenant::calcPaidFeesTotal() const {
    double sum = 0;
    for (bool value : paymentsStatus) {
        sum += value ? rentalFee : 0;
    }
    return sum;
}

bool Tenant::hasUnpaidFees() const {
    for (bool status : paymentsStatus) {
        if (!status) return true;
    }
    return false;
}

string Tenant::getProfile() const {
    stringstream profile;
    profile.setf(ios::left);
    profile.setf(ios::fixed);
    profile.precision(2);
    profile << "[TENANT]" << endl;
    profile << setw(14) << "Name: " << name << endl
            << setw(14) << "Age: " << age << endl
            << setw(14) << "Gender: " << gender << endl
            << setw(14) << "Unit No: " << unitNo << endl
            << setw(14) << "Move-in Date: " << moveInDate << endl
            << setw(14) << "Monthly Rent: $" << rentalFee << endl;
            "\n";
    return profile.str();
}

// Getters and setters

string Tenant::getJob() const {
    return job;
}

int Tenant::getUnitNo() const {
    return unitNo;
}

double Tenant::getRentalFee() const {
    return rentalFee;
}

string Tenant::getMoveInDate() const {
    return moveInDate;
}

vector<bool> Tenant::getPaymentsStatus() const {
    return paymentsStatus;
}

void Tenant::setJob(string job) {
    Tenant::job = job;
}

void Tenant::setUnitNo(int unitNo) {
    Tenant::unitNo = unitNo;
}

void Tenant::setMoveInDate(string moveInDate) {
    Tenant::moveInDate = moveInDate;
}

void Tenant::setRentalFee(double rentalFee) {
    Tenant::rentalFee = rentalFee;
}

void Tenant::setPaymentsStatus(vector<bool> paymentsStatus){
    //Tenant::paymentsStatus = paymentsStatus;
    Tenant::paymentsStatus.assign(paymentsStatus.begin(), paymentsStatus.end());
}
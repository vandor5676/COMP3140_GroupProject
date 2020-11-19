/*
 *Tititle: COMP3140 Project Stage 2
 *File name: Tenant.cpp
 *File Type: Imlementation File 
 *Date: 11/16/2020
 */

#include "Tenant.h"
#ifndef DATE_DEF
#include "Date.cpp"
#endif

//Constructors
Tenant::Tenant(const string &newName, const int &newAge,
               const string &newGender, const string &newJob,
               const int &newUnitNumber, Date newMoveIn_Day,
               const double &newMonthly_rent, const char &newPayment_status)
:Person(newName,newAge,newGender), job(newJob),unitNumber(newUnitNumber), monthly_rent(newMonthly_rent)
{
    this->movingIn_Date = Date(newMoveIn_Day);
   //  it looks like we cant use newPayment_status, im going to vreate a list in ManagmentExtraFunctions that contains the information that shoud go here
  // this->payment_status[1] = 'a'; 
}
Tenant::Tenant()
{
}
//Destructors
Tenant::~Tenant()
{
}
//Mutators
void Tenant::setJob(const string &newJob)
{
}
void Tenant::setUnitNumber(const int &newUnitNumber)
{
}
void Tenant::setMonthlyRent(const double &newMonthly_rent)
{
}
void Tenant::setPaymentStatus(const char &newPayment_status)
{
}
//Accessors
string Tenant::getJob() const
{
}
int Tenant::getUnitNumber() const
{
}
Date Tenant::getmovingIn_Date() const
{
}
double Tenant::getMonthlyRent() const
{
    return(this->monthly_rent);
}
char *Tenant::getPaymentStatus() const
{
}
//Print information of Tenant
void Tenant::printInfo() const
{
}
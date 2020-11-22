#include "Tenant.h"
#include <iostream>

//Constructors
Tenant::Tenant(const string& newName, const int& newAge,
	const string& newGender, const string& newJob,
	const int& newUnitNumber, Date newMoveIn_Day,
	const double& newMonthly_rent, const char& newPayment_status)
{
	this->job = newJob;
	this->unitNumber = newUnitNumber;
	this->movingIn_Date = Date(newMoveIn_Day);
	this->monthly_rent = newMonthly_rent;
}

Tenant::Tenant()
{

}

//Destructors
Tenant::~Tenant()
{

}

//Mutators
void Tenant::setJob(const string& newJob)
{
	this->job = newJob;
}

void Tenant::setUnitNumber(const int& newUnitNumber)
{
	this->unitNumber = newUnitNumber;
}

void Tenant::setMonthlyRent(const double& newMonthly_rent)
{
	this->monthly_rent = newMonthly_rent;
}

void Tenant::setPaymentStatus(const char& newPayment_status)
{
	
}

//Accessors
string Tenant::getJob() const
{
	return job;
}

int Tenant::getUnitNumber() const
{
	return unitNumber;
}

Date Tenant::getmovingIn_Date() const
{
	return movingIn_Date;
}

double Tenant::getMonthlyRent() const
{
	return monthly_rent;
}

char* Tenant::getPaymentStatus() const
{
	
}

//Print information of Tenant
void Tenant::printInfo() const
{
	cout << "Tenant Info:" << endl;

}
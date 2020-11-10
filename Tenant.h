#pragma once
#include "Tenant.h"
#include "Person.h"
#include <iostream>
#include <ctime>

/*
- Team Project: Stage #1
- Dayton Butler
- T00258753
- November 12, 2020
- COMP 3140
*/

using namespace std;

class Tenant: public Person
{
private:
	string job;
	int unitNumber;
	time_t moveInDate;
	double monthlyFee;
	bool isMonthPaid;
public:
	// Constructors/Deconstructors
	Tenant();
	Tenant(string name, int age, string gender, string job, int unitNumber, time_t moveInDate, double monthlyFee, bool isMonthPaid);
	Tenant(const Tenant& tenant);
	~Tenant();
	// Getters/Setters
	string getJob() const;
	int getUnitNumber() const;
	time_t getMoveInDate() const;
	double getMonthlyFee() const;
	bool getIsMonthPaid() const;
	void setJob(string job);
	void setUnitNumber(int unitNumber);
	void setMoveInDate(time_t moveInDate);
	void setMonthlyFee(double monthlyFee);
	void setIsMonthPaid(bool isMonthPaid);
	void profile();
};
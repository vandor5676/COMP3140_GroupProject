/*
 *Tititle: COMP3140 Project Stage 1
 *File name: Tenant.h
 *File Type: Interface File 
 *Date: 11/13/2020
 */
#ifndef TENANT_H
#define TENANT_H
#include <string>
#include"Tenant.h"
#include"Person.h"

using namespace std;

class Tenant : public Person
{
    private:
        string job;
        int unitNumber;
        Date movingIn_Date;
        double monthly_rent;
        char payment_status[6];
    public:
        //Constructors
        Tenant(const string& newName,const int& newAge, 
                const string& newGender,const string& newJob, 
                const int& newUnitNumber, Date newMoveIn_Day,
                const double& newMonthly_rent, const char& newPayment_status);
        Tenant();
        //Destructors
        virtual ~Tenant();
        //Mutators
        void setJob(const string& newJob);
        void setUnitNumber(const int& newUnitNumber);
        void setMonthlyRent(const double& newMonthly_rent);
        void setPaymentStatus(const char& newPayment_status)
        //Accessors
        string getJob() const; 
        int getUnitNumber() const; 
        Date getmovingIn_Date() const; 
        double getMonthlyRent() const;
        char* getPaymentStatus() const;
        //Print information of Tenant
        virtual void printInfo() const;
};
#endif
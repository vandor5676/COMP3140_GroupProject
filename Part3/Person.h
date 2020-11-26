/*********************************************************************************************************
* Title: COMP 3140 Team Project - Stage 1 -  Person.h
* Description: Interface File for the Person Abstract class.
* Author: Kiel Riley, Cody Painter, and C. Malcolm Todd
* Student ID: T00538035, T00546693, T00232792
* Date: November 13th, 2020
*********************************************************************************************************/
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

// Person is an abstract class representing a person with a name, age, and gender.
// It is intended to serve as the base class for Managers and Tenants in the Rental
// Management application.
class Person {

    protected:
        string name;
        int age;
        string gender;

        // Since the class is abstract, the constructors should be protected, as
        // the class cannot be constructed but its constructors can still be used by its derived
        // classes to delegate assignment of its protected attributes.
        Person() = default;
        Person(string name, int age, string gender);
        virtual ~Person() = default;

    public:
        string getName() const;
        void setName(string newName);
        int getAge() const;
        void setAge(int newAge);
        string getGender() const;
        void setGender(string newGender);

        // This method should return a profile for either managers or tenants
        // depending on the concrete child class.
        virtual string getProfile() const= 0;
};
#endif

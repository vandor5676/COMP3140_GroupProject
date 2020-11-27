/*********************************************************************************************************
* Title: COMP 3140 Team Project - Stage 2 -  Person.cpp
* Description: Implementation File for the Person Abstract class.
* Author: Kiel Riley, Cody Painter, and C. Malcolm Todd
* Student ID: T00538035, T00546693, T00232792
* Date: November 22nd, 2020
*********************************************************************************************************/
#include "Person.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Person is an abstract class representing a person with a name, age, and gender.
// It is intended to serve as the base class for Managers and Tenants in the Rental
// Management application.

Person :: Person(string name, int age, string gender)
:name(name), age(age), gender(gender)
{
    if(age <=0) {
        cout << "Unable to create Person with negative age!"<<endl;
        assert(false);
    }
}

//Accessor Member Functions
string Person :: getName() const {
    return name;
}
void Person :: setName(string newName) {
    name = newName;
}
int Person :: getAge() const {
    return age;
}
void Person :: setAge(int newAge) {
    age = newAge;
}
string Person :: getGender() const {
    return gender;
}
void Person :: setGender(string newGender) {
    gender = newGender;
}
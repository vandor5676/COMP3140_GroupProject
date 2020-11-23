/*
* Title: COMP 3140 Team Project Part2
* File: Person.cpp
* Description: This file is the implementation file of the Person class.
*
* Date: November 17, 2020
*/
#include "Person.h"
#include <string>
using namespace std;

/* Constructors and Destructors */
Person::Person(const string &newName, const int &newAge, const string &newGender) 
:name(newName), age(newAge), gender(newGender)
{

}
Person::Person()
{
}
Person::~Person()
{
}
/* Getters and Setters */
void Person :: setName(string& newName){
    this->name = newName;
};
void Person :: setAge(string& newAge){   
    this->age = stoi(newAge);
};
void Person :: setGender(int& newGender){
   string gender;
   if(newGender == 1)
   {
       gender = "Male";
   }
   else if (newGender == 2) {
   gender = "Female";
   }
   else
   {
       gender = "Other";
   }   
    this->gender = gender;
};
int Person :: getAge() const{
    return age;
};
string Person :: getName() const{
    return name;
};
string Person :: getGender() const{
    return gender;
};

void Person::printInfo() const{

};

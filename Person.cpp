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
void Person :: setAge(int& newAge){
    this->age = newAge;
};
void Person :: setGender(string& newGender){
    this->gender = newGender;
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

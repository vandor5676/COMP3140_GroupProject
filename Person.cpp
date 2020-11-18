/*
 *Tititle: COMP3140 Project Stage 2
 *File name: Manager.cpp
 *File Type: Imlementation File 
 *Date: 11/16/2020
 */
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

//had to implement constructor to get manager to work, make any changes you want

//Constructors
Person::Person(const string &newName, const int &newAge, const string &newGender) 
:name(newName), age(newAge), gender(newGender)
{

}
Person::Person()
{
}
//Destructors
Person::~Person()
{
}
//Mutators
void Person::setName(string &newName)
{
}
void Person::setAge(string &newAge)
{
}
void Person::setGender(int &newAge)
{
}
//Accessors
// int Person::getAge() const
// {
// }
// string Person::getName() const
// {
// }
// string Person::getGender() const
// {
// }
//  void Person::printInfo() const
// {
// }
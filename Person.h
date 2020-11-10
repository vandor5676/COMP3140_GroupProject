#pragma once
#pragma once
#include "Person.h"
#include <iostream>

/*
- Team Project: Stage #1
- Dayton Butler
- T00258753
- November 12, 2020
- COMP 3140
*/

using namespace std;

class Person
{
private:
	string name;
	int age;
	string gender;
public:
	// Constructors/Destructors
	Person();
	Person(string name, int age, string gender);
	Person(const Person& person);
	virtual ~Person();
	// Getters/Setters
	string getName() const;
	int getAge() const;
	string getGender() const;
	void setName(string name);
	void setAge(int age);
	void setGender(string gender);
	virtual void profile();
};
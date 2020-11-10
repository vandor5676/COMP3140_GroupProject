/*
* Title: COMP 3140 Team Project Stage 1
* File: Person.h
* Description: Team project part 1, header file for the Person class
*
* Author: Logan Royer
* Student ID: T00215409
* Date: November 9th, 2020
*/

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;
using std::string; 

class Person{
protected:
  string name;
  string gender;
  int age;
  
public:
  
  /* Constructors */
  Person ();
  Person (string name, string gender, int age);
  Person (const Person &pOld);
  ~Person ();

  /* Getters and Setters */
  string getName ();
  string getGender ();
  int getAge ();
  
  void setName (string name);
  void setGender (string gender);
  void setAge (int age);
  
  /* Member Functions */
  //gets a string representation of the person
  string getPerson ();
};

#endif

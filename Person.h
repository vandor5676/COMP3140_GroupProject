/*
 *Tititle: COMP3140 Project Stage 1
 *File name: Person.h
 *File Type: Interface File 
 *Date: 11/13/2020
 */
#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
    protected:
        string name;
        string gender;
        int age;
    public:
        //Constructors
        Person(const string& newName,const int& newAge,const string& newGender);
        Person();
        //Destructors
        virtual ~Person();
        //Mutators
        void setName(string& newName);
        void setAge(string& newAge);
        void setGender(int& newAge);
        //Accessors
        int getAge() const;
        string getName() const;
        string getGender() const;
        virtual void printInfo() const;
};
#endif
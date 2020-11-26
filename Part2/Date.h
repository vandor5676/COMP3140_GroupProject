/*
 *Tititle: COMP3140 Project Stage 1
 *File name: date.h
 *File Type: Interface File 
 *Date: 11/13/2020
 */
#ifndef DATE_DEF
#define DATE_DEF
#include <string>

using namespace std;

class Date
{
      private:
            int day, month, year;
            //Converts a numbered month into a worded one. i.e. January, Febuary, March, April... etc
            string converMonth(int m);
            //Checks if the given numbers is a valid date by checking if days is between 
            //1 - 31, Months is 1 - 12, and Year is correct.
            bool checkValidDate();
      public:
            //Constructors
            Date(const int& newDay, const int& newMonth, const int& newYear);
            Date();
            Date(const Date& date);
            //Destructors
            ~Date();
            //Mutators 
            void setDay(const int& newDay);
            void setMonth(const int& newMonth);
            void setYear(const int& newYear);
            //Accessors
            int getDay();
            int getMonth();
            int getYear();
            //Return full date information
            string getDate(); 
};
#endif
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
            // represents a day, month and year in a numeric format 
            int day, month, year;
            
            //Converts a numbered month into a worded one. i.e. January, Febuary, March, April... etc
            string converMonth(int m);
            
            //Checks if the given numbers is a valid date by checking if days is between 
            //1 - 31, Months is 1 - 12, and Year is correct.
            bool checkValidDate();
      public:
            //Constructors

            //creates a new Date with a day a month and a year
            Date(const int& newDay, const int& newMonth, const int& newYear);
            //creates a new date
            Date();
            //creates a new date from an existing Date object
            Date(const Date& date);

            //Destructors

            //deconstructs a date
            ~Date();

            //Mutators 

            //sets the day
            void setDay(const int& newDay);
            //sets the month
            void setMonth(const int& newMonth);
            //sets teh year
            void setYear(const int& newYear);
            //Accessors
            int getDay();
            int getMonth();
            int getYear();
            //Return full date information
            string getDate(); 
};
#endif
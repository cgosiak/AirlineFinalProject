//
// Created by caleb on 10/13/15.
//

#ifndef MYPROGRAM3_USEFULFUNCTIONS_H
#define MYPROGRAM3_USEFULFUNCTIONS_H

#include <ctime>


namespace FinalProject {
    class UsefulFunctions {
    public:
        UsefulFunctions();

        //Handles answers to yes/no questions
        bool Yes_No_Question();

        //Converts strings to upper case.
        std::string changeToUpper(std::string myInput);

        //Takes a seat's letter as a string and returns the int value
        int getIntFromSeatLetter(std::string seatLetterUsed);

        //Takes the int value of a seat's letter and returns the string value
        std::string getSeatLetterFromInt(int seatInt);

        //Takes an int and returns the string value
        std::string getStringfromInt(int myInput);

        //Calculates the difference between two dates (time between the dates)
        int Days_Difference(time_t first_date, time_t second_date);
    };
}


#endif //MYPROGRAM3_USEFULFUNCTIONS_H

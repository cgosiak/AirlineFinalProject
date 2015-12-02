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
        bool Yes_No_Question();
        std::string changeToUpper(std::string myInput);
        int getIntFromSeatLetter(std::string seatLetterUsed);
        std::string getSeatLetterFromInt(int seatInt);
        std::string getStringfromInt(int myInput);
        int Days_Difference(time_t first_date, time_t second_date);
    };
}


#endif //MYPROGRAM3_USEFULFUNCTIONS_H

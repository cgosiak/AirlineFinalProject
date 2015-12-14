#ifndef USEFULFUNCTIONS_H
#define USEFULFUNCTIONS_H

#include <QObject>
#include <ctime>
#include <stdlib.h>


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

#endif // USEFULFUNCTIONS_H

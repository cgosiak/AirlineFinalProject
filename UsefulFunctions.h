//
// Created by caleb on 10/13/15.
//

#ifndef MYPROGRAM3_USEFULFUNCTIONS_H
#define MYPROGRAM3_USEFULFUNCTIONS_H


namespace CalebG {
    class UsefulFunctions {
    public:
        UsefulFunctions();
        bool Yes_No_Question();
        std::string changeToUpper(std::string myInput);
        int getIntFromSeatLetter(std::string seatLetterUsed);
        std::string getSeatLetterFromInt(int seatInt);
        std::string getStringfromInt(int myInput);
    };
}


#endif //MYPROGRAM3_USEFULFUNCTIONS_H

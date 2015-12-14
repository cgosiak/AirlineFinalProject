#include <iostream>
#include <set>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <sstream>
using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::string;
using std::endl;

#include "usefulfunctions.h"


namespace FinalProject {
    bool FinalProject::UsefulFunctions::Yes_No_Question() {
        // create a set of acceptable continue commands
        std::set<string> yesList;
        yesList.insert("Y");
        yesList.insert("YES");
        string answer;
        cout << "[yes/no]: ";
        cin >> answer;

        // change the answer to uppercase
        answer = UsefulFunctions::changeToUpper(answer);

        // if the user said yes, use the default input/output files
        if (yesList.find(answer) != yesList.end()) {
            return true;
        }
        else {
            return false;
        }
        return false;
    }

    string UsefulFunctions::changeToUpper(string myInput) {
        string newTest;

        // Length of word
        int wordLength = myInput.length();

        // Will hold the newly parsed string of uppercase characters
        string parsedString = "";

        // Loop through all the letters of the string, and convert to upper one by one and append
        // to full string to return upper cased word
        for (int letter=0; letter < wordLength; letter++) {
            newTest = ::toupper(myInput[letter]);
            parsedString += newTest;
        }

        // Return an uppercased string
        return parsedString;
    }

    UsefulFunctions::UsefulFunctions() {
        // There is a better way to do this
    }

    int UsefulFunctions::getIntFromSeatLetter(std::string seatLetterUsed) {
        // my favorite function!!!
        // it was an elegent solution for switching back and forth between ints and strings of seats

        // First define seat mapping
        string seatLetter[16];

        seatLetter[0] = "A"; seatLetter[1] = "B"; seatLetter[2] = "C"; seatLetter[3] = "D";
        seatLetter[4] = "E"; seatLetter[5] = "F"; seatLetter[6] = "G"; seatLetter[7] = "H";
        seatLetter[8] = "I"; seatLetter[9] = "J"; seatLetter[10] = "K"; seatLetter[11] = "L";
        seatLetter[12] = "M"; seatLetter[13] = "N"; seatLetter[14] = "O"; seatLetter[15] = "P";

        // this will loop through all the seat mapping until the correct letter is found, and the array int is returned
        for (int i=0; i < 16; i++) {
            if (seatLetter[i] == seatLetterUsed) {
                return i;
            }
        }

        // something went wrong, return an error int
        return -1;
    }

    std::string UsefulFunctions::getSeatLetterFromInt(int seatInt) {
        string letter;
        switch (seatInt) {
            case 0:
                letter = "A";
                break;
            case 1:
                letter = "B";
                break;
            case 2:
                letter = "C";
                break;
            case 3:
                letter = "D";
                break;
            case 4:
                letter = "E";
                break;
            case 5:
                letter = "F";
                break;
            case 6:
                letter = "G";
                break;
            case 7:
                letter = "H";
                break;
            case 8:
                letter = "I";
                break;
            case 9:
                letter = "J";
                break;
            case 10:
                letter = "K";
                break;
            case 11:
                letter = "L";
                break;
            case 12:
                letter = "M";
                break;
            case 13:
                letter = "N";
                break;
            case 14:
                letter = "O";
                break;
            case 15:
                letter = "P";
                break;
            default:
                letter = "X";
        }
        return letter;
    }

    std::string UsefulFunctions::getStringfromInt(int myInput) {
        // Get a stream of the input string
        std::ostringstream ostr;
        ostr << myInput;

        // Convert the int to a string
        string theStringfromNumber = ostr.str();

        // Return the string
        return theStringfromNumber;
    }

    int UsefulFunctions::Days_Difference(time_t first_date, time_t second_date) {
        int diff_integer = 0;
        if ( first_date != (time_t)(-1) && second_date != (time_t)(-1) )
        {
            double difference = difftime(second_date, first_date) / (60 * 60 * 24);
            diff_integer = ceil(difference);
            return diff_integer;
        }
    }
}

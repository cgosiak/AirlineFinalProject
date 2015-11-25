//
// Created by caleb on 11/24/15.
//

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;

#include "Passenger.h"
#include "UsefulFunctions.h"

namespace FinalProject {

    Passenger::Passenger() {
        cout << "Passenger First Name: ";
        cin >> first_name;
        cout << std::endl;

        cout << "Passenger Last Name: ";
        cin >> last_name;
        cout << std::endl;

        cout << "Passenger Age: ";
        cin >> age;
        cout << std::endl;
    }

    std::string Passenger::Get_Name() {
        std::string full_name;

        full_name = first_name + " " + last_name;
        return full_name;
    }

    std::string Passenger::Get_Assigned_Seat() {
        return seat_assigned;
    }
}
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
        cout << std::endl;
        cout << "New Passenger Creation" << std::endl;
        cout << "----------------------------" << std::endl;
        cout << "Passenger First Name: ";
        cin >> first_name;

        cout << "Passenger Last Name: ";
        cin >> last_name;

        cout << "Passenger Age: ";
        cin >> age;
    }

    std::string Passenger::Get_Name() {
        std::string full_name;

        full_name = first_name + " " + last_name;
        return full_name;
    }

    std::string Passenger::Get_Assigned_Seat() {
        return seat_assigned;
    }

    void Passenger::Add_To_Flight(Flight* connection) {
        booked_flights++;
        on_these_flights[booked_flights-1] = connection;
    }
}
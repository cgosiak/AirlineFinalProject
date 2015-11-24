//
// Created by caleb on 11/23/15.
//

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;

#include "Airport.h"
#include "UsefulFunctions.h"

namespace FinalProject {


    Airport::Airport() {
        cout << "Creating Airport!" << std::endl;
    }

    void Airport::AddFlight() {
        current_flight_amount++;
        Flight *all_flights[current_flight_amount];
        
        // First add in all previously created flights
        for (int i = 0; i < (current_flight_amount-1); ++i) {
            all_flights[i] = current_flights[i];
        }

        Flight new_flight;
        all_flights[current_flight_amount-1] = &new_flight;

        current_flights = all_flights;

        cout << "Flight " << new_flight.Get_Flight_Name() << " Created!" << std::endl;
    }

    void Airport::PrintNamesOfAllFlights() {
        for (int i = 0; i < current_flight_amount; ++i) {
            current_flights[i]->Print_Flight_Name();
        }
    }
}
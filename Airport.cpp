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

        // Need at least 1 flight
        if (current_flight_amount == 0) {
            AddFlight();
        }
    }

    void Airport::AddFlight() {
        // Increment Flight Amount
        current_flight_amount++;

        // Create a new flight at the pointed array position
        current_flights[current_flight_amount-1] = new Flight();

        // Print name of the created flight
        cout << "Flight " << current_flights[current_flight_amount-1]->Get_Flight_Name() << " Created!" << std::endl;
    }

    void Airport::PrintNamesOfAllFlights() {
        // Print out all the names of all the flights created!
        for (int i = 0; i < current_flight_amount; ++i) {
            current_flights[i]->Print_Flight_Name();
        }
    }

    void Airport::CleanUp() {
        cout << "Clean Up Array!" << std::endl;
    }
}
//
// Created by caleb on 11/23/15.
//

#ifndef MYPROGRAM3_AIRPORT_H
#define MYPROGRAM3_AIRPORT_H

#include "Flight.h"
#include "Plane.h"
#include "Passenger.h"

namespace FinalProject {
    class Airport {
    public:
        Airport();
        void AddFlight();
        void PrintNamesOfAllFlights();
        void CleanUp();

    private:
        // Pointers to all the flights at the given airport, max 100 right now
        Flight *current_flights[100];
        // Pointers to all the planes at the given airport, max 100 right now
        Plane *planes_at_airport[100];
        // Pointers to all the passengers at the given airport, max 1000 right now
        Passenger *passengers_at_airport[1000]; // THis may make more sense to implement in the flight class

        int current_flight_amount = 0;
    };
}


#endif //MYPROGRAM3_AIRPORT_H

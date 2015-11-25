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

        // Method to add a flight to the airport
        void AddFlight();

        // Method to add plane to airport
        void AddPlane();

        // Cleans pointers
        void CleanUp();

        // Assign Selected Flight, Automaticall set to the first flight if it exists
        bool Select_Flight(int index_of_flight);

        // Pointers to all the flights at the given airport, max 100 right now
        Flight *current_flights[100];

        // Pointers to all the planes at the given airport, max 100 right now
        Plane *planes_at_airport[100];

        // Print all available flights
        void Print_Upcoming_Flights();

        // Select a new flight
        void Select_New_Flight();

        // Pointer to current selected flight
        Flight *selected_flight;

    private:
        int current_flight_amount = 0;
        int current_plane_amount = 0;
    };
}


#endif //MYPROGRAM3_AIRPORT_H

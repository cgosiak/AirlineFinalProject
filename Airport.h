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

        // Pointer to current selected plane
        Plane *selected_plane;

        // Print all passengers taking any flight at the airport
        void Print_All_Passengers();

        // Print all available planes
        void Print_All_Planes();

        // Get Number of Flights
        int Get_Number_of_Flights();

        // Get Number of Planes
        int Get_Number_of_Planes();

        // This will be the tool for handling Flight manipulation with the user
        bool user_selections();

        // Select New Plane
        void Select_New_Plane();

        // Assign Selected Plane
        bool Select_Plane(int index_of_plane);

        // Print Seating Map
        void Print_Seat_Map();

        // Select Plane for Plane Options
        void Select_Plane_For_Options();

        // Show plane options
        bool Plane_Options(int index_to_use);

        // Read in External Saved
        void Read_External_Saved();

        // Read Passenger External
        bool Read_External_Passengers();

        // Read Amount of Planes/FLight
        bool Read_External_Amounts();

        // Read External Planes
        bool Read_External_Planes();

        // Read external flights
        bool Read_External_Flights();

        // Need to write to external files now!
        void Save_States();

        // SS Planes?FLights
        void Save_State_Planes_Flights();

        // SS Passengers
        void Save_State_Passengers();

        // SS Planes
        void Save_State_Planes();

        // SS Flights
        void Save_State_Flights();


    private:
        int current_flight_amount = 0;
        int current_plane_amount = 0;

        // Save Index Yo!
        int index_of_saved_flight;
        int index_of_saved_plane;
    };
}


#endif //MYPROGRAM3_AIRPORT_H

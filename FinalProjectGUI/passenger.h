#ifndef PASSENGER_H
#define PASSENGER_H

#include <QObject>

#include "flight.h"
#include <stdlib.h>

/*
 * Our namespace for AirlineFinalProject
 */
namespace FinalProject {

    class Flight; //  Must do this to resolve circular dependency between Flight and Passenger Objects
    class Seat; //  Must do this to resolve circular dependency between Seat and Passenger Objects

    class Passenger {

        public:

            Passenger();

            // Overloaded constructor to read form text file
            Passenger(std::string fName /**< [in] docs for input parameter v. */, std::string lName, int age_used, int row_used, int seat_used);

            // Get Full Name
            std::string Get_Name();

            // Get First Name
            std::string Get_First();

            // Get Last Name
            std::string Get_Last();

            // Get Seat Assigned
            std::string Get_Assigned_Seat();

            // Add Passenger to a Flight
            void Add_To_Flight(Flight* connection);

            // Get List of Flights
            std::string Get_Flight_List();

            // An array of pointers to any/all flights that this particular user is assigned to
            Flight *on_these_flights[10]; // For arguments sake we will assume the max amount of flights a single person will ever hold tickets for at a single time will be 10

            // Set assigned seat from reservation
            bool Assign_Seat(Seat *input_seat);

            // Assign Row and Seat
            void Assign_Row_Seat(int row_used, int seat_used);

            // get age of passenger
            int Get_Age();

            // Print all the flights this passenger is on
            void Print_Flights_Attending();

            // This is used to get a string to write to external file!
            std::string Get_Writable_Data(int flight_num);

            // Check if passenger is on a certain flight
            bool Is_On_Flight(int flight_check);

            int row;
            int seat;

        private:
            // Passenger Identifiers
            std::string first_name;
            std::string last_name;
            int age;

            // Seat Assigned To
            Seat *assigned_seat;

            // Bool for checking
            bool assigned_to_seat = false;

            // Number of booked flights for the passenger
            int booked_flights = 0;

            // Just setting this up to hold a seat
            // Will connect to a seat object
            std::string seat_assigned = "1A";

    };
}

#endif // PASSENGER_H

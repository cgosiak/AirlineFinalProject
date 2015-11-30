//
// Created by caleb on 10/12/15.
//

#ifndef MYPROGRAM3_PLANE_H
#define MYPROGRAM3_PLANE_H

#include "SeatMap.h"
#include "Seat.h"
#include <ctime>

namespace FinalProject {
    class Plane {
    public:
        // This is the constructor for the plane class; this will set the private data members
        // that are not designated as constants.
        Plane(int rows, int seats);
        // Overloaded Method for handling the creation of a plane object from a non-text based file (i.e. debugging interaction)
        Plane();
        // Overloaded Method to control creation of planes from external text files
        Plane(int plane_num_used, int rows, int seats);

        // This will show a printout of useful plane data to the user
        void Show_plane_data();

        // This will allow the change of all defaults, calling each individual change method
        void Change_plane_defaults();

        // These allow the changing of the flightNumber
        void Change_flight_number(int newFlightNum);
        // Overloaded, to support user interaction if undefined for whatever reason
        void Change_flight_number();

        // These allow the changing of the airline name
        void Change_airline_name(std::string newAirlineName);
        // Overloaded, to support user interaction if undefined for whatever reason
        void Change_airline_name();

        // These allow the changing of the leaving airport name
        void Change_leaving_name(std::string newLeavingName);
        // Overloaded, to support user interaction if undefined for whatever reason
        void Change_leaving_name();

        // These allow the changing of the destination airport name
        void Change_destination_name(std::string newArrivalName);
        // Overloaded, to support user interaction if undefined for whatever reason
        void Change_destination_name();

        // This will allow the changing of the departure date
        void Change_departure_date();

        // The Plane Object must also include the ability to make a seat mapping, this will create a seatmap object within the Plane object
        void Generate_seat_map();

        // This will Print the Seat Map to the User
        void Print_seat_map();

        // This will reserve a seat!
        void Reserve_seat();
        // Overloaded to Reserve a Defined Seat
        void Reserve_seat(std::string reserveThis);

        // Clean Up Workspace
        void CleanUp_and_Close();

        // Get Current Time
        void Get_current_time();

        // Difference Function
        int Get_days_difference(int year, int month, int day);

        // Get Days to Flight
        void Get_days_to_departure();

        // Offer Choices to User
        bool User_selection_tool();

        // Return Seat
        void Return_seat();

        // Write to External File
        void WriteToExternal();

        // Get the flight number
        int Get_Flight_Num();

        // Get Rows
        int Get_Rows();

        // Get Seats Per Row
        int Get_Seats_Per_Row();

        // Is the plane assigned
        bool Is_Plane_Assigned_To_Flight();

        // Set Max Available Seats
        int Get_Max_Seats();

        // Plane has been assigned
        void Take_Plane();

        // Plane is no longer assigned
        void Return_Plane();

        // Reserving a seat, with a passenger
        bool Reserve_Seat_For_Passenger(int row, int seat, Passenger *reserving_passenger);

        // Reserve from external file
        void Reserve_From_External_File(int row, int seat, Passenger *passenger_from_file);


    private:
        int flightNumber = 456;
        std::string airLineName = "Delta";
        std::string leavingAirport = "MSP";
        std::string destinationAirport = "DFW";

        // Bool to see if plane has been assigned to a flight
        bool assigned_to_flight = false;

        // These are virtually constant, as they are private data member that do not include a method for changing them
        int plane_rows;
        int plane_seats_per_row;

        // Every Plane Object will also Require a SeatMap Object
        // This must be a pointer, as I cannot create the object completely until
        // seats and rows are defined
        FinalProject::SeatMap* plane_seat_map;

        // Save Current Time Values
        int currentYear;
        int currentMonth;
        int currentDay;

        // Flight Departure Date
        int printableDepartYear;
        int departYear = 115;
        int departMonth = 11;
        int departDay = 16;

        // Days to Flight!
        int daysToFlight;
    };
}


#endif //MYPROGRAM3_PLANE_H

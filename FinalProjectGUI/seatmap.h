#ifndef SEATMAP_H
#define SEATMAP_H

#include <QObject>

#include "seat.h"
#include "passenger.h"
#include <stdlib.h>

namespace FinalProject {
    class Seat;
    class Passenger;
    class SeatMap {
    public:
        SeatMap(int rows, int seats_per_row, int days_left);

        // This will print the current seat mapping
        void Print_seat_map();

        // Generate All the Seats in a Seat Mapping
        void  Generate_seats();

        // This will clean up the 2d pointer array when finished
        void  Dismember_seats();

        // Reservation of a Single Seat
        void Reserve_seat(int row, int seat, bool fromInputFile=false);

        // Reserving a seat, with a passenger
        bool Reserve_Seat(int row, int seat, Passenger *reserving_passenger);

        // Return Seat
        void Return_seat(int row, int seat);

        // Get a number of seats available
        int Seats_available();

        // Print Seat Data for Program 3
        double PrintSeatData(int row, int seat, int daysToFlight, int newDist);

        // Last Assigned Seat Object
        Seat *last_assigned_seat;

        // Reserve seat from external file
        void Reserve_From_File(int row, int seat, Passenger *passenger_from_file);

        // Update all seats with new days to flight
        void Update_Days_To_Flight(int days_to);

        // Get the cost of a single seat in the mapping
        double Get_Cost_of_Seat(int row, int seat);

        // get a string to print
        std::string Return_SeatMapping_String2();

        // Something is messed up
        void Set_Seat_Ints(int rows, int seats_per_row);

        // Update seats mapt string
        void Update_String_map();

        // Get String Man
        std::string Get_String_mapping(int use_this_index);


    private:
        // These are virtually constant, as they are private data member that do not include a method for changing them
        int plane_rows;
        int plane_seats_per_row;
        int days_to_flight;

        std::string printable_string_map;

        FinalProject::Seat* **Seats;

    };
}

#endif // SEATMAP_H

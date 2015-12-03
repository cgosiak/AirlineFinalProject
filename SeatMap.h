//
// Created by caleb on 10/12/15.
//

#ifndef MYPROGRAM3_SEATMAP_H
#define MYPROGRAM3_SEATMAP_H

#include "Seat.h"
#include "Passenger.h"

namespace FinalProject {
    class Seat;
    class Passenger;
    class SeatMap {
    public:
        SeatMap(int rows, int seats_per_row);

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


    private:
        // These are virtually constant, as they are private data member that do not include a method for changing them
        int plane_rows = 0;
        int plane_seats_per_row = 0;

        FinalProject::Seat* **Seats;

    };
}


#endif //MYPROGRAM3_SEATMAP_H

//
// Created by caleb on 10/12/15.
//

#ifndef MYPROGRAM3_SEATMAP_H
#define MYPROGRAM3_SEATMAP_H

#include "Seat.h"

namespace CalebG {
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

        // Return Seat
        void Return_seat(int row, int seat);

        // Get a number of seats available
        int Seats_available();

        // Write out data
        void WriteDataToFile();

        // Print Seat Data for Program 3
        double PrintSeatData(int row, int seat, int daysToFlight, int newDist);


    private:
        // These are virtually constant, as they are private data member that do not include a method for changing them
        int plane_rows;
        int plane_seats_per_row;

        CalebG::Seat* **Seats;

    };
}


#endif //MYPROGRAM3_SEATMAP_H

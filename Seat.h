//
// Created by caleb on 10/12/15.
//

#ifndef MYPROGRAM3_SEAT_H
#define MYPROGRAM3_SEAT_H

#include "Passenger.h"

namespace FinalProject {
    class Seat {
    public:
        Seat(double basePriceOfSeat, int daysLeftToFlight, int row, int seat, bool isIsle);

        // Check if Seat is Reserved
        bool Seat_reserved();

        // Reserve the seat
        void Reserve_Seat();

        // Return Seat
        void Return_Seat();

        // Assign Seat Type
        // Seat Types are: 1->First Class, 2->Economy, 3->Economy Plus
        void Assign_seat_type(int typeOfSeat);

        // Set Base Cost of Seat
        void Set_base_cost_of_seat(double basePrice);

        // Get Cost of Seat
        double Get_cost_of_seat();

        // Add Fees to Seat
        void Add_Seat_Fees(double addedFees);

        // Print Out the Seat Data
        void Print_seat_data();

        // This will be only for program 3
        void Program3(int newDaystoFlight, int distToDestination);

        // Sets days to flight
        void Set_Days_to_Flight(int newDays);

        // Set Assigned Passenger
        void Assign_Passenger(Passenger *input_pass);



        // Get Seat Letter
        // Important for if it it reserved
        std::string Get_seat_letter();

    private:
        bool isleSeat = false;
        std::string mySeatName = "Unknown";
        std::string mySeatLetter = "X";
        int seatSpace;
        double endFlightCost;
        bool reserved;
        int seat_type = 2;
        double base_cost = 0.00;
        int daysToFlight = 0;
        double seatFees = 0.00;
        std::string seatingType = "Unknown";
        Passenger *assigned_passenger;
    };
}


#endif //MYPROGRAM3_SEAT_H

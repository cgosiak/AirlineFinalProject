//
// Created by caleb on 10/12/15.
//
#include <iostream>
#include <cctype>
#include <cstdlib>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;

#include <math.h>
#include <fstream>

#include "SeatMap.h"
#include "UsefulFunctions.h"

namespace FinalProject {

    SeatMap::SeatMap(int rows, int seats_per_row, int days_left) {
        plane_rows = rows;
        plane_seats_per_row = seats_per_row;
        days_to_flight = days_left;
        Generate_seats();
    }

    void SeatMap::Print_seat_map() {
        UsefulFunctions useThis;
        cout << "SEAT MAP--------------------" << std::endl;
        cout << "ROWS: " << plane_rows << " | Seats: " << plane_seats_per_row << std::endl;
        for (int rowNum = 0; rowNum < plane_rows; rowNum++) {
            std::string rowToPrint = useThis.getStringfromInt(rowNum+1) + ":";
            for (int seatNum = 0; seatNum <= plane_seats_per_row; seatNum++) {
                rowToPrint += " " + Seats[rowNum][seatNum]->Get_seat_letter();
            }
            cout << rowToPrint << std::endl;
        }
    }

    void SeatMap::Generate_seats() {
        // this initializes the data type and memory for each element of the 2D array
        UsefulFunctions useThis;
        Seats = new Seat* * [plane_rows]; // get a chunk of memory to hold a pointer to a bool
        for (int i = 0; i < plane_rows; ++i){
            int seats_with_isle = plane_seats_per_row + 1;
            Seats[i] = new Seat* [seats_with_isle];
        }
        int isleSeat = floor((plane_seats_per_row+1)/2);
        for (int rowNum = 0; rowNum < plane_rows; ++rowNum) {
            for (int seatNum = 0; seatNum <= plane_seats_per_row; seatNum++) {
                bool isIsle;
                if (seatNum == isleSeat) {
                    isIsle = true;
                }
                else {
                    isIsle = false;
                }
                // Need to set the actual days to flight in the creation of the seat
                Seats[rowNum][seatNum] = new Seat(1000.00, days_to_flight, rowNum, seatNum, isIsle);
                if (rowNum > 0 && rowNum <=3) {
                    // First class
                    Seats[rowNum][seatNum]->Assign_seat_type(1);
                }
                else {
                    if (rowNum > 3 && rowNum <=7) {
                        // Economy Plus
                        Seats[rowNum][seatNum]->Assign_seat_type(3);
                    }
                    else {
                        // Economy
                        Seats[rowNum][seatNum]->Assign_seat_type(2);
                    }
                }

            }
            }
    }

    void SeatMap::Reserve_seat(int row, int seat, bool fromInputFile) {
        UsefulFunctions useThis;
        if (fromInputFile) {
            Seats[row][seat]->Reserve_Seat();
        }
        else {
            Seats[row][seat]->Print_seat_data();
            if (!Seats[row][seat]->Seat_reserved()) {
                cout << "\nWould you like to reserve this seat?" << std::endl;
                if (useThis.Yes_No_Question()) {
                    Seats[row][seat]->Reserve_Seat();
                }
            }
        }
    }

    void SeatMap::Dismember_seats() {
        // loop to delete all internal elements of 2d array
        for (int i = 0; i < plane_rows; ++i){
            delete [] Seats[i] ;
        }
        delete [] Seats;
    }

    int SeatMap::Seats_available() {
        int seatsAvailable = 0;
        for (int rowNum = 0; rowNum < plane_rows; ++rowNum) {
            for (int seatNum = 0; seatNum <= plane_seats_per_row; seatNum++) {
                if (!Seats[rowNum][seatNum]->Seat_reserved()) {
                   seatsAvailable++;
                }
            }
        }
        return seatsAvailable;
    }

    void SeatMap::Return_seat(int row, int seat) {
        UsefulFunctions useThis;
        Seats[row][seat]->Print_seat_data();
        if (Seats[row][seat]->Seat_reserved()) {
            cout << "\nWould you like to return this seat?" << std::endl;
            if (useThis.Yes_No_Question()) {
                Seats[row][seat]->Return_Seat();
            }
        }
    }

    double SeatMap::PrintSeatData(int row, int seat, int daysToFlight, int newDist) {
        return Seats[row][seat]->Get_cost_of_seat();
    }

    bool SeatMap::Reserve_Seat(int row, int seat, Passenger *reserving_passenger) {
        UsefulFunctions useThis;

        Seats[row][seat]->Print_seat_data();
        if (!Seats[row][seat]->Seat_reserved()) {
            cout << "\nWould you like to reserve this seat?" << std::endl;
            if (useThis.Yes_No_Question()) {
                Seats[row][seat]->Reserve_Seat();
                Seats[row][seat]->Assign_Passenger(reserving_passenger);
                reserving_passenger->Assign_Row_Seat(row, seat);
                last_assigned_seat = Seats[row][seat];
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    void SeatMap::Reserve_From_File(int row, int seat, Passenger *passenger_from_file) {
        Seats[row][seat]->Reserve_Seat();
        Seats[row][seat]->Assign_Passenger(passenger_from_file);
        last_assigned_seat = Seats[row][seat];
    }

    void SeatMap::Update_Days_To_Flight(int days_to) {
        days_to_flight = days_to;
        for (int rowNum = 0; rowNum < plane_rows; ++rowNum) {
            for (int seatNum = 0; seatNum <= plane_seats_per_row; seatNum++) {
                Seats[rowNum][seatNum]->Update_Days_and_Time(days_to_flight);
            }
        }
    }

    double SeatMap::Get_Cost_of_Seat(int row, int seat) {
        double cost = Seats[row-1][seat-1]->Get_cost_of_seat();
        return cost;
    }
}

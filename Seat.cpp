//
// Created by caleb on 10/12/15.
//
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;

#include "Seat.h"
#include "UsefulFunctions.h"

namespace FinalProject {

    Seat::Seat(double basePriceOfSeat, int daysLeftToFlight, int row, int seat, bool isIsle) {
        UsefulFunctions useThis;
        std::string seatName = useThis.getStringfromInt(row+1)+useThis.getSeatLetterFromInt(seat);
        seatSpace = seat;
        mySeatLetter = useThis.getSeatLetterFromInt(seat);
        reserved = false;
        daysToFlight = daysLeftToFlight;
        mySeatName = seatName;
        Set_base_cost_of_seat(basePriceOfSeat);
        Get_cost_of_seat();
        if (isIsle) {
            mySeatLetter = " ";
            reserved = true;
            endFlightCost = 0.00;
            seatingType = "Isle";
            isleSeat = true;
        }
    }

    bool Seat::Seat_reserved() {
        if (reserved) {
            return true;
        }
        return false;
    }

    void Seat::Reserve_Seat() {
        if (!Seat::Seat_reserved()) {
            reserved = true;
            mySeatLetter = "X";
        }
        cout << "Seat " << mySeatName << " Successfully Reserved!" << std::endl;
    }

    void Seat::Assign_seat_type(int typeOfSeat) {
        // Seat Types are: 1->First Class, 2->Economy, 3->Economy Plus
        seat_type = typeOfSeat;

        switch (typeOfSeat) {
            case 1:
                seat_type = 1;
                seatingType = "First Class";
                Get_cost_of_seat();
                break;
            case 2:
                seat_type = 2;
                seatingType = "Economy";
                Get_cost_of_seat();
                break;
            case 3:
                seat_type = 3;
                seatingType = "Economy Plus";
                Get_cost_of_seat();
                break;
            default:
                seatingType = "Economy";
                Get_cost_of_seat();
                break;
        }
    }

    void Seat::Set_base_cost_of_seat(double basePrice) {
        base_cost = basePrice;
    }

    double Seat::Get_cost_of_seat() {
        double flightCost;
        double multiplier = 1.0;

        // this is a switch controlling the direction of the program based on the user input
        switch (seat_type) {
            case 1:
                // First Class
                // Get Multiplier
                if (daysToFlight >= 30) {
                    multiplier = 3.0;
                }
                else {
                    if (daysToFlight >= 8 and daysToFlight < 30) {
                        multiplier = 4.0;
                    }
                    else {
                        multiplier = 5.0;
                    }
                }
                // Quick Check to make sure that it is non-negative in days
                if (daysToFlight < 0) {
                    cout << "THERE IS A PROBLEM WITH YOUR DAYS TO FLIGHT: " << daysToFlight << std::endl;
                    return 0.00;
                }
                flightCost = base_cost * multiplier;
                seatingType = "First Class";
                break;
            case 2:
                // Economy Class
                // Get Multiplier
                if (daysToFlight >= 30) {
                    multiplier = 1.0;
                }
                else {
                    if (daysToFlight >= 8 and daysToFlight < 30) {
                        multiplier = 1.1;
                    }
                    else {
                        multiplier = 1.2;
                    }
                }
                // Quick Check to make sure that it is non-negative in days
                if (daysToFlight < 0) {
                    cout << "THERE IS A PROBLEM WITH YOUR DAYS TO FLIGHT: " << daysToFlight << std::endl;
                    return 0.00;
                }
                flightCost = base_cost * multiplier;
                seatingType = "Economy";
                break;
            case 3:
                // Economy Plus Class
                // Get Multiplier
                if (daysToFlight >= 30) {
                    multiplier = 1.0;
                }
                else {
                    if (daysToFlight >= 8 and daysToFlight < 30) {
                        multiplier = 1.1;
                    }
                    else {
                        multiplier = 1.2;
                    }
                }
                // Quick Check to make sure that it is non-negative in days
                if (daysToFlight < 0) {
                    cout << "THERE IS A PROBLEM WITH YOUR DAYS TO FLIGHT: " << daysToFlight << std::endl;
                    return 0.00;
                }
                flightCost = base_cost * multiplier;
                seatingType = "Economy Plus";
                break;
            default:
                // every other case, just as an exception, but should already be sanitized prior to
                cout << "THERE IS A PROBLEM WITH YOUR SEAT TYPE: " << seat_type << std::endl;
                return 0.00;
        }
        flightCost += seatFees;
        endFlightCost = flightCost;
        return flightCost;
    }

    void Seat::Add_Seat_Fees(double addedFees) {
        seatFees = addedFees;
    }

    void Seat::Print_seat_data() {
        std::string isReservable;
        if (reserved) {
            isReservable = "NO";
        }
        else {
            isReservable = "YES";
        }

        if (isleSeat) {
            cout << "ERROR: Cannot Reserve Isle Seat!" << std::endl;
        }
        else {
            cout << "\nSeat " << mySeatName << " Information:" << std::endl;
            cout << "Seating Type: " << seatingType << std::endl;
            cout << "Cost: " << std::fixed << std::setprecision(2) << endFlightCost << std::endl;
            cout << "Reservable: " << isReservable << std::endl;
        }
    }

    std::string Seat::Get_seat_letter() {
        return mySeatLetter;
    }

    void Seat::Return_Seat() {
        UsefulFunctions useThis;
        if (Seat::Seat_reserved()) {
            reserved = false;
            mySeatLetter = useThis.getSeatLetterFromInt(seatSpace);
        }
        cout << "Seat " << mySeatName << " Successfully Returned!" << std::endl;
    }

    void Seat::Set_Days_to_Flight(int newDays) {
        daysToFlight = newDays;
        Seat::Get_cost_of_seat();
    }

    void Seat::Assign_Passenger(Passenger *input_pass) {
        assigned_passenger = input_pass;
    }

    void Seat::Update_Days_and_Time(int days_to) {
        daysToFlight = days_to;
        Get_cost_of_seat();
    }
}

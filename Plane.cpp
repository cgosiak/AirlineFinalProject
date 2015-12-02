//
// Created by Caleb J. Gosiak
// Desc:
// The "Plane" class is implemented in the FinalProject namespace, as are all subsequent classes.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;

#include "Plane.h"
#include "UsefulFunctions.h"

namespace FinalProject {

    Plane::Plane(int rows, int seats) {
        plane_rows = rows;
        plane_seats_per_row = seats;

        Generate_seat_map();
    }

    Plane::Plane() {
        cout << "Let's Setup Your New Plane!" << std::endl;
        cout << "----------------------------" << std::endl;
        cout << "Enter Plane Number: ";
        cin >> flightNumber;
        cout << std::endl;

        cout << "Please Enter the Amount of Rows for Your Plane: ";
        cin >> plane_rows;
        cout << std::endl;

        cout << "Please Enter the Amount of Seats Per Row for Your Plane: ";
        cin >> plane_seats_per_row;
        cout << std::endl;

        Generate_seat_map();
    }

    void Plane::Show_plane_data() {
        cout << airLineName << " Airline Information" << std::endl;
        cout << "Flight: " << flightNumber << std::endl;
        cout << "From: " << leavingAirport << " To: " << destinationAirport << std::endl;
        cout << "Rows: " << plane_rows << " | Seats Per Row: " << plane_seats_per_row << std::endl;
        cout << "Departure Date: " << departMonth << "-" << departDay << "-" << printableDepartYear << std::endl;
        cout << "Days to Flight: " << daysToFlight << std::endl;
        cout << "Current Seats Avaialble: " << plane_seat_map->Seats_available() << std::endl;
    }

    void Plane::Generate_seat_map() {
        plane_seat_map = new SeatMap(plane_rows,plane_seats_per_row);
    }

    void Plane::Print_seat_map() {
        plane_seat_map->Print_seat_map();
    }

    void Plane::Reserve_seat() {
        int row;
        int seat;

        std::string userSeat;

        cout << "Row for Reservation: ";
        cin >> row;

        cout << "Seat for Reservation: ";
        cin >> userSeat;

        FinalProject::UsefulFunctions useThis;

        seat = useThis.getIntFromSeatLetter(useThis.changeToUpper(userSeat));
        row--;


        plane_seat_map->Reserve_seat(row,seat);
    }

    void Plane::CleanUp_and_Close() {
        plane_seat_map->Dismember_seats();
    }

    void Plane::Get_current_time() {
        // Get Current Time
        time_t now = time(0);

        // Convert to Parts
        tm *ltm = localtime(&now);

        // Convert Time to String Form
        currentYear = ltm->tm_year;
        currentMonth = ltm->tm_mon + 1; // add 1 to month because users enter months as Jan = 1 rather than 0
        currentDay = ltm->tm_mday;

//        cout << "\nYear: " << currentYear << " Month: " << currentMonth << " Day: " << currentDay;
    }

    void Plane::Change_departure_date() {
        // This section still needs methods in place for sanitizing inputs!!!
        // I should be able to find good sanitization from my last program!
        int mon;
        int yr;
        int day;

        cout << "What is the Year You Would Like to Change Your Date to (ex. 2017): ";
        cin >> yr;

        cout << "What is the Month You Would Like to Change Your Date to (1-12): ";
        cin >> mon;

        cout << "What is the Day You Would Like to Change Your Date to (ex 1,30,23): ";
        cin >> day;

        printableDepartYear = day;
        departDay = printableDepartYear - 1900;
        departMonth = mon;
        departYear = yr;

        // Update Days to Flight!
        Plane::Get_days_to_departure();
    }

    void Plane::Get_days_to_departure() {
        daysToFlight = Plane::Get_days_difference(departYear,departMonth,departDay) - Plane::Get_days_difference(currentYear,currentMonth,currentDay);
    }

    int Plane::Get_days_difference(int year, int month, int day) {
        // Credit for this function goes to "chansen"
        // http://stackoverflow.com/questions/14218894/number-of-days-between-two-dates-c
        if (month > 3) {
            year--, month+=12;
        }
        int days = 365*year + year/4 - year/100 + year/400 + (153*month - 457)/5 + day - 306;
        return days;
    }

    bool Plane::User_selection_tool() {
        int usersChoice;
        cout << "\nOptions:\n" <<
                "1 - Print Seat Mapping   |   2 - Display Flight Data\n" <<
                "3 - Remove Plane         |   4 - Back To Main\n" <<
                "Your Choice [Enter]: ";
        cin >> usersChoice;
        cout << std::endl;
        switch (usersChoice) {
            case 1:
                Plane::Print_seat_map();
                break;
            case 2:
                Plane::Show_plane_data();
                break;
            case 3:
                cout << "Not Yet Implemented!" << std::endl;
                break;
            case 4:
                return false;
            default:
                cout << "Not a valid Option!" << std::endl;
                break;
        }
        return true;
    }

    void Plane::Reserve_seat(std::string reserveThis) {
        int row;
        int seat;
        UsefulFunctions useThis;
        std::string newTest;
        std::string first;
        std::string second;

        // Split up the string
        first = reserveThis[0];
        second = reserveThis[1];

        row = std::stoi(first); //stoi causes problems for me  - Matt L.
        // I see now! Why doesn't this work for you!!!
        seat = useThis.getIntFromSeatLetter(useThis.changeToUpper(second));

        // Return an uppercased string

        plane_seat_map->Reserve_seat(row, seat, true);
    }

    void Plane::Return_seat() {
        int row;
        int seat;

        std::string userSeat;

        cout << "Row for Return: ";
        cin >> row;

        cout << "Seat for Return: ";
        cin >> userSeat;

        FinalProject::UsefulFunctions useThis;

        seat = useThis.getIntFromSeatLetter(useThis.changeToUpper(userSeat));
        row--;


        plane_seat_map->Return_seat(row,seat);
    }

    int Plane::Get_Flight_Num() {
        return flightNumber;
    }

    int Plane::Get_Rows() {
        return plane_rows;
    }

    int Plane::Get_Seats_Per_Row() {
        return plane_seats_per_row;
    }

    bool Plane::Is_Plane_Assigned_To_Flight() {
        return assigned_to_flight;
    }

    int Plane::Get_Max_Seats() {
        return (plane_rows*plane_seats_per_row);
    }

    void Plane::Take_Plane() {
        assigned_to_flight = true;
    }

    void Plane::Return_Plane() {
        // no longer assigned
        assigned_to_flight = false;

        // give a brand new seat mapping
        plane_seat_map = new SeatMap(plane_rows, plane_seats_per_row);
    }

    bool Plane::Reserve_Seat_For_Passenger(int row, int seat, Passenger *reserving_passenger) {
        if (plane_seat_map->Reserve_Seat(row, seat, reserving_passenger)) {
            reserving_passenger->Assign_Seat(plane_seat_map->last_assigned_seat);
            return true;
        }
        else {
            return false;
        }
    }

    Plane::Plane(int plane_num_used, int rows, int seats) {
        plane_rows = rows;
        plane_seats_per_row = seats;
        printableDepartYear = departYear + 1900;
        flightNumber = plane_num_used;

        Plane::Generate_seat_map();
        Plane::Get_current_time();
        Plane::Get_days_to_departure();
    }

    void Plane::Reserve_From_External_File(int row, int seat, Passenger *passenger_from_file) {
        plane_seat_map->Reserve_From_File(row,seat,passenger_from_file);
        passenger_from_file->Assign_Seat(plane_seat_map->last_assigned_seat);
    }

    std::string Plane::Get_Writable_Data() {
        std::string packet_to_write;

        packet_to_write = "plane_num=" + std::to_string(flightNumber) + "\nrows=" + std::to_string(plane_rows) + "\nseats_per_row=" + std::to_string(plane_seats_per_row);

        return packet_to_write;
    }
}

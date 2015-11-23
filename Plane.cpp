//
// Created by Caleb J. Gosiak
// Desc:
// The "Plane" class is implemented in the FinalProject namespace, as are all subsequent classes.
//
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
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
        printableDepartYear = departYear + 1900;

        Plane::Generate_seat_map();
        Plane::Get_current_time();
        Plane::Get_days_to_departure();
    }

    Plane::Plane() {
        int rows;
        int seats;
        UsefulFunctions useThis;
        cout << "Would You Like to Read From an External File?" << std::endl;
        if (useThis.Yes_No_Question()) {
            std::string nameOfFIle;
            cout << "What is the name of the file your would like to read from? (ex. plane.txt): ";
            cin >> nameOfFIle;

            std::ifstream myInputFile(nameOfFIle.c_str());

            int currentIter = 0;
            if (myInputFile.is_open()) {
                // Loop Through to EOF
                std::string currentInput;
                while (myInputFile >> currentInput) {
                    // Gets numbers of rows
                    if (currentIter == 0) {
                        rows = std::stoi(currentInput);
                    }
                    else {
                        // Get Seats per row
                        if (currentIter == 1) {
                            seats = std::stoi(currentInput);

                            // Setup Everything before file reserves seats programatically
                            plane_rows = rows;
                            plane_seats_per_row = seats;

                            printableDepartYear = departYear + 1900;

                            Plane::Generate_seat_map();
                            Plane::Get_current_time();
                            Plane::Get_days_to_departure();
                        }
                        else {
                            // Handles all reserved seats
                            Plane::Reserve_seat(currentInput);
                        }
                    }
                    currentIter++;
                }
                myInputFile.close();
            }
            else {
                cout << "\nERROR: Cannot open file!" << std::endl;
            }
        }
        else {
            cout << "Please Enter the Amount of Rows for Your Plane: ";
            cin >> rows;

            cout << "Please Enter the Amount of Seats Per Row for Your Plane: ";
            cin >> seats;

            plane_rows = rows;
            plane_seats_per_row = seats;

            printableDepartYear = departYear + 1900;

            Plane::Generate_seat_map();
            Plane::Get_current_time();
            Plane::Get_days_to_departure();
        }
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

    void Plane::Change_plane_defaults() {
        Plane::Change_flight_number();
        Plane::Change_airline_name();
        Plane::Change_leaving_name();
        Plane::Change_destination_name();
        Plane::Change_departure_date();
    }

    void Plane::Change_flight_number(int newFlightNum) {
        flightNumber = newFlightNum;
    }

    void Plane::Change_flight_number() {
        int newFlightNum;

        cout << "Enter New Flight Num: ";
        cin >> newFlightNum;
        flightNumber = newFlightNum;
    }

    void Plane::Change_airline_name(std::string newAirlineName) {
        airLineName = newAirlineName;
    }

    void Plane::Change_airline_name() {
        std::string newAirlineName;

        cout << "Enter New Airline Name: ";
        cin >> newAirlineName;
        airLineName = newAirlineName;
    }

    void Plane::Change_leaving_name(std::string newLeavingName) {
        leavingAirport = newLeavingName;
    }

    void Plane::Change_leaving_name() {
        std::string newLeavingName;

        cout << "Enter New Departing Airport Name: ";
        cin >> newLeavingName;
        leavingAirport = newLeavingName;
    }

    void Plane::Change_destination_name(std::string newArrivalName) {
        destinationAirport = newArrivalName;
    }

    void Plane::Change_destination_name() {
        std::string newArrivalName;

        cout << "Enter New Destination Airport Name: ";
        cin >> newArrivalName;
        destinationAirport = newArrivalName;
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
                "3 - Seat  Reserve Tool   |   4 - Change  Flight Options\n" <<
                "5 - Cancel Reservation   |   6 - Close/End Program\n" <<
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
                Plane::Reserve_seat();
                break;
            case 4:
                Plane::Change_plane_defaults();
                break;
            case 5:
                Plane::Return_seat();
                break;
            case 6:
                Plane::WriteToExternal();
                cout << "\nHave a nice day!" << std::endl;
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

        row = std::stoi(first);
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

    void Plane::WriteToExternal() {
        plane_seat_map->WriteDataToFile();
    }

}

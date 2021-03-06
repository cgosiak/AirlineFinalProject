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
using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::cin;

#include "plane.h"
#include "usefulfunctions.h"

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
        cout << "Rows: " << plane_rows << " | Seats Per Row: " << plane_seats_per_row << std::endl;
        cout << "Current Seats Avaialble: " << plane_seat_map->Seats_available() << std::endl;
    }

    void Plane::Generate_seat_map() {
        plane_seat_map = new SeatMap(plane_rows,plane_seats_per_row,days_to_flight);
        plane_seat_map->Set_Seat_Ints(plane_rows,plane_seats_per_row);
    }

    void Plane::Print_seat_map() {
        plane_seat_map->Print_seat_map();
    }

    std::string Plane::Get_Seat_Map_String(int use_index) {
        return plane_seat_map->Get_String_mapping(use_index);
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
        plane_seat_map = new SeatMap(plane_rows, plane_seats_per_row, days_to_flight);
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
        flightNumber = plane_num_used;

        Plane::Generate_seat_map();
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

    void Plane::Update_days_to_flight(int days_to) {
        days_to_flight = days_to;
        plane_seat_map->Update_Days_To_Flight(days_to_flight);
    }

    double Plane::Get_Cost_of_Seat(int row, int seat) {
        return plane_seat_map->Get_Cost_of_Seat(row,seat);
    }
}

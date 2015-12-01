//
// Created by caleb on 11/23/15.
//
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;

#include "Flight.h"
#include "UsefulFunctions.h"

namespace FinalProject {

    Flight::Flight() {
        cout << "Let's Setup Your New Flight!" << std::endl;
        cout << "----------------------------" << std::endl;
        cout << "Enter Flight Number: ";
        cin >> flight_num;
        cout << std::endl;

        cout << "Enter Destination Airport: ";
        cin >> destination;
        cout << std::endl;

        cout << "Enter Departure Year: ";
        cin >> year;
        cout << std::endl;

        cout << "Enter Departure Month: ";
        cin >> month;
        cout << std::endl;

        cout << "Enter Departure Day: ";
        cin >> day;
        cout << std::endl;

        cout << std::endl;
    }

    void Flight::Print_Flight_Num() {
        cout << "Name of Flight: " << flight_num << std::endl;
    }

    int Flight::Get_Flight_Num() {
        return flight_num;
    }

    void Flight::Update_Days_To_Flight() {
        int days_to = 0;

        // Write Function to update days to flight

        days_to_flight = days_to;
    }

    void Flight::Assign_New_Plane() {
        if (plane_assigned) {
            assigned_plane = new Plane();
            plane_assigned = true;
        }
        else {
            // Bring up options to change to other available planes, or create a new one

        }

    }

    int Flight::Get_Days_To_Flight() {
        int days_left = 0;
        // Write function to return days between current date and departure date

        return days_left;
    }

    void Flight::Add_Passenger_To_Flight() {
        // Add ability to add passenger
        assigned_passengers++;
        passengers[assigned_passengers-1] = new Passenger();

        // Set current passenger as most recently added
        most_recently_added = passengers[assigned_passengers-1];

        // Add connection to passenger, of the flight the passenger has booked
        passengers[assigned_passengers-1]->Add_To_Flight(this);
    }

    void Flight::Print_Passenger_List() {
        // Format Space
        cout << std::endl;

        for (int i = 0; i < assigned_passengers; ++i) {
            if (i == 0) {
                cout << "Flight " << flight_num << " Passenger List:" << std::endl;
                cout << "___________________________________________" << std::endl;
                cout << "| NUM | PASSENGER NAME              | SEAT |" << std::endl;
                cout << "-------------------------------------------" << std::endl;
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(27) << passengers[i]->Get_Name() << " | " << std::setw(4) << passengers[i]->Get_Assigned_Seat() << " |" << std::endl;
                cout << "-------------------------------------------" << std::endl;
            }
            else {
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(27) << passengers[i]->Get_Name() << " | " << std::setw(4) << passengers[i]->Get_Assigned_Seat() << " |" << std::endl;
                cout << "-------------------------------------------" << std::endl;
            }
        }
    }

    std::string Flight::Get_Destination() {
        return destination;
    }

    std::string Flight::Get_Departure_Date() {
        std::string depart_day;
        depart_day = std::to_string(month) + "-" + std::to_string(day) + "-" + std::to_string(year);
        return depart_day;
    }

    int Flight::Get_Seats_Available() {
        return seats_available;
    }

    int Flight::Return_Passengers_Booked() {
        return assigned_passengers;
    }

    void Flight::Print_Flight_Data() {
        if (plane_assigned) {
            seats_available = assigned_plane->Get_Max_Seats() - assigned_passengers;
            cout << std::endl;
            cout << "Flight " << Get_Flight_Num() << " Information:" << std::endl;
            cout << "Departure: " << departure << " | Destination: " << destination << std::endl;
            cout << "Date: " << Get_Departure_Date() << std::endl;
            cout << "Plane: " << assigned_plane->Get_Flight_Num() << std::endl; // need to add plane data
            cout << "Available Seats: " << seats_available << std::endl;
        }
        else {
            cout << std::endl;
            cout << "Flight " << Get_Flight_Num() << " Information:" << std::endl;
            cout << "Departure: " << departure << " | Destination: " << destination << std::endl;
            cout << "Date: " << Get_Departure_Date() << std::endl;
            cout << "Plane: Not Set"  << std::endl; // need to add plane data
            cout << "Available Seats: 0" << std::endl;
        }
    }

    void Flight::Assign_Plane(Plane *use_this_plane) {
        if (!plane_assigned) {
            assigned_plane = use_this_plane;
            cout << "Assigned Plane " << assigned_plane->Get_Flight_Num() << " To Flight " << flight_num << std::endl;
            seats_available = (assigned_plane->Get_Max_Seats() - assigned_passengers);
            plane_assigned = true;
            assigned_plane->Take_Plane();
        }
        else {
            // Some constraints, a plane at this point for changing should have identical rows/seats to make sure the swap is taken care of correctly
            // in the future this would be replaced with an algorithm to assign seat dynamically to a plane of different sizes
            // but first check if it is already taken
            if (use_this_plane->Is_Plane_Assigned_To_Flight()) {
                cout << "ERROR: Plane " << use_this_plane->Get_Flight_Num() << " is already assigned to another flight!" << std::endl;
            }
            else {
                if (assigned_plane->Get_Rows() == use_this_plane->Get_Rows() &&
                    assigned_plane->Get_Seats_Per_Row() == use_this_plane->Get_Seats_Per_Row()) {
                    assigned_plane->Return_Plane(); // return the old plane
                    assigned_plane = use_this_plane;
                    cout << "Assigned Plane " << assigned_plane->Get_Flight_Num() << " To Flight " << flight_num <<
                    std::endl;
                    seats_available = (assigned_plane->Get_Max_Seats() - assigned_passengers);
                    plane_assigned = true;
                    assigned_plane->Take_Plane();
                }
                else {
                    cout << "ERROR: Plane " << use_this_plane->Get_Flight_Num() << " is not a valid substitute for plane " << assigned_plane->Get_Flight_Num() << std::endl;
                }
            }
        }
    }

    int Flight::Get_Plane_Num() {
        if (plane_assigned) {
            return assigned_plane->Get_Flight_Num();
        }
        else {
            return 0;
        }
    }

    bool Flight::Is_Assigned() {
        return plane_assigned;
    }

    Flight::Flight(int flight_num_used, std::string dest, int dep_yr, int dep_mt, int dep_dy, int assigned_plane_used) {
        flight_num = flight_num_used;
        destination = dest;
        year = dep_yr;
        month = dep_mt;
        day = dep_dy;
    }

    void Flight::Add_Passenger_To_Flight(std::string fName, std::string lName, int age_used, int row_used, int seat_used) {
        assigned_passengers++;
        passengers[assigned_passengers-1] = new Passenger(fName,lName,age_used,row_used,seat_used);

        // Set current passenger as most recently added
        most_recently_added = passengers[assigned_passengers-1];

        // Add connection to passenger, of the flight the passenger has booked
        passengers[assigned_passengers-1]->Add_To_Flight(this);
    }

    void Flight::Write_Passengers(std::ofstream& my_output_file) {
        for (int i = 0; i < assigned_passengers; ++i) {
            std::string acquired_passenger_data = passengers[i]->Get_Writable_Data(flight_num);
            my_output_file << acquired_passenger_data << std::endl;
        }
    }

    std::string Flight::Get_Writable_Packet() {
        std::string packet_to_use;

        if (plane_assigned) {
            packet_to_use =
                    "flight_num=" + std::to_string(flight_num) + "\ndestination=" + destination + "\ndeparture_year=" +
                    std::to_string(year) + "\ndeparture_month=" + std::to_string(month) + "\ndeparture_day=" +
                    std::to_string(day) + "\nassigned_plane=" + std::to_string(assigned_plane->Get_Flight_Num());
        }
        else {
            packet_to_use =
                    "flight_num=" + std::to_string(flight_num) + "\ndestination=" + destination + "\ndeparture_year=" +
                    std::to_string(year) + "\ndeparture_month=" + std::to_string(month) + "\ndeparture_day=" +
                    std::to_string(day) + "\nassigned_plane=" + std::to_string(0);
        }

        return packet_to_use;
    }
}
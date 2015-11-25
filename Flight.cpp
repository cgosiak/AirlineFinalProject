//
// Created by caleb on 11/23/15.
//
#include <iostream>
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

        // Call functions to complete setup of flight
        // Update_Days_To_Flight();
        // Assign_New_Plane();
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
        if (plane_set) {
            assigned_plane = new Plane();
            plane_set = true;
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
    }

    void Flight::Print_Passenger_List() {
        for (int i = 0; i < assigned_passengers; ++i) {
            if (i == 0) {
                cout << "Flight " << flight_num << " Passenger List:" << std::endl;
                cout << "___________________________________________" << std::endl;
                cout << "| NUM | PASSENGER NAME              | SEAT |" << std::endl;
                cout << "-------------------------------------------" << std::endl;
                cout << "| " << i << " | " << passengers[i]->Get_Name() << " | " << passengers[i]->Get_Assigned_Seat() << " |" << std::endl;
                cout << "-------------------------------------------" << std::endl;
            }
            else {
                cout << "| " << i << " | " << passengers[i]->Get_Name() << " | " << passengers[i]->Get_Assigned_Seat() << " |" << std::endl;
                cout << "-------------------------------------------" << std::endl;
            }
        }

    }
}
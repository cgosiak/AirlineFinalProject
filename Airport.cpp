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

#include "Airport.h"
#include "UsefulFunctions.h"

namespace FinalProject {


    Airport::Airport() {
        cout << "Opening Airport!" << std::endl;
    }

    void Airport::AddFlight() {
        // Increment Flight Amount
        current_flight_amount++;

        // Leave Space on screen for formatting
        cout << std::endl;

        // Create a new flight at the pointed array position
        current_flights[current_flight_amount-1] = new Flight();

        // Print name of the created flight
        cout << "Flight " << current_flights[current_flight_amount-1]->Get_Flight_Num() << " Created!" << std::endl;
    }

    void Airport::CleanUp() {
        cout << "Clean Up Array!" << std::endl;
    }

    void Airport::Print_Upcoming_Flights() {
        for (int i = 0; i < current_flight_amount; ++i) {
            if (i == 0) {
                cout << "List of Upcoming Flights:" << std::endl;
                cout << "____________________________________________________________" << std::endl;
                cout << "| NUM | FLIGHT NUMBER | DEST | DEPARTURE DATE | OPEN SEATS |" << std::endl;
                cout << "------------------------------------------------------------" << std::endl;
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(13) << current_flights[i]->Get_Flight_Num() << " | " << std::setw(4) << current_flights[i]->Get_Destination() << " |" << std::setw(15) << current_flights[i]->Get_Departure_Date() << " |"  << std::setw(11) << current_flights[i]->Get_Seats_Available() << " |"  << std::endl;
                cout << "------------------------------------------------------------" << std::endl;
            }
            else {
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(13) << current_flights[i]->Get_Flight_Num() << " | " << std::setw(4) << current_flights[i]->Get_Destination() << " |" << std::setw(15) << current_flights[i]->Get_Departure_Date() << " |"  << std::setw(11) << current_flights[i]->Get_Seats_Available() << " |"  << std::endl;
                cout << "------------------------------------------------------------" << std::endl;
            }
        }
    }

    void Airport::AddPlane() {
        // Increment Plane Amount
        current_plane_amount++;

        // Create a new flight at the pointed array position
        planes_at_airport[current_plane_amount-1] = new Plane();

        // Print name of the created flight
        cout << "New Plane Added!" << std::endl;
    }

    bool Airport::Select_Flight(int index_of_flight) {
        if ((index_of_flight < current_flight_amount) && (index_of_flight >= 0)) {
            selected_flight = current_flights[index_of_flight];
            cout << "SUCCESS: FLIGHT " << selected_flight->Get_Flight_Num() << " TO " << selected_flight->Get_Destination() << " SELECTED." << std::endl;

            // This will be the main loop for doing all user options with a flight!
            while (user_selections()) {
                // Do nothing in here! Could Possibly Update to external files here though...
            }

            return true;
        }
        else {
            cout << "ERROR: CANNOT SELECT NON-EXISTENT FLIGHT!!!" << std::endl;
            return false;
        }
    }

    void Airport::Select_New_Flight() {
        // Format Space
        cout << std::endl;

        // Print all available flights
        Print_Upcoming_Flights();

        int selection = 1; // This will be the answer the user chooses
        cout << "Enter the \"NUM\" value of the flight you would like to choose: ";
        cin >> selection;

        if (!Select_Flight(selection-1)) {
            // Try again
            Select_New_Flight();
        }


    }

    void Airport::Print_All_Passengers() {
        // for loop to go through all flights
        cout << std::endl << "######################### All Passengers at Airport #########################" << std::endl;
        for (int i = 0; i < current_flight_amount; ++i) {
            current_flights[i]->Print_Passenger_List();
        }
        cout << std::endl << "#############################################################################" << std::endl;
    }

    int Airport::Get_Number_of_Flights() {
        return current_flight_amount;
    }

    int Airport::Get_Number_of_Planes() {
        return current_plane_amount;
    }

    bool Airport::user_selections() {
        int usersChoice;
        cout << "\nOptions:\n" <<
        "1 - Add Passenger to Flight |   2 - Print Passengers On Flight\n" <<
        "3 - Assign  Plane to Flight |   4 - Change Flight Departure\n" <<
        "5 - Delete/Refund Flight    |   6 - Print  Flight Data\n" <<
        "7 - Return to Main\n" <<
        "Your Choice [Enter]: ";
        cin >> usersChoice;
        cout << std::endl;
        switch (usersChoice) {
            case 1:
                selected_flight->Add_Passenger_To_Flight();
                break;
            case 2:
                if (selected_flight->Return_Passengers_Booked() > 0) {
                    selected_flight->Print_Passenger_List();
                }
                else {
                    cout << "\nNo Passenger On Flight Yet!" << std::endl;
                }
                break;
            case 3:
                // Have not implemented yet
                break;
            case 4:
                // Have not implemented yet
                break;
            case 5:
                // Have not implemented yet
                break;
            case 6:
                selected_flight->Print_Flight_Data();
                break;
            case 7:
                return false;
            default:
                cout << "Not a valid Option!" << std::endl;
                break;
        }
        return true;
    }
}
//
// Created by caleb on 11/23/15.
//

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

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
                cout << "______________________________________________________________________________" << std::endl;
                cout << "| NUM | FLIGHT NUMBER | DEST | DEPARTURE DATE | OPEN SEATS | ASSIGNED FLIGHT |" << std::endl;
                cout << "------------------------------------------------------------------------------" << std::endl;
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(13) << current_flights[i]->Get_Flight_Num() << " | " << std::setw(4) << current_flights[i]->Get_Destination() << " |" << std::setw(15) << current_flights[i]->Get_Departure_Date() << " |"  << std::setw(11) << current_flights[i]->Get_Seats_Available() << " |"  << std::setw(16) << current_flights[i]->Get_Plane_Num() << " | " << std::endl;
                cout << "------------------------------------------------------------------------------" << std::endl;
            }
            else {
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(13) << current_flights[i]->Get_Flight_Num() << " | " << std::setw(4) << current_flights[i]->Get_Destination() << " |" << std::setw(15) << current_flights[i]->Get_Departure_Date() << " |"  << std::setw(11) << current_flights[i]->Get_Seats_Available() << " |"  << std::setw(16) << current_flights[i]->Get_Plane_Num() << " | " << std::endl;
                cout << "------------------------------------------------------------------------------" << std::endl;
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
        "7 - Return Reservation      |   8 - Return To Main\n" <<
        "Your Choice [Enter]: ";
        cin >> usersChoice;
        cout << std::endl;
        switch (usersChoice) {
            case 1:
                if (selected_flight->Is_Assigned()) {
                    selected_flight->Add_Passenger_To_Flight();

                    // Print Seat Mapping Quick
                    selected_flight->assigned_plane->Print_seat_map();

                    // Assign Seat
                    int row_user;
                    int seat_user;

                    std::string userSeat;

                    cout << "Row for Reservation: ";
                    cin >> row_user;

                    cout << "Seat for Reservation: ";
                    cin >> userSeat;

                    FinalProject::UsefulFunctions useThis;

                    seat_user = useThis.getIntFromSeatLetter(useThis.changeToUpper(userSeat));
                    row_user--;

                    selected_flight->assigned_plane->Reserve_Seat_For_Passenger(row_user, seat_user, selected_flight->most_recently_added);
                }
                else {
                    cout << "Plane Not Yet Assigned to Flight! Cannot Add Passengers..." << std::endl;
                }

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
                if (current_plane_amount > 0) {
                    Select_New_Plane();
                    selected_flight->Assign_Plane(selected_plane);
                }
                else {
                    cout << "\nNo Planes Exist Yet!" << std::endl;
                    return false;
                }
                break;
            case 4:
                // Have not implemented yet
                cout << "Not Yet Implemented! Under Construction!" << std::endl;
                break;
            case 5:
                // Have not implemented yet
                cout << "Not Yet Implemented! Under Construction!" << std::endl;
                break;
            case 6:
                selected_flight->Print_Flight_Data();
                Print_Seat_Map();
                break;
            case 7:
                break;
            case 8:
                return false;
            default:
                cout << "Not a valid Option!" << std::endl;
                break;
        }
        return true;
    }

    void Airport::Print_All_Planes() {
        for (int i = 0; i < current_plane_amount; ++i) {
            if (i == 0) {
                cout << "List of Available Planes:" << std::endl;
                cout << "_____________________________________________________" << std::endl;
                cout << "| NUM | PLANE NUMBER | ROWS | SEATS PER ROW | TAKEN |" << std::endl;
                cout << "-----------------------------------------------------" << std::endl;
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(12) << planes_at_airport[i]->Get_Flight_Num() << " | " << std::setw(4) << planes_at_airport[i]->Get_Rows() << " |" << std::setw(14) << planes_at_airport[i]->Get_Seats_Per_Row() << " |"  << std::setw(6) << planes_at_airport[i]->Is_Plane_Assigned_To_Flight() << " |"  << std::endl;
                cout << "-----------------------------------------------------" << std::endl;
            }
            else {
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(12) << planes_at_airport[i]->Get_Flight_Num() << " | " << std::setw(4) << planes_at_airport[i]->Get_Rows() << " |" << std::setw(14) << planes_at_airport[i]->Get_Seats_Per_Row() << " |"  << std::setw(6) << planes_at_airport[i]->Is_Plane_Assigned_To_Flight() << " |"  << std::endl;
                cout << "-----------------------------------------------------" << std::endl;
            }
        }
    }

    void Airport::Select_New_Plane() {
        // Format Space
        cout << std::endl;

        // Print all available flights
        Print_All_Planes();

        int selection = 1; // This will be the answer the user chooses
        cout << "Enter the \"NUM\" value of the plane you would like to choose: ";
        cin >> selection;

        if (!Select_Plane(selection-1)) {
            // Try again
            Select_New_Plane();
        }
    }

    bool Airport::Select_Plane(int index_of_plane) {
        if ((index_of_plane < current_plane_amount) && (index_of_plane >= 0)) {
            selected_plane = planes_at_airport[index_of_plane];
            cout << "SUCCESS: FLIGHT " << selected_plane->Get_Flight_Num() << " SELECTED." << std::endl;

            return true;
        }
        else {
            cout << "ERROR: CANNOT SELECT NON-EXISTENT PLANE!!!" << std::endl;
            return false;
        }
    }

    void Airport::Print_Seat_Map() {
        if (selected_flight->Is_Assigned()) {
            selected_plane->Print_seat_map();
        }
    }

    void Airport::Select_Plane_For_Options() {
        // Format Space
        cout << std::endl;

        // Print all available flights
        Print_All_Planes();

        int selection = 1; // This will be the answer the user chooses
        cout << "Enter the \"NUM\" value of the plane you would like to choose: ";
        cin >> selection;

        if (!Plane_Options(selection-1)) {
            // Try again
            Select_Plane_For_Options();
        }
    }

    bool Airport::Plane_Options(int index_to_use) {
        if ((index_to_use < current_plane_amount) && (index_to_use >= 0)) {
            selected_plane = planes_at_airport[index_to_use];
            cout << "SUCCESS: FLIGHT " << selected_plane->Get_Flight_Num() << " SELECTED." << std::endl;
            while (selected_plane->User_selection_tool()) {
                // Do nothing
            }
            return true;
        }
        else {
            cout << "ERROR: CANNOT SELECT NON-EXISTENT PLANE!!!" << std::endl;
            return false;
        }
    }

    void Airport::Read_External_Saved() {
        // Get Amounts
        if (Read_External_Amounts()) {
            // Read External Passengers
            if (Read_External_Passengers()) {
            }
            else {
                cout << "ERROR: Broken Reading Saved Passengers!" << std::endl;
            }
        }
        else {
            cout << "ERROR: Broken Reading Saved Amounts of Flights and Planes!" << std::endl;
        }
    }

    bool Airport::Read_External_Passengers() {
        // input file
        std::ifstream myFile ("/home/caleb/Documents/AirlineFinalProject/SavedData/passengers.txt");

        if (myFile.is_open()) {
            std::string line_read;
            while (myFile >> line_read) {
                std::stringstream line_to_use(line_read);
                std::string segment;
                std::vector<std::string> seglist;

                while(std::getline(line_to_use, segment, '$'))
                {
                    seglist.push_back(segment);
                }

                // Print contents of vector
                for (int i = 0; i < seglist.size(); ++i) {
                    cout << seglist[i] << std::endl;
                }
            }
            return true;
        }
        else {
            return false;
        }
    }

    bool Airport::Read_External_Amounts() {
        // input file
        std::ifstream myFile ("/home/caleb/Documents/AirlineFinalProject/SavedData/planes_and_flights.txt");
        int num_planes = 0;
        int num_flights = 0;

        if (myFile.is_open()) {
            std::string line_read;
            while (myFile >> line_read) {
                if (line_read.find("planes") != std::string::npos) {
                    line_read.erase(0,7);
                    num_planes = std::stoi(line_read);
                    cout << num_planes << " PLANES FOUND!" << std::endl;
                }
                else {
                    line_read.erase(0,8);
                    num_flights = std::stoi(line_read);
                    cout << num_flights << " FLIGHTS FOUND!" << std::endl;
                }
            }
            current_plane_amount = num_planes;
            current_flight_amount = num_flights;
            return true;
        }
        else {
            return false;
        }
    }
}
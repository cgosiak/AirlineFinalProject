#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using std::istream;
using std::ostream;
using std::cout;
using std::cin;

#include "Airport.h"
#include "UsefulFunctions.h"

namespace FinalProject {


    Airport::Airport() {
        // Default constructor, does nothing special!
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
        // This currently does nothing, but will clean up all arrays/pointers.
        cout << "Clean Up Array!" << std::endl;
    }

    void Airport::Print_Upcoming_Flights() {
        // Order Flights by Departure Date
        Order_Flights_By_Date();
        // Loops through all available flights, and prints valuable data
        for (int i = 0; i < current_flight_amount; ++i) {
            if (i == 0) {
                cout << "List of Upcoming Flights:" << std::endl;
                cout << "_____________________________________________________________________________________________________________" << std::endl;
                cout << "| NUM | FLIGHT NUMBER | DEST | DEPARTURE DATE | ARRIVAL DATE | OPEN SEATS | ASSIGNED PLANE | DAYS TO FLIGHT |" << std::endl;
                cout << "-------------------------------------------------------------------------------------------------------------" << std::endl;
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(13) << current_flights[i]->Get_Flight_Num() << " | " << std::setw(4) << current_flights[i]->Get_Destination() << " |" << std::setw(15) << current_flights[i]->Get_Time_Departing() << " |" << std::setw(13) << current_flights[i]->Get_Time_Arriving() << " |"  << std::setw(11) << current_flights[i]->Get_Seats_Available() << " |"  << std::setw(15) << current_flights[i]->Get_Plane_Num() << " | " << std::setw(14) << current_flights[i]->Get_Days_To_Flight() << " | " << std::endl;
                cout << "-------------------------------------------------------------------------------------------------------------" << std::endl;
            }
            else {
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(13) << current_flights[i]->Get_Flight_Num() << " | " << std::setw(4) << current_flights[i]->Get_Destination() << " |" << std::setw(15) << current_flights[i]->Get_Time_Departing() << " |" << std::setw(13) << current_flights[i]->Get_Time_Arriving() << " |"  << std::setw(11) << current_flights[i]->Get_Seats_Available() << " |"  << std::setw(15) << current_flights[i]->Get_Plane_Num() << " | " << std::setw(14) << current_flights[i]->Get_Days_To_Flight() << " | " << std::endl;
                cout << "-------------------------------------------------------------------------------------------------------------" << std::endl;
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
        // make sure the index is valid!
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
        FinalProject::UsefulFunctions useThis;
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
                    cout << "Do you need to create a new passenger? ";
                    if (useThis.Yes_No_Question()) {
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

                        seat_user = useThis.getIntFromSeatLetter(useThis.changeToUpper(userSeat));
                        row_user--;

                        selected_flight->assigned_plane->Reserve_Seat_For_Passenger(row_user, seat_user,
                                                                                    selected_flight->most_recently_added);

                        all_passengers[current_passenger_amount] = selected_flight->most_recently_added; // add the most recently added passenger to the list of all passengers
                        current_passenger_amount++;
                    }
                    else {
                        // Need to use an old passenger
                        Select_Passenger();

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


                        seat_user = useThis.getIntFromSeatLetter(useThis.changeToUpper(userSeat));
                        row_user--;

                        selected_flight->Add_Passenger_To_Flight(selected_passenger,row_user,seat_user);

                        selected_flight->assigned_plane->Reserve_Seat_For_Passenger(row_user, seat_user,
                                                                                    selected_flight->most_recently_added);
                    }
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
                // Lets Return The Flight
                cout << "Warning: This action cannot be undone!\nAre you certain you would like to continue? ";
                if (useThis.Yes_No_Question()) {
                    Return_Flight();
                    return false;
                }
                else {
                    cout << "Operation successfully cancelled." << std::endl;
                }
                break;
            case 6:
                selected_flight->Print_Flight_Data();
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
        // for loop to print valuable info for all available planes
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

        // plane selection didn't work
        if (!Select_Plane(selection-1)) {
            // Try again
            Select_New_Plane();
        }
    }

    bool Airport::Select_Plane(int index_of_plane) {
        // check to be sure that the plane selection took place correctly
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
            if (Read_External_Planes()) {
            }
            else {
                cout << "ERROR: Broken Reading Saved Planes!" << std::endl;
            }
            if (Read_External_Flights()) {
            }
            else {
                cout << "ERROR: Broken Reading Saved Flights!" << std::endl;
            }
            // Passengers can only exist if they are assigned to a flight and plane
            if (current_plane_amount > 0 && current_flight_amount > 0) {
                // Read External Passengers
                if (Read_External_Passengers()) {
                }
                else {
                    cout << "ERROR: Broken Reading Saved Passengers!" << std::endl;
                }
            }
        }
        else {
            cout << "ERROR: Broken Reading Saved Amounts of Flights and Planes!" << std::endl;
        }
    }

    bool Airport::Read_External_Passengers() {
        // input file
        std::ifstream myFile ("/home/caleb/Documents/AirlineFinalProject/SavedData/passengers.txt");

        // Passenger Stuff
        std::string first_nam;
        std::string last_nam;
        int age_used;
        int flight_assigned;
        int row_assigned;
        int seat_assigned;

        if (myFile.is_open()) {
            std::string line_read;
            while (myFile >> line_read) {
                std::stringstream line_to_use(line_read);
                std::string segment;
                std::vector<std::string> seglist;

                // create a vector of elements from a single line in the "passenger" file, seperated by the "$" character
                while(std::getline(line_to_use, segment, '$'))
                {
                    seglist.push_back(segment);
                }

                // set options for passenger to be created from external file
                // the erase option lets us "erase" unused characters in the current string
                for (int i = 0; i < seglist.size(); ++i) {
                    std::string current_string = (seglist[i]); // current string is the current iterated element in the vector created above
                    if (current_string.find("first_name") != std::string::npos) {
                        current_string.erase(0,11);
                        first_nam = current_string;
                    }
                    else {
                        if (current_string.find("last_name") != std::string::npos) {
                            current_string.erase(0, 10);
                            last_nam = current_string;
                        }
                        else {
                            if (current_string.find("age") != std::string::npos) {
                                current_string.erase(0, 4);
                                age_used = std::stoi(current_string);
                            }
                            else {
                                if (current_string.find("flight") != std::string::npos) {
                                    current_string.erase(0, 7);
                                    flight_assigned = std::stoi(current_string);
                                }
                                else {
                                    if (current_string.find("row") != std::string::npos) {
                                        current_string.erase(0, 4);
                                        row_assigned = std::stoi(current_string);
                                    }
                                    else {
                                        current_string.erase(0, 5);
                                        seat_assigned = std::stoi(current_string);
                                    }
                                }
                            }
                        }
                    }
                }
                // Everything read, create flight
                for (int j = 0; j < current_flight_amount; ++j) {
                    if (current_flights[j]->Get_Flight_Num() == flight_assigned) {
                        if (seat_assigned > 0 && row_assigned > 0) {
                            if (Check_For_Duplicate_Passenger(first_nam,last_nam,age_used)) {
                                selected_passenger = Get_Duplicate_Passenger(first_nam,last_nam,age_used);

                                selected_flight = current_flights[j];

                                selected_flight->Add_Passenger_To_Flight(selected_passenger,row_assigned,seat_assigned);

                                selected_flight->assigned_plane->Reserve_From_External_File(row_assigned-1, seat_assigned-1,
                                                                                            selected_flight->most_recently_added);
                            }
                            else {
                                current_flights[j]->Add_Passenger_To_Flight(first_nam, last_nam, age_used, row_assigned,
                                                                            seat_assigned);
                                current_flights[j]->assigned_plane->Reserve_From_External_File((row_assigned - 1),
                                                                                               (seat_assigned - 1),
                                                                                               current_flights[j]->most_recently_added);
                                all_passengers[current_passenger_amount] = current_flights[j]->most_recently_added; // add the most recently added passenger to the list of all passengers
                                current_passenger_amount++;
                            }
                        }
                    }
                }
                cout << "Passenger " << first_nam << " " << last_nam << " assigned seat Row " << row_assigned << " Seat " << seat_assigned << " On Flight " << flight_assigned << "." << std::endl;
            }
            myFile.close();
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
            myFile.close();
            return true;
        }
        else {
            return false;
        }
    }

    bool Airport::Read_External_Planes() {
        // Setup Plane Options
        int flight_num;
        int rows_read;
        int seats_read;

        // input file
        if (current_plane_amount > 0) {
            // Generate Files
            for (int i = 0; i < current_plane_amount; ++i) {
                std::string file_name;
                file_name = "/home/caleb/Documents/AirlineFinalProject/SavedData/saved_plane_" + std::to_string(i+1) + ".txt";

                std::ifstream myFile (file_name.c_str());

                if (myFile.is_open()) {
                    std::string line_read;
                    cout << "READING FILE: " << file_name << std::endl;
                    while (myFile >> line_read) {
                        if (line_read.find("plane_num") != std::string::npos) {
                            line_read.erase(0,10);
                            flight_num = std::stoi(line_read);
                        }
                        else {
                            if (line_read.find("rows") != std::string::npos) {
                                line_read.erase(0, 5);
                                rows_read = std::stoi(line_read);
                            }
                            else {
                                line_read.erase(0, 14);
                                seats_read = std::stoi(line_read);
                            }
                        }
                    }
                    // Everything read, create plane
                    planes_at_airport[i] = new Plane(flight_num,rows_read,seats_read);
                    cout << "Plane " << flight_num << " created with " << rows_read << " rows and " << seats_read << " seats per row." << std::endl;
                    myFile.close();
                }
                else {
                    cout << "ERROR: Cannot Read File_ " << file_name << std::endl;
                    return false;
                }
            }
            return true;
        }
        else {
            return true;
        }
    }

    bool Airport::Read_External_Flights() {
        // Setup Plane Options
        int flight_num;
        std::string destination;
        int depart_year;
        int depart_month;
        int depart_day;
        int depart_hr;
        int depart_min;
        int a_yr, a_mt, a_dy, a_hr, a_min;
        int plane;


        // input file
        if (current_flight_amount > 0) {
            // Generate Files
            for (int i = 0; i < current_flight_amount; ++i) {
                std::string file_name;
                file_name = "/home/caleb/Documents/AirlineFinalProject/SavedData/saved_flight_" + std::to_string(i+1) + ".txt";

                std::ifstream myFile (file_name.c_str());

                if (myFile.is_open()) {
                    std::string line_read;
                    cout << "READING FILE: " << file_name << std::endl;
                    while (myFile >> line_read) {
                        if (line_read.find("flight_num") != std::string::npos) {
                            line_read.erase(0,11);
                            flight_num = std::stoi(line_read);
                        }
                        else {
                            if (line_read.find("destination") != std::string::npos) {
                                line_read.erase(0, 12);
                                destination = line_read;
                            }
                            else {
                                if (line_read.find("departure_year") != std::string::npos) {
                                    line_read.erase(0, 15);
                                    depart_year = std::stoi(line_read);
                                }
                                else {
                                    if (line_read.find("departure_month") != std::string::npos) {
                                        line_read.erase(0, 16);
                                        depart_month = std::stoi(line_read);
                                    }
                                    else {
                                        if (line_read.find("departure_day") != std::string::npos) {
                                            line_read.erase(0, 14);
                                            depart_day = std::stoi(line_read);
                                        }
                                        else {
                                            if (line_read.find("departure_hour") != std::string::npos) {
                                                line_read.erase(0, 15);
                                                depart_hr = std::stoi(line_read);
                                            }
                                            else {
                                                if (line_read.find("departure_minute") != std::string::npos) {
                                                    line_read.erase(0, 17);
                                                    depart_min = std::stoi(line_read);
                                                }
                                                else {
                                                    if (line_read.find("arrival_year") != std::string::npos) {
                                                        line_read.erase(0, 13);
                                                        a_yr = std::stoi(line_read);
                                                    }
                                                    else {
                                                        if (line_read.find("arrival_month") != std::string::npos) {
                                                            line_read.erase(0, 14);
                                                            a_mt = std::stoi(line_read);
                                                        }
                                                        else {
                                                            if (line_read.find("arrival_day") != std::string::npos) {
                                                                line_read.erase(0, 12);
                                                                a_dy = std::stoi(line_read);
                                                            }
                                                            else {
                                                                if (line_read.find("arrival_hour") != std::string::npos) {
                                                                    line_read.erase(0, 13);
                                                                    a_hr = std::stoi(line_read);
                                                                }
                                                                else {
                                                                    if (line_read.find("arrival_minute") != std::string::npos) {
                                                                        line_read.erase(0, 15);
                                                                        a_min = std::stoi(line_read);
                                                                    }
                                                                    else {
                                                                        line_read.erase(0, 15);
                                                                        plane = std::stoi(line_read);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    // Everything read, create flight
                    current_flights[i] = new Flight(flight_num,destination,depart_year,depart_month,depart_day,depart_hr,depart_min,a_yr,a_mt,a_dy,a_hr,a_min,plane);
                    // Flight is already assigned to a plane in external data
                    if (plane > 0) {
                        for (int j = 0; j < current_plane_amount; ++j) {
                            int test_plane_num = planes_at_airport[j]->Get_Flight_Num();
                            if (test_plane_num == plane) {
                                // Assign plane object to flight
                                current_flights[i]->Assign_Plane(planes_at_airport[j]);
                            }
                        }
                    }
                    cout << "Flight " << flight_num << " created with destination " << destination << " departing " << depart_month << "-" << depart_day << "-" << depart_year << "." << std::endl;
                    myFile.close();
                }
                else {
                    cout << "ERROR: Cannot Read File_ " << file_name << std::endl;
                    return false;
                }
            }
            return true;
        }
        else {
            return true;
        }
    }

    void Airport::Save_States() {
        // Something to keep in mind is persistent data, where the same files will be stored in the same directories
        // and will always be overwritten!
        // If need arose it would be fairly easy to keep track of backup files/folders as well, but
        // for the sake of this assignment is entirely unnecessary

        // Delete all contents in directory first!
        std::string command = "rm ";
        std::string path = "/home/caleb/Documents/AirlineFinalProject/SavedData/*.txt";
        system(command.append(path).c_str());

        // Planes and Flight Amount First
        Save_State_Planes_Flights();

        // Write Passenger Data
        Save_State_Passengers();

        // Write Plane Data
        Save_State_Planes();
        // Write Flight Data
        Save_State_Flights();
    }

    void Airport::Save_State_Planes_Flights() {
        std::string file_name;
        file_name = "/home/caleb/Documents/AirlineFinalProject/SavedData/planes_and_flights.txt";
        std::ofstream myFile (file_name.c_str());

        if (myFile.is_open()) {
            myFile << "planes=" << current_plane_amount << std::endl;
            myFile << "flights=" << current_flight_amount << std::endl;
        }

        myFile.close();
    }

    void Airport::Save_State_Passengers() {
        std::string file_name;
        file_name = "/home/caleb/Documents/AirlineFinalProject/SavedData/passengers.txt";
        std::ofstream myFile (file_name.c_str());

        if (myFile.is_open()) {
            // Must loop through all available flights!
            for (int i = 0; i < current_flight_amount; ++i) {
                current_flights[i]->Write_Passengers(myFile);
            }
        }
        myFile.close();
    }

    void Airport::Save_State_Planes() {
        std::string file_name;
        // Iterate through all planes, each with a new file name
        for (int i = 0; i < current_plane_amount; ++i) {
            file_name = "/home/caleb/Documents/AirlineFinalProject/SavedData/saved_plane_" + std::to_string(i+1) + ".txt";
            std::ofstream myFile (file_name.c_str());
            myFile << planes_at_airport[i]->Get_Writable_Data() << std::endl;
            myFile.close();
        }
    }
    // Basically it moves all flights that are not being deleted into the pointer array in positions 0 - previous length -1

    void Airport::Save_State_Flights() {
        std::string file_name;
        // Iterate through all flights, each with a new file name
        for (int i = 0; i < current_flight_amount; ++i) {
            file_name = "/home/caleb/Documents/AirlineFinalProject/SavedData/saved_flight_" + std::to_string(i+1) + ".txt";
            std::ofstream myFile (file_name.c_str());
            myFile << current_flights[i]->Get_Writable_Packet() << std::endl;
            myFile.close();
        }
    }

    void Airport::Return_Flight() {
        // This is a cool algorithm I, Caleb, wrote to remove a flight.
        // The last pointer still exist, however we decrement the flight amount by 1, and the last element becomes inaccessible.

        int iter_gator = 0; // chomp chomp
        for (int i = 0; i < current_flight_amount; ++i) {
            if (current_flights[i]->Get_Flight_Num() == selected_flight->Get_Flight_Num()) {
                // This does not get iterated back into the flight
                // Return the plane, if one exists
                if (selected_flight->Is_Assigned()) {
                    selected_flight->assigned_plane->Return_Plane();
                }
            }
            else {
                // Set current iter_gator in current_flights equal to the current iterative i in current flights.
                current_flights[iter_gator] = current_flights[i];
                iter_gator++; // iterate to next position
            }
        }
        current_flight_amount--; // decrement available flights
    }

    void Airport::Order_Flights_By_Date() {
        // Need to sort flights by date
        // we will sort by days to flight
        // applying a bubble sort method!

        for (int i = 0; i < (current_flight_amount-1); ++i) {
            for (int j = 0; j < (current_flight_amount - i - 1); ++j) {
                if (current_flights[j]->departure_date > current_flights[j+1]->departure_date) {
                    Flight *swap = current_flights[j];
                    current_flights[j] = current_flights[j+1];
                    current_flights[j+1] = swap;
                }
            }
        }

    }

    void Airport::Delete_Old_Flights() {
        for (int i = 0; i < current_flight_amount; ++i) {
            if (current_flights[i]->Get_Days_To_Flight() < 0) {
                // Select the flight
                selected_flight = current_flights[i];

                // Delete the flight!
                Return_Flight();
            }
        }
    }

    void Airport::Select_Passenger() {
        // First Print all passengers
        for (int i = 0; i < current_passenger_amount; ++i) {
            if (i == 0) {
                cout << "List of Available Passengers:" << std::endl;
                cout << "______________________________________" << std::endl;
                cout << "| NUM | PASSENGER NAME         | AGE |" << std::endl;
                cout << "--------------------------------------" << std::endl;
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(22) << all_passengers[i]->Get_Name() << " | " << std::setw(3) << all_passengers[i]->Get_Age() << " |" << std::endl;
                cout << "--------------------------------------" << std::endl;
            }
            else {
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(22) << all_passengers[i]->Get_Name() << " | " << std::setw(3) << all_passengers[i]->Get_Age() << " |" << std::endl;
                cout << "--------------------------------------" << std::endl;
            }
        }
        int selection_user;
        cout << "Enter the NUM Value of the Passenger You Would Like to Select: ";
        cin >> selection_user;

        if (selection_user < 1 || selection_user > current_passenger_amount) {
            // Invalid
            cout << "Invalid Selection!" << std::endl;
        }
        else {
            // valid
            selected_passenger = all_passengers[selection_user-1];
        }
    }

    bool Airport::Passenger_Options() {
        UsefulFunctions useThis;
        cout << "\nPassenger Options for: " << selected_passenger->Get_Name() << std::endl;
        int usersChoice;
        cout << "\nOptions:\n" <<
        "1 - Add Passenger to Flight |   2 - Print Flights for This Passenger\n" <<
        "3 - Delete Passenger        |   4 - Return to Main\n" <<
        "Your Choice [Enter]: ";
        cin >> usersChoice;
        cout << std::endl;
        switch (usersChoice) {
            case 1: {
                // Select the flight
                Select_New_Flight();

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


                seat_user = useThis.getIntFromSeatLetter(useThis.changeToUpper(userSeat));
                row_user--;

                selected_flight->Add_Passenger_To_Flight(selected_passenger, row_user, seat_user);

                selected_flight->assigned_plane->Reserve_Seat_For_Passenger(row_user, seat_user,
                                                                            selected_flight->most_recently_added);
                break;
            }
            case 2: {
                selected_passenger->Print_Flights_Attending();
                break;
            }
            case 3: {
                //nothins
                break;
            }
            case 4: {
                return false;
            }
            default: {
                cout << "Not a valid Option!" << std::endl;
                break;
            }
        }
        return true;
    }

    bool Airport::Check_For_Duplicate_Passenger(std::string f_name, std::string l_name, int age) {
        for (int i = 0; i < current_passenger_amount; ++i) {
            if (all_passengers[i]->Get_First() == f_name && all_passengers[i]->Get_Last() == l_name && all_passengers[i]->Get_Age() == age) {
                return true;
            }
        }
        return false;
    }

    Passenger *Airport::Get_Duplicate_Passenger(std::string f_name, std::string l_name, int age) {
        for (int i = 0; i < current_passenger_amount; ++i) {
            if (all_passengers[i]->Get_First() == f_name && all_passengers[i]->Get_Last() == l_name && all_passengers[i]->Get_Age() == age) {
                return all_passengers[i];
            }
        }
        return nullptr;
    }
}
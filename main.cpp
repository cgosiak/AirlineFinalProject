#include <iostream>
#include "Plane.h"
#include "Flight.h"
#include "Airport.h"

using namespace std;

// This will be the main user selection tool
bool user_selections(FinalProject::Airport& airport);

int main() {
    using FinalProject::Airport;

    // Testing Time Stuff
    std::time_t now = time(0);
    char* dt = ctime(&now);
    cout << "Current Date/Time: " << dt << std::endl;

    // Construct Airport
    Airport myAirport;

    // Read in all externally saved data
    myAirport.Read_External_Saved();

    // Main Airport Loop for User Interaction
    while (user_selections(myAirport)) {
        // Anything in here should more than likely not run
    }

    // Successful Run
    return 0;
}

bool user_selections(FinalProject::Airport& airport) {
    int usersChoice;
    cout << "\nOptions:\n" <<
    "1 - Add Flight         |   2 - Add Plane\n" <<
    "3 - Select Flight      |   4 - Print All Passengers\n" <<
    "5 - Print All Flights  |   6 - Print All Planes\n" <<
    "7 - Select Plane       |   8 - Close/End Program\n" <<
    "Your Choice [Enter]: ";
    cin >> usersChoice;
    cout << std::endl;
    switch (usersChoice) {
        case 1:
            // Adding Flight
            airport.AddFlight();
            break;
        case 2:
            // Adding plane
            airport.AddPlane();
            break;
        case 3:
            // only allows the selection of a flight, if at least one flight exists
            if (airport.Get_Number_of_Flights() > 0) {
                airport.Select_New_Flight(); // This will have to be a loop to do user options local to the flight

                // Save all data, many things can change in the flight options section
                airport.Save_States();
            }
            else {
                cout << "\nNo Flights Exist! Add a Flight First!" << std::endl;
            }
            break;
        case 4:
            // print all passengers, if passengers exist
            if (airport.Get_Number_of_Flights() > 0) {
                // print passengers for each flight
                airport.Print_All_Passengers();
            }
            else {
                cout << "\nNo Passengers Exist! Add a Flight First!" << std::endl;
            }
            break;
        case 5:
            // print all flights, if the flights exist
            if (airport.Get_Number_of_Flights() > 0) {
                airport.Print_Upcoming_Flights();
            }
            else {
                cout << "\nNo Flights Exist!" << std::endl;
            }
            break;
        case 6:
            // Print all the planes
            if (airport.Get_Number_of_Planes() > 0) {
                airport.Print_All_Planes();
            }
            else {
                cout << "\nNo Planes Exist!" << std::endl;
            }
            break;
        case 7:
            // Select internal plane, go to options for that plane
            if (airport.Get_Number_of_Planes() > 0) {
                airport.Select_Plane_For_Options();
            }
            else {
                cout << "\nNo Planes Exist!" << std::endl;
            }
            break;
        case 8:
            // Clean up arrays/pointers
            airport.CleanUp();

            // Save states of all data
            airport.Save_States();

            cout << "\nHave a nice day!" << std::endl;
            return false;
        default:
            cout << "Not a valid Option!" << std::endl;
            break;
    }
    return true;
}
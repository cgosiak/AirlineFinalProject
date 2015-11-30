#include <iostream>
#include "Plane.h"
#include "Flight.h"
#include "Airport.h"

using namespace std;
bool user_selections(FinalProject::Airport& airport);

int main() {
    using FinalProject::Airport;

    Airport myAirport;

    // Read in all externally saved data
    myAirport.Read_External_Saved();

    // Main Airport Loop for User Interaction
    while (user_selections(myAirport)) {
        // Anything in here should more than likely not run
    }

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
            airport.AddFlight();
            break;
        case 2:
            airport.AddPlane();
            break;
        case 3:
            if (airport.Get_Number_of_Flights() > 0) {
                airport.Select_New_Flight(); // This will have to be a loop to do user options local to the flight
            }
            else {
                cout << "\nNo Flights Exist! Add a Flight First!" << std::endl;
            }
            break;
        case 4:
            if (airport.Get_Number_of_Flights() > 0) {
                airport.Print_All_Passengers();
            }
            else {
                cout << "\nNo Passengers Exist! Add a Flight First!" << std::endl;
            }
            break;
        case 5:
            if (airport.Get_Number_of_Flights() > 0) {
                airport.Print_Upcoming_Flights();
            }
            else {
                cout << "\nNo Flights Exist!" << std::endl;
            }
            break;
        case 6:
            if (airport.Get_Number_of_Planes() > 0) {
                airport.Print_All_Planes();
            }
            else {
                cout << "\nNo Planes Exist!" << std::endl;
            }
            break;
        case 7:
            if (airport.Get_Number_of_Planes() > 0) {
                airport.Select_Plane_For_Options();
            }
            else {
                cout << "\nNo Planes Exist!" << std::endl;
            }
            break;
        case 8:
            airport.CleanUp();
            cout << "\nHave a nice day!" << std::endl;
            return false;
        default:
            cout << "Not a valid Option!" << std::endl;
            break;
    }
    return true;
}
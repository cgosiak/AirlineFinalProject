#include <iostream>
#include "Plane.h"
#include "Flight.h"
#include "Airport.h"

using namespace std;

int main() {
    using FinalProject::Plane;
    using FinalProject::Flight;
    using FinalProject::Airport;

    // Commented Out for Testing
    // Plane myPlane;

    Airport myAirport;

//    for (int i = 0; i < 2; ++i) {
//        myAirport.AddFlight();
//    }

    myAirport.PrintNamesOfAllFlights();

    // Just a test to print user
    for (int j = 0; j < 2; ++j) {
        myAirport.current_flights[0]->Add_Passenger_To_Flight();
    }
    myAirport.current_flights[0]->Print_Passenger_List();

    myAirport.CleanUp();

    // Commented Out for Testing
    // while (myPlane.User_selection_tool());
    return 0;
}
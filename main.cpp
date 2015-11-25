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

    // Second Flight
    myAirport.AddFlight();

    myAirport.Print_Upcoming_Flights();

    // Just a test to print user
    for (int j = 0; j < 2; ++j) {
        myAirport.selected_flight->Add_Passenger_To_Flight();
    }
    myAirport.selected_flight->Print_Passenger_List();


    myAirport.Select_New_Flight();


    for (int j = 0; j < 2; ++j) {
        myAirport.selected_flight->Add_Passenger_To_Flight();
    }
    myAirport.selected_flight->Print_Passenger_List();

    myAirport.CleanUp();

    // Commented Out for Testing
    // while (myPlane.User_selection_tool());
    return 0;
}
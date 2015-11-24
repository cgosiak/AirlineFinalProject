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

    for (int i = 0; i < 3; ++i) {
        myAirport.AddFlight();
    }

    myAirport.PrintNamesOfAllFlights();

    // Commented Out for Testing
    // while (myPlane.User_selection_tool());
    return 0;
}
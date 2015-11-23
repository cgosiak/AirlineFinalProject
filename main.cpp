#include <iostream>
#include "Plane.h"
#include "Flight.h"

using namespace std;

int main() {
    using FinalProject::Plane;
    using FinalProject::Flight;

    Plane myPlane;
    Flight myAirplane;
    
    while (myPlane.User_selection_tool());
    return 0;
}
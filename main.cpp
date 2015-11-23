#include <iostream>
#include "Plane.h"
#include "Airplane.h"

using namespace std;

int main() {
    using FinalProject::Plane;
    using FinalProject::Airplane;

    Plane myPlane;
    Airplane myAirplane;
    
    while (myPlane.User_selection_tool());
    return 0;
}
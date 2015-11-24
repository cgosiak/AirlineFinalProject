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

#include "Flight.h"
#include "UsefulFunctions.h"

namespace FinalProject {

    Flight::Flight() {
        cout << "Name Your Flight: ";
        cin >> name_of_flight;
    }

    void Flight::Print_Flight_Name() {
        cout << "Name of Flight: " << name_of_flight << std::endl;
    }

    std::string Flight::Get_Flight_Name() {
        return name_of_flight;
    }
}
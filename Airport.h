//
// Created by caleb on 11/23/15.
//

#ifndef MYPROGRAM3_AIRPORT_H
#define MYPROGRAM3_AIRPORT_H

#include "Flight.h"

namespace FinalProject {
    class Airport {
    public:
        Airport();
        void AddFlight();
        void PrintNamesOfAllFlights();
        void CleanUp();

    private:
        Flight *current_flights[100];
        int current_flight_amount = 0;
    };
}


#endif //MYPROGRAM3_AIRPORT_H

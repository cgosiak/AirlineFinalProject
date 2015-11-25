//
// Created by caleb on 11/24/15.
//

#ifndef MYPROGRAM3_PASSENGER_H
#define MYPROGRAM3_PASSENGER_H


namespace FinalProject {
    class Flight; //  Must do this to resolve circular dependency between Flight and Passenger Objects
    class Passenger {
        public:
            Passenger();

            // Get Full Name
            std::string Get_Name();

            // Get Seat Assigned
            std::string Get_Assigned_Seat();

            // Add Passenger to a Flight
            void Add_To_Flight(Flight* connection);

            // An array of pointers to any/all flights that this particular user is assigned to
            Flight *on_these_flights[10]; // For arguments sake we will assume the max amount of flights a single person will ever hold tickets for at a single time will be 10

        private:
            // Passenger Identifiers
            std::string first_name;
            std::string last_name;
            int age;

            // Number of booked flights for the passenger
            int booked_flights = 0;

            // Just setting this up to hold a seat
            // Will connect to a seat object
            std::string seat_assigned = "1A";

    };
}

#endif //MYPROGRAM3_PASSENGER_H

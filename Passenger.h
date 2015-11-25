//
// Created by caleb on 11/24/15.
//

#ifndef MYPROGRAM3_PASSENGER_H
#define MYPROGRAM3_PASSENGER_H

namespace FinalProject {
    class Passenger {
        public:
            Passenger();

            // Get Full Name
            std::string Get_Name();

            // Get Seat Assigned
            std::string Get_Assigned_Seat();

        private:
            std::string first_name;
            std::string last_name;
            int age;

            // Just setting this up to hold a seat
            // Will connect to a seat object
            std::string seat_assigned = "1A";

    };
}

#endif //MYPROGRAM3_PASSENGER_H

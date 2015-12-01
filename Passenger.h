#ifndef MYPROGRAM3_PASSENGER_H
#define MYPROGRAM3_PASSENGER_H


namespace FinalProject {
    class Flight; //  Must do this to resolve circular dependency between Flight and Passenger Objects
    class Seat; //  Must do this to resolve circular dependency between Seat and Passenger Objects
    class Passenger {
        public:
            Passenger();
            // Overloaded constructor to read form text file
            Passenger(std::string fName, std::string lName, int age_used, int row_used, int seat_used);

            // Get Full Name
            std::string Get_Name();

            // Get Seat Assigned
            std::string Get_Assigned_Seat();

            // Add Passenger to a Flight
            void Add_To_Flight(Flight* connection);

            // An array of pointers to any/all flights that this particular user is assigned to
            Flight *on_these_flights[10]; // For arguments sake we will assume the max amount of flights a single person will ever hold tickets for at a single time will be 10

            // Set assigned seat from reservation
            bool Assign_Seat(Seat *input_seat);

            // Assign Row and Seat
            void Assign_Row_Seat(int row_used, int seat_used);

            // This is used to get a string to write to external file!
            std::string Get_Writable_Data(int flight_num);

        private:
            // Passenger Identifiers
            std::string first_name;
            std::string last_name;
            int age;

            // Seat Assigned To
            Seat *assigned_seat;
            int row;
            int seat;

            // Bool for checking
            bool assigned_to_seat = false;

            // Number of booked flights for the passenger
            int booked_flights = 0;

            // Just setting this up to hold a seat
            // Will connect to a seat object
            std::string seat_assigned = "1A";

    };
}

#endif //MYPROGRAM3_PASSENGER_H

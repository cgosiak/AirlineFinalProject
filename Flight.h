#ifndef MYPROGRAM3_AIRPLANE_H
#define MYPROGRAM3_AIRPLANE_H

#include "Plane.h"
#include "Passenger.h"
#include "SeatMap.h"

namespace FinalProject {
    class Flight {
    public:
        // Default Constructor
        Flight();
        // Overloaded to read from input file
        Flight(int flight_num_used, std::string dest, int dep_yr, int dep_mt, int dep_dy, int dep_hr, int dep_min, int arr_yr, int arr_mt, int arr_dy, int arr_hr, int arr_min, int assigned_plane_used);

        // Print the Flight name
        void Print_Flight_Num();

        // Return Flight Name
        int Get_Flight_Num();

        // Return the days left to departure
        int Get_Days_To_Flight();

        // Update days to flight
        void Update_Days_To_Flight();

        // Assign new plane to flight
        void Assign_New_Plane();

        // Add Passenger to Flight
        void Add_Passenger_To_Flight();
        // Overloaded to handle input from external file
        void Add_Passenger_To_Flight(std::string fName, std::string lName, int age_used, int row_used, int seat_used);

        // Print Names of all passengers
        void Print_Passenger_List();

        // Get Destination
        std::string Get_Destination();

        // Get number of seats available
        int Get_Seats_Available();

        // Retunr amount of passengers on flight
        int Return_Passengers_Booked();

        // Print Useful info about flight
        void Print_Flight_Data();

        // Assign plane to flight
        void Assign_Plane(Plane *use_this_plane);

        // Return The Plane Associated with a flight
        int Get_Plane_Num();

        // Is plane assigned to flight
        bool Is_Assigned();

        // Pointer to Plane Object
        Plane *assigned_plane;

        // Last Created Passenger
        Passenger *most_recently_added;

        // Saving Passengers w/ Reference to Write File, and right file...
        void Write_Passengers(std::ofstream& my_output_file);

        // Get packet of output info for writing flight to external file
        std::string Get_Writable_Packet();

        // Update Passengers, like when a new plane is assigned
        void Update_Passengers();

        // Get Time Departing
        std::string Get_Time_Departing();

        // Get Time Arriving
        std::string Get_Time_Arriving();

        // date structure
        time_t departure_date;

    private:
        // Name of Flight
        int flight_num;

        // Bool to check if plane has been assigned
        bool plane_assigned = false;

        // Departure Airport
        std::string departure = "MSP";

        // Destination Airport
        std::string destination;

        // Date of Flight Departure
        int day,month,year,hour,minute;

        // Date Structure
        time_t arrival_date;
        time_t current_date;

        // Days to flight
        int days_to_flight;

        // Seatmapping for Flight
        SeatMap *flight_seating;

        // Max available seats for the flight
        int max_amount_of_passengers;

        // Current amount of available seats
        int seats_available = 0;

        // Pointer to Passengers on flight
        Passenger *passengers[240]; // Initialized to 240, the max amount of passengers on a POSSIBLE flight,

        // Amount of Passengers assigned to the flight
        int assigned_passengers = 0;

    };
}

#endif //MYPROGRAM3_AIRPLANE_H

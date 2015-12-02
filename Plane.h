#ifndef MYPROGRAM3_PLANE_H
#define MYPROGRAM3_PLANE_H

#include "SeatMap.h"
#include "Seat.h"
#include <ctime>

namespace FinalProject {
    class Plane {
    public:
        // This is the constructor for the plane class; this will set the private data members
        // that are not designated as constants.
        Plane(int rows, int seats);
        // Overloaded Method for handling the creation of a plane object from a non-text based file (i.e. debugging interaction)
        Plane();
        // Overloaded Method to control creation of planes from external text files
        Plane(int plane_num_used, int rows, int seats);

        // This will show a printout of useful plane data to the user
        void Show_plane_data();

        // The Plane Object must also include the ability to make a seat mapping, this will create a seatmap object within the Plane object
        void Generate_seat_map();

        // This will Print the Seat Map to the User
        void Print_seat_map();

        // Offer Choices to User
        bool User_selection_tool();

        // Return Seat
        void Return_seat();

        // Get the flight number
        int Get_Flight_Num();

        // Get Rows
        int Get_Rows();

        // Get Seats Per Row
        int Get_Seats_Per_Row();

        // Is the plane assigned
        bool Is_Plane_Assigned_To_Flight();

        // Set Max Available Seats
        int Get_Max_Seats();

        // Plane has been assigned
        void Take_Plane();

        // Plane is no longer assigned
        void Return_Plane();

        // Reserving a seat, with a passenger
        bool Reserve_Seat_For_Passenger(int row, int seat, Passenger *reserving_passenger);

        // Reserve from external file
        void Reserve_From_External_File(int row, int seat, Passenger *passenger_from_file);

        // Get the string to write to files
        std::string Get_Writable_Data();


    private:
        int flightNumber = 456;
        std::string airLineName = "Delta";

        // Bool to see if plane has been assigned to a flight
        bool assigned_to_flight = false;

        // These are virtually constant, as they are private data member that do not include a method for changing them
        int plane_rows;
        int plane_seats_per_row;

        // Every Plane Object will also Require a SeatMap Object
        // This must be a pointer, as I cannot create the object completely until
        // seats and rows are defined
        FinalProject::SeatMap* plane_seat_map;
    };
}


#endif //MYPROGRAM3_PLANE_H

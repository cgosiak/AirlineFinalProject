#ifndef AIRPORT_H
#define AIRPORT_H

#include <QObject>

#include "flight.h"
#include "plane.h"
#include "passenger.h"
#include <vector>
#include <stdlib.h>

namespace FinalProject {
    class Airport {
    public:
        Airport();

        // Method to add a flight to the airport
        void AddFlight();

        // Method to add plane to airport
        void AddPlane();

        // Cleans pointers
        void CleanUp();

        // Assign Selected Flight, Automaticall set to the first flight if it exists
        bool Select_Flight(int index_of_flight);

        // Pointers to all the flights at the given airport, max 100 right now
        Flight *current_flights[100];

        // Pointers to all the planes at the given airport, max 100 right now
        Plane *planes_at_airport[100];

        // Print all available flights
        void Print_Upcoming_Flights();

        // Select a new flight
        void Select_New_Flight();

        // Pointer to current selected flight
        Flight *selected_flight;

        // Pointer to current selected plane
        Plane *selected_plane;

        // Print all passengers taking any flight at the airport
        void Print_All_Passengers();

        // Print all available planes
        void Print_All_Planes();

        // Get Number of Flights
        int Get_Number_of_Flights();

        // Get Number of Planes
        int Get_Number_of_Planes();

        // Get Number of Passengers
        int Get_Number_of_Passengers();

        // This will be the tool for handling Flight manipulation with the user
        bool user_selections();

        // Select New Plane
        void Select_New_Plane();

        // Assign Selected Plane
        bool Select_Plane(int index_of_plane);

        // Print Seating Map
        void Print_Seat_Map();

        // Select Plane for Plane Options
        void Select_Plane_For_Options();

        // Show plane options
        bool Plane_Options(int index_to_use);

        // Read in External Saved
        void Read_External_Saved();

        // Read Passenger External
        bool Read_External_Passengers();

        // Read Amount of Planes/FLight
        bool Read_External_Amounts();

        // Read External Planes
        bool Read_External_Planes();

        // Read external flights
        bool Read_External_Flights();

        // Need to write to external files now!
        void Save_States();

        // SS Planes?FLights
        void Save_State_Planes_Flights();

        // SS Passengers
        void Save_State_Passengers();

        // SS Planes
        void Save_State_Planes();

        // SS Flights
        void Save_State_Flights();

        // Return a flight
        void Return_Flight();

        // Order flights by date
        void Order_Flights_By_Date();

        // Delete all Flights passed
        void Delete_Old_Flights();

        // Select a passenger object
        void Select_Passenger();
        Passenger *selected_passenger; // currently seleted passenger

        // Passenger Selected Tools
        bool Passenger_Options();

        // Check for duplicate
        bool Check_For_Duplicate_Passenger(std::string f_name, std::string l_name, int age);

        // Return Passenger Object
        Passenger* Get_Duplicate_Passenger(std::string f_name, std::string l_name, int age);

        // Check for Duplicate Flight
        bool Check_For_Duplicate_Flight(int bool_flight_no);

        // Check for Duplicate Plane
        bool Check_For_Duplicate_Plane(int bool_plane_no);

        // Run Test Cases
        void Run_Test_Cases();

        // Gui add Flight
        bool GUI_Add_Flight(int flight_num,std::string destination,int depart_year,int depart_month,int depart_day,int depart_hr,int depart_min,int a_yr,int a_mt,int a_dy,int a_hr,int a_min);

        // Gui add plane
        bool GUI_Add_Plane(int plane_num, int rows, int seats_per_row);

        // GUI add passenger
        bool GUI_Add_Passenger(std::string fName, std::string lName, int age, int row, int seat);

        // GUI need printable row for flight
        std::string Get_Printable_Flight_Row(int cur_index);

        // GUI need printable row for plane
        std::string Get_Printable_Plane_Row(int cur_index);

        // GUI need printable row for passenger
        std::string Get_Printable_Passenger_Row(int cur_index);

        Passenger *all_passengers[5000]; // array of all passengers, could be bigger

        int current_passenger_amount = 0;

    private:
        int current_flight_amount = 0;
        int current_plane_amount = 0;

    };
}

#endif // AIRPORT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>
using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::cin;


#include "flight.h"
#include "usefulfunctions.h"

namespace FinalProject {

    Flight::Flight() {
        // quick lets get the current date/time
        current_date = time(0); // gets a date/time stamp
        cout << "Let's Setup Your New Flight!" << std::endl;
        cout << "----------------------------" << std::endl;
        cout << "Enter Flight Number: ";
        cin >> flight_num;
        cout << std::endl;

        cout << "Enter Destination Airport: ";
        cin >> destination;
        cout << std::endl;

        cout << "Departure Information" << std::endl;
        cout << "----------------------------" << std::endl;

        cout << "Enter Departure Year (ex. 2016): ";
        cin >> year;
        year = year - 1900; // this is how it works in date format
        cout << std::endl;

        cout << "Enter Departure Month (ex. 09): ";
        cin >> month;
        month--; // this is how it works in date format
        cout << std::endl;

        cout << "Enter Departure Day (ex. 2): ";
        cin >> day;
        cout << std::endl;

        cout << "Enter Departure Hour (ex. 8): ";
        cin >> hour;
        cout << std::endl;

        cout << "Enter Departure Minute (ex. 30): ";
        cin >> minute;
        cout << std::endl;

        UsefulFunctions useThis;
        cout << "Is this a morning flight? (prior to noon) ";
        if (useThis.Yes_No_Question()) {
            // AM Flight
        }
        else {
            // PM Flight
            if (hour <= 12 && hour > 0) {
                // add 12 hours
                hour = hour + 12;

                // If it is 24
                if (hour == 24) {
                    hour = 0;
                }
            }
            else if (hour > 12 && hour < 24) {
                // Everything is good
            }
        }

        // make destination time
        // date format
        struct tm dest_time = {0,minute,hour,day,month,year};
        departure_date = mktime(&dest_time);

        cout << "Arrival Information" << std::endl;
        cout << "----------------------------" << std::endl;

        cout << "Enter Arrival Year (ex. 2016): ";
        cin >> year;
        year = year - 1900; // this is how it works in date format
        cout << std::endl;

        cout << "Enter Arrival Month (ex. 09): ";
        cin >> month;
        month--; // this is how it works in date format
        cout << std::endl;

        cout << "Enter Arrival Day (ex. 2): ";
        cin >> day;
        cout << std::endl;

        cout << "Enter Arrival Hour (ex. 8): ";
        cin >> hour;
        cout << std::endl;

        cout << "Enter Arrival Minute (ex. 30): ";
        cin >> minute;
        cout << std::endl;

        cout << "Is this a morning arrival? (prior to noon) ";
        if (useThis.Yes_No_Question()) {
            // AM Flight
        }
        else {
            // PM Flight
            if (hour <= 12 && hour > 0) {
                // add 12 hours
                hour = hour + 12;

                // If it is 24
                if (hour == 24) {
                    hour = 0;
                }
            }
            else if (hour > 12 && hour < 24) {
                // Everything is good
            }
        }

        // make destination time
        // date format
        struct tm arri_time = {0,minute,hour,day,month,year};
        arrival_date = mktime(&arri_time);

        Update_Days_To_Flight();

        cout << std::endl;
    }

    void Flight::Print_Flight_Num() {
        cout << "Name of Flight: " << flight_num << std::endl;
    }

    int Flight::Get_Flight_Num() {
        return flight_num;
    }

    void Flight::Update_Days_To_Flight() {
        UsefulFunctions useThis;

        // update current time
        current_date = time(0); // gets a date/time stamp
        cout << "Current Date: " << ctime(&current_date);

        // Set days to flight using difference function
        days_to_flight = useThis.Days_Difference(current_date,departure_date);
    }

    void Flight::Assign_New_Plane() {
        if (plane_assigned) {
            assigned_plane = new Plane();
            plane_assigned = true;
        }
        else {
            // Bring up options to change to other available planes, or create a new one

        }

    }

    int Flight::Get_Days_To_Flight() {
        return days_to_flight;
    }

    void Flight::Add_Passenger_To_Flight() {
        // Add ability to add passenger
        assigned_passengers++;
        passengers[assigned_passengers-1] = new Passenger();

        // Set current passenger as most recently added
        most_recently_added = passengers[assigned_passengers-1];

        // Add connection to passenger, of the flight the passenger has booked
        passengers[assigned_passengers-1]->Add_To_Flight(this);
    }

    void Flight::Print_Passenger_List() {
        // Format Space
        cout << std::endl;

        for (int i = 0; i < assigned_passengers; ++i) {
            if (i == 0) {
                cout << "Flight " << flight_num << " Passenger List:" << std::endl;
                cout << "___________________________________________" << std::endl;
                cout << "| NUM | PASSENGER NAME              | SEAT |" << std::endl;
                cout << "-------------------------------------------" << std::endl;
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(27) << passengers[i]->Get_Name() << " | " << std::setw(4) << passengers[i]->Get_Assigned_Seat() << " |" << std::endl;
                cout << "-------------------------------------------" << std::endl;
            }
            else {
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(27) << passengers[i]->Get_Name() << " | " << std::setw(4) << passengers[i]->Get_Assigned_Seat() << " |" << std::endl;
                cout << "-------------------------------------------" << std::endl;
            }
        }
    }

    std::string Flight::Get_Destination() {
        return destination;
    }

    int Flight::Get_Seats_Available() {
        if (plane_assigned) {
            // max amount of passengers is rows * seats per row
            max_amount_of_passengers = assigned_plane->Get_Rows() * assigned_plane->Get_Seats_Per_Row();

            // max available - seats taken
            seats_available = max_amount_of_passengers - assigned_passengers;
        }
        else {
            seats_available = 0;
        }
        return seats_available;
    }

    int Flight::Return_Passengers_Booked() {
        return assigned_passengers;
    }

    void Flight::Print_Flight_Data() {
        if (plane_assigned) {
            seats_available = assigned_plane->Get_Max_Seats() - assigned_passengers;
            cout << std::endl;
            cout << "Flight " << Get_Flight_Num() << " Information:" << std::endl;
            cout << "Departure: " << departure << " | Destination: " << destination << std::endl;
            cout << "Date: " << Get_Time_Departing() << std::endl;
            cout << "Plane: " << assigned_plane->Get_Flight_Num() << std::endl; // need to add plane data
            cout << "Available Seats: " << seats_available << std::endl;
        }
        else {
            cout << std::endl;
            cout << "Flight " << Get_Flight_Num() << " Information:" << std::endl;
            cout << "Departure: " << departure << " | Destination: " << destination << std::endl;
            cout << "Date: " << Get_Time_Departing() << std::endl;
            cout << "Plane: Not Set"  << std::endl; // need to add plane data
            cout << "Available Seats: 0" << std::endl;
        }
    }

    void Flight::Assign_Plane(Plane *use_this_plane) {
        if (!plane_assigned) {
            assigned_plane = use_this_plane;
            cout << "Assigned Plane " << assigned_plane->Get_Flight_Num() << " To Flight " << flight_num << std::endl;
            seats_available = (assigned_plane->Get_Max_Seats() - assigned_passengers);
            plane_assigned = true;
            assigned_plane->Take_Plane();
        }
        else {
            // Some constraints, a plane at this point for changing should have identical rows/seats to make sure the swap is taken care of correctly
            // in the future this would be replaced with an algorithm to assign seat dynamically to a plane of different sizes
            // but first check if it is already taken
            if (use_this_plane->Is_Plane_Assigned_To_Flight()) {
                cout << "ERROR: Plane " << use_this_plane->Get_Flight_Num() << " is already assigned to another flight!" << std::endl;
            }
            else {
                // currently a plane swap can be made, if and only if there are exactly the same amount of seats per row as the previous plane
                // and either equal rows or greater.
                // we intend to add a plane switching assignmnet algorithm here, so a plane switch reassigns passengers to an optimal mapping
                if (assigned_plane->Get_Rows() <= use_this_plane->Get_Rows() &&
                    assigned_plane->Get_Seats_Per_Row() == use_this_plane->Get_Seats_Per_Row()) {
                    assigned_plane->Return_Plane(); // return the old plane
                    assigned_plane = use_this_plane;
                    cout << "Assigned Plane " << assigned_plane->Get_Flight_Num() << " To Flight " << flight_num <<
                    std::endl;
                    seats_available = (assigned_plane->Get_Max_Seats() - assigned_passengers);
                    plane_assigned = true;
                    assigned_plane->Take_Plane();
                    Update_Passengers();
                }
                else {
                    cout << "ERROR: Plane " << use_this_plane->Get_Flight_Num() << " is not a valid substitute for plane " << assigned_plane->Get_Flight_Num() << std::endl;
                }
            }
        }
    }

    int Flight::Get_Plane_Num() {
        if (plane_assigned) {
            return assigned_plane->Get_Flight_Num();
        }
        else {
            return 0;
        }
    }

    bool Flight::Is_Assigned() {
        return plane_assigned;
    }

    int Flight::Get_Cost_Of_Seat(int row, int seat) {
        return flight_seating->Get_Cost_of_Seat(row,seat);
    }

    Flight::Flight(int flight_num_used, std::string dest, int dep_yr, int dep_mt, int dep_dy, int dep_hr, int dep_min, int arr_yr, int arr_mt, int arr_dy, int arr_hr, int arr_min, int assigned_plane_used) {
        flight_num = flight_num_used;
        destination = dest;

        // departure times
        year = dep_yr;
        month = dep_mt;
        day = dep_dy;
        hour = dep_hr;
        minute = dep_min;

        // format for date creation
        month = month - 1;
        year = year - 1900;

        // make destination time
        // date format
        struct tm dest_time = {0,minute,hour,day,month,year};
        departure_date = mktime(&dest_time);
        cout << "Departure Date Created: " << ctime(&departure_date);

        // arrival times
        year = arr_yr;
        month = arr_mt;
        day = arr_dy;
        hour = arr_hr;
        minute = arr_min;

        // format for date creation
        month = month - 1;
        year = year - 1900;

        // make destination time
        // date format
        struct tm arri_time = {0,minute,hour,day,month,year};
        arrival_date = mktime(&arri_time);

        cout << "Arrival Date Created: " << ctime(&arrival_date);

        // Update
        Update_Days_To_Flight();
    }

    void Flight::Add_Passenger_To_Flight(std::string fName, std::string lName, int age_used, int row_used, int seat_used) {
        assigned_passengers++;
        passengers[assigned_passengers-1] = new Passenger(fName,lName,age_used,row_used,seat_used);

        // Set current passenger as most recently added
        most_recently_added = passengers[assigned_passengers-1];

        // Add connection to passenger, of the flight the passenger has booked
        passengers[assigned_passengers-1]->Add_To_Flight(this);
    }

    void Flight::Write_Passengers(std::ofstream& my_output_file) {
        for (int i = 0; i < assigned_passengers; ++i) {
            std::string acquired_passenger_data = passengers[i]->Get_Writable_Data(flight_num);
            my_output_file << acquired_passenger_data << std::endl;
        }
    }

    std::string Flight::Get_Writable_Packet() {
        std::string packet_to_use;
        tm dep_times = *localtime(&departure_date);
        tm arr_times = *localtime(&arrival_date);

        if (plane_assigned) {
            packet_to_use =
                    "flight_num=" + std::to_string(flight_num) + "\ndestination=" + destination + "\ndeparture_year=" +
                    std::to_string(dep_times.tm_year + 1900) + "\ndeparture_month=" + std::to_string(dep_times.tm_mon + 1) + "\ndeparture_day=" +
                    std::to_string(dep_times.tm_mday) + "\ndeparture_hour=" + std::to_string(dep_times.tm_hour) + "\ndeparture_minute=" +
                    std::to_string(dep_times.tm_min) + "\narrival_year=" + std::to_string(arr_times.tm_year + 1900) + "\narrival_month=" +
                    std::to_string(arr_times.tm_mon + 1) + "\narrival_day=" + std::to_string(arr_times.tm_mday) + "\narrival_hour=" +
                    std::to_string(arr_times.tm_hour) + "\narrival_minute=" + std::to_string(arr_times.tm_min) +
                    "\nassigned_plane=" + std::to_string(assigned_plane->Get_Flight_Num());
        }
        else {
            packet_to_use =
                    "flight_num=" + std::to_string(flight_num) + "\ndestination=" + destination + "\ndeparture_year=" +
                    std::to_string(dep_times.tm_year + 1900) + "\ndeparture_month=" + std::to_string(dep_times.tm_mon + 1) + "\ndeparture_day=" +
                    std::to_string(dep_times.tm_mday) + "\ndeparture_hour=" + std::to_string(dep_times.tm_hour) + "\ndeparture_minute=" +
                    std::to_string(dep_times.tm_min) + "\narrival_year=" + std::to_string(arr_times.tm_year + 1900) + "\narrival_month=" +
                    std::to_string(arr_times.tm_mon + 1) + "\narrival_day=" + std::to_string(arr_times.tm_mday) + "\narrival_hour=" +
                    std::to_string(arr_times.tm_hour) + "\narrival_minute=" + std::to_string(arr_times.tm_min) +
                    "\nassigned_plane=" + std::to_string(0);
        }

        return packet_to_use;
    }

    void Flight::Update_Passengers() {
        for (int i = 0; i < assigned_passengers; ++i) {
            assigned_plane->Reserve_From_External_File(passengers[i]->row,passengers[i]->seat,passengers[i]);
        }
    }

    std::string Flight::Get_Time_Departing() {
        tm my_time = *localtime(&departure_date);
        std::string departure_date_string;
        if (my_time.tm_min < 10) {
            departure_date_string =
                    std::to_string(my_time.tm_mon + 1) + "-" + std::to_string(my_time.tm_mday) + " " +
                    std::to_string(my_time.tm_hour) + ":0" + std::to_string(my_time.tm_min);
        }
        else {
            departure_date_string =
                    std::to_string(my_time.tm_mon + 1) + "-" + std::to_string(my_time.tm_mday) + " " +
                    std::to_string(my_time.tm_hour) + ":" + std::to_string(my_time.tm_min);
        }
        return departure_date_string;
    }

    std::string Flight::Get_Time_Arriving() {
        tm my_time = *localtime(&arrival_date);
        std::string arrival_date_string;
        if (my_time.tm_min < 10) {
            arrival_date_string =
                    std::to_string(my_time.tm_mon + 1) + "-" + std::to_string(my_time.tm_mday) + " " +
                    std::to_string(my_time.tm_hour) + ":0" + std::to_string(my_time.tm_min);
        }
        else {
            arrival_date_string =
                    std::to_string(my_time.tm_mon + 1) + "-" + std::to_string(my_time.tm_mday) + " " +
                    std::to_string(my_time.tm_hour) + ":" + std::to_string(my_time.tm_min);
        }
        return arrival_date_string;
    }

    Passenger* Flight::Return_Passenger_Object(int object_iter) {
        return passengers[object_iter];
    }

    std::string Flight::Return_SeatMapping_String() {
        std::string rows = flight_seating->Return_SeatMapping_String2();
        return rows;
    }

    void Flight::Add_Passenger_To_Flight(Passenger *passenger, int row_used, int seat_used) {
        assigned_passengers++;
        passengers[assigned_passengers-1] = passenger;

        // Set current passenger as most recently added
        most_recently_added = passengers[assigned_passengers-1];

        // Add connection to passenger, of the flight the passenger has booked
        passengers[assigned_passengers-1]->Add_To_Flight(this);
    }

    void Flight::Fix_Added_Passenger(Passenger *fixed_passenger) {
        // Add ability to add passenger
        passengers[assigned_passengers-1] = fixed_passenger;

        // Set current passenger as most recently added
        most_recently_added = passengers[assigned_passengers-1];

        // Add connection to passenger, of the flight the passenger has booked
        passengers[assigned_passengers-1]->Add_To_Flight(this);
    }

    bool Flight::Has_Passengers() {
        if (assigned_passengers > 0) {
            return true;
        }
        return false;
    }
}

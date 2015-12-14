#include <iostream>
#include <iomanip>
#include "passenger.h"
#include "seat.h"
#include <sstream>
using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::cin;


namespace FinalProject {

    Passenger::Passenger() {

        cout << std::endl;
        cout << "New Passenger Creation" << std::endl;
        cout << "----------------------------" << std::endl;
        cout << "Passenger First Name: ";
        cin >> first_name;

        cout << "Passenger Last Name: ";
        cin >> last_name;

        cout << "Passenger Age: ";
        cin >> age;

    }

    std::string Passenger::Get_Name() {
        std::string full_name;

        full_name = first_name + " " + last_name;
        return full_name;
    }

    std::string Passenger::Get_Assigned_Seat() {
        seat_assigned = assigned_seat->mySeatName;
        return seat_assigned;
    }

    void Passenger::Add_To_Flight(Flight* connection) {
        booked_flights++;
        on_these_flights[booked_flights-1] = connection;
    }

    bool Passenger::Assign_Seat(Seat *input_seat) {
        assigned_seat = input_seat;
        assigned_to_seat = true;
        return assigned_to_seat;
    }

    void Passenger::Assign_Row_Seat(int row_used, int seat_used) {
        row = row_used;
        seat = seat_used;
    }

    std::string Passenger::Get_Flight_List() {
        std::string flight_list;
        if (booked_flights == 0) {
            flight_list = "NOT ASSIGNED TO FLIGHTS";
        }
        else {
            for (int i = 0; i < booked_flights; i++) {
                flight_list = std::to_string(on_these_flights[i]->Get_Flight_Num()) + " to " + on_these_flights[i]->Get_Destination() + ", ";
            }
        }
        return flight_list;
    }

    Passenger::Passenger(std::string fName, std::string lName, int age_used, int row_used, int seat_used) {
        first_name = fName;
        last_name = lName;
        age = age_used;
        row = row_used;
        seat = seat_used;
    }

    std::string Passenger::Get_Writable_Data(int flight_num) {
        std::string write_this;
        write_this = "first_name=" + first_name + "$last_name=" + last_name + "$age=" + std::to_string(age) + "$flight=" + std::to_string(flight_num) + "$row=" + std::to_string(row) + "$seat=" + std::to_string(seat);
        return write_this;
    }

    int Passenger::Get_Age() {
        return age;
    }

    void Passenger::Print_Flights_Attending() {
        cout <<  "Passenger: " << Get_Name() << " Flights" << std::endl;
        for (int i = 0; i < booked_flights; ++i) {
            if (i == 0) {
                cout << "__________________________________________________________" << std::endl;
                cout << "| NUM | FLIGHT | DEST | DEPARTURE   | ARRIVAL     | DAYS |" << std::endl;
                cout << "----------------------------------------------------------" << std::endl;
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(6) << on_these_flights[i]->Get_Flight_Num() << " | " << std::setw(4) << on_these_flights[i]->Get_Destination() << " |" << std::setw(12) << on_these_flights[i]->Get_Time_Departing() << " |" << std::setw(12) << on_these_flights[i]->Get_Time_Arriving() << " | " << std::setw(4) << on_these_flights[i]->Get_Days_To_Flight() << " | " << std::endl;
                cout << "----------------------------------------------------------" << std::endl;
            }
            else {
                cout << "| " << std::setw(3) << (i+1) << " | " << std::setw(6) << on_these_flights[i]->Get_Flight_Num() << " | " << std::setw(4) << on_these_flights[i]->Get_Destination() << " |" << std::setw(12) << on_these_flights[i]->Get_Time_Departing() << " |" << std::setw(12) << on_these_flights[i]->Get_Time_Arriving() << " | " << std::setw(4) << on_these_flights[i]->Get_Days_To_Flight() << " | " << std::endl;
                cout << "----------------------------------------------------------" << std::endl;
            }
        }
    }

    std::string Passenger::Get_First() {
        return first_name;
    }

    std::string Passenger::Get_Last() {
        return last_name;
    }

    bool Passenger::Is_On_Flight(int flight_check) {
        for (int i = 0; i < booked_flights; i++) {
            if (on_these_flights[i]->Get_Flight_Num() == flight_check) {
                return true;
            }
        }
        return false;
    }
}

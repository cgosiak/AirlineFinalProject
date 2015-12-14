#include "planegui.h"
#include "ui_planegui.h"
#include <iostream>
#include "plane.h"
#include "flight.h"
#include "airport.h"
#include "usefulfunctions.h"
#include <QMessageBox>
using namespace std;

FinalProject::Airport airport;

PlaneGUI::PlaneGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlaneGUI)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    airport.Read_External_Saved();
}

PlaneGUI::~PlaneGUI()
{
    cout << "Saving All Data!" << endl;
    airport.Save_States();
    delete ui;
}

void PlaneGUI::on_add_flight_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void PlaneGUI::on_add_plane_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void PlaneGUI::on_select_flight_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    // Clear List first
    ui->flights_list->clear();
    int flights = airport.Get_Number_of_Flights();
    if (flights == 0) {
        ui->flights_list->addItem("NO FLIGHTS EXIST");
    }
    else {
        airport.Order_Flights_By_Date();
        for (int i = 0; i < flights; i++) {
            QString myRow = QString::fromStdString(airport.Get_Printable_Flight_Row(i));
            ui->flights_list->addItem(myRow);
        }
    }
}

void PlaneGUI::on_print_passengers_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->passenger_list->clear();
    int passengers = airport.Get_Number_of_Passengers();
    if (passengers == 0) {
        ui->passenger_list->addItem("NO PASSENGERS EXIST");
    }
    else {
        for (int i = 0; i < passengers; i++) {
            QString myRow = QString::fromStdString(airport.Get_Printable_Passenger_Row(i));
            ui->passenger_list->addItem(myRow);
        }
    }
}

void PlaneGUI::on_print_flights_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    // Clear List first
    ui->flights_list->clear();
    int flights = airport.Get_Number_of_Flights();
    if (flights == 0) {
        ui->flights_list->addItem("NO FLIGHTS EXIST");
    }
    else {
        airport.Order_Flights_By_Date();
        for (int i = 0; i < flights; i++) {
            QString myRow = QString::fromStdString(airport.Get_Printable_Flight_Row(i));
            ui->flights_list->addItem(myRow);
        }
    }

}

void PlaneGUI::on_print_planes_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->plane_list_widget->clear();
    int planes = airport.Get_Number_of_Planes();
    if (planes == 0) {
        ui->plane_list_widget->addItem("NO PLANES EXIST");
    }
    else {
        for (int i = 0; i < planes; i++) {
            QString myRow = QString::fromStdString(airport.Get_Printable_Plane_Row(i));
            ui->plane_list_widget->addItem(myRow);
        }
    }
}

void PlaneGUI::on_Cancel_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PlaneGUI::on_Cancel_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PlaneGUI::on_Cancel_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PlaneGUI::on_Cancel_button_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PlaneGUI::on_Cancel_button_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PlaneGUI::on_Cancel_button_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PlaneGUI::on_Cancel_button_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PlaneGUI::on_Cancel_button_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PlaneGUI::on_Cancel_button_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PlaneGUI::on_Add_Planeinput_button_clicked()
{
    int plane_num = ui->FlightNum_Input->text().toInt();
    int seat_per_row = ui->NumeberofSeatsPer_input->text().toInt();
    int rows = ui->NumberofRows_input->text().toInt();
    if (plane_num == 0 || seat_per_row == 0 || rows == 0) {
        ui->error_label_2->setText("ERROR: Please fill in all forms!");
    }
    else {
        //make a new plane
        if (airport.GUI_Add_Plane(plane_num,rows,seat_per_row)) {
            ui->FlightNum_Input->clear();
            ui->NumeberofSeatsPer_input->clear();
            ui->NumberofRows_input->clear();
            ui->stackedWidget->setCurrentIndex(0);
        }
        else {
            ui->error_label_2->setText("ERROR: Plane already exists!");
        }
    }
}

void PlaneGUI::on_Search_For_Flight_Button_clicked()
{
    ui->Select_FlightNum_Input->text().toStdString();
}

void PlaneGUI::on_Select_New_Plane_button_clicked()
{
    ui->PlaneNum_input->text().toStdString();
}

void PlaneGUI::on_Search_Passenger_Num_button_clicked()
{
    ui->Passenger_Num_input->text().toStdString();
}

void PlaneGUI::on_save_flight_button_clicked()
{
    int flight_num = ui->FlightNumDepart_Input->text().toInt();
    std::string destination = ui->Destination__Input->text().toStdString();
    int dep_year = ui->YearDepart_Input->text().toInt();
    int arr_year = ui->YearArrive_Input->text().toInt();
    int dep_month = ui->MonthDepart_Input->text().toInt();
    int arr_month = ui->MonthArrive_Input->text().toInt();
    int dep_day = ui->DayDepart_input->text().toInt();
    int arr_day = ui->DayArrive_input->text().toInt();
    int dep_hour = ui->HourDepart_Input->text().toInt();
    int arr_hour = ui->HourArrive_Input->text().toInt();
    int dep_min = ui->MinuteDepart_Input->text().toInt();
    int arr_min = ui->MinuteArrive_Input->text().toInt();

    // check if any are null, which they cannot be
    if (flight_num == 0 || destination == "" || dep_year == 0 || arr_year == 0 || dep_month == 0 || arr_month == 0 || dep_day == 0 || arr_day == 0 || dep_hour == 0 || arr_hour == 0 || dep_min == 0 || arr_min == 0) {
        cout << "No Good!" << endl;
        ui->error_label->setText("ERROR: Please fill in all forms!");
    }
    else {
        if (airport.GUI_Add_Flight(flight_num,destination,dep_year,dep_month,dep_day,dep_hour,dep_min,arr_year,arr_month,arr_day,arr_hour,arr_min)) {
            ui->FlightNumDepart_Input->clear();
            ui->Destination__Input->clear();
            ui->YearDepart_Input->clear();
            ui->YearArrive_Input->clear();
            ui->MonthDepart_Input->clear();
            ui->MonthArrive_Input->clear();
            ui->DayDepart_input->clear();
            ui->DayArrive_input->clear();
            ui->HourDepart_Input->clear();
            ui->HourArrive_Input->clear();
            ui->MinuteDepart_Input->clear();
            ui->MinuteArrive_Input->clear();
            ui->stackedWidget->setCurrentIndex(0);
        }
        else {
            ui->error_label->setText("ERROR: Cannot add flight!");
        }
    }
}

void PlaneGUI::on_flights_list_currentRowChanged(int currentRow)
{
    // Flight Selected
    cout << currentRow << endl;
    if (airport.Get_Number_of_Flights() > 0 && currentRow >= 0) {
        airport.Select_Flight(currentRow);
        ui->stackedWidget->setCurrentIndex(10);
    }
}

void PlaneGUI::on_plane_list_widget_currentRowChanged(int currentRow)
{
    // Flight Selected
    cout << currentRow << endl;
    if (airport.Get_Number_of_Planes() > 0 && currentRow >= 0) {
        airport.Select_Plane(currentRow);
    }
}

void PlaneGUI::on_return_to_main_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PlaneGUI::on_assign_plane_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    ui->select_plane_list_widget->clear();
    int planes = airport.Get_Number_of_Planes();
    if (planes == 0) {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else {
        for (int i = 0; i < planes; i++) {
            QString myRow = QString::fromStdString(airport.Get_Printable_Plane_Row(i));
            ui->select_plane_list_widget->addItem(myRow);
        }
    }
}

void PlaneGUI::on_select_plane_list_widget_currentRowChanged(int currentRow)
{
    if (currentRow > 0) {
        airport.selected_flight->Assign_Plane(airport.planes_at_airport[currentRow]);
        ui->stackedWidget->setCurrentIndex(10);
    }
}

void PlaneGUI::on_back_to_flight_options_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void PlaneGUI::on_print_passengers_on_flight_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
    ui->passengers_list_widget->clear();
    ui->passenger_flight_title->setText("Flight " + QString::fromStdString(std::to_string(airport.selected_flight->Get_Flight_Num())) + " Passenger List");
    int passengers = airport.Get_Number_of_Passengers();
    if (passengers == 0) {
        ui->passengers_list_widget->addItem("NO PASSENGERS EXIST");
    }
    else {
        for (int i = 0; i < passengers; i++) {
            if (airport.all_passengers[i]->Is_On_Flight(airport.selected_flight->Get_Flight_Num())) {
                QString myRow = QString::fromStdString(airport.Get_Printable_Passenger_Row(i));
                ui->passengers_list_widget->addItem(myRow);
            }
        }
    }
}

void PlaneGUI::on_back_again_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void PlaneGUI::on_print_flight_data_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
    std::string myRow;
    myRow = "Flight Number: " + std::to_string(airport.selected_flight->Get_Flight_Num()) + "\nDestination: " + airport.selected_flight->Get_Destination() + "\nDeparture: " + airport.selected_flight->Get_Time_Departing() + "\nArrival: " + airport.selected_flight->Get_Time_Departing() + "\nSeats Available: " + std::to_string(airport.selected_flight->Get_Seats_Available());
    ui->flight_details_fill->setText(QString::fromStdString(myRow));
}

void PlaneGUI::on_add_passenger_to_flight_clicked()
{
    if (airport.selected_flight->Is_Assigned()) {
        ui->stackedWidget->setCurrentIndex(14);
        ui->usable_passenger_list->clear();
        int passengers = airport.Get_Number_of_Passengers();
        if (passengers == 0) {
            ui->usable_passenger_list->addItem("NO PASSENGERS EXIST");
        }
        else {
            for (int i = 0; i < passengers; i++) {
                QString myRow = QString::fromStdString(airport.Get_Printable_Passenger_Row(i));
                ui->usable_passenger_list->addItem(myRow);
            }
        }
    }
    else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Alert");
        msgBox.setText("You cannot add passengers to a flight without an assigned plane!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}

void PlaneGUI::on_usable_passenger_list_currentRowChanged(int currentRow)
{
    if (currentRow > 0) {
        if (airport.all_passengers[currentRow]->Is_On_Flight(airport.selected_flight->Get_Flight_Num())) {
            // can't add the passenger
        }
        else {
            airport.selected_passenger = airport.all_passengers[currentRow];
            ui->stackedWidget->setCurrentIndex(20);
            ui->available_seats_mapping_2->clear();
            int rows = airport.selected_flight->assigned_plane->Get_Rows();
            for (int i = 0; i < rows; i++) {
                std::string new_row = airport.selected_flight->assigned_plane->Get_Seat_Map_String(i);
                ui->available_seats_mapping_2->addItem(QString::fromStdString(new_row));
            }
        }
    }
}

void PlaneGUI::on_next_from_passenger_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
    ui->available_seats_mapping->clear();
    int rows = airport.selected_flight->assigned_plane->Get_Rows();
    for (int i = 0; i < rows; i++) {
        std::string new_row = airport.selected_flight->assigned_plane->Get_Seat_Map_String(i);
        ui->available_seats_mapping->addItem(QString::fromStdString(new_row));
    }
}

void PlaneGUI::on_add_new_passenger_to_flight_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void PlaneGUI::on_cancel_flight_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Cancel Flight");
    msgBox.setText("Are you sure you would like to cancel this flight?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
        // do something
        airport.Return_Flight();
        ui->stackedWidget->setCurrentIndex(0);
    }else {
        // do something else
    }
}

void PlaneGUI::on_passenger_list_currentRowChanged(int currentRow)
{
    airport.selected_passenger = airport.all_passengers[currentRow];
    ui->stackedWidget->setCurrentIndex(17);
    ui->pass_label->setText("Passenger: " + QString::fromStdString(airport.selected_passenger->Get_Name()));
}

void PlaneGUI::on_ret_pass_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void PlaneGUI::on_cancel_add_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void PlaneGUI::on_add_to_flight_pass_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
    ui->add_pass_to_flight_list->clear();
    int flights = airport.Get_Number_of_Flights();
    if (flights == 0) {
        ui->add_pass_to_flight_list->addItem("NO FLIGHTS EXIST");
    }
    else {
        airport.Order_Flights_By_Date();
        for (int i = 0; i < flights; i++) {
            QString myRow = QString::fromStdString(airport.Get_Printable_Flight_Row(i));
            ui->add_pass_to_flight_list->addItem(myRow);
        }
    }
}

void PlaneGUI::on_add_pass_to_flight_list_currentRowChanged(int currentRow)
{
    if (currentRow >= 0) {
        airport.Select_Flight(currentRow);
        ui->stackedWidget->setCurrentIndex(20);
        ui->available_seats_mapping_2->clear();
        int rows = airport.selected_flight->assigned_plane->Get_Rows();
        for (int i = 0; i < rows; i++) {
            std::string new_row = airport.selected_flight->assigned_plane->Get_Seat_Map_String(i);
            ui->available_seats_mapping_2->addItem(QString::fromStdString(new_row));
        }
    }
}

void PlaneGUI::on_back_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void PlaneGUI::on_print_flights_pass_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
    ui->on_flights_label->setText(QString::fromStdString(airport.selected_passenger->Get_Name()) + " Flights");
    ui->on_these_flights_list->clear();
    int flights = airport.Get_Number_of_Flights();
    if (flights == 0) {
        ui->on_these_flights_list->addItem("NO FLIGHTS EXIST");
    }
    else {
        airport.Order_Flights_By_Date();
        for (int i = 0; i < flights; i++) {
            if (airport.selected_passenger->Is_On_Flight(airport.current_flights[i]->Get_Flight_Num())) {
                QString myRow = QString::fromStdString(airport.Get_Printable_Flight_Row(i));
                ui->on_these_flights_list->addItem(myRow);
            }
        }
    }
}

void PlaneGUI::on_pushButton_clicked()
{
    FinalProject::UsefulFunctions useThis;
    std::string first_name = ui->fName_input->text().toUtf8().constData();
    std::string last_name = ui->lName_input->text().toUtf8().constData();
    int age = ui->age_input->text().toInt();
    int row_chosen = ui->row_chosen->text().toInt();
    std::string seat_chosen = ui->seat_chosen->text().toUtf8().constData();

    if (first_name == "" || last_name == "" || age == 0 || row_chosen == 0 || seat_chosen == "") {
        // Missing Stuff!
    }
    else {
        // Offer A reservation
        QMessageBox msgBox;
        msgBox.setWindowTitle("Reserve Seat");
        msgBox.setText("Are you sure you would like to reserve seat " + QString::number(row_chosen) + QString::fromStdString(seat_chosen));
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec() == QMessageBox::Yes){
            int row_assigned = row_chosen;
            int seat_assigned = useThis.getIntFromSeatLetter(seat_chosen) + 1;
            // do something
            if (airport.Check_For_Duplicate_Passenger(first_name,last_name,age)) {
                airport.selected_passenger = airport.Get_Duplicate_Passenger(first_name,last_name,age);

                airport.selected_flight->Add_Passenger_To_Flight(airport.selected_passenger,row_assigned,seat_assigned);

                airport.selected_flight->assigned_plane->Reserve_From_External_File(row_assigned-1, seat_assigned-1,
                                                                            airport.selected_flight->most_recently_added);
            }
            else {
                airport.selected_flight->Add_Passenger_To_Flight(first_name,last_name,age, row_assigned,
                                                            seat_assigned);
                airport.selected_flight->assigned_plane->Reserve_From_External_File((row_assigned - 1),
                                                                               (seat_assigned - 1),
                                                                               airport.selected_flight->most_recently_added);
                airport.all_passengers[airport.current_passenger_amount] = airport.selected_flight->most_recently_added; // add the most recently added passenger to the list of all passengers
                airport.current_passenger_amount++;
            }
            ui->stackedWidget->setCurrentIndex(0);
        }else {
            // do something else
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
}

void PlaneGUI::on_pushButton_2_clicked()
{
    FinalProject::UsefulFunctions useThis;
    std::string first_name = airport.selected_passenger->Get_First();
    std::string last_name = airport.selected_passenger->Get_Last();
    int age = airport.selected_passenger->Get_Age();
    int row_chosen = ui->row_chosen_2->text().toInt();
    std::string seat_chosen = ui->seat_chosen_2->text().toUtf8().constData();

    if (first_name == "" || last_name == "" || age == 0 || row_chosen == 0 || seat_chosen == "") {
        // Missing Stuff!
        cout << "Something SHitty!" << endl;
    }
    else {
        // Offer A reservation
        QMessageBox msgBox;
        msgBox.setWindowTitle("Reserve Seat");
        msgBox.setText("Are you sure you would like to reserve seat " + QString::number(row_chosen) + QString::fromStdString(seat_chosen));
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec() == QMessageBox::Yes){
            int row_assigned = row_chosen;
            int seat_assigned = useThis.getIntFromSeatLetter(seat_chosen) + 1;
            // do something
            if (airport.Check_For_Duplicate_Passenger(first_name,last_name,age)) {
                airport.selected_passenger = airport.Get_Duplicate_Passenger(first_name,last_name,age);

                airport.selected_flight->Add_Passenger_To_Flight(airport.selected_passenger,row_assigned,seat_assigned);

                airport.selected_flight->assigned_plane->Reserve_From_External_File(row_assigned-1, seat_assigned-1,
                                                                            airport.selected_flight->most_recently_added);
            }
            else {
                airport.selected_flight->Add_Passenger_To_Flight(first_name,last_name,age, row_assigned,
                                                            seat_assigned);
                airport.selected_flight->assigned_plane->Reserve_From_External_File((row_assigned - 1),
                                                                               (seat_assigned - 1),
                                                                               airport.selected_flight->most_recently_added);
                airport.all_passengers[airport.current_passenger_amount] = airport.selected_flight->most_recently_added; // add the most recently added passenger to the list of all passengers
                airport.current_passenger_amount++;
            }
            ui->stackedWidget->setCurrentIndex(0);
        }else {
            // do something else
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
}

#ifndef PLANEGUI_H
#define PLANEGUI_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>

namespace Ui {
class PlaneGUI;
}

class PlaneGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlaneGUI(QWidget *parent = 0);
    ~PlaneGUI();

private slots:

    void on_add_flight_button_clicked();

    void on_add_plane_button_clicked();

    void on_select_flight_button_clicked();

    void on_print_passengers_button_clicked();

    void on_print_flights_button_clicked();

    void on_print_planes_button_clicked();

    void on_Cancel_button_clicked();

    void on_Cancel_button_2_clicked();

    void on_Cancel_button_3_clicked();

    void on_Cancel_button_4_clicked();

    void on_Cancel_button_5_clicked();

    void on_Cancel_button_6_clicked();

    void on_Cancel_button_7_clicked();

    void on_Cancel_button_8_clicked();

    void on_Cancel_button_9_clicked();

    void on_Add_Planeinput_button_clicked();

    void on_Search_For_Flight_Button_clicked();

    void on_Select_New_Plane_button_clicked();

    void on_Search_Passenger_Num_button_clicked();

    void on_save_flight_button_clicked();

    void on_flights_list_currentRowChanged(int currentRow);

    void on_plane_list_widget_currentRowChanged(int currentRow);

    void on_return_to_main_clicked();

    void on_assign_plane_clicked();

    void on_select_plane_list_widget_currentRowChanged(int currentRow);

    void on_back_to_flight_options_clicked();

    void on_print_passengers_on_flight_clicked();

    void on_back_again_clicked();

    void on_print_flight_data_clicked();

    void on_add_passenger_to_flight_clicked();

    void on_usable_passenger_list_currentRowChanged(int currentRow);

    void on_next_from_passenger_clicked();

    void on_add_new_passenger_to_flight_clicked();

    void on_cancel_flight_clicked();

    void on_passenger_list_currentRowChanged(int currentRow);

    void on_ret_pass_clicked();

    void on_cancel_add_clicked();

    void on_add_to_flight_pass_clicked();

    void on_add_pass_to_flight_list_currentRowChanged(int currentRow);

    void on_back_back_clicked();

    void on_print_flights_pass_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PlaneGUI *ui;
};

#endif // PLANEGUI_H

#include "../include/mainwindow.h"

void MainWindow::set_insertion_panel(void)
{
    //-----------INSERTION PANEL CONFIG ---------------//
    insertion_panel = new QWidget();
    insertion_panel_layout = new QVBoxLayout();
    info_insert_panel = new QLabel();
    name_field = new QRoundedLineEdit("", "Enter the name of the food");
    number_field = new QRoundedLineEdit("", "Enter the number of unit of that food");
    location_field = new QRoundedLineEdit("", "Enter the location of the food");
    date_of_recording_field = new QRoundDateEdit();
    expiring_date_field = new QRoundDateEdit();
    insert_button = new QPushRoundButton("Insert");

    info_insert_panel -> setText("     INSERT NEW ELEMENTS HERE ");
    info_insert_panel -> setStyleSheet("font-weight: bold 2px; text-align: center; font-size: 16px;");
    info_insert_panel -> setAlignment(Qt::AlignCenter);
    info_insert_panel -> setFixedSize(QSize(400, 100));
    insertion_panel_layout -> addStretch();
    insertion_panel_layout -> addWidget(info_insert_panel, Qt::AlignCenter);
    insertion_panel_layout -> addSpacing(15);
    insertion_panel_layout -> addWidget(name_field);
    insertion_panel_layout -> addSpacing(25);
    insertion_panel_layout -> addWidget(number_field);
    insertion_panel_layout -> addSpacing(25);
    insertion_panel_layout -> addWidget(location_field);
    insertion_panel_layout -> addSpacing(25);
    insertion_panel_layout -> addWidget(date_of_recording_field);
    insertion_panel_layout -> addSpacing(25);
    insertion_panel_layout -> addWidget(expiring_date_field);
    insertion_panel_layout -> addSpacing(30);
    insertion_panel_layout -> addWidget(insert_button, Qt::AlignCenter);
    insertion_panel_layout -> addStretch();
    insertion_panel -> setLayout(insertion_panel_layout);
    //-----------INSERTION PANEL CONFIG ---------------//
}
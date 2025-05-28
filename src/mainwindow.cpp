/*
** MY_PROJECT, 2025
** mainwindow.cpp
** )
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), left_panel_content_in(true)
{
    this->setStyleSheet("background-color:solid  #D3D3D3 ;");

    centralWidget = new QWidget(this);
    stack = new QStackedLayout(centralWidget);
    insideapp = new QWidget();
    insideapp_layout = new QHBoxLayout();
    primary_page = new QWidget();
    primary_page_layout = new QVBoxLayout();

    resize(513, 689);
    setCentralWidget(centralWidget);
    set_btn_icon();
    set_login_form();
    set_custom_toolbar();
    set_left_panel();
    set_main_widget();
    set_insertion_panel();
    //----------Adding members to the centralwidget------------//
    insideapp_layout -> addWidget(left_panel, 3);
    insideapp_layout -> addWidget(mainwidget, 10);
    insideapp_layout -> addWidget(insertion_panel, 5);
    insideapp -> setLayout(insideapp_layout);
    primary_page_layout -> addWidget(toolbar);
    primary_page_layout -> addWidget(insideapp);
    primary_page -> setLayout(primary_page_layout);
    insideapp_layout -> setSpacing(0);
    primary_page_layout -> setContentsMargins(0, 0, 0, 0);
    primary_page -> setContentsMargins(0, 0, 0, 0);
    primary_page_layout -> setSpacing(0);
    //----------Adding members to the centralwidget------------//

    stack -> addWidget(loginpage);
    stack -> addWidget(primary_page);
    stack -> setCurrentWidget(loginpage);
    
    QObject::connect(menu, &QPushButton::clicked, this, &MainWindow::on_toggle_clicked);
    QObject::connect(login, &QPushButton::clicked, this, &MainWindow::on_login_clicked);
}

MainWindow::~MainWindow() {}

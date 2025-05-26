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
    : QMainWindow(parent), menubar_in(true)
{
    this->setStyleSheet("background-color:solid  #D3D3D3 ;");
    //-------------------QICONS---------------------//
    QIcon user("assets/user-solid.svg");
    QIcon locked("assets/lock-solid.svg");
    QIcon unlocked("assets/unlock-solid.svg");
    QIcon menu_icon("assets/bars-solid.svg");
    QIcon home_icon("assets/house-solid.svg");
    QIcon more_icon("assets/ellipsis-vertical-solid.svg");
    QIcon about_us_icon("assets/about_us.svg");
    //-------------------QICONS---------------------//


    QWidget *centralWidget = new QWidget(this);
    centralwid_layout = new QHBoxLayout();
    sidebar = new QWidget();
    menubar = new QWidget(centralWidget);
    menubar_layout = new QVBoxLayout();
    mainwidget = new QWidget();
    QVBoxLayout *sidebar_layout = new QVBoxLayout();
    stack = new QStackedLayout(centralWidget);
    insideapp = new QWidget();
    loginpage = new QWidget();

    //     -------LOGO---------    //
    logo = QPixmap("assets/logo.png");
    for_logo = new QLabel(loginpage);
    for_logo -> setPixmap(logo.scaled(350, 350, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    //     -------LOGO--------    //

    //---------LOGIN BRO -----------// :(
    QVBoxLayout *lgin_layout = new QVBoxLayout(loginpage);
    login = new QPushRoundButton("LOGIN", QIcon(), loginpage);
    usernameInput = new QRoundedLineEdit("" ,"Enter your username", user, loginpage);
    passwordInput = new QRoundedLineEdit("", "Enter your password", locked, loginpage);
    passwordInput -> setEchoMode(QLineEdit::Password);
    passwordInput -> setMaximumWidth(400);
    usernameInput -> setMaximumWidth(400);
    login -> setMaximumWidth(200);
    lgin_layout -> addStretch();
    lgin_layout -> addWidget(for_logo, 0, Qt::AlignCenter);
    lgin_layout -> addSpacing(50);
    lgin_layout -> addWidget(usernameInput);
    lgin_layout -> addSpacing(5);
    lgin_layout -> addWidget(passwordInput);
    lgin_layout -> addSpacing(10);
    lgin_layout -> addWidget(login, 0, Qt::AlignCenter);
    lgin_layout -> addStretch();
    lgin_layout -> setAlignment(Qt::AlignCenter);
    loginpage -> setLayout(lgin_layout);
    //---------LOGIN DONE ----------// :)

    resize(513, 689);

    //------------INSIDE APP---------------//
    setCentralWidget(centralWidget);
    //remove margins
    centralwid_layout -> setContentsMargins(0, 0, 0, 0);
    sidebar -> setContentsMargins(0, 0, 0, 0);
    menubar -> setContentsMargins(0, 0, 0, 0);

    sidebar -> setMaximumWidth(400);

    //--------MEMBERS OF THE SIDE BAR-----------//
    menu = new QPushRoundButton("", menu_icon);
    home = new QPushRoundButton(" Home", home_icon);
    my_tables = new QPushRoundButton("TABLES");
    about_us = new QPushRoundButton("About Us", about_us_icon, true);
    about_us -> setMaximumWidth(120);
    menubar_layout -> addWidget(home);
    menubar_layout -> addWidget(my_tables);
    menubar_layout -> addStretch();
    menubar_layout -> addWidget(about_us, Qt::AlignCenter);
    menubar -> setMaximumWidth(400);
    menubar -> setStyleSheet("background-color: white;");
    menubar -> setLayout(menubar_layout);
    //--------MEMBERS OF THE SIDE BAR-----------//

    //-----------INSERTION PANEL CONFIG ---------------//
    insertion_panel = new QWidget();
    insertion_panel_layout = new QVBoxLayout();
    info_insert_panel = new QLabel();
    info_insert_panel -> setText("     INSERT NEW ELEMENTS HERE ");
    info_insert_panel -> setStyleSheet("font-weight: bold 2px; text-align: center; font-size: 16px;");
    info_insert_panel -> setAlignment(Qt::AlignCenter);
    info_insert_panel -> setFixedSize(QSize(400, 100));
    name_field = new QRoundedLineEdit("", "Enter the name of the food");
    number_field = new QRoundedLineEdit("", "Enter the number of unit of that food");
    location_field = new QRoundedLineEdit("", "Enter the location of the food");
    date_of_recording_field = new QRoundDateEdit();
    expiring_date_field = new QRoundDateEdit();
    insert_button = new QPushRoundButton("Insert");

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

    //Adding members to the centralwidget
    sidebar_layout -> addWidget(menu);
    sidebar_layout -> addWidget(menubar);
    sidebar -> setLayout(sidebar_layout);
    centralwid_layout -> addWidget(sidebar, 3);
    centralwid_layout -> addWidget(mainwidget, 10);
    centralwid_layout -> addWidget(insertion_panel, 5);
    insideapp -> setLayout(centralwid_layout);
    //------------INSIDE APP---------------//

    stack -> addWidget(loginpage);
    stack -> addWidget(insideapp);
    stack -> setCurrentWidget(loginpage);
    
    QObject::connect(menu, &QPushButton::clicked, this, &MainWindow::on_toggle_clicked);
    QObject::connect(login, &QPushButton::clicked, this, &MainWindow::on_login_clicked);
}

void MainWindow::on_toggle_clicked(void)
{
    int startwidth = menubar -> width();
    int endingwidth = menubar_in ? 0 : 400;
    int menu_startwidth = sidebar -> width();
    int menu_endingwidth = menubar_in ? 50 : 400;
    QPropertyAnimation *animation = new QPropertyAnimation(menubar, "maximumWidth");
    QPropertyAnimation *animation_menu = new QPropertyAnimation(sidebar, "maximumWidth");

    animation -> setDuration(300);
    animation -> setStartValue(startwidth);
    animation -> setEndValue(endingwidth);
    animation -> setEasingCurve(QEasingCurve::InOutQuad);
    animation_menu -> setDuration(300);
    animation_menu -> setStartValue(menu_startwidth);
    animation_menu -> setEndValue(menu_endingwidth);
    animation_menu -> setEasingCurve(QEasingCurve::InOutQuad);
    animation -> start();
    animation_menu -> start();
    menubar_in = !menubar_in;
}

void MainWindow::on_login_clicked(void)
{
    // from_qlinedit_to_cstr(username, usernameInput);
    // from_qlinedit_to_cstr(passwd, passwordInput);
    // init_sql_con();
    // connect_sql();
    // do_sql_query();
    // get_query_res();
    // show_query_res();
    // mysql_free_result(result);
    // mysql_close(MainWindow::connect);
    showMaximized();
    stack -> setCurrentWidget(insideapp);
}

MainWindow::~MainWindow() {}

/*
** MY_PROJECT, 2025
** left_panel.cpp
** PROVISION_MNG
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/mainwindow.h"

void MainWindow::set_left_panel(void)
{
    left_panel = new QWidget();
    left_panel_layout = new QVBoxLayout();
    left_panel_content = new QWidget();
    left_panel_content_layout = new QVBoxLayout();
    menu = new QPushRoundButton("", menu_icon);
    home = new QPushRoundButton(" Home", home_icon);
    my_tables = new QPushRoundButton("TABLES");
    about_us = new QPushRoundButton("About Us", about_us_icon, true);

    about_us -> setMaximumWidth(120);
    left_panel_content_layout -> addWidget(home);
    left_panel_content_layout -> addWidget(my_tables);
    left_panel_content_layout -> addStretch();
    left_panel_content_layout -> addWidget(about_us, Qt::AlignCenter);
    left_panel_content -> setMaximumWidth(400);
    left_panel_content -> setStyleSheet("background-color: white;");
    left_panel_content -> setLayout(left_panel_content_layout);

    left_panel_layout -> addWidget(menu);
    left_panel_layout -> addWidget(left_panel_content);
    left_panel -> setLayout(left_panel_layout);
    left_panel -> setMaximumWidth(400);
    left_panel -> setContentsMargins(0, 0, 0, 0);
    left_panel_content -> setContentsMargins(0, 0, 0, 0);
}

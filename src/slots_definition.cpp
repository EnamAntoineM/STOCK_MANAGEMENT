/*
** MY_PROJECT, 2025
** slots_definition.cpp
** PROVISION_MNG
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/mainwindow.h"

void MainWindow::on_toggle_clicked(void)
{
    int startwidth = left_panel_content -> width();
    int endingwidth = left_panel_content_in ? 0 : 400;
    int menu_startwidth = left_panel -> width();
    int menu_endingwidth = left_panel_content_in ? 50 : 400;
    QPropertyAnimation *animation = new QPropertyAnimation(left_panel_content, "maximumWidth");
    QPropertyAnimation *animation_menu = new QPropertyAnimation(left_panel, "maximumWidth");

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
    left_panel_content_in = !left_panel_content_in;
}

void MainWindow::on_login_clicked(void)
{
    showMaximized();
    stack -> setCurrentWidget(primary_page);
}

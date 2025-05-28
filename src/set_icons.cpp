#include "../include/mainwindow.h"

void MainWindow::set_btn_icon(void)
{
//-------------------QICONS---------------------//
    user = QIcon("assets/user-solid.svg");
    locked = QIcon("assets/lock-solid.svg");
    unlocked = QIcon("assets/unlock-solid.svg");
    menu_icon = QIcon("assets/bars-solid.svg");
    home_icon = QIcon("assets/house-solid.svg");
    more_icon = QIcon("assets/ellipsis-vertical-solid.svg");
    about_us_icon = QIcon("assets/about_us.svg");
//-------------------QICONS---------------------//
}
/*
** MY_PROJECT, 2025
** toolbar.cpp
** PROVISION_MNG
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/mainwindow.h"

void MainWindow::set_custom_toolbar(void)
{
    //------------SETTING UP TOOLBAR-------------//
    toolbar = new QWidget();
    toolbar_layout = new QHBoxLayout();
    QPushButton *sizelay = new QPushButton();
    file_btn = new QPushRoundButton("File");
    export_btn = new QPushRoundButton("Export");
    logout_btn = new QPushRoundButton("Logout");

    //-------STYLESHEET-------//
    QString toolbar_reg_btn_stylesheet = (R"(
        #QPushRoundButton {
            color: black;
            font-size: 14px;
            font-weight: bold;
            border: 0px solid rgb(27, 27, 27) ;
            border-radius: 36px;
        }
        #QPushRoundButton:hover {
            background-color:rgb(228, 229, 230);
        }
        #QPushRoundButton:pressed {
            background-color:rgb(176, 180, 180);
        }
    )");
    QString toolbar_logout_btn_stylesheet = (R"(
        #QPushRoundButton {
            color: black;
            font-size: 14px;
            font-weight: bold;
            border: 0px solid rgb(27, 27, 27) ;
            border-radius: 36px;
        }
        #QPushRoundButton:hover {
            background-color:rgb(250, 184, 184);
        }
        #QPushRoundButton:pressed {
            background-color:rgb(243, 31, 31);
        }
    )");
    file_btn -> setStyleSheet(toolbar_reg_btn_stylesheet);
    export_btn -> setStyleSheet(toolbar_reg_btn_stylesheet);
    logout_btn -> setStyleSheet(toolbar_logout_btn_stylesheet);
    sizelay -> setStyleSheet("border: none;");
    toolbar->setStyleSheet("border: 0.5px solid rgb(171, 172, 173);");
    //-------STYLESHEET-------//

    //------SET_SIZE------//
    sizelay -> setFixedSize(QSize(0, 33));
    file_btn -> setFixedSize(QSize(70, 30));
    export_btn -> setFixedSize(QSize(70, 30));
    logout_btn -> setFixedSize(QSize(80, 30));
    toolbar -> setContentsMargins(0, 0, 0, 0);
    toolbar_layout -> setContentsMargins(0, 0, 0, 0);
    //------SET_SIZE------//

    toolbar_layout -> addWidget(sizelay);
    toolbar_layout -> addWidget(file_btn);
    toolbar_layout -> addWidget(export_btn);
    toolbar_layout -> addStretch();
    toolbar_layout -> addWidget(logout_btn, 1,Qt::AlignRight);
    toolbar_layout -> setSpacing(0);
    toolbar -> setLayout(toolbar_layout);
    //------------SETTING UP TOOLBAR-------------//
}

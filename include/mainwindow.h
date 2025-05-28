/*
** MY_PROJECT, 2025
** mainwindow.h
** PASSWD_MANAGER
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
    #include "my.h"
    #include "../custom_objects/header/round_button.h"
    #include "../custom_objects/header/round_qlineedit.h"
    #include "../custom_objects/header/round_date_edit.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPushRoundButton *menu;
    QPushRoundButton *home;
    QPushRoundButton *my_tables;
    QPushRoundButton *about_us;
    QVBoxLayout *menubar_layout;
    QVBoxLayout *primary;
    QWidget *primary_page;
    QWidget *toolbarr;
    QHBoxLayout *toolbar;
    QPushRoundButton *file_btn;
    QPushRoundButton *export_btn;
    QPushRoundButton *logout_btn;
    QHBoxLayout *centralwid_layout;
    QStackedLayout *home_tables;
    QWidget *home_page;
    QWidget *tables_page;
    QLabel *for_logo;
    QPixmap logo;
    QWidget *menubar;
    QWidget *mainwidget;
    QWidget *sidebar;
    //-----------INSERTION PANEL CONFIG ---------------//
    QWidget *insertion_panel;
    QVBoxLayout *insertion_panel_layout;
    QLabel *info_insert_panel;
    QRoundedLineEdit *name_field;
    QRoundedLineEdit *number_field;
    QRoundedLineEdit *location_field;
    QRoundDateEdit *date_of_recording_field;
    QRoundDateEdit *expiring_date_field;
    QPushRoundButton *insert_button;
    //-----------INSERTION PANEL CONFIG ---------------//

    QWidget *insideapp;
    QPushButton *login;
    bool menubar_in;

private:
    QWidget *loginpage;
    QStackedLayout *stack;
    QRoundedLineEdit *usernameInput;
    QRoundedLineEdit *passwordInput;
private slots:
    void on_toggle_clicked(void);
    void on_login_clicked(void);
};

#endif // MAINWINDOW_H
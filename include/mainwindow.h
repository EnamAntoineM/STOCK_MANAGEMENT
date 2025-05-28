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
    //-----------ICON------------//
    QIcon user;
    QIcon locked;
    QIcon unlocked;
    QIcon menu_icon;
    QIcon home_icon;
    QIcon more_icon;
    QIcon about_us_icon;
    //-----------ICON------------//

    //--------INSIDEAPP--------//
    QWidget *centralWidget;
    QWidget *primary_page;
    QVBoxLayout *primary_page_layout;
    QWidget *insideapp;
    QHBoxLayout *insideapp_layout;
    QStackedLayout *home_tables;
    QWidget *home_page;
    QWidget *tables_page;
    //--------INSIDEAPP--------//
    
    //---------TOOLBAR----------//
    QWidget *toolbar;
    QHBoxLayout *toolbar_layout;
    QPushRoundButton *file_btn;
    QPushRoundButton *export_btn;
    QPushRoundButton *logout_btn;
    //---------TOOLBAR----------//

    //----------MAIN_CENTER_WIDGET------------//
    QWidget *mainwidget;
    //----------MAIN_CENTER_WIDGET------------//

    //---------LEFT_PANEL--------//
    QPushRoundButton *menu;
    QPushRoundButton *home;
    QPushRoundButton *my_tables;
    QPushRoundButton *about_us;
    QWidget *left_panel_content;
    QWidget *left_panel;
    QVBoxLayout *left_panel_layout;
    QVBoxLayout *left_panel_content_layout;
    //---------LEFT_PANEL--------//

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

    //----------FUNCTIONS-------------//
    void set_btn_icon(void);
    void set_login_form(void);
    void set_custom_toolbar(void);
    void set_insertion_panel(void);
    void set_left_panel(void);
    void set_main_widget(void);
    //----------FUNCTIONS-------------//

private:
    //----------LOGIN_FORM------------//
    QPushButton *login;
    bool left_panel_content_in;
    QWidget *loginpage;
    QStackedLayout *stack;
    QLabel *for_logo;
    QPixmap logo;
    QRoundedLineEdit *usernameInput;
    QRoundedLineEdit *passwordInput;
    //----------LOGIN_FORM------------//
private slots:
    void on_toggle_clicked(void);
    void on_login_clicked(void);
};

#endif // MAINWINDOW_H
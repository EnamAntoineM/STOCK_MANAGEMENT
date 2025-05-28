#include "../include/mainwindow.h"

void MainWindow::set_login_form(void)
{
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
}
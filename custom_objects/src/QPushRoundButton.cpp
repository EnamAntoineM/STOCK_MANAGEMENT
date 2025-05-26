#include "../../include/my.h"
#include "../header/round_button.h"

QPushRoundButton::QPushRoundButton(const QString &text, const QIcon &icon, bool icon_right, QWidget *parent)
    : QPushButton(text, parent)
{
    setObjectName("QPushRoundButton");
    setCursor(Qt::PointingHandCursor);
    setFocusPolicy(Qt::NoFocus);
    QString button_style_1= (R"(
        #QPushRoundButton {
            background-color:rgb(254, 255, 255);
            color: black;
            border: 1px solid #D3D3D3 ;
            border-radius: 16px;
            padding: 8px 16px;
        }
        #QPushRoundButton:hover {
            background-color:rgb(190, 227, 252);
        }
        #QPushRoundButton:pressed {
            background-color:rgb(52, 128, 175);
        }
    )");
    QString button_style_2= (R"(
        #QPushRoundButton {
            text-align: left;
            background-color:rgb(254, 255, 255);
            color: black;
            border: 1px solid #D3D3D3 ;
            border-radius: 16px;
            padding: 8px 16px;
        }
        #QPushRoundButton:hover {
            background-color:rgb(190, 227, 252);
        }
        #QPushRoundButton:pressed {
            background-color:rgb(52, 128, 175);
        }
    )");
    setStyleSheet(button_style_1);
    if (!icon.isNull()) {
        setIcon(icon);
        setIconSize(QSize(16, 16));
        if (icon_right) {
            setLayoutDirection(Qt::RightToLeft);
            setStyleSheet(button_style_2);
        }
    }
}
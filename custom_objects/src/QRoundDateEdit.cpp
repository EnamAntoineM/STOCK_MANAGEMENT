/*
** MY_PROJECT, 2025
** QRoundDateEdit.cpp
** PROVISION_MNG
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../../include/my.h"
#include "../header/round_date_edit.h"

QRoundDateEdit::QRoundDateEdit(QWidget *parent)
    : QDateEdit(parent)
{
    setObjectName("QRoundDateEdit");
    setDisplayFormat("dd/mm/yyyy");
    setCalendarPopup(true);
    setDate(QDate::currentDate());
    setCursor(Qt::PointingHandCursor);
    setStyleSheet(R"(
        #QRoundDateEdit {
            background-color:rgb(252, 253, 253);
            color: black;
            border: 1px solid #D3D3D3 ;
            border-radius: 16px;
            padding: 8px 16px;
        }
    )");
}

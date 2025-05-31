/*
** MY_PROJECT, 2025
** QRoundedLineEdit.cpp
** PROVISION_MNG
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../../include/my.h"
#include "../header/round_qlineedit.h"

QRoundedLineEdit::QRoundedLineEdit(const QString &text, const QString &placeholderText, const QIcon &icon, QWidget *parent)
    : QLineEdit(text, parent)
{
    setObjectName("QRoundedLineEdit");
    if (!icon.isNull()) {
        addAction(icon, QLineEdit::LeadingPosition);
    }
    if (!placeholderText.isEmpty()) {
        setPlaceholderText(placeholderText);
    }
    setCursor(Qt::IBeamCursor);
    setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    setTextMargins(20, 0, 0, 0);
    setStyleSheet(R"(
        #QRoundedLineEdit {
            background-color:rgb(252, 253, 253);
            color: black;
            border: 1px solid #D3D3D3 ;
            border-radius: 16px;
            padding: 8px 16px;
        }
    )");
}

/*
** MY_PROJECT, 2025
** round_qlineedit.h
** PROVISION_MNG
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../../include/my.h"

class QRoundedLineEdit : public QLineEdit {
public:
    explicit QRoundedLineEdit(const QString &text = "", const QString &placeholderText = "", const QIcon &icon = QIcon(), QWidget *parent = nullptr);
};

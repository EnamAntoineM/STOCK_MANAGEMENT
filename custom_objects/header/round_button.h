/*
** MY_PROJECT, 2025
** round_button.h
** PROVISION_MNG
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../../include/my.h"

class QPushRoundButton : public QPushButton {
public:
    explicit QPushRoundButton(const QString &text = "", const QIcon &icon = QIcon(), bool icon_right = false , QWidget *parent = nullptr);
};

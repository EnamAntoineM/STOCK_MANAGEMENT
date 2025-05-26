#include "../../include/my.h"

class QPushRoundButton : public QPushButton {
public:
    explicit QPushRoundButton(const QString &text = "", const QIcon &icon = QIcon(), bool icon_right = false , QWidget *parent = nullptr);
};
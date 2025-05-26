#include "../../include/my.h"

class QRoundedLineEdit : public QLineEdit {
public:
    explicit QRoundedLineEdit(const QString &text = "", const QString &placeholderText = "", const QIcon &icon = QIcon(), QWidget *parent = nullptr);
};
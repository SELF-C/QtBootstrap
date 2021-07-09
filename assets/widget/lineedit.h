#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>
#include "stylesheet.h"

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit LineEdit(QWidget *parent = nullptr) : QLineEdit(parent)
    {
        auto qss = StyleSheet::loadStyleSheet(StyleSheet::Qss::LineEdit);
        this->setStyleSheet(qss);

        this->setObjectName("form-control");
    }


private:

};

#endif // LINEEDIT_H

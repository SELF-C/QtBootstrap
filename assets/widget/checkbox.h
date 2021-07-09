#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QCheckBox>
#include "stylesheet.h"

class CheckBox : public QCheckBox
{
    Q_OBJECT
public:
    enum Style{
        Check,
        Switch,
    };

    explicit CheckBox(int style=Style::Check, QWidget *parent = nullptr) : QCheckBox(parent)
    {
        auto qss = StyleSheet::loadStyleSheet(StyleSheet::Qss::CheckBox);
        this->setStyleSheet(qss);

        switch (style) {
        case Style::Check:
            this->setObjectName("form-check");
            break;
        case Style::Switch:
            this->setObjectName("form-switch");
            break;
        default:
            this->setObjectName("form-check");
            break;
        }
    }

private:

};

#endif // CHECKBOX_H

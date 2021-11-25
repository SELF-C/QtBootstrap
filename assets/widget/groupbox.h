#ifndef GROUPBOX_H
#define GROUPBOX_H

#include <QGroupBox>
#include "stylesheet.h"

class GroupBox : public QGroupBox
{
    Q_OBJECT
public:
    explicit GroupBox(QWidget *parent = nullptr) : QGroupBox(parent)
    {
        auto qss = StyleSheet::loadStyleSheet(StyleSheet::Qss::GroupBox);
        this->setStyleSheet(qss);
    }
};
#endif // GROUPBOX_H

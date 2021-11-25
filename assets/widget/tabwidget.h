#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include "stylesheet.h"

class TabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit TabWidget(QWidget *parent = nullptr) : QTabWidget(parent)
    {
        auto qss = StyleSheet::loadStyleSheet(StyleSheet::Qss::Tab);
        this->setStyleSheet(qss);

        auto font = this->font();
        font.setWeight(QFont::Bold);
        this->setFont(font);
    }
};

#endif // TABWIDGET_H

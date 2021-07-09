#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include "stylesheet.h"

class ComboBox : public QWidget
{
    Q_OBJECT
public:
    explicit ComboBox(QWidget *parent = nullptr) : QWidget(parent)
    {
        auto qss = StyleSheet::loadStyleSheet(StyleSheet::Qss::ComboBox);
        this->setStyleSheet(qss);

        m_combobox = new QComboBox(this);
        m_combobox->setObjectName("form-select");

        m_button = new QPushButton("Option", this);
        m_button->setObjectName("form-text");
        m_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

        this->setFixedHeight(m_button->height() +5);
        m_combobox->setFixedHeight(m_button->height() +5);

        auto* layout = new QHBoxLayout(this);
        this->setLayout(layout);

        layout->addWidget(m_button);
        layout->addWidget(m_combobox);

        layout->setMargin(0);
        layout->setSpacing(0);
    }

    QComboBox* combobox(){ return m_combobox; }
    QPushButton* pushbutton(){ return m_button; }

private:
    QComboBox* m_combobox;
    QPushButton* m_button;
};

#endif // COMBOBOX_H

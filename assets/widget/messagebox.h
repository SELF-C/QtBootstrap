#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QString>

#include "stylesheet.h"

class MessageBox : public QWidget
{
    Q_OBJECT
public:
    explicit MessageBox(QWidget *parent = nullptr, const QString &title = "", const QString &text = "") : QWidget(parent)
    {
        auto qss = StyleSheet::loadStyleSheet(StyleSheet::Qss::MessageBox);
        this->setStyleSheet(qss);

        this->setObjectName("popup-box");
        this->resize(QSize(420, 150));
        this->setWindowFlag(Qt::Popup);

        auto* layout = new QGridLayout(this);
        this->setLayout(layout);
        layout->setMargin(0);

        /* title bar */
        QFont font = this->font();
        font.setPointSize(font.pointSize() + 3);
        font.setBold(true);

        m_title = new QLabel(title);
        m_title->setObjectName("popup-title");
        m_title->setFont(font);
        m_title->setMargin(13);

        auto* titlebar = new QHBoxLayout();
        titlebar->addWidget(m_title);

        /* message */
        m_text = new QLabel(text);
        m_text->setObjectName("popup-text");
        m_text->setContentsMargins(10,10,10,10);
        m_text->setFixedHeight(70);

        auto* contents = new QHBoxLayout();
        contents->addWidget(m_text);
        contents->setMargin(0);

        /* select button */
        m_accept = new QPushButton("Accept", this);
        m_accept->setObjectName("popup-accept-btn");
        m_accept->setFixedHeight(50);

        m_cancel = new QPushButton("Cancel", this);
        m_cancel->setObjectName("popup-cancel-btn");
        m_cancel->setFixedHeight(50);

        auto* choice = new QHBoxLayout();
        choice->addWidget(m_accept);
        choice->addWidget(m_cancel);
        choice->setMargin(0);
        choice->setSpacing(0);

        /* window */
        layout->addLayout(titlebar, 0, 0);
        layout->addLayout(contents, 1, 0);
        layout->addLayout(choice, 2, 0);
    }

    QLabel* title(){ return m_title; }
    QLabel* text(){ return m_text; }
    QPushButton* accept(){ return m_accept; }
    QPushButton* cancel(){ return m_cancel; }
signals:

protected:
    void showEvent(QShowEvent *event) override
    {
        if (this->parentWidget() != nullptr)
        {
            int x = (this->parentWidget()->geometry().x() + this->parentWidget()->width() / 2) - (this->width() / 2);
            int y = (this->parentWidget()->geometry().y() + this->parentWidget()->height() / 2) - (this->height() / 2);
            this->move(x, y);
        }
    }

public slots:

private:
    QLabel* m_title;
    QLabel* m_text;
    QPushButton* m_accept;
    QPushButton* m_cancel;
};

#endif // MESSAGEBOX_H

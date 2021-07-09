#ifndef MODAL_H
#define MODAL_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "stylesheet.h"
#include "button.h"

class Modal : public QWidget
{
    Q_OBJECT
public:
    explicit Modal(const QString &title="", const QString &body="", QWidget *parent = nullptr) : QWidget(parent)
    {
        auto qss = StyleSheet::loadStyleSheet(StyleSheet::Qss::Modal);
        this->setStyleSheet(qss);

        this->setWindowFlags(Qt::Tool | Qt::CustomizeWindowHint);
        this->setObjectName("modal");
        this->resize(QSize(620, 258));

        auto* vlayout = new QVBoxLayout(this);
        this->setLayout(vlayout);


        /* Header */
        m_title = new QLabel(title.isEmpty() ? "Modal title" : title);
        m_title->setObjectName("modal-title");
        m_title->setMargin(0);

        m_close = new CloseButton(this);
        m_close->setObjectName("close-button");

        auto* header= new QHBoxLayout();
        header->addWidget(m_title);
        header->addWidget(m_close);
        header->setContentsMargins(15, 20, 15, 20);

        /* Body */
        m_body = new QLabel(body.isEmpty() ? "Modal body test goes here." : body);
        m_body->setObjectName("modal-body");
        m_body->setMargin(15);
        m_body->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        /* Footer */
        m_cancel = new Button("Cancel", Button::Secondary);
        connect(m_cancel, &Button::clicked, this, &QWidget::close);

        m_accept = new Button("Accept", Button::Primary);


        auto* footer = new QHBoxLayout();
        footer->addStretch();
        footer->addWidget(m_cancel);
        footer->addWidget(m_accept);
        footer->setContentsMargins(10, 10, 20, 20);

        vlayout->addLayout(header);
        vlayout->addWidget(m_body);
        vlayout->addLayout(footer);
        vlayout->setMargin(0);
    }

    QLabel* title(){ return m_title; }
    QLabel* body(){ return m_body; }
    CloseButton* close(){ return m_close; }
    Button* accept(){ return m_accept; }
    Button* cancel(){ return m_cancel; }


private:
    QLabel* m_title;
    QLabel* m_body;
    CloseButton* m_close;
    Button* m_accept;
    Button* m_cancel;
};

#endif // MODAL_H

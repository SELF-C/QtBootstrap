#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include "stylesheet.h"

class Button : public QPushButton
{
    Q_OBJECT
public:
    enum Style
    {
        Primary,
        Secondary,
        Success,
        Danger,
        Warning,
        Info,
        Light,
        Dark,
        Link
    };

    explicit Button(const QString &text, int style=Button::Primary, bool outlein=false, QWidget *parent = nullptr) : QPushButton(text, parent)
    {
        m_outline = outlein;

        auto qss = StyleSheet::loadStyleSheet(StyleSheet::Qss::Button);
        this->setStyleSheet(qss);

        this->setObjectName(className(style));
        this->setGeometry(this->x(), this->y(), this->width() * 2, this->height() + 10);
        this->setMinimumHeight(40);
        this->setMaximumHeight(40);
    }

    void setStyle(int style)
    {
        this->setObjectName(className(style));
    }



private:
    bool m_outline;

    QString className(int style)
    {
        QString str;
        QString outline = m_outline ? "outline-" : "";
        switch (style) {
        case Button::Primary:
            str = "btn-" + outline + "primary";
            break;
        case Button::Secondary:
            str = "btn-" + outline + "secondary";
            break;
        case Button::Success:
            str = "btn-" + outline + "success";
            break;
        case Button::Danger:
            str = "btn-" + outline + "danger";
            break;
        case Button::Warning:
            str = "btn-" + outline + "warning";
            break;
        case Button::Info:
            str = "btn-" + outline + "info";
            break;
        case Button::Light:
            str = "btn-" + outline + "light";
            break;
        case Button::Dark:
            str = "btn-" + outline + "dark";
            break;
        case Button::Link:
            str = "btn-" + outline + "link";
            break;
        default:
            str = "";
            break;
        }

        return str;
    }

};

class CloseButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CloseButton(QWidget *parent = nullptr) : QPushButton(parent)
    {
        auto qss = StyleSheet::loadStyleSheet(StyleSheet::Qss::Button);
        this->setStyleSheet(qss);
        this->setFixedSize(36, 36);

        connect(this, &QPushButton::clicked, parent, &QWidget::close);
    }

private:
};

#endif // BUTTON_H

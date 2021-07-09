#ifndef INPUTSPINNER_H
#define INPUTSPINNER_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QHBoxLayout>

#include "stylesheet.h"
class InputSpinner : public QWidget
{
    Q_OBJECT
public:
    explicit InputSpinner(QWidget *parent = nullptr) : QWidget(parent)
    {
        auto qss = StyleSheet::loadStyleSheet(StyleSheet::Qss::InputSinner);
        this->setStyleSheet(qss);

        auto* layout = new QHBoxLayout(this);
        this->setLayout(layout);

        /* Spinboxの初期化 */
        m_spinbox = new QDoubleSpinBox(this);
        m_spinbox->setObjectName("input-spinner");
        m_spinbox->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);    // up,downボタンを非表示
        m_spinbox->setAlignment(Qt::AlignRight);                            // 右寄せ
        m_spinbox->setAccelerated(true);                                    // ステップの頻度を加速

        /* 値減少ボタンの初期化 */
        m_downArrow = new QPushButton("-", this);
        m_downArrow->setObjectName("down-arrow");
        m_downArrow->setAutoRepeat(true);   // ボタンの押しっぱなしを許可
        m_downArrow->setFixedSize(22, 22);
        connect(m_downArrow, &QPushButton::clicked, m_spinbox, &QSpinBox::stepDown);

        /* 値増加ボタンの初期化 */
        m_upArrow = new QPushButton("+", this);
        m_upArrow->setObjectName("up-arrow");
        m_upArrow->setAutoRepeat(true);     // ボタンの押しっぱなしを許可
        m_upArrow->setFixedSize(22, 22);
        connect(m_upArrow, &QPushButton::clicked, m_spinbox, &QSpinBox::stepUp);

        layout->addWidget(m_downArrow);
        layout->addWidget(m_spinbox);
        layout->addWidget(m_upArrow);

        /* Widget間の隙間を詰める */
        layout->setMargin(0);
        layout->setSpacing(0);
    }

    QDoubleSpinBox* spinbox(){ return m_spinbox; }
    QPushButton* downArrow(){ return m_downArrow; }
    QPushButton* upArrow(){ return m_upArrow; }

private:
    QDoubleSpinBox* m_spinbox;
    QPushButton* m_downArrow;
    QPushButton* m_upArrow;
};

#endif // INPUTSPINNER_H

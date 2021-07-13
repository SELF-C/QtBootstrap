#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "assets/widget/messagebox.h"
#include "assets/widget/button.h"
#include "assets/widget/inputspinner.h"
#include "assets/widget/checkbox.h"
#include "assets/widget/lineedit.h"
#include "assets/widget/modal.h"
#include "assets/widget/combobox.h"
#include <QDebug>
#include <QScrollArea>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    /* add widgets */
    QScrollArea * scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    setCentralWidget(scrollArea);

    auto* widget = new QWidget(scrollArea);
    scrollArea->setWidget(widget);

    widget->setObjectName("widget");
    widget->setStyleSheet("QWidget#widget{ background-color: #ffffff; }");

    auto* vlayout = new QVBoxLayout(widget);
    widget->setLayout(vlayout);

    vlayout->addLayout(makeButton());
    vlayout->addLayout(makeOutLineButton());
    vlayout->addLayout(makeCheacks());
    vlayout->addLayout(makeForm());
    vlayout->addLayout(makeForm2());
    vlayout->addLayout(makeDialog());



}

MainWindow::~MainWindow()
{
    delete ui;
}

QHBoxLayout *MainWindow::makeButton()
{
    auto* layout = new QHBoxLayout();

    layout->addWidget(new Button("Primary", Button::Primary));
    layout->addWidget(new Button("Secondary", Button::Secondary));
    layout->addWidget(new Button("Success", Button::Success));
    layout->addWidget(new Button("Danger", Button::Danger));
    layout->addWidget(new Button("Warning", Button::Warning));
    layout->addWidget(new Button("Info", Button::Info));
    layout->addWidget(new Button("Light", Button::Light));
    layout->addWidget(new Button("Dark", Button::Dark));
    layout->addWidget(new Button("Link", Button::Link));

    return layout;
}

QHBoxLayout *MainWindow::makeOutLineButton()
{
    auto* layout = new QHBoxLayout();

    layout->addWidget(new Button("Primary", Button::Primary, true));
    layout->addWidget(new Button("Secondary", Button::Secondary, true));
    layout->addWidget(new Button("Success", Button::Success, true));
    layout->addWidget(new Button("Danger", Button::Danger, true));
    layout->addWidget(new Button("Warning", Button::Warning, true));
    layout->addWidget(new Button("Info", Button::Info, true));
    layout->addWidget(new Button("Light", Button::Light, true));
    layout->addWidget(new Button("Dark", Button::Dark, true));

    return layout;
}

QHBoxLayout *MainWindow::makeForm()
{
    auto* layout = new QHBoxLayout();

    auto* inputspin = new InputSpinner(this);
    inputspin->setEnabled(false);
    layout->addWidget(inputspin);
    layout->addWidget(new LineEdit(this));

    return layout;
}

QHBoxLayout *MainWindow::makeForm2()
{
    auto* layout = new QHBoxLayout();

    auto* cmb = new ComboBox(this);
    cmb->combobox()->addItem(u8"アイテム1");
    cmb->combobox()->addItem(u8"アイテム2");

    layout->addWidget(cmb);

    return layout;
}

QHBoxLayout *MainWindow::makeCheacks()
{
    auto* layout = new QHBoxLayout();

    /* check */
    layout->addWidget(new CheckBox(CheckBox::Style::Check, this));

    auto* checkChecked = new CheckBox(CheckBox::Style::Check, this);
    checkChecked->setChecked(true);
    layout->addWidget(checkChecked);

    auto* checkDefDisabled = new CheckBox(CheckBox::Style::Check, this);
    checkDefDisabled->setEnabled(false);
    layout->addWidget(checkDefDisabled);

    auto* checkCheckedDisabled = new CheckBox(CheckBox::Style::Check, this);
    checkCheckedDisabled->setChecked(true);
    checkCheckedDisabled->setEnabled(false);
    layout->addWidget(checkCheckedDisabled);

    /* switch */
    layout->addWidget(new CheckBox(CheckBox::Style::Switch, this));

    auto* switchChecked = new CheckBox(CheckBox::Style::Switch, this);
    switchChecked->setChecked(true);
    layout->addWidget(switchChecked);

    auto* switchDefDisabled = new CheckBox(CheckBox::Style::Switch, this);
    switchDefDisabled->setEnabled(false);
    layout->addWidget(switchDefDisabled);

    auto* switchCheckedDisabled = new CheckBox(CheckBox::Style::Switch, this);
    switchCheckedDisabled->setChecked(true);
    switchCheckedDisabled->setEnabled(false);
    layout->addWidget(switchCheckedDisabled);

    return layout;
}

QHBoxLayout *MainWindow::makeDialog()
{
    auto* layout = new QHBoxLayout();

    auto* modalBtn = new Button("Launch demo modal", Button::Primary);
    layout->addWidget(modalBtn);

    auto* modal = new Modal();
    connect(modalBtn, &Button::clicked, modal, &Modal::show);

    auto* popupBtn = new Button("Launch demo popup", Button::Primary);
    layout->addWidget(popupBtn);

    auto* popup = new MessageBox(this, "Trabel Info", "Do you want to receive notifications about you trip?");
    connect(popup->accept(), &QPushButton::clicked, popup, &QWidget::close);
    connect(popup->cancel(), &QPushButton::clicked, popup, &QWidget::close);
    connect(popupBtn, &Button::clicked, popup, &QWidget::show);

    return layout;
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void loadStyleSheet(QWidget* parent);
    QWidget* createDialog();

    QHBoxLayout* makeButton();
    QHBoxLayout* makeOutLineButton();
    QHBoxLayout* makeForm();
    QHBoxLayout* makeForm2();
    QHBoxLayout* makeCheacks();
    QHBoxLayout* makeDialog();
};
#endif // MAINWINDOW_H

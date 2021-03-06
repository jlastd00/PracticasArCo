#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <alu.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Alu *alu;

private slots:
    void on_buttonCalcular_clicked();

};

#endif // MAINWINDOW_H

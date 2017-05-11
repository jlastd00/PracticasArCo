#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <alu.h>
#include <QString>
#include <QMessageBox>
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    alu = new Alu();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete alu;
}

void MainWindow::on_buttonCalcular_clicked() {

    QString op1 = ui->valueOp1dec->text();
    QString op2 = ui->valueOp2dec->text();
    QString operation = ui->selectOperacion->currentText();

    if (op1 == "" || op2 == "") {
        QMessageBox m;
        m.setText("Debes introducir los dos operandos en formato decimal");
        m.exec();
    }
    else if (operation == "- Operacion -") {
        QMessageBox m;
        m.setText("Debes elegir una operacón a realizar");
        m.exec();
    }
    else {

        alu->addNumber1(op1.toFloat());
        alu->addNumber2(op2.toFloat());

        ui->valueOp1BCF->setText(alu->getBinaryNumber1());
        ui->valueOp2BCF->setText(alu->getBinaryNumber2());

        ui->valueOp1hex->setText(alu->getHexNumber1());
        ui->valueOp2hex->setText(alu->getHexNumber2());

        if (operation == "Suma") {

            //NumberBinary result = alu->sum();

            ui->valueResultDec->setText("Resultado OP1 + OP2 en decimal");
            ui->valueResultBCF->setText("Resultado OP1 + OP2 en código BCF");
            ui->valueResultHex->setText("Resultado OP1 + OP2 en hexdecimal");
        }
        else if (operation == "Producto") {

            //NumberBinary result = alu->multiply();

            ui->valueResultDec->setText("Resultado OP1 x OP2 en decimal");
            ui->valueResultBCF->setText("Resultado OP1 x OP2 en código BCF");
            ui->valueResultHex->setText("Resultado OP1 x OP2 en hexdecimal");
        }
        else {

            //NumberBinary result = alu->division();

            ui->valueResultDec->setText("Resultado OP1 / OP2 en decimal");
            ui->valueResultBCF->setText("Resultado OP1 / OP2 en código BCF");
            ui->valueResultHex->setText("Resultado OP1 / OP2 en hexdecimal");
        }

    }
}




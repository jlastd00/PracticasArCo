#include "mainwindow.h"
#include <QApplication>
#include <numberbinary.h>
#include <iostream>
#include <stdio.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

/*
    NumberBinary *nb = new NumberBinary(15.15);

    char* numero;
    char* numerob;

    numerob = nb->getNumberBinary();
    numero = nb->getNumberHex();
    float p = nb->getNumberDec();

    for(int i=0; i<10; i++){

        printf("%c", numero[i]);

    }
    printf("\n");
    for(int i=0; i<32; i++){

        printf("%d", numerob[i]);

    }

    printf("\n");
    printf("%f\n", p);*/
}

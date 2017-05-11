#include "alu.h"
#include <iostream>
#include <QString>


Alu::Alu()
{



}

Alu::~Alu()
{

}

void Alu::addNumber1(float newNumber){

    number1 = new NumberBinary(newNumber);

}

void Alu::addNumber2(float newNumber){

    number2 = new NumberBinary(newNumber);

}

QString Alu::getBinaryNumber1(){

    QString solution;
    char* binary = new char[32];

    binary = number1->getNumberBinary();

    for(int i=0; i<32; i++){

        if (binary[i] == 1){

            solution.append("1");

        }

        else {

            solution.append("0");

        }

    }

    return solution;

}

QString Alu::getBinaryNumber2(){

    QString solution;
    char* binary = new char[32];

    binary = number2->getNumberBinary();

    for(int i=0; i<32; i++){

        if (binary[i] == 1){

            solution.append("1");

        }

        else {

            solution.append("0");

        }

    }

    return solution;

}

QString Alu::getHexNumber1(){

    QString solution;
    char* hex = new char[10];

    hex = number1->getNumberHex();

    for(int i=0; i<10; i++){

        solution.append(hex[i]);

    }

    return solution;

}

QString Alu::getHexNumber2(){

    QString solution;
    char* hex = new char[10];

    hex = number2->getNumberHex();

    for(int i=0; i<10; i++){

        solution.append(hex[i]);

    }

    return solution;

}

void Alu::sum(){



}

void Alu::multiply(){



}

void Alu::division(){



}


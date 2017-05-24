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

    char sigOp1 = number1->getSign();
    char sigOp2 = number2->getSign();
    char expOp1[8] = number1->getExponent();
    char expOp2[8] = number2->getExponent();
    char mantOp1[23] = number1->getMantisa();
    char mantOp2[23] = number2->getMantisa();

    char carry = '0';
    char resultSig, resultExp[8], resultMant[23];

    /*** Cálculo del signo ***/

    if (sigOp1 == sigOp2) {
        resultSig = '0';
    }
    else {
        resultSig = '1';
    }

    /*** Cálculo del exponente ***/

    char resultExpTemp[8];

    for (int i = 7; i >= 0; i++) {
        /* Los 2 digitos son distintos */
        if (expOp1[i] != expOp2[i]) {
            if (carry == '1') {
                resultExpTemp[i] == '0';
                carry = '1';
            }
            else {
                resultExpTemp[i] = '1';
                carry = '0';
            }
        }
        /* Los 2 digitos son iguales */
        else {
            /* Los 2 digitos son unos */
            if (expOp1[i] == '1' && expOp2[i] == '1') {
                if (carry == '1') {
                    resultExpTemp[i] = '1';
                    carry = '1';
                }
                else {
                    resultExpTemp[i] = '0';
                    carry = '1';
                }
            }
            /* Los 2 digitos son ceros */
            else {
                if (carry = '1') {
                    resultExpTemp[i] = '1';
                }
                else {
                    resultExpTemp[i] = '0';
                }
                carry = '0';
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        resultExp[i] = resultExpTemp[i];
    }

    /*** Cálculo de la mantisa ***/

    char resultMantTemp[23];



}

void Alu::division(){

    char sigOp1 = number1->getSign();
    char sigOp2 = number2->getSign();
    char expOp1[8] = number1->getExponent();
    char expOp2[8] = number2->getExponent();
    char mantOp1[23] = number1->getMantisa();
    char mantOp2[23] = number2->getMantisa();

    char resultSig, resultExp[8], resultMant[23];

    /*** Cálculo del signo ***/

    if (sigOp1 == sigOp2) {
        resultSig = '0';
    }
    else {
        resultSig = '1';
    }

    /*** Cálculo del exponente ***/

    /*** Cálculo de la mantisa ***/

}



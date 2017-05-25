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

NumberBinary* Alu::multiply() {

    char sigOp1 = number1->getSign();
    char sigOp2 = number2->getSign();
    char *expOp1 = number1->getExponent();
    char *expOp2 = number2->getExponent();
    char *mantOp1 = number1->getMantisa();
    char *mantOp2 = number2->getMantisa();

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

    for (int i = 7; i >= 0; i--) {
        /* Los 2 digitos son distintos */
        if (*(expOp1+i) != *(expOp2+i)) {
            if (carry == '1') {
                resultExpTemp[i] = '0';
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
            if (*(expOp1+i) == '1' && *(expOp2+i) == '1') {
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
                if (carry == '1') {
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

    char A[23], B[23], c = '0', P[23];

    for (int i = 0; i < 23; i++) {
        P[i] = '0';
    }

    for (int i = 0; i < 23; i++) {
        A[i] = *(mantOp1+i);
        B[i] = *(mantOp2+i);
    }

    for (int i = 0; i < 23; i++) {

        if (A[22] == '1') {
            // P = P + B
            for (int i = 22; i >= 0; i--) {

                if (P[i] != B[i]) {
                    if (c == '1') {
                        P[i] = '0';
                        c = '1';
                    }
                    else {
                        P[i] = '1';
                        c = '0';
                    }
                }
                else {
                    if (P[i] == '1' && B[i] == '1') {
                        if (c == '1') {
                            P[i] = '1';
                            c = '1';
                        }
                        else {
                            P[i] = '0';
                            c = '1';
                        }
                    }
                    else {
                        if (c == '1') {
                            P[i] = '1';
                        }
                        else {
                            P[i] = '0';
                        }
                        c = '0';
                    }
                }
            }
        }

        char newP[23], newA[23], newc;

        newc = '0';
        newP[0] = c;
        newA[0] = P[22];

        for (int j = 1; j < 23; j++) {
            newP[j] = P[j-1];
            newA[j] = A[j-1];
        }

        for (int j = 0; j < 23; j++) {
            P[j] = newP[j];
            A[j] = newA[j];
        }

        c = newc;

    }

    if (P[22] == '0') {
        for (int i = 1; i < 23; i++) {
            P[i-1] = P[i];
        }
        P[22] = A[0];
        for (int i = 1; i < 23; i++) {
            A[i-1] = A[i];
        }
        A[22] = '0';
    }
    else {
        char opExp[8], opUno[8], carry = '0', res[8];

        for (int i = 0; i < 8; i++) {
            opUno[i] = '0';
        }
        opUno[7] = '1';

        for (int i = 7; i >= 0; i--) {

            if (opExp[i] != opUno[i]) {
                if (carry == '1') {
                    res[i] = '0';
                    carry = '1';
                }
                else {
                    res[i] = '1';
                    carry = '0';
                }
            }
            else {
                if (opExp[i] == '1' && opUno[i] == '1') {
                    if (carry == '1') {
                        res[i] = '1';
                        carry = '1';
                    }
                    else {
                        res[i] = '0';
                        carry = '1';
                    }
                }
                else {
                    if (carry == '1') {
                        res[i] = '1';
                    }
                    else {
                        res[i] = '0';
                    }
                    carry = '0';
                }
            }
        }

        for (int i = 0; i < 8; i++) {
            resultExp[i] = res[i];
        }

    }

    // bit de redondeo
    char red = A[22];

    // bit sticky
    char sticky = A[0] | A[1] | A[2] | A[3] | A[4] | A[5] | A[6] | A[7] | A[8] | A[9] | A[10] |
            A[11] | A[12] | A[13] | A[14] | A[15] | A[16] | A[17] | A[18] | A[19] | A[20] | A[21] | A[22];

    if ((red == '1' && sticky == '1') || (red == '1' && sticky == '0' && P[0] == '1')) {
        // P = P + 1
        char opUno[23], carry = '0';

        for (int i = 0; i < 23; i++) {
            opUno[i] = '0';
        }
        opUno[22] = '1';

        for (int i = 22; i >= 0; i--) {

            if (P[i] != opUno[i]) {
                if (carry == '1') {
                    P[i] = '0';
                    carry = '1';
                }
                else {
                    P[i] = '1';
                    carry = '0';
                }
            }
            else {
                if (P[i] == '1' && opUno[i] == '1') {
                    if (carry == '1') {
                        P[i] = '1';
                        carry = '1';
                    }
                    else {
                        P[i] = '0';
                        carry = '1';
                    }
                }
                else {
                    if (carry == '1') {
                        P[i] = '1';
                    }
                    else {
                        P[i] = '0';
                    }
                    carry = '0';
                }
            }
        }

    }

    for (int i = 0; i < 23; i++) {
        resultMant[i] = P[i];
    }

    NumberBinary *result = new NumberBinary();

    result->setSign(resultSig);
    result->setExponent(resultExp);
    result->setMantisa(resultMant);

    return result;
}

void Alu::division(){
/*
    char sigOp1 = number1->getSign();
    char sigOp2 = number2->getSign();
    char expOp1[8] = number1->getExponent();
    char expOp2[8] = number2->getExponent();
    char mantOp1[23] = number1->getMantisa();
    char mantOp2[23] = number2->getMantisa();

    char resultSig, resultExp[8], resultMant[23];

    if (sigOp1 == sigOp2) {
        resultSig = '0';
    }
    else {
        resultSig = '1';
    }

*/
}



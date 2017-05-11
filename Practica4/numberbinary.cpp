#include "numberbinary.h"
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>

NumberBinary::NumberBinary()
{

}

NumberBinary::NumberBinary(float newNumber)
{

    setNumber(newNumber);
    setMantisa();
    setExponent();

}

NumberBinary::~NumberBinary()
{

}

void NumberBinary::setNumber(float newNumber){

    char newSign = 0;

    if(newNumber>=0){

        setSign(newSign);
        numberDecimal = newNumber;

    }

    else {
        newSign = 1;
        setSign(1);
        numberDecimal = newNumber*(-1);

    }

}

/**
 * Devuelve el array de bits organizado
 *
 * @brief NumberBinary::getNumberBinary
 * @return
 */
char* NumberBinary::getNumberBinary(){

    char *binary = new char[32];

    binary[0] = sign;

    for(int i=0; i<8;i++){

        binary[i+1] = exponent[i];

    }

    for(int i=0; i<23; i++){

        binary[i+9] = mantisa[i];

    }

    return binary;

}

/**
 * convierte el numero binaro almacenado en decimal
 *
 * @brief NumberBinary::getNumberDec
 * @return
 */
float NumberBinary::getNumberDec(){

    float toDecimal = 0;
    double sizeInteger = normalizeMantisa-1;
    char* newMantisa;

    /**
     * pasamos la parte entera a decimal
     */

   toDecimal = toDecimal + bitRemoveMantisa*pow(2.0, (sizeInteger+1));

    for(int i=0; i<=sizeInteger;i++){

        if(mantisa[i]==1){

            toDecimal = toDecimal + (pow(2.0, ((sizeInteger-i))));

        }

    }

    /**
     * pasamos la parte fraccionaria a decimal
     */
    for(int i=sizeInteger+1; i<23; i++){

        if(mantisa[i]==1){

            toDecimal = toDecimal + (1/pow(2.0, ((i-sizeInteger))));

        }

    }

    if(sign == 1){

        toDecimal = toDecimal*(-1);

    }

    return toDecimal;

}

char* NumberBinary::getNumberHex(){

    int current = 3;
    int aux = 0;
    int index = 2;
    char* binary = new char[32];
    char* result = new char[10];

    binary = getNumberBinary();

    result[0] = '0';
    result[1] = 'x';

    for(int i=0; i<32; i++) {

        if (binary[i] == 1){

            aux = aux + pow(2, current);

        }
        current--;

        if (current<0) {

            switch (aux) {

                case 0:

                    result[index] = '0';
                    break;

                case 1:

                    result[index] = '1';
                    break;

                case 2:

                    result[index] = '2';
                    break;

                case 3:

                    result[index] = '3';
                    break;

                case 4:

                    result[index] = '4';
                    break;

                case 5:

                    result[index] = '5';
                    break;

                case 6:

                    result[index] = '6';
                    break;

                case 7:

                    result[index] = '7';
                    break;

                case 8:

                    result[index] = '8';
                    break;

                case 9:

                    result[index] = '9';
                    break;


                case 10:

                    result[index] = 'A';
                    break;

                case 11:

                    result[index] = 'B';
                    break;

                case 12:

                    result[index] = 'C';
                    break;

                case 13:

                    result[index] = 'D';
                    break;

                case 14:

                    result[index] = 'E';
                    break;

                case 15:

                    result[index] = 'F';
                    break;

            }

            index++;
            aux = 0;
            current = 3;

        }

    }

    return result;

}

void NumberBinary::setSign(char newSign){

    sign = newSign;

}

void NumberBinary::setSign(){

    if(numberDecimal<0){

        sign = 1;

    }

    else {

        sign = 0;

    }

}

void NumberBinary::setExponent(){

    int aux = 127+normalizeMantisa;
    int index = 7;

    while(aux>0){

        exponent[index] = aux%2;
        aux = aux/2;
        index--;

    }

    while(index>=0) {

        exponent[index] = 0;
        index--;

    }

}

void NumberBinary::setMantisa(){

    int integer = numberDecimal;
    float decimal = numberDecimal - integer;
    int auxDecimal;
    std::stack<int> stackInteger;
    std::queue<int> queueDecimal;

    /**
     * se inicializa a -1 porque se tiene que correr la coma tantas veces como bits-1 tiene la parte entera
     */

    normalizeMantisa = -1;

    /**
      * convertimos parte entera en binario y lo guardamos en su pila
      */
    while (integer>0){

        stackInteger.push(integer%2);
        integer = integer/2;
        normalizeMantisa++;

    }

    /**
      * convertimos la parte decimal a binario y lo giardamos en su cola
      */
    while (decimal>0) {

        decimal = decimal*2;
        auxDecimal = decimal;
        queueDecimal.push(auxDecimal);
        decimal = decimal-auxDecimal;

    }

    /**
     * guardamos la parte entera en la mantisa
     */
    int index = 0;
    bitRemoveMantisa = stackInteger.top();
    stackInteger.pop();
    while(!stackInteger.empty()){

        mantisa[index] = stackInteger.top();
        stackInteger.pop();
        index++;

    }

    /**
      * guardamos la parte decimal en la mantisa, acontinuacion de la parte entera
      */
    while(!queueDecimal.empty() && index<23){

        mantisa[index] = queueDecimal.front();
        queueDecimal.pop();
        index++;

    }

    /**
      * si no se han rellenado los 23bits de la mantisa lo rellenamos con ceros
      */
    while(index<23){

        mantisa[index] = 0;
        index++;

    }

}

char* NumberBinary::setA2(char* oldMantisa){

    char newMantisa[23];
    int index = 22;

    for(int i=0; i<23; i++){

        newMantisa[i] = oldMantisa[i];

    }

    /**
      * nos colocamos en el primer 1 empezando por la izquierda
      */
    while(newMantisa[index]!=1 && index>=0){

        index--;

    }
    /**
      * una vez encontrado el primer 1 empezando por la izquierda bajamos una posicion mas
      * y cambiamos los 1 por 0 y 0 por 1
      */
    index--;

    while(index>=0){

        if(newMantisa[index]==1){

            newMantisa[index] = 0;

        }

        else {

            newMantisa[index] = 1;

        }

        index--;

    }

    return newMantisa;

}

char* NumberBinary::getExponent(){

    return exponent;

}

char* NumberBinary::getMantisa(){

    return mantisa;

}

char NumberBinary::getSign(){

    return sign;

}

int NumberBinary::getNumberOfExponent(){

    return normalizeMantisa;

}

void NumberBinary::sum(NumberBinary *otherNumber){

    char* A;
    char* B;
    char* P;
    char signThis = getSign();
    char signOther = otherNumber->getSign();
    int es = 0;
    int g = 0;
    int r = 0;
    int st = 0;
    int d = 0;

    /**
     * Comprobamos cual de los dos numeros es mayor y si son de signo diferente calculamos el complemento
     * a2 de B
     */
    if(getNumberOfExponent()<otherNumber->getNumberOfExponent()) {

        A = otherNumber->getMantisa();
        B = getMantisa();

        es = otherNumber->getNumberOfExponent();
        d = otherNumber->getNumberOfExponent() - getNumberOfExponent();


        if (signThis != signOther){

            B = setA2(B);

        }

    }

    else {

        B = otherNumber->getMantisa();
        A = getMantisa();

        es = getNumberOfExponent();
        d = getNumberOfExponent() - otherNumber->getNumberOfExponent();

       if (signThis != signOther){

            B = setA2(B);

        }

    }

    P = B;

    /**
     * Asignamos los bit de guarda, redondeo y sticky
     */
    if (d-1>=0){

        g = P[d-1];

    }

    if(d-2>=0){

        r = P[d-2];

    }

    //FALTA ST

    int acarreo = 0;
    for(int i=23; i>=0;i++){

        //P

    }

}

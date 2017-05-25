#ifndef ALU_H
#define ALU_H

#include "numberbinary.h"
#include <QString>

class Alu
{
public:

    Alu();
    ~Alu();
    void addNumber1(float newNumber);
    void addNumber2(float newNumber);
    QString getBinaryNumber1();
    QString getBinaryNumber2();
    QString getHexNumber1();
    QString getHexNumber2();
    void sum();
    NumberBinary *multiply();
    void division();

private:

    NumberBinary *number1;
    NumberBinary *number2;
};

#endif // ALU_H

#ifndef NUMBERBINARY_H
#define NUMBERBINARY_H

class NumberBinary
{
public:
    NumberBinary();
    NumberBinary(float newNumber);
    ~NumberBinary();
    void setNumber(float newNumber);
    char* getNumberBinary();
    float getNumberDec();
    char* getNumberHex();
    char* getMantisa();
    char* getExponent();
    char getSign();
    int getNumberOfExponent();
    void sum(NumberBinary *otherNumber);

private:
    void setSign();
    void setSign(char newSign);
    void setExponent();
    void setMantisa();
    char* setA2(char *oldMantisa);
    float numberDecimal;
    char sign;
    char exponent[8];
    char mantisa[23];
    int bitRemoveMantisa;
    int normalizeMantisa; // contiene el numero de posiciones que se ha corrido la coma
};

#endif // NUMBERBINARY_H

#include <stdio.h>
#include <stdlib.h>

#include "module.h"



struct ComplexNumbers{
    float real;
    float complex;
};


ComplexNumber createNewComplexNumber(float real, float complex) {
    ComplexNumber newNum = (ComplexNumber)malloc(sizeof(struct ComplexNumbers));
    newNum -> real = real;
    newNum -> complex = complex;

    return newNum;
}

void freeNumber(ComplexNumber z) {
    free(z);
}

ComplexNumber complexSum(ComplexNumber z1, ComplexNumber z2) {
    ComplexNumber result = createNewComplexNumber(0, 0);
    
    float a = ( z1 -> real ), c = ( z1 -> complex );
    float b = ( z2 -> real ), d = ( z2 -> complex );

    ( result -> real ) = a + c;
    ( result -> complex ) = b + d;
    
    return result;
}

ComplexNumber complexProduct(ComplexNumber z1, ComplexNumber z2) {
    ComplexNumber result = createNewComplexNumber(0, 0);

    float a = ( z1 -> real ), c = ( z1 -> complex );
    float b = ( z2 -> real ), d = ( z2 -> complex );

    ( result -> real ) = a * c - b * d;
    ( result -> complex ) = a * d + b * c;

    return result;
}



void printComplex(ComplexNumber z) {
    float a = z -> real, b = z -> complex;
    // Negative sign handler
    char sign = ( b > 0 ) ? '+' : '-';
    b = ( b < 0 ) ? b * (-1) : b;

    printf("%.2f %c j%.2f\n", a, sign, b);
}
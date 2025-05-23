#include <stdio.h>


#include "module.h"



int main() {
    ComplexNumber z1 = createNewComplexNumber(2, 3);
    ComplexNumber z2 = createNewComplexNumber(3, -4);

    printComplex(z1);
    printComplex(z2);

    printComplex(complexSum(z1, z2));
    printComplex(complexProduct(z1, z2));

    freeNumber(z1);
    freeNumber(z2);

    return 0;
}
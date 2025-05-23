#ifndef MODULE_H
#define MODULE_H



typedef struct ComplexNumbers *ComplexNumber;


ComplexNumber createNewComplexNumber(float real, float complex);
void freeNumber(ComplexNumber z);

ComplexNumber complexSum(ComplexNumber z1, ComplexNumber z2);
ComplexNumber complexProduct(ComplexNumber z1, ComplexNumber z2);


void printComplex(ComplexNumber z);


#endif  // MODULE_H
#include <stdio.h>
#include "complex.h"
#include "boolean.h"

boolean IsCOMPLEXValid(float Re, float Im) {
    return true;
}

void CreateComplex(COMPLEX *C, float Re, float Im) {
    Real(*C) = Re;
    Imag(*C) = Im;
}

void BacaCOMPLEX(COMPLEX *C) {
    float Re, Im;
    scanf("%f %f", &Re, &Im);
    CreateComplex(C, Re, Im);
}

void TulisCOMPLEX(COMPLEX C) {
    if (C.Im < 0) {
        printf("%.2f%.2fi\n", Real(C), Imag(C));
    } else {
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    }
}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX C;
    Real(C) = Real(C1) + Real(C2);
    Imag(C) = Imag(C1) + Imag(C2);
    return C;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX C;
    Real(C) = Real(C1) - Real(C2);
    Imag(C) = Imag(C1) - Imag(C2);
    return C;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX C;
    Real(C) = (Real(C1) * Real(C2)) - (Imag(C1) * Imag(C2));
    Imag(C) = (Real(C1) * Imag(C2)) + (Imag(C1) * Real(C2));
    return C;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX C;
    float x = (Real(C2) * Real(C2)) + (Imag(C2) * Imag(C2));
    if (x == 0) {
        Real(C) = 0;
        Imag(C) = 0;
        return C;
    } else {
        COMPLEX conjugateC2 = ConjugateCOMPLEX(C2);
        C = MultiplyCOMPLEX(C1, conjugateC2);
        Real(C) /= x;
        Imag(C) /= x;
        return C;
    }
}

float AbsCOMPLEX(COMPLEX C) {
    return sqrt((Real(C) * Real(C)) + (Imag(C) * Imag(C)));
}

COMPLEX ConjugateCOMPLEX(COMPLEX C) {
    Imag(C) = Imag(C) * (-1);
    return C;
}

boolean CEQ(COMPLEX C1, COMPLEX C2) {
    return ((Real(C1) == Real(C2)) && (Imag(C1) == Imag(C2)));
}

boolean CNEQ(COMPLEX C1, COMPLEX C2) {
    return !((Real(C1) == Real(C2)) && (Imag(C1) == Imag(C2)));
}
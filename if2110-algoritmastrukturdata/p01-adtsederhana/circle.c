#include "circle.h"

#include <math.h>
#include <stdio.h>

boolean IsCIRCLEValid(float X, float Y, float R) { return (R > 0); }

void CreateCIRCLE(CIRCLE *C, float X, float Y, float R) {
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    Center(*C) = P;
    Radius(*C) = R;
}

void ReadCIRCLE(CIRCLE *C) {
    float X, Y, R;
    scanf("%f %f %f", &X, &Y, &R);
    while (!(IsCIRCLEValid(X, Y, R))) {
        printf("CIRCLE tidak valid\n");
        scanf("%f %f %f\n", &X, &Y, &R);
    }
    CreateCIRCLE(C, X, Y, R);
}

void WriteCIRCLE(CIRCLE C) {
    printf("P(%.2f,%.2f) r=%.2f", Absis(Center(C)), Ordinat(Center(C)),
           Radius(C));
}

float Circumference(CIRCLE C) {
    float K = 2 * 3.14 * Radius(C);
    return K;
}

float Area(CIRCLE C) {
    float A = 3.14 * Radius(C) * Radius(C);
    return A;
}

boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P) {
    return (Panjang(Center(C), P) < Radius(C));
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P) {
    float pan = Panjang(Center(C), P);
    return fabs(pan - Radius(C)) < 1e-6;
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2) {
    float d = Panjang(Center(C1), Center(C2));
    return d < fabs(Radius(C2) - Radius(C1));
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2) {
    float d = Panjang(Center(C1), Center(C2));
    float rSum = Radius(C1) + Radius(C2);
    float rDiff = fabs(Radius(C1) - Radius(C2));
    return (fabs(d - rSum) < 1e-6 || fabs(d - rDiff) < 1e-6);
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2) {
    float d = Panjang(Center(C1), Center(C2));
    float rSum = Radius(C1) + Radius(C2);
    float rDiff = fabs(Radius(C1) - Radius(C2));
    return (rDiff < d && d < rSum);
}

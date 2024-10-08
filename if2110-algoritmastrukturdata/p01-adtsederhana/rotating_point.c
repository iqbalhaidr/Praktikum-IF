#include "rotating_point.h"
#include <stdio.h>

COMPLEX PowerCOMPLEX(COMPLEX C, int p)
{
    COMPLEX res;
    int i;
    if (p == 0){
        CreateComplex(&res, 1, 0);
    }else if (p == 1){
        return(C);
    }else {
        res = C;
        for (i = 1; i < p; i++){
            res = MultiplyCOMPLEX(res, C);
        }
    }

    return res;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n)
{
    float x = Absis(*P);
    float y = Ordinat(*P);
    float X_baru, Y_baru;
    int i=0;

    for (i = 0; i < n; i++){
        X_baru = x*Real(PowerCOMPLEX(C, i+1)) - y*Imag(PowerCOMPLEX(C, i+1));
        Y_baru = x*Imag(PowerCOMPLEX(C, i+1)) + y*Real(PowerCOMPLEX(C, i+1)); 

        x = X_baru; y = Y_baru; Absis(*P) = X_baru; Ordinat(*P) = Y_baru;

        if (pow(x, 2) + pow(y, 2) > 1){
            printf("Titik keluar dari lingkaran pada iterasi ke %d", i+1);
            break;
        }
    }

    if (pow(x, 2) + pow(y, 2) <= 1){
        printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", i);
    }else if ((pow(x, 2) + pow(y, 2) > 1) && n == 0){
        printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
    }
}

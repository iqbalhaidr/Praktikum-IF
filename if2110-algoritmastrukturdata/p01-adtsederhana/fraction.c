#include "fraction.h"

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

boolean IsFRACTIONValid(int N, int D) { return (D != 0); }

void CreateFRACTION(FRACTION *F, int N, int R) {
    Numerator(*F) = N;
    Denominator(*F) = R;
}

void ReadFRACTION(FRACTION *F) {
    int R, N;
    scanf("%d %d", &N, &R);
    while (!IsFRACTIONValid(N, R)) {
        printf("FRACTION tidak valid\n");
        scanf("%d %d", &N, &R);
    }
    Numerator(*F) = N;
    Denominator(*F) = R;
}

void WriteFRACTION(FRACTION F) {
    F = SimplifyFRACTION(F);
    printf("%d/%d", Numerator(F), Denominator(F));
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION hasil;
    Numerator(hasil) =
        Numerator(F1) * Denominator(F2) + Numerator(F2) * Denominator(F1);
    Denominator(hasil) = Denominator(F1) * Denominator(F2);
    return SimplifyFRACTION(hasil);
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION hasil;
    Numerator(hasil) =
        Numerator(F1) * Denominator(F2) - Numerator(F2) * Denominator(F1);
    Denominator(hasil) = Denominator(F1) * Denominator(F2);
    return SimplifyFRACTION(hasil);
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION hasil;
    Numerator(hasil) = Numerator(F1) * Numerator(F2);
    Denominator(hasil) = Denominator(F1) * Denominator(F2);

    return SimplifyFRACTION(hasil);
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION hasil;
    Numerator(hasil) = Numerator(F1) * Denominator(F2);
    Denominator(hasil) = Denominator(F1) * Numerator(F2);

    return SimplifyFRACTION(hasil);
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1) {
    FRACTION hasil;
    Numerator(hasil) = Numerator(F1) * n;
    Denominator(hasil) = Denominator(F1);

    return SimplifyFRACTION(hasil);
}
FRACTION SimplifyFRACTION(FRACTION F) {
    FRACTION result;
    int a = Numerator(F);
    int b = Denominator(F);
    int fpb = gcd(a, b);

    int x = a / fpb;
    int y = b / fpb;

    if (y < 0) {
        x = -x;
        y = -y;
    }

    CreateFRACTION(&result, x, y);
    return result;
}

float ToDecimal(FRACTION F) {
    return (float)Numerator(F) / (float)Denominator(F);
}
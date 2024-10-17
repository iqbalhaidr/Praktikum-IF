#include "matrix.h"
#include <stdio.h>

#define MOD 1000000007

int main() {
    Matrix papan;
    int n;
    long long kekacauan = 0;

    scanf("%d", &n);
    readMatrix(&papan, n, n);

    int kekacauanRow[n], kekacauanCol[n];
    for (int i=0; i<n; ++i) {
        kekacauanRow[i] = 0;
        kekacauanCol[i] = 0;
    }

    for (int i=0; i<=getLastIdxRow(papan); ++i) {
        for (int j=0; j<=getLastIdxCol(papan); ++j) {
            kekacauanRow[i] += ELMT(papan, i, j);
            kekacauanCol[j] += ELMT(papan, i, j);
        }
    }

    for (int i=0; i<=getLastIdxRow(papan); ++i) {
        for (int j=0; j<=getLastIdxCol(papan); ++j) {
            if (ELMT(papan, i, j) > 0) {
                kekacauan += (kekacauanRow[i] + kekacauanCol[j] - 2*ELMT(papan, i, j));
            }
        }
    }

    kekacauan = kekacauan % MOD;
    printf("%lld\n", kekacauan);
    return 0;
}
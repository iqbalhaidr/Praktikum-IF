#include "matrix.h"
#include <stdio.h>

#define MOD 1000000007

int main() {
    int n;
    scanf("%d", &n);

    Matrix grid;
    createMatrix(n, n, &grid); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &ELMT(grid, i, j));
        }
    }

    Matrix dp;
    createMatrix(n, n, &dp);
    if (ELMT(grid, 0, 0) == 0) {
        ELMT(dp, 0, 0) = 1;
    }

    for (int i = 1; i < n; i++) {
        if (ELMT(grid, i, 0) == 0) {
            ELMT(dp, i, 0) = ELMT(dp, i-1, 0);
        }
    }
    for (int j = 1; j < n; j++) {
        if (ELMT(grid, 0, j) == 0) {
            ELMT(dp, 0, j) = ELMT(dp, 0, j-1);
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (ELMT(grid, i, j) == 0) {
                ELMT(dp, i, j) = (ELMT(dp, i-1, j) + ELMT(dp, i, j-1)) % MOD;
            }
        }
    }

    printf("%d\n", ELMT(dp, n-1, n-1));
    return 0;
}

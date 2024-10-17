#include "matrix.h"
#include <stdio.h>

void pRotate(Matrix *m) {
    int temp2 = ELMT(*m, 0, 1);
    int temp3 = ELMT(*m, 1, 0);
    ELMT(*m, 0, 1) = ELMT(*m, 0, 0);
    ELMT(*m, 1, 0) = ELMT(*m, 1, 1);
    ELMT(*m, 0, 0) = temp3;
    ELMT(*m, 1, 1) = temp2;
}

int main() {
    Matrix papan, gabungan;
    int n;
    int kemungkinan = 0;
    
    scanf("%d", &n);
    readMatrix(&papan, n, n);
    readMatrix(&gabungan, 2, 2);

    for (int i=1; i<=getLastIdxRow(papan); ++i) {
        for (int j=1; j<=getLastIdxCol(papan); ++j) {
            if ((ELMT(gabungan, 0, 0)<ELMT(papan, i-1, j-1)) && (ELMT(gabungan, 0, 1)<ELMT(papan, i-1, j)) && (ELMT(gabungan, 1, 0)<ELMT(papan, i, j-1)) && (ELMT(gabungan, 1, 1)<ELMT(papan, i, j))) {
                kemungkinan += 1;
            } else {
                for (int r=1; r<=3; ++r) {
                    pRotate(&gabungan);
                    if ((ELMT(gabungan, 0, 0)<ELMT(papan, i-1, j-1)) && (ELMT(gabungan, 0, 1)<ELMT(papan, i-1, j)) && (ELMT(gabungan, 1, 0)<ELMT(papan, i, j-1)) && (ELMT(gabungan, 1, 1)<ELMT(papan, i, j))) {
                        kemungkinan += 1;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", kemungkinan);
    
    return 0;
}
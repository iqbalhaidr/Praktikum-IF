#include "liststatik.h"
#include <stdio.h>

int main() {
    ListStatik l;
    readList(&l);
    int i = getLastIdx(l);
    boolean isGreaterNine = true;
    while (isGreaterNine && i>=0) {
        ELMT(l, i) += 1;
        if (ELMT(l, i) <= 9) {
            isGreaterNine = false;
        } else {
            ELMT(l, i) = 0;
        }
        --i;
    }

    if (isGreaterNine) {
        insertFirst(&l, 1);
    }

    for (int j = IDX_MIN; j < listLength(l); ++j) {
        if (j > 0) {
            printf(" ");
        }
        printf("%d", ELMT(l, j));
    }
    printf("\n");

    return 0;
}
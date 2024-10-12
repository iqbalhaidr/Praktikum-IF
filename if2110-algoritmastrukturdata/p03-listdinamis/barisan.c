#include "listdin.h"
#include <stdio.h>

int main () {
    ListDin l;
    CreateListDin(&l, 1000);
    readList(&l);
    int counter = 0;
    int temp;

    for (int i=0; i<NEFF(l); ++i) {
        for (int j=getFirstIdx(l); j<getLastIdx(l)-i; ++j) {
            if (ELMT(l, j) > ELMT(l, j+1)) {
                temp = ELMT(l, j);
                ELMT(l, j) = ELMT(l, j+1);
                ELMT(l, j+1) = temp;
                counter += 1;
            }
        }
    }

    printf("%d\n", counter);

    return 0;
}
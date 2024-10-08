#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik l, counter, counter_sort;
    CreateListStatik(&counter);
    CreateListStatik(&counter_sort);
    for (int i=IDX_MIN; i<10; ++i) {
        ELMT(counter, i) = 0;         /*init counter*/
        ELMT(counter_sort, i) = 0;    /*init counter_sort*/
    }
    readList(&l);

    for (int i=IDX_MIN; i<listLength(l); ++i) {
        ELMT(counter, ELMT(l, i)) += 1;
        ELMT(counter_sort, ELMT(l, i)) += 1;
    }

    sortList(&counter_sort, false);
    int idx = 0;
    boolean isSecondMostNotZero = false;
    while (!isSecondMostNotZero && (idx<9)) {
        if ((ELMT(counter_sort, idx) != ELMT(counter_sort, idx+1)) && (ELMT(counter_sort, idx+1) != 0)) {
            isSecondMostNotZero = true;
        }
        ++idx;
    }
    

    if (!isSecondMostNotZero) {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    } else {
        printf("%d\n", indexOf(counter, ELMT(counter_sort, idx))); /*indexOf return idx terkecil*/
    }

    return 0;
}
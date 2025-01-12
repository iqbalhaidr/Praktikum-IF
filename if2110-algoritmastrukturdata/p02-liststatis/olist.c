#include <stdio.h>

#include "liststatik.h"

int main() {
    ListStatik l, l_single, counter;
    CreateListStatik(&l_single);
    CreateListStatik(&counter);
    readList(&l);

    for (int i = IDX_MIN; i < listLength(l); ++i) {
        if (indexOf(l_single, ELMT(l, i)) == IDX_UNDEF) {
            insertLast(&l_single, ELMT(l, i));
        }
    }

    for (int j = IDX_MIN; j < listLength(l_single); ++j) {
        int el_ctr = 0;
        for (int k = IDX_MIN; k < listLength(l); ++k) {
            if (ELMT(l_single, j) == ELMT(l, k)) {
                el_ctr = el_ctr + 1;
            }
            ELMT(counter, j) = el_ctr;
        }
    }

    printList(l_single);
    printf("\n");
    for (int a = IDX_MIN; a < listLength(l_single); ++a) {
        printf("%d %d\n", ELMT(l_single, a), ELMT(counter, a));
    }

    return 0;
}
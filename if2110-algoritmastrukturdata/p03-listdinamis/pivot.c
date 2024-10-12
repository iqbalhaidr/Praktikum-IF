#include "listdin.h"
#include <stdio.h>

int main() {
    ListDin l;
    CreateListDin(&l, 100000);
    readList(&l);
    int counter = 0;
    int idxLeft, idxRight;
    boolean isLessEqual, isGreater;

    for (int i=getFirstIdx(l); i<=getLastIdx(l); ++i) {

        isLessEqual = true;
        idxLeft = i-1;
        while (isLessEqual && (idxLeft>=getFirstIdx(l))) {
            if (ELMT(l, i)<ELMT(l, idxLeft)) {
                isLessEqual = false;
            }
            --idxLeft;
        }

        isGreater = true;
        idxRight = i+1;
        while (isGreater && (idxRight<=getLastIdx(l))) {
            if (ELMT(l, i)>=ELMT(l, idxRight)) {
                isGreater = false;
            }
            ++idxRight;
        }

        if (isLessEqual && isGreater) {
            ++counter;
        }
    }

    printf("%d\n", counter);

    return 0;
}
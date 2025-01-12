#include "hapus-duplikat.h"

#include <stdio.h>
#include <stdlib.h>

List hapusDuplikat(List l) {
    List lNew;
    CreateList(&lNew);
    Address p = FIRST(l);
    ElType val;

    if (isEmpty(l)) {  // list kosong
        return lNew;
    }

    if (NEXT(p) == NULL) {  // list hanya 1 elemen
        insertFirst(&lNew, INFO(p));
        return lNew;
    }

    while (NEXT(p) != NULL) {
        if (INFO(p) == INFO(NEXT(p))) {
            val = INFO(p);
            while (INFO(p) == val && NEXT(p) != NULL) {
                p = NEXT(p);
            }
        } else {
            val = INFO(p);
            insertFirst(&lNew, INFO(p));
            p = NEXT(p);
        }
    }

    if (val != INFO(p)) {  // cek elemen terakhir
        insertFirst(&lNew, INFO(p));
    }
    return lNew;
}
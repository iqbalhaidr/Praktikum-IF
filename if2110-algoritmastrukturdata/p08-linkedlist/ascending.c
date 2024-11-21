#include <stdio.h>
#include <stdlib.h>

#include "listlinier.h"

int main() {
    int num, idx;
    Address p;
    List l;
    CreateList(&l);

    scanf("%d", &num);

    while (num != -9999) {
        idx = 0;
        p = FIRST(l);
        while ((p != NULL && num > INFO(p))) {
            idx += 1;
            p = NEXT(p);
        }
        insertAt(&l, num, idx);
        scanf("%d", &num);
    }
    displayList(l);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "listlinier.h"

int main() {
    int N, val, idx;
    char ch;
    List l;
    CreateList(&l);

    scanf("%c", &ch);
    while (ch != 'X') {
        if (ch == 'P') {
            scanf("%d", &N);
            insertFirst(&l, N);

        } else if (ch == 'I') {
            scanf("%d", &N);
            insertLast(&l, N);

        } else if (ch == 'C') {
            if (!isEmpty(l)) {
                deleteFirst(&l, &val);
            }

        } else if (ch == 'D') {
            scanf("%d", &N);
            idx = indexOf(l, N);

            if (idx != -1) {
                deleteAt(&l, idx, &val);
            }
        }
        scanf("%c", &ch);
    }
    displayList(l);

    return 0;
}
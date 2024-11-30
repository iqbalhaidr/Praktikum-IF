#include <stdio.h>

#include "list_circular.h"

int main() {
    int n, i;
    ElType val, max;
    List l;
    CreateList(&l);

    scanf("%d", &n);
    scanf("%d", &val);
    insertLast(&l, val);
    max = val;
    for (i = 0; i < n - 1; ++i) {
        scanf("%d", &val);
        insertLast(&l, val);
        if (val > max) {
            max = val;
        }
    }

    while (INFO(FIRST(l)) != max) {
        deleteFirst(&l, &val);
        insertLast(&l, val);
    }
    displayList(l);

    return 0;
}

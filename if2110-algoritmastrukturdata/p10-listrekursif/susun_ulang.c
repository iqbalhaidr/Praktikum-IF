#include <stdio.h>
#include <stdlib.h>

#include "listrec.h"

ElType getLastEl(List l) {
    if (isOneElmt(l)) {
        return INFO(l);
    }

    return getLastEl(tail(l));
}

void susunUlang(List l, List *res, boolean isNowLast) {
    if (isEmpty(l)) {
        return;
    }

    if (isNowLast) {
        ElType lastElmt = getLastEl(l);
        List l1 = deleteLast(l);
        *res = konsb(*res, lastElmt);
        susunUlang(l1, res, false);
    } else {
        ElType firstElmt = head(l);
        List l1 = deleteFirst(l);
        *res = konsb(*res, firstElmt);
        susunUlang(l1, res, true);
    }
}

int main() {
    int n, i;
    ElType elmt;
    List l = NIL;
    List res = NIL;

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &elmt);
        l = konsb(l, elmt);
    }

    susunUlang(l, &res, false);
    displayList(res);

    return 0;
}
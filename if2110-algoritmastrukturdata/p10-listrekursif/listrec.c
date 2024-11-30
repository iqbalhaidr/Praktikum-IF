#include "listrec.h"

#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType x) {
    Address p = (Address)malloc(sizeof(Node));

    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NIL;
    }

    return p;
}

boolean isEmpty(List l) { return l == NIL; }

boolean isOneElmt(List l) { return !isEmpty(l) && NEXT(l) == NIL; }

ElType head(List l) { return INFO(l); }

List tail(List l) {
    if (isOneElmt(l)) {
        return NIL;
    } else {
        return NEXT(l);
    }
}

List konso(List l, ElType e) {
    Address p = newNode(e);

    if (p != NIL) {
        NEXT(p) = l;
        l = p;
    }

    return l;
}

List konsb(List l, ElType e) {
    if (isEmpty(l)) {
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

List copy(List l) {
    if (isEmpty(l)) {
        return NIL;
    }

    if (isOneElmt(l)) {
        List l1 = newNode(head(l));
        if (l1 == NIL) {
            return l;
        }

        return l1;
    }

    List l1 = newNode(head(l));
    if (l1 == NIL) {
        return l;
    }

    NEXT(l1) = copy(tail(l));
    if (NEXT(l1) == NEXT(l)) {
        return l;
    }

    return l1;
}

Address getLast(List l) {
    if (isEmpty(l)) {
        return NIL;
    }

    if (isOneElmt(l)) {
        return l;
    }

    return getLast(tail(l));
}

List concat(List l1, List l2) {
    List l3 = copy(l1);
    List l4 = copy(l2);

    if (isEmpty(l1) && isEmpty(l2)) {
        return NIL;
    } else if (isEmpty(l1) && !isEmpty(l2)) {
        if (l4 == l2) {
            return NIL;
        }
        return l4;
    } else if (!isEmpty(l1) && isEmpty(l2)) {
        if (l3 == l1) {
            return NIL;
        }
        return l3;
    } else {
        if (l3 == l1 || l4 == l2) {
            return NIL;
        }

        Address lastElmtl3 = getLast(l3);
        NEXT(lastElmtl3) = l4;
        return l3;
    }
}

int length(List l) {
    if (isEmpty(l)) {
        return 0;
    }

    return 1 + length(tail(l));
}

boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    }

    if (head(l) == x) {
        return true;
    }

    return isMember(tail(l), x);
}

void displayList(List l) {
    if (isEmpty(l)) {
        printf("");
        return;
    }

    printf("%d\n", head(l));
    displayList(tail(l));
}

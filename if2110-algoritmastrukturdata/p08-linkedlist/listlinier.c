#include "listlinier.h"

#include <stdio.h>
#include <stdlib.h>

Address getAddress(List l, int idx) {
    Address p = FIRST(l);
    while (idx > 0) {
        p = NEXT(p);
        idx -= 1;
    }
    return p;
}

Address newNode(ElType val) {
    Address p = (Address)malloc(sizeof(Node));

    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(List *l) { FIRST(*l) = NULL; }

boolean isEmpty(List l) { return FIRST(l) == NULL; }

ElType getElmt(List l, int idx) {
    Address p = FIRST(l);

    while (idx > 0) {
        p = NEXT(p);
        idx -= 1;
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
    Address p = FIRST(*l);

    while (idx > 0) {
        p = NEXT(p);
        idx -= 1;
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val) {
    if (isEmpty(l)) {
        return IDX_UNDEF;
    }

    Address p = FIRST(l);
    int idx = IDX_UNDEF;

    while (NEXT(p) != NULL) {
        idx += 1;
        if (INFO(p) == val) {
            return idx;
        }
        p = NEXT(p);
    }

    if (INFO(p) == val) {
        idx += 1;
        return idx;
    }
    return IDX_UNDEF;
}

void insertFirst(List *l, ElType val) {
    Address p = newNode(val);
    if (p == NULL) {
        return;
    }

    if (isEmpty(*l)) {
        FIRST(*l) = p;
        return;
    }

    NEXT(p) = *l;
    FIRST(*l) = p;
}

void insertLast(List *l, ElType val) {
    Address p = newNode(val);
    if (p == NULL) {
        return;
    }

    if (isEmpty(*l)) {
        FIRST(*l) = p;
        return;
    }

    Address t = FIRST(*l);
    while (NEXT(t) != NULL) {
        t = NEXT(t);
    }
    NEXT(t) = p;
}

void insertAt(List *l, ElType val, int idx) {
    Address p = newNode(val);
    if (p == NULL) {
        return;
    }

    if (idx == 0) {
        insertFirst(l, val);
        return;
    }

    Address t = FIRST(*l);
    while (idx > 1) {
        t = NEXT(t);
        idx -= 1;
    }
    NEXT(p) = NEXT(t);
    NEXT(t) = p;
}

void deleteFirst(List *l, ElType *val) {
    Address p = FIRST(*l);
    *val = INFO(p);

    if (length(*l) == 1) {
        CreateList(l);
        free(p);
        return;
    }

    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val) {
    if (length(*l) == 1) {
        Address first = FIRST(*l);
        *val = INFO(first);
        CreateList(l);
        free(first);
        return;
    }

    Address beforeLast = getAddress(*l, length(*l) - 2);
    Address last = NEXT(beforeLast);
    *val = INFO(last);
    NEXT(beforeLast) = NULL;
    free(last);
}

void deleteAt(List *l, int idx, ElType *val) {
    if (idx == 0) {
        deleteFirst(l, val);
        return;
    }

    Address beforeIdx = getAddress(*l, idx - 1);
    Address currentIdx = NEXT(beforeIdx);
    *val = INFO(currentIdx);
    NEXT(beforeIdx) = NEXT(currentIdx);
    free(currentIdx);
}

void displayList(List l) {
    if (isEmpty(l)) {
        printf("[]");
        return;
    }

    Address p = FIRST(l);
    printf("[");
    while (NEXT(p) != NULL) {
        printf("%d,", INFO(p));
        p = NEXT(p);
    }
    printf("%d]", INFO(p));
}

int length(List l) {
    if (isEmpty(l)) {
        return 0;
    }

    int len = 1;
    Address p = FIRST(l);

    while (NEXT(p) != NULL) {
        len += 1;
        p = NEXT(p);
    }
    return len;
}

List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);

    Address p = FIRST(l1);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    p = FIRST(l2);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    return l3;
}
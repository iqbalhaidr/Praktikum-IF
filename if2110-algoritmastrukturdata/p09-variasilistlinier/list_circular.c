#include "list_circular.h"

#include <stdio.h>
#include <stdlib.h>

boolean isEmpty(List l) { return FIRST(l) == NULL; }

void CreateList(List *l) { FIRST(*l) = NULL; }

Address allocate(ElType val) {
    Address p = (Address)malloc(sizeof(ElmtList));

    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }

    return p;
}

void deallocate(Address P) { free(P); }

Address search(List l, ElType val) {
    if (isEmpty(l)) {
        return NULL;
    }

    Address firstElmt = FIRST(l);
    if (INFO(firstElmt) == val) {
        return firstElmt;
    }

    Address p = NEXT(firstElmt);
    while (p != firstElmt) {
        if (INFO(p) == val) {
            return p;
        }
        p = NEXT(p);
    }

    return NULL;
}

boolean addrSearch(List l, Address p) {
    if (isEmpty(l)) {
        return false;
    }

    Address firstElmt = FIRST(l);
    if (firstElmt == p) {
        return true;
    }

    Address trav = NEXT(firstElmt);
    while (trav != firstElmt) {
        if (trav == p) {
            return true;
        }
        trav = NEXT(trav);
    }

    return false;
}

void insertFirst(List *l, ElType val) {
    Address p = allocate(val);

    if (p == NULL) {
        return;
    }

    if (isEmpty(*l)) {
        FIRST(*l) = p;
        NEXT(p) = p;
        return;
    }

    Address lastElmt = FIRST(*l);
    while (NEXT(lastElmt) != FIRST(*l)) {
        lastElmt = NEXT(lastElmt);
    }

    NEXT(p) = FIRST(*l);
    FIRST(*l) = p;
    NEXT(lastElmt) = p;
}

void insertLast(List *l, ElType val) {
    Address p = allocate(val);

    if (p == NULL) {
        return;
    }

    if (isEmpty(*l)) {
        FIRST(*l) = p;
        NEXT(p) = p;
        return;
    }

    Address lastElmt = FIRST(*l);
    while (NEXT(lastElmt) != FIRST(*l)) {
        lastElmt = NEXT(lastElmt);
    }

    NEXT(p) = FIRST(*l);
    NEXT(lastElmt) = p;
}

void deleteFirst(List *l, ElType *val) {
    Address firstElmt = FIRST(*l);
    *val = INFO(firstElmt);

    if (NEXT(firstElmt) == firstElmt) {
        FIRST(*l) = NULL;
        deallocate(firstElmt);
        return;
    }

    Address lastElmt = FIRST(*l);
    while (NEXT(lastElmt) != FIRST(*l)) {
        lastElmt = NEXT(lastElmt);
    }

    FIRST(*l) = NEXT(firstElmt);
    NEXT(lastElmt) = NEXT(firstElmt);
    deallocate(firstElmt);
}

void deleteLast(List *l, ElType *val) {
    Address firstElmt = FIRST(*l);
    Address lastElmt = FIRST(*l);
    Address prevLastElmt;

    while (NEXT(lastElmt) != FIRST(*l)) {
        prevLastElmt = lastElmt;
        lastElmt = NEXT(lastElmt);
    }
    *val = INFO(lastElmt);

    if (NEXT(firstElmt) == firstElmt) {
        FIRST(*l) = NULL;
        deallocate(firstElmt);
        return;
    }

    NEXT(prevLastElmt) = FIRST(*l);
    deallocate(lastElmt);
}

void displayList(List l) {
    if (isEmpty(l)) {
        printf("[]");
        return;
    }

    Address firstElmt = FIRST(l);
    Address p = NEXT(firstElmt);
    printf("[%d", INFO(firstElmt));
    while (p != firstElmt) {
        printf(",%d", INFO(p));
        p = NEXT(p);
    }
    printf("]");
}
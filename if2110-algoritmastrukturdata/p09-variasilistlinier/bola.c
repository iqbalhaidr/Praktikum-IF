#include <stdio.h>
#include <stdlib.h>

#include "list_circular.h"

// N >= 1 Optimized
void makeList(List *l, int N, Address *lastElmtAddr) {
    Address firstElmt, prev, p;
    ElType val;
    int i;

    val = 1;
    firstElmt = allocate(val);
    while (firstElmt == NULL) {
        firstElmt = allocate(val);
    }
    p = firstElmt;

    for (i = 0; i < N - 1; i++) {
        prev = p;
        val = i + 2;
        p = allocate(val);
        while (p == NULL) {
            p = allocate(val);
        }
        NEXT(prev) = p;
    }

    FIRST(*l) = firstElmt;
    NEXT(p) = firstElmt;
    *lastElmtAddr = p;
}

void normalizeMov(int *mov, int len) {
    int newMov = *mov;
    if (newMov > 0) {
        if (newMov % len == 0) {
            newMov = len;
            *mov = newMov;
            return;
        }
        newMov %= len;
        *mov = newMov;
        return;
    } else {
        if (newMov % len == 0) {
            newMov = 1;
            *mov = newMov;
            return;
        }
        newMov %= len;
        newMov += len + 1;
        *mov = newMov;
        return;
    }
}

void normalizeMovFirst(int *mov, int len) {
    int newMov = *mov;
    if (newMov > 0) {
        newMov %= len;
        *mov = newMov;
        return;
    } else {
        if (newMov % len == 0) {
            newMov = 0;
            *mov = newMov;
            return;
        }
        newMov %= len;
        newMov += len;
        *mov = newMov;
        return;
    }
}

void firstMove(Address *p, Address *prev, int mov, int len) {
    for (int j = 0; j < mov; j++) {
        *prev = *p;
        *p = NEXT(*p);
    }
}

void move(Address *p, Address *prev, int mov, int len) {
    *p = NEXT(*p);
    for (int j = 0; j < mov - 1; j++) {
        *prev = *p;
        *p = NEXT(*p);
    }
}

int main() {
    int n, i, mov, len;
    ElType val;
    Address p, lastElmtAddr, prev;
    List l;
    CreateList(&l);

    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    makeList(&l, n, &lastElmtAddr);

    len = n;
    p = FIRST(l);
    prev = lastElmtAddr;

    scanf("%d", &mov);
    normalizeMovFirst(&mov, len);
    firstMove(&p, &prev, mov, len);
    for (i = 0; i < n - 2; ++i) {
        NEXT(prev) = NEXT(p);
        len--;
        scanf("%d", &mov);
        normalizeMov(&mov, len);
        move(&p, &prev, mov, len);
    }

    printf("%d\n", INFO(prev));

    return 0;
}
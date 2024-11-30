#include <stdio.h>

#include "list_circular.h"

boolean isClockwise(List l, int len) {
    Address maxAddr = search(l, len);
    Address p = NEXT(maxAddr);

    while (p != maxAddr) {
        if (INFO(NEXT(p)) <= INFO(p)) {
            return false;
        }
        p = NEXT(p);
    }

    return true;
}

boolean isCounterClockwise(List l, int len) {
    Address maxAddr = search(l, len);
    Address p = maxAddr;

    while (NEXT(p) != maxAddr) {
        if (INFO(NEXT(p)) >= INFO(p)) {
            return false;
        }
        p = NEXT(p);
    }

    return true;
}

int main() {
    int n, i;
    ElType val;
    List l;
    CreateList(&l);

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &val);
        insertLast(&l, val);
    }

    if (isClockwise(l, n) || isCounterClockwise(l, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
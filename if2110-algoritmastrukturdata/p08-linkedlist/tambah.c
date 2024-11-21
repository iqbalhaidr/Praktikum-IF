#include <stdio.h>
#include <stdlib.h>

#include "listlinier.h"

void reverseList(List *l) {
    Address prev = NULL;
    Address current = *l;
    Address next = NULL;
    while (current != NULL) {
        next = NEXT(current);
        NEXT(current) = prev;
        prev = current;
        current = next;
    }
    *l = prev;
}

int main() {
    List l1, l2, sumList;
    CreateList(&l1);
    CreateList(&l2);
    CreateList(&sumList);

    int digit;
    while (scanf("%d", &digit), digit != -1) {
        insertLast(&l1, digit);
    }

    while (scanf("%d", &digit), digit != -1) {
        insertLast(&l2, digit);
    }

    reverseList(&l1);
    reverseList(&l2);

    Address p1 = l1;
    Address p2 = l2;
    int carry = 0;
    while (p1 != NULL || p2 != NULL || carry != 0) {
        int val1 = (p1 != NULL) ? INFO(p1) : 0;
        int val2 = (p2 != NULL) ? INFO(p2) : 0;
        int sum = val1 + val2 + carry;
        int digitSum = sum % 10;
        carry = sum / 10;
        insertLast(&sumList, digitSum);
        if (p1 != NULL) p1 = NEXT(p1);
        if (p2 != NULL) p2 = NEXT(p2);
    }

    reverseList(&sumList);

    Address p = sumList;
    while (p != NULL) {
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p != NULL) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

#include "prioqueue.h"

#include <stdio.h>

void switchBefore(PrioQueue *pq,
                  int idx) {  // selalu switch dengan idx-1 (sebelumnya)
    if (idx == 0) {
        ElType temp = (*pq).buffer[idx];
        (*pq).buffer[idx] = (*pq).buffer[CAPACITY - 1];
        (*pq).buffer[CAPACITY - 1] = temp;
        return;
    }

    ElType temp = (*pq).buffer[idx];
    (*pq).buffer[idx] = (*pq).buffer[idx - 1];
    (*pq).buffer[idx - 1] = temp;
}

void CreatePrioQueue(PrioQueue *pq) {
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq) {
    return (IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF);
}

boolean isFull(PrioQueue pq) { return (length(pq) == CAPACITY); }

int length(PrioQueue pq) {
    if (isEmpty(pq)) {
        return 0;
    }

    if (IDX_TAIL(pq) >= IDX_HEAD(pq)) {  //"tail" tidak didepan "head"
        return (IDX_TAIL(pq) - IDX_HEAD(pq) + 1);
    } else {  //"tail" didepan "head"
        return (CAPACITY - IDX_HEAD(pq)) + (IDX_TAIL(pq) + 1);
    }
}

void enqueue(PrioQueue *pq, ElType val) {
    if (isEmpty(*pq)) {  // kasus queue kosong
        IDX_HEAD(*pq) += 1;
        IDX_TAIL(*pq) += 1;
        HEAD(*pq) = val;
        return;
    }

    IDX_TAIL(*pq) += 1;
    if (IDX_TAIL(*pq) == CAPACITY) {  // kasus "tail" lebih dari "capacity"
        IDX_TAIL(*pq) = 0;
    }

    TAIL(*pq) = val;
    int idx = IDX_TAIL(*pq);

    while (idx != (IDX_HEAD(*pq))) {
        if (idx == 0) {
            if ((*pq).buffer[idx] > (*pq).buffer[CAPACITY - 1]) {
                switchBefore(pq, idx);
                idx = CAPACITY - 1;
            } else {
                break;
            }
        } else {
            if ((*pq).buffer[idx] > (*pq).buffer[idx - 1]) {
                switchBefore(pq, idx);
                idx -= 1;
            } else {
                break;
            }
        }
    }
}

void dequeue(PrioQueue *pq, ElType *val) {
    *val = HEAD(*pq);

    if (IDX_HEAD(*pq) ==
        IDX_TAIL(*pq)) {  // kasus hanya satu elemen sehingga menjadi kosong
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
        return;
    }

    IDX_HEAD(*pq) += 1;
    if (IDX_HEAD(*pq) == CAPACITY) {  // kasus "head" melebihi "capacity"
        IDX_HEAD(*pq) = 0;
    }
}

void displayPrioQueue(PrioQueue pq) {
    if (isEmpty(pq)) {
        printf("[]\n");
        return;
    }

    int initIdxHead = IDX_HEAD(pq);
    int len = length(pq);

    printf("[");
    for (int i = 0; i < len - 1; ++i) {
        printf("%d,", HEAD(pq));
        IDX_HEAD(pq) += 1;

        if (IDX_HEAD(pq) == CAPACITY) {
            IDX_HEAD(pq) = 0;
        }
    }
    printf("%d", HEAD(pq));
    printf("]\n");
    IDX_HEAD(pq) = initIdxHead;
}
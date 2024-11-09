#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q) {
    return(length(q) == CAPACITY);
}

int length(Queue q) {
    if (isEmpty(q)) {
        return 0;
    }

    if (IDX_TAIL(q) >= IDX_HEAD(q)) { //"tail" tidak didepan "head"
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    } else { //"tail" didepan "head"
        return (CAPACITY-IDX_HEAD(q)) + (IDX_TAIL(q) + 1);
    }
}

void enqueue(Queue *q, ElType val) { 
    if (isEmpty(*q)) { //kasus queue kosong
        IDX_HEAD(*q) += 1;
    }

    IDX_TAIL(*q) += 1;
    if (IDX_TAIL(*q) == CAPACITY) { //kasus "tail" lebih dari "capacity"
        IDX_TAIL(*q) = 0;
    }

    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val) {
    *val = HEAD(*q);

    if (IDX_HEAD(*q) == IDX_TAIL(*q)) { //kasus hanya satu elemen sehingga menjadi kosong
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
        return;
    }

    IDX_HEAD(*q) += 1;
    if (IDX_HEAD(*q) == CAPACITY) { //kasus "head" melebihi "capacity"
        IDX_HEAD(*q) = 0;
    }
}

void displayQueue(Queue q) {
    if (isEmpty(q)) {
        printf("[]\n");
        return;
    }

    int initIdxHead = IDX_HEAD(q);
    int len = length(q);

    printf("[");
    for (int i=0; i<len-1; ++i) {
        printf("%d,", HEAD(q));
        IDX_HEAD(q) += 1;

        if (IDX_HEAD(q) == CAPACITY) {
            IDX_HEAD(q) = 0;
        }
    }
    printf("%d", HEAD(q));
    printf("]\n");
    IDX_HEAD(q) = initIdxHead;
}

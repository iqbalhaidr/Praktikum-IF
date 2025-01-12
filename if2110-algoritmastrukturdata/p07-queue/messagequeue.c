#include <stdio.h>

#include "queue.h"

int main() {
    Queue q;
    CreateQueue(&q);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int x;
            scanf("%d", &x);

            if (isFull(q)) {
                printf("Queue Penuh\n");
            } else {
                enqueue(&q, x);
                printf("Enqueue %d Berhasil\n", x);
            }

        } else if (op == 2) {
            int val;

            if (isEmpty(q)) {
                printf("Queue Kosong\n");
            } else {
                dequeue(&q, &val);
                printf("Dequeue %d Berhasil\n", val);
            }

        } else if (op == 3) {
            if (isEmpty(q)) {
                printf("Queue Kosong\n");
            } else {
                printf("Elemen Awal Queue adalah %d\n", HEAD(q));
            }

        } else if (op == 4) {
            int len = length(q);
            printf("Ukuran Queue saat ini adalah %d\n", len);
        }
    }

    displayQueue(q);
}